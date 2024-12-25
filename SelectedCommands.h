#pragma once
#include "DEFS.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"

class SelectedCommands
{
	// Always add action parameters as private data members

	int selectedCommandsCount;
	Command selectedCommands[MaxSelectedCommands]; // 1- The position of the flag
public:

	SelectedCommands();

	void AddCommand(Command selecComm/*, Player* pPlayer*/);

	Command GetCommand(int index);

	void ResetSelectedCommands(void);


	~SelectedCommands();
};
