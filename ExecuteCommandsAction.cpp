#include "ExecuteCommandsAction.h"
#include "Player.h"
#include "SelectedCommands.h"
#include "Grid.h"



ExecuteCommandsAction::ExecuteCommandsAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void ExecuteCommandsAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Click on the command you want to select");
	selectedCommand = pGrid->GetAvailableCommands().GetCommand(pIn->GetSelectedCommandIndex());


	pManager->GetGrid()->GetOutput()->ClearStatusBar();
}

void ExecuteCommandsAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	pPlayer->GetSelectedCommands().AddCommand(selectedCommand);

}

ExecuteCommandsAction::~ExecuteCommandsAction()
{
}
