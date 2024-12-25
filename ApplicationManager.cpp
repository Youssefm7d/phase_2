#include "ApplicationManager.h"

#include "Grid.h"
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddFlagAction.h"

///TODO: Add #include for all action types
#include "AddAntennaAction.h"
#include "AddWaterPitaction.h"
#include "AddWorkshopAction.h"
#include "AddDangerZoneAction.h"
#include "SaveGridAction.h"
#include "DeleteGameObject.h"
#include "LoadGridAction.h"

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_BELT:
		pAct = new AddBeltAction(this);
		break;

	case ADD_ROTATING_GEAR:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this);
		break;
	case ADD_FLAG:
		// create an object of AddFlagAction here
		pAct = new AddFlagAction(this);
		break;

	case EXIT:
		break;

	case TO_PLAY_MODE:					//TODO:
		pOut->CreatePlayModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		UI.InterfaceMode = MODE_PLAY;
		pGrid->UpdateInterface();
		pOut->PrintMessage("Play");
		break;

	

	case TO_DESIGN_MODE:				//TODO:
		pOut->CreateDesignModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		UI.InterfaceMode = MODE_DESIGN;
		pOut->ClearGridArea();
		pOut->PrintMessage("DESIGN");
		break;

	case NEW_GAME:


		///TODO: Add a case for EACH Action type in the Design mode or Play mode

	case ADD_ANTENNA:
		// create an object of AddFlagAction here
		pAct = new AddAntennaAction(this);
		break;

	case ADD_WATER_PIT:
		// create an object of AddFlagAction here
		pAct = new AddWaterPitaction(this);
		break;

	case ADD_DANGER_ZONE:
		// create an object of AddFlagAction here
		pAct = new AddDangerZoneAction(this);
		break;

	case ADD_WORKSHOP:
		// create an object of AddFlagAction here
		pAct = new AddWorkshopAction(this);
		break;

	case SAVE_GRID:
		// create an object of AddFlagAction here
		pAct = new SaveGridAction(this);
		break;

	case OPEN_GRID:
		// create an object of AddFlagAction here
		pAct = new LoadGridAction(this);
		break;


	case DELETE_GAME_OBJECT:
		// create an object of AddFlagAction here
		pAct = new DeleteGameObject(this);
		break;



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
