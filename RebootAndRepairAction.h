#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class RebootAndRepairAction :public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	Player* pPlayer; //pointer to the current player choosing the action
public:

	RebootAndRepairAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 

	virtual void Execute();

	~RebootAndRepairAction();
};
