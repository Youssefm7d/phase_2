#include "Workshop.h"



Workshop::Workshop(const CellPosition & workshopPosition):GameObject( workshopPosition)
{

}
Objectschoise Workshop::GetType() const{
	return workshop;
}

void Workshop::Draw(Output * pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid * pGrid, Player * pPlayer)
{
}


void Workshop::Save(ofstream& OutFile) {
	OutFile << position.GetCellNum() << endl;

}
void Workshop::Load(ifstream& Infile) {
	int cellNum, range;
	Infile >> cellNum >> range;
}

Workshop::~Workshop()
{
}
