#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"

class PasteAction : public Action {
    CellPosition targetPos; // Position where the object will be pasted
public:
    PasteAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();
    virtual void Execute();

    virtual ~PasteAction();
};