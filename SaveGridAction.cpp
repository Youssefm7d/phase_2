#include "SaveGridAction.h"
/*
SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp) {}
void SaveGridAction::ReadActionParameters()
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
void SaveGridAction::Execute() {
    ReadActionParameters();
    Grid* pGrid = pManager->GetGrid();

    //open ile and check
    std::ofstream OutFile(filename);
    if (OutFile.is_open()) {
        pGrid->PrintErrorMessage("Error opening file for saving.");
        return;
    }
    // Save all game objects by type
    pGrid->SaveAll(OutFile, flag);           // Save flags
    pGrid->SaveAll(OutFile, water_pit);      // Save water pits
    pGrid->SaveAll(OutFile, danger_zone);    // Save danger zones
    pGrid->SaveAll(OutFile, belt);           // Save belts
    pGrid->SaveAll(OutFile, workshop);       // Save workshop
    pGrid->SaveAll(OutFile, antenna);        // Save antenna
    pGrid->SaveAll(OutFile, rotating_gear);  // Save rotating gear

    // Close the file
    OutFile.close();

    // Show completion message
    pGrid->PrintErrorMessage("Grid saved successfully! Click to continue...");
}

SaveGridAction::~SaveGridAction() {

}
*/
// SaveGridAction.cpp
SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp) {

}

void SaveGridAction::ReadActionParameters()
{
    // No parameters needed for SaveGridAction
}
void SaveGridAction::Execute() {

    // Get grid and UI pointers
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    // Ask the user for the filename
    pOut->PrintMessage("Enter the filename to save the grid: ");
    std::string filename = pIn->GetSrting(pOut);

    // Open the file
    std::ofstream OutFile(filename);
    if (!OutFile.is_open())
    {
        pGrid->PrintErrorMessage("Error opening file for saving. Click to continue...");
        return;
    }

    // Save each game object type in the specified format
    pGrid->SaveAll(OutFile, flag);           // Save flags
    pGrid->SaveAll(OutFile, water_pit);      // Save water pits
    pGrid->SaveAll(OutFile, danger_zone);    // Save danger zones
    pGrid->SaveAll(OutFile, belt);           // Save belts
    pGrid->SaveAll(OutFile, workshop);       // Save workshops
    pGrid->SaveAll(OutFile, antenna);        // Save antennas
    pGrid->SaveAll(OutFile, rotating_gear);  // Save rotating gears

    // Close the file and confirm completion
    OutFile.close();
    pOut->PrintMessage("Grid saved successfully. Click to continue...");
}

SaveGridAction::~SaveGridAction()
{
}