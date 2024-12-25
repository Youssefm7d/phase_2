#pragma once
#include "DEFS.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"

class AvailableCommands
{
	// Always add action parameters as private data members

	int availableCommandsCount;
	Command availableCommands[MaxAvailableCommands]; // 1- The position of the flag
public:

	AvailableCommands();
	void AddCommand(Command avaComm);

	void DrawAvailableCommands(Output* pOut);


	~AvailableCommands();
};
