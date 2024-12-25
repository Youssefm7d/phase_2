#include "SaveGridAction.h"
SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp) {

}

void SaveGridAction::ReadActionParameters()
{
    /*
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
    */
}
void SaveGridAction::Execute() {
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    // Get the filename from the user
    pOut->PrintMessage("Enter the filename to save the grid: ");
    std::string filename = pIn->GetSrting(pOut);

    // Open the file
    std::ofstream OutFile(filename);
    if (!OutFile.is_open())
    {
        pGrid->PrintErrorMessage("Error opening file for saving. Click to continue...");
        return;
    }

    // Save all object types in order
    pGrid->SaveAll(OutFile, flag);
    pGrid->SaveAll(OutFile, water_pit);
    pGrid->SaveAll(OutFile, danger_zone);
    pGrid->SaveAll(OutFile, belt);
    pGrid->SaveAll(OutFile, workshop);
    pGrid->SaveAll(OutFile, antenna);
    pGrid->SaveAll(OutFile, rotating_gear);

    OutFile.close();
    pOut->PrintMessage("Grid saved successfully. Click to continue...");
}

SaveGridAction::~SaveGridAction()
{
}