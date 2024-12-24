#pragma once
#include "Input.h"
#include "Output.h"
#include <fstream>
#include "ApplicationManager.h"
#include "Action.h"
#include "Grid.h"

class LoadGridAction :public Action
{
    string filename;

public: 
    LoadGridAction(ApplicationManager* pApp); // Constructor
    virtual void ReadActionParameters();       
    virtual void Execute();                    
    virtual ~LoadGridAction();               // Destructor

};

