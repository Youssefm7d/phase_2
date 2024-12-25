#include "SelectedCommands.h"
#include "SelectedCommands.h"
#include "Grid.h"



SelectedCommands::SelectedCommands()
{
	ResetSelectedCommands();
	selectedCommandsCount = 0;
}


void SelectedCommands::AddCommand(Command selecComm/*, Player* pPlayer*/)
{

}


Command SelectedCommands::GetCommand(int index)
{
	return selectedCommands[index];
}

void SelectedCommands::ResetSelectedCommands(void)
{
	for (int i = 0; i < MaxSelectedCommands; i++)
		selectedCommands[i] = NO_COMMAND;
}


SelectedCommands::~SelectedCommands()
{
}