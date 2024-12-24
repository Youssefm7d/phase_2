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
    pOut->PrintMessage("Enter the filename to save the grid: ");
    filename = pIn->GetSrting(pOut);

    // Clear the status bar
    pOut->ClearStatusBar();
}

/*

void LoadGridAction::Execute() {


    ReadActionParameters();

    std::ifstream inFile(filename);

    Grid* pGrid = pManager->GetGrid();

    //open ile and check
    if (!inFile.is_open()) 
    {
        // If the file couldn't be opened, show an error message
        Grid* pGrid = pManager->GetGrid();
        pGrid->PrintErrorMessage("Error: Could not open file. Click to continue...");
        return;
    }

    // Get the grid
    Grid* pGrid = pManager->GetGrid();

    // Read and load objects by type
    pGrid->SaveAll(OutFile, flag);           // Save flags
    pGrid->SaveAll(OutFile, water_pit);      // Save water pits
    pGrid->SaveAll(OutFile, danger_zone);    // Save danger zones
    pGrid->SaveAll(OutFile, belt);           // Save belts
    pGrid->SaveAll(OutFile, workshop);       // Save workshop
    pGrid->SaveAll(OutFile, antenna);        // Save antenna
    pGrid->SaveAll(OutFile, rotating_gear);  // Save rotating gear

    // Show completion message
    pGrid->PrintErrorMessage("Grid loaded successfully! Click to continue...");
}

LoadGridAction::~LoadGridAction() {

}
*/

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