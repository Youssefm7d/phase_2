#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class UseToolKitAction :public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	Player* pRepairingPlayer; //pointer to the current player choosing the action
public:

	UseToolKitAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 

	virtual void Execute();

	~UseToolKitAction();
};
