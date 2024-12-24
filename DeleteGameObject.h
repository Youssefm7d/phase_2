#pragma once
#include "Action.h"
#include "Grid.h"
#include "Output.h"
#include "GameObject.h"
#include "CellPosition.h"
#include "Input.h"

class DeleteGameObject : public Action
{
    CellPosition targetPosition; // The position of the object to delete
    bool DeleteActive;
public:
    DeleteGameObject(ApplicationManager* pApp); // Constructor
    virtual void ReadActionParameters();       // Reads cell position
    virtual void Execute();                    // Executes delete logic
    virtual ~DeleteGameObject();               // Destructor
};