#pragma once
#include "GameObject.h"
#include <fstream>
class Workshop :
	public GameObject
{
public:
	Workshop(const CellPosition & workshopPosition);
	virtual Objectschoise GetType() const;
	virtual void Draw(Output* pOut) const; // Draws workshop
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the workshop
	virtual void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& Infile) override;
	~Workshop();
};

