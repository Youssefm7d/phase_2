#pragma once
#include "GameObject.h"
#include <fstream>

class WaterPit:public GameObject
{
public:
	WaterPit(const CellPosition & waterPitPosition); // A constructor for initialization
	virtual Objectschoise GetType() const;
	virtual void Draw(Output* pOut) const; // Draws a water pit in the cell
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the waterPit by killing the robot instantly and ending the game
	virtual void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& Infile) override;
	virtual ~WaterPit();
};

