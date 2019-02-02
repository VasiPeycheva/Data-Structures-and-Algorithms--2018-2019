#include <iostream>

const int MAX_SIZE = 10;
const int MAZE_SIZE = 8;
// 0 -> Free position
// 1 -> There is fence
// 2 -> Path which the algorihm chose
// 3 -> End / Princess
int maze[MAX_SIZE][MAX_SIZE] =
	{   { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };


bool IsValidPosition(unsigned int x, unsigned int y)
{
	return	x >= 0 && x < MAZE_SIZE &&
			y >= 0 && y < MAZE_SIZE &&
			maze[y][x] < 1; // Everything above zero is unvalid 
}

void PrintMaze() 
{
	for (int i = 0; i < MAZE_SIZE; i++)
	{
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			std::cout << maze[i][j] <<' ';
		}
		std::cout << '\n';
	}
}

bool FindPathWrapper(unsigned int FinishX, unsigned int FinishY, unsigned int CurrentX, unsigned int CurrentY)
{
	if(!IsValidPosition(CurrentX, CurrentY))
	{
		return false;
	}

	
	if (FinishX == CurrentX && FinishY == CurrentY)
	{
		maze[FinishY][FinishX] = 3;
		return true;
	}

	maze[CurrentY][CurrentX] = 2;
	if (FindPathWrapper(FinishX, FinishY, CurrentX, CurrentY + 1))
	{
		return true;
	}

	if (FindPathWrapper(FinishX, FinishY, CurrentX + 1, CurrentY))
	{
		return true;
	}

	if (FindPathWrapper(FinishX, FinishY, CurrentX, CurrentY - 1))
	{
		return true;
	}

	if (FindPathWrapper(FinishX, FinishY, CurrentX - 1, CurrentY))
	{
		return true;
	}

	maze[CurrentY][CurrentX] = 0;
	return false;

}

bool FindPath(unsigned int FinishX, unsigned int FinishY, unsigned int StartX = 0, unsigned int StartY = 0, bool Print = true)
{	
	if (!IsValidPosition(StartX, StartY) || !IsValidPosition(FinishX, FinishY))
	{
		std::cout << "Positions must be valid!\n";
	}
	
	if (FindPathWrapper(FinishX, FinishY, StartX, StartY))
	{
		std::cout << "Hey, there is a path to the princess! Now you can save her... :)\n";
		if (Print)
		{
			PrintMaze();
		}
		return true;
	}

	std::cout << "Sorry boy, you are in a trap... You can't save the princess... :(\n";

}

int main()
{
	FindPath(6, 0);
	return 0;
}