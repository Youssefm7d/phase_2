#include "Player.h"
#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT)
{
	this->pCell = pCell;

	// Make all the needed initialization or validations
	ownedToolKits= 0;
	ownedHackDevices= 0;
	doubleLaser= false;
	roundFinishedOrHacked= false;
}


// ====== Updating Methods ======

void Player::BuyToolKit(void)
{
	ownedToolKits++;
}
bool Player::UseToolKit(void)
{
	if (ownedToolKits > 0) {
		ownedToolKits--;
		return true;
	}
	else
		return false;
}

void Player::BuyHackDevice(void)
{
	ownedHackDevices++;
}
bool Player::UseHackDevice(void)
{
	if (ownedHackDevices > 0) {
		ownedHackDevices--;
		return true;
	}
	else
		return false;
}

bool Player::BuyDoubleLaser(void)
{
	if (!doubleLaser) {
		doubleLaser = true;
		return true;
	}
	else
		return false;
}

void Player::FinishPlayingRound(void)
{
	roundFinishedOrHacked = true;
}
void Player::ResetRound(void)
{
	roundFinishedOrHacked = false;
}


// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetHealth(int h)
{
	if (h > 0 && h < 10)
		this->health = h;
	///TODO: Do any needed validations
}

int Player::GetHealth()
{
	return this->health;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor, currDirection);
	//DONE
}

void Player::ClearDrawing(Output* pOut) const
{
	///TODO: Modify the cellColor to draw the correct cellColor (hint: if cell contains non-default cellColor)
	color cellColor = UI.CellColor;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawCell(pCell->GetCellPosition(), cellColor);
	//DONE
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid/*, Command moveCommands[]*/)
{
	int x, y;
	///TODO: Implement this function using the guidelines mentioned below
	CellPosition newPos= pCell->GetCellPosition();
	for (int i = 0; (i < 5 && moveCommands.GetCommand(i) != NO_COMMAND); i++) {
		switch (moveCommands.GetCommand(i))
		{
		case MOVE_FORWARD_ONE_STEP:
			newPos.AddCellNum(1, currDirection);
			break;
		case MOVE_FORWARD_TWO_STEPS:
			newPos.AddCellNum(2, currDirection);
			break;
		case MOVE_FORWARD_THREE_STEPS:
			newPos.AddCellNum(3, currDirection);
			break;
		case MOVE_BACKWARD_ONE_STEP:
			newPos.AddCellNum(-1, currDirection);
			break;
		case MOVE_BACKWARD_TWO_STEPS:
			newPos.AddCellNum(-2, currDirection);
			break;
		case MOVE_BACKWARD_THREE_STEPS:
			newPos.AddCellNum(-3, currDirection);
			break;
		case ROTATE_CLOCKWISE:
			currDirection= (Direction)((currDirection < LEFT) ? currDirection + 1 : 0); 
			break;
		case ROTATE_COUNTERCLOCKWISE:
			currDirection = (Direction)((currDirection > UP) ? currDirection - 1 : 3);
			break;
		}

		pGrid->UpdatePlayerCell(this, newPos);

		pGrid->GetOutput()->PrintMessage("Click anywhere to execute the next command");
		pGrid->GetInput()->GetPointClicked(x, y);
	}

	pCell->GetGameObject()->Apply(pGrid, this);
	// - If a player has 5 (could have less) saved moveCommands, the robot will execute the first saved command,
	//		then wait for a mouse click (display a message "Click anywhere to execute the next command").
	//		After executing all the 5 saved commands, the game object effect at the final destination cell will
	//		be applied.
	// 
	// - Use the CellPosition class to help you calculate the destination cell using the current cell
	// - Use the Grid class to update pCell
	// - Don't forget to apply game objects at the final destination cell and check for game ending

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "Player " + to_string(playerNum) + " (" ;
	playersInfo += "Direction: " + to_string(currDirection) + ", ";
	playersInfo += "Health: " + to_string(health) + ")";

}