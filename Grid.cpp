#include "Grid.h"
#include <fstream>
#include "Cell.h"
#include "GameObject.h"
#include "Player.h"
#include "Flag.h"
#include "Belt.h"
#include "DangerZone.h"
#include "Antenna.h"
#include "RotatingGear.h"
#include "WaterPit.h"
#include "Workshop.h"


Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.GetCellNum() == 1 || pos.GetCellNum() == 55) {
		return false;
	}

	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			
			return false; // do NOT add and return false
		
		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

GameObject* Grid::Get_object_pos(const CellPosition& pos) const
{
	if (pos.IsValidCell()) // Check if the position is valid
	{
		// Retrieve the GameObject pointer from the specified cell
		return CellList[pos.VCell()][pos.HCell()]->GetGameObject();
	}
	return NULL; // Return NULL if the position is invalid
}

// Note: You may need to change the return type of this function (Think)
void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's triangle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's triangle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(GameObject * gameObject) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = gameObject;
}

GameObject * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

Player* Grid::Get_player_pos(const CellPosition& pos) const
{
	CellPosition playerPos;
	for (int i = 0; i < MaxPlayerCount; i++) {
		playerPos = PlayerList[i]->GetCell()->GetCellPosition();
		if ((pos.HCell() == playerPos.HCell()) && (pos.VCell() == playerPos.VCell())) // Check if the position is valid
		{
			return PlayerList[i];
		}
	}
	return NULL; // Return NULL if the position is invalid
}


// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Belt * Grid::GetNextBelt(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the belt in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a belt, if yes return it
			

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}




// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without waterpits or dangerzone 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrWaterPitOrDangerZone(pOut);
			}
		}

		// 2- Draw other game objects(excluding waterpit and dangerzone)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawGameObject(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cgame objects do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::SaveAll(std::ofstream& OutFile, Objectschoise Type)
{
	int count = 0;
	// Count objects of the specified type
	for (int i = 0; i < NumVerticalCells; ++i)
	{
		for (int j = 0; j < NumHorizontalCells; ++j)
		{
			GameObject* pGameObject = CellList[i][j]->GetGameObject();
			if (pGameObject && pGameObject->GetType() == Type)
			{
				count++;
			}
		}
	}

	// Write the count to the file
	OutFile << count << std::endl;

	for (int i = 0; i < NumVerticalCells; ++i)
	{
		for (int j = 0; j < NumHorizontalCells; ++j)
		{
			GameObject* pGameObject = CellList[i][j]->GetGameObject();
			if (pGameObject && pGameObject->GetType() == Type)
			{
				pGameObject->Save(OutFile); 
			}
		}
	}
}


void Grid::LoadAll(std::ifstream& InFile, Objectschoise Type) {
	int count;
	InFile >> count; // Read the number of objects of this type

	for (int i = 0; i < count; ++i)
	{
		GameObject* pGameObject = nullptr;

		// Create an object of the correct type
		switch (Type)
		{
		case flag:
			pGameObject = new Flag(CellPosition());
			break;
		case water_pit:
			pGameObject = new WaterPit(CellPosition());
			break;
		case danger_zone:
			pGameObject = new DangerZone(CellPosition());
			break;
		case belt:
			pGameObject = new Belt(CellPosition(), CellPosition());
			break;
		case workshop:
			pGameObject = new Workshop(CellPosition());
			break;
		case antenna:
			pGameObject = new Antenna(CellPosition());
			break;
		case rotating_gear:
			pGameObject = new RotatingGear(CellPosition(),0);
			break;
		}

		if (pGameObject)
		{
			// Load the object's data from the file
			pGameObject->Load(InFile);
			AddObjectToCell(pGameObject);
		}
	}
}

Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}