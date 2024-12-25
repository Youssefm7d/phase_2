#include "RebootAndRepairAction.h"
#include "Player.h"
#include "Grid.h"



RebootAndRepairAction::RebootAndRepairAction(ApplicationManager* pApp) : Action(pApp)
{
	pPlayer = NULL;
	// Initializes the pManager pointer of Action with the passed pointer
}

void RebootAndRepairAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pPlayer = pGrid->GetCurrentPlayer();
	pOut->PrintMessage("Click anywhere to reboot and repair your health");

	pManager->GetGrid()->GetOutput()->ClearStatusBar();
}

void RebootAndRepairAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	if (pPlayer->GetHealth() == 10) {
		pGrid->PrintErrorMessage("Your Health Is Already Full");
		return;
	}
	else {
		pPlayer->SetHealth(10);
		pPlayer->FinishPlayingRound();
	}
}

RebootAndRepairAction::~RebootAndRepairAction()
{
}