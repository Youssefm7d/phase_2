#pragma once
#include "Action.h"

class CopyGameObject : public Action {
public:
    CopyGameObject(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~CopyGameObject();
};
