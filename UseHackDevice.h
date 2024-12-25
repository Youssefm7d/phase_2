#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class UseHackDevice :public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	Player* pHackedPlayer; //pointer to the current player choosing the action
public:

	UseHackDevice(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 

	virtual void Execute();

	~UseHackDevice();
};
