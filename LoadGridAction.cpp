#include "LoadGridAction.h"
LoadGridAction::LoadGridAction(ApplicationManager* pApp) : Action(pApp) {
}
void LoadGridAction::ReadActionParameters()
{
    // Get pointers to Input and Output
    Grid* pGrid = pManager->GetGrid();
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();
    // Ask the user for the filename
    pOut->PrintMessage("Enter the filename to load the grid: ");
    filename = pIn->GetSrting(pOut);

    // Clear the status bar
    pOut->ClearStatusBar();
}

void LoadGridAction::Execute() {
    
    ReadActionParameters();

    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();

    std::ifstream InFile(filename);
    if (!InFile.is_open()) {
        pGrid->PrintErrorMessage("Error opening file for loading.");
        return;
    }
    // remoe new grid
    for (int i = 0; i < NumVerticalCells; ++i)
    {
        for (int j = 0; j < NumHorizontalCells; ++j)
        {
            CellPosition pos(i, j); // Create a CellPosition for the current cell
            pGrid->RemoveObjectFromCell(pos); // Remove the object from this cell
        }
    }
    // Load all game objects by type with headers
    pGrid->LoadAll(InFile, flag);
    pGrid->LoadAll(InFile, water_pit);
    pGrid->LoadAll(InFile, danger_zone);
    pGrid->LoadAll(InFile, belt);
    pGrid->LoadAll(InFile, workshop);
    pGrid->LoadAll(InFile, antenna);
    pGrid->LoadAll(InFile, rotating_gear);
    pOut->PrintMessage("Grid loaded successfully.");

}
LoadGridAction::~LoadGridAction() {

}