#pragma once
#include "Input.h"
#include "Output.h"
#include <fstream>
#include "Action.h"
#include "Grid.h"
class SaveGridAction :public Action
{
    string filename;

public:
    SaveGridAction(ApplicationManager* pApp); // Constructor
    virtual void ReadActionParameters();       // Reads cell position
    virtual void Execute();                    // Executes delete logic
    virtual ~SaveGridAction();               // Destructor


};

