#include "Paste.h"

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp) {}

void PasteAction::ReadActionParameters() {
    Grid* pGrid = pManager->GetGrid();
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();

    pOut->PrintMessage("Paste: Click on the cell to paste the object...");
    targetPos = pIn->GetCellClicked();
    if (!targetPos.IsValidCell()) {
        pOut->PrintMessage("Invalid cell. Operation canceled.");
        return;
    }

    pOut->ClearStatusBar();
}

void PasteAction::Execute() {
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();

    GameObject* clipboardObj = pGrid->GetClipboard();
    if (!clipboardObj) {
        pOut->PrintMessage("Paste: No object in the clipboard. Operation canceled.");
        return;
    }

    if (pGrid->GetGameObject(targetPos)) {
        pOut->PrintMessage("Paste: Target cell is occupied. Operation canceled.");
        return;
    }

    GameObject* pastedObj = clipboardObj->Clone(); // Create a copy of the clipboard object
    pastedObj->SetPosition(targetPos);
    bool added = pGrid->AddObjectToCell(pastedObj);

    if (added) {
        pOut->PrintMessage("Paste: Object successfully pasted.");
    }
    else {
        delete pastedObj; // Avoid memory leak
        pOut->PrintMessage("Paste: Failed to paste object.");
    }
}

PasteAction::~PasteAction() {}