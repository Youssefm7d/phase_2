#include "UseToolKitAction.h"
#include "Player.h"
#include "Grid.h"



UseToolKitAction::UseToolKitAction(ApplicationManager* pApp) : Action(pApp)
{
	pRepairingPlayer = NULL;
	// Initializes the pManager pointer of Action with the passed pointer
}

void UseToolKitAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Click anywhere to repair your health");
	pRepairingPlayer = pGrid->GetCurrentPlayer();

	pManager->GetGrid()->GetOutput()->ClearStatusBar();
}

void UseToolKitAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	if (pRepairingPlayer->GetHealth() == 10) {
		pGrid->PrintErrorMessage("Your Health Is Already Full");
		return;
	}
	else {
		pRepairingPlayer->SetHealth(10);
	}
}

UseToolKitAction::~UseToolKitAction()
{
}