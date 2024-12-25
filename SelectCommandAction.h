#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class SelectCommandAction :public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	Command selectedCommand; //The selected command
	Player* pPlayer; //pointer to the current player choosing the action
public:

	SelectCommandAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 

	virtual void Execute();

	~SelectCommandAction();
};
