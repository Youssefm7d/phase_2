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

    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();


    pOut->PrintMessage("Enter the filename to load the grid: ");
    std::string filename = pIn->GetSrting(pOut);

    std::ifstream InFile(filename);
    if (!InFile.is_open()) {
        pGrid->PrintErrorMessage("Error opening file for loading.");
        return;
    }

    // Load all game objects by type with headers
    std::string header;
    InFile >> header; // Read header
    pGrid->LoadAll(InFile, flag);

    InFile >> header; // Read header
    pGrid->LoadAll(InFile, water_pit);

    InFile >> header; // Read header
    pGrid->LoadAll(InFile, danger_zone);

    InFile >> header; // Read header
    pGrid->LoadAll(InFile, belt);

    InFile >> header; // Read header
    pGrid->LoadAll(InFile, workshop);

    InFile >> header; // Read header
    pGrid->LoadAll(InFile, antenna);

    InFile >> header; // Read header
    pGrid->LoadAll(InFile, rotating_gear);

    InFile.close();
    pOut->PrintMessage("Grid loaded successfully.");
}
LoadGridAction::~LoadGridAction() {

}