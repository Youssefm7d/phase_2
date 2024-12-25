#include "SelectCommandAction.h"
#include "SelectedCommands.h"
#include "Grid.h"



SelectCommandAction::SelectCommandAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void SelectCommandAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Click on the command you want to select");
	//selectedCommand = pGrid->GetAvailableCommands()->GetCommand(pIn->GetSelectedCommandIndex());


	pManager->GetGrid()->GetOutput()->ClearStatusBar();
}

void SelectCommandAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	//pPlayer->
	// 1-Create a flag object
	// 2-get a pointer to the Grid from the ApplicationManager
	// 3-Add the flag object to the GameObject of its Cell:
	// 4-Check if the flag was added and print an errror message if flag couldn't be added

}

SelectCommandAction::~SelectCommandAction()
{
}