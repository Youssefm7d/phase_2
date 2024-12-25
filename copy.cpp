#include "copy.h"
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Cell.h"

CopyGameObject::CopyGameObject(ApplicationManager* pApp) : Action(pApp) {}

void CopyGameObject::ReadActionParameters() {
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    // Prompt user to select a source cell
    pOut->PrintMessage("Click on the source cell to copy the game object.");
    CellPosition cellPos = pIn->GetCellClicked();

    if (!cellPos.IsValidCell()) {
        pOut->PrintMessage("Invalid cell! Action aborted.");
        return;
    }

    GameObject* pGameObject = pGrid->Get_object_pos(cellPos);
    if (!pGameObject) {
        pOut->PrintMessage("No game object found in the selected cell! Action aborted.");
        return;
    }

    pGrid->SetClipboard(pGameObject);
    pOut->PrintMessage("Game object copied to clipboard successfully!");
}

void CopyGameObject::Execute() {
    ReadActionParameters();
}

CopyGameObject::~CopyGameObject() {}
