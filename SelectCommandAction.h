#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class SelectCommandAction :public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	Command selectedCommand; //The selected command
public:

	SelectCommandAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 

	virtual void Execute();

	~SelectCommandAction();
};
