#pragma once
#include "DEFS.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"

class AvailableCommands
{
	// Always add action parameters as private data members

	int availableCommandsCount;
	Command availableCommands[MaxAvailableCommands];
public:

	AvailableCommands();
	void AddCommand(Command avaComm);

	void DrawAvailableCommfands(Output* pOut);

	Command GetCommand(int index);


	~AvailableCommands();
};
