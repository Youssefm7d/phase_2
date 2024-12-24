#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class SelectCommandAction :public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	Command command; // 1- The position of the flag
public:

	SelectCommandAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 

	virtual void Execute(); // Creates a new flag Object 
	// then Sets this flag object to the GameObject Pointer of its Cell

	~SelectCommandAction();
};
