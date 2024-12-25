#include "UseHackDevice.h"
#include "Player.h"
#include "Grid.h"



UseHackDevice::UseHackDevice(ApplicationManager* pApp) : Action(pApp)
{
	pHackedPlayer = NULL;
	// Initializes the pManager pointer of Action with the passed pointer
}

void UseHackDevice::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Click on the player you want to prevent from playing this turn");
	CellPosition playerPos = pIn->GetCellClicked();

	pHackedPlayer = pGrid->Get_player_pos(playerPos);

	pManager->GetGrid()->GetOutput()->ClearStatusBar();
}

void UseHackDevice::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	if (pHackedPlayer != NULL) {
		pHackedPlayer->FinishPlayingRound();
	}
	else {
		pGrid->PrintErrorMessage("There are no players in this cell");
		return;
	}
}

UseHackDevice::~UseHackDevice()
{
}