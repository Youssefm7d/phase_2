
#include "DeleteGameObject.h"

DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp)
{
    DeleteActive = false;
}

void DeleteGameObject::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();

    // Indicate to the user that delete mode is active
    pOut->PrintMessage("Delete mode activated. Click on the cell to delete its game object...");
    // Wait for the user to click a cell
    targetPosition = pIn->GetCellClicked();

    DeleteActive = true;

    // Clear status bar after selection
    pOut->ClearStatusBar();
}

void DeleteGameObject::Execute()
{


    if (!DeleteActive)
    {
        // Ensure action only happens after delete mode is triggered
        ReadActionParameters();
    }

    // Access Grid
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();

    // Validate position
    if (!targetPosition.IsValidCell())
    {
        pGrid->PrintErrorMessage("Error: Invalid cell position! Click to continue...");
        return;
    }

    GameObject* pObject = pGrid->Get_object_pos(targetPosition);

    // Check if an object was deleted
    if (pObject)
    {
        pGrid->RemoveObjectFromCell(targetPosition);
        delete pObject; // Free memory
        pOut->DrawCell(targetPosition,UI.CellColor);
        pGrid->PrintErrorMessage("Game object deleted successfully! Click to continue...");
    }
    else
    {
        pGrid->PrintErrorMessage("No game object found at the selected cell! Click to continue...");
    }
}

DeleteGameObject::~DeleteGameObject()
{
}

