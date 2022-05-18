#include "bots.h"

void cDijkstra::Build(cBotBase& bot)
{
	for (int i = 0; i < GRIDWIDTH; i++)
	{
		for (int j = 0; j < GRIDHEIGHT; j++)
		{
			//Initialising the data arrays.
			closed[i][j] = false; //closed is set to open
			cost[i][j] = 1000000.0f; //cost set to large number
			linkX[i][j] = -1;
			linkY[i][j] = -1;
			inPath[i][j] = false;
		}
	}

	cost[bot.PositionX()][bot.PositionY()] = 0; //bot position set to 0

	int lowestCostXPos;
	int lowestCostYPos;
	float lowestCostTile;


	while (!closed[gTarget.PositionX()][gTarget.PositionY()])
	{
		lowestCostTile = 1000000.0f;

		/*Finds the current lowest cost tile in the grid*/
		for (int i = 0; i < GRIDWIDTH; i++)
		{
			for (int j = 0; j < GRIDHEIGHT; j++)
			{
				if (!closed[i][j] && gLevel.isValid(i, j))
				{
					if (cost[i][j] < lowestCostTile)
					{
						lowestCostXPos = i;
						lowestCostYPos = j;
						lowestCostTile = cost[i][j];
					}
				}
			}
		}

		/*Up Direction*/
		if (gLevel.isValid(lowestCostXPos, lowestCostYPos - 1) && !closed[lowestCostXPos][lowestCostYPos - 1])
		{
			if (cost[lowestCostXPos][lowestCostYPos - 1] > cost[lowestCostXPos][lowestCostYPos] + 1)
			{
				cost[lowestCostXPos][lowestCostYPos - 1] = cost[lowestCostXPos][lowestCostYPos] + 1;
				linkX[lowestCostXPos][lowestCostYPos - 1] = lowestCostXPos;
				linkY[lowestCostXPos][lowestCostYPos - 1] = lowestCostYPos;
			}
		}

		/*Down Direction*/
		if (gLevel.isValid(lowestCostXPos, lowestCostYPos + 1) && !closed[lowestCostXPos][lowestCostYPos + 1])
		{
			if (cost[lowestCostXPos][lowestCostYPos + 1] > cost[lowestCostXPos][lowestCostYPos] + 1)
			{
				cost[lowestCostXPos][lowestCostYPos + 1] = cost[lowestCostXPos][lowestCostYPos] + 1;
				linkX[lowestCostXPos][lowestCostYPos + 1] = lowestCostXPos;
				linkY[lowestCostXPos][lowestCostYPos + 1] = lowestCostYPos;
			}
		}

		/*Left Direction*/
		if (gLevel.isValid(lowestCostXPos - 1, lowestCostYPos) && !closed[lowestCostXPos - 1][lowestCostYPos])
		{
			if (cost[lowestCostXPos - 1][lowestCostYPos] > cost[lowestCostXPos][lowestCostYPos] + 1)
			{
				cost[lowestCostXPos - 1][lowestCostYPos] = cost[lowestCostXPos][lowestCostYPos] + 1;
				linkX[lowestCostXPos - 1][lowestCostYPos] = lowestCostXPos;
				linkY[lowestCostXPos - 1][lowestCostYPos] = lowestCostYPos;
			}
		}

		/*Right Direction*/
		if (gLevel.isValid(lowestCostXPos + 1, lowestCostYPos) && !closed[lowestCostXPos + 1][lowestCostYPos])
		{
			if (cost[lowestCostXPos + 1][lowestCostYPos] > cost[lowestCostXPos][lowestCostYPos] + 1)
			{
				cost[lowestCostXPos + 1][lowestCostYPos] = cost[lowestCostXPos][lowestCostYPos] + 1;
				linkX[lowestCostXPos + 1][lowestCostYPos] = lowestCostXPos;
				linkY[lowestCostXPos + 1][lowestCostYPos] = lowestCostYPos;
			}

		}

		/*Upper Right Direction*/
		if (gLevel.isValid(lowestCostXPos + 1, lowestCostYPos - 1) && !closed[lowestCostXPos + 1][lowestCostYPos - 1])
		{
			if (cost[lowestCostXPos + 1][lowestCostYPos - 1] > cost[lowestCostXPos][lowestCostYPos] + 1.4f)
			{
				cost[lowestCostXPos + 1][lowestCostYPos - 1] = cost[lowestCostXPos][lowestCostYPos] + 1.4f;
				linkX[lowestCostXPos + 1][lowestCostYPos - 1] = lowestCostXPos;
				linkY[lowestCostXPos + 1][lowestCostYPos - 1] = lowestCostYPos;
			}
		}

		/*Upper Left Direction*/
		if (gLevel.isValid(lowestCostXPos - 1, lowestCostYPos - 1) && !closed[lowestCostXPos - 1][lowestCostYPos - 1])
		{
			if (cost[lowestCostXPos - 1][lowestCostYPos - 1] > cost[lowestCostXPos][lowestCostYPos] + 1.4f)
			{
				cost[lowestCostXPos - 1][lowestCostYPos - 1] = cost[lowestCostXPos][lowestCostYPos] + 1.4f;
				linkX[lowestCostXPos - 1][lowestCostYPos - 1] = lowestCostXPos;
				linkY[lowestCostXPos - 1][lowestCostYPos - 1] = lowestCostYPos;
			}
		}

		/*Lower Right Direction*/
		if (gLevel.isValid(lowestCostXPos + 1, lowestCostYPos + 1) && !closed[lowestCostXPos + 1][lowestCostYPos + 1])
		{
			if (cost[lowestCostXPos + 1][lowestCostYPos + 1] > cost[lowestCostXPos][lowestCostYPos] + 1.4f)
			{
				cost[lowestCostXPos + 1][lowestCostYPos + 1] = cost[lowestCostXPos][lowestCostYPos] + 1.4f;
				linkX[lowestCostXPos + 1][lowestCostYPos + 1] = lowestCostXPos;
				linkY[lowestCostXPos + 1][lowestCostYPos + 1] = lowestCostYPos;
			}
		}

		/*Lower Left Direction*/
		if (gLevel.isValid(lowestCostXPos - 1, lowestCostYPos + 1) && !closed[lowestCostXPos - 1][lowestCostYPos + 1])
		{
			if (cost[lowestCostXPos - 1][lowestCostYPos + 1] > cost[lowestCostXPos][lowestCostYPos] + 1.4f)
			{
				cost[lowestCostXPos - 1][lowestCostYPos + 1] = cost[lowestCostXPos][lowestCostYPos] + 1.4f;
				linkX[lowestCostXPos - 1][lowestCostYPos + 1] = lowestCostXPos;
				linkY[lowestCostXPos - 1][lowestCostYPos + 1] = lowestCostYPos;
			}
		}

		//Set the current lowest cost grid as closed or 'visited'
		closed[lowestCostXPos][lowestCostYPos] = true;
	}

	bool finished = false; //set to true when we are back at the bot position
	int nextClosedXPos = gTarget.PositionX(); //start of path
	int nextClosedYPos = gTarget.PositionY(); //start of path
	while (!finished)
	{
		inPath[nextClosedXPos][nextClosedYPos] = true;
		int tempX = nextClosedXPos;
		int tempY = nextClosedYPos;
		nextClosedXPos = linkX[tempX][tempY];
		nextClosedYPos = linkY[tempX][tempY];
		if ((nextClosedXPos == bot.PositionX()) && (nextClosedYPos == bot.PositionY()))
			finished = true;
	}

	//Dijkstra's Algorithm is complete
	completed = true;
}

cDijkstra gDijkstra;

void cAstar::Build(cBotBase& bot)
{
	//int playerPosX = gTarget.PositionX();
	//int playerPosY = gTarget.PositionY();
	//int pathCoordinates[playerPosX, playerPosY;];

	for (int i = 0; i < GRIDWIDTH; i++)
	{
		
		for (int j = 0; j < GRIDHEIGHT; j++)
		{
			//Initialises data arrays for nodes, costs, Links and paths
			closed[i][j] = false; //closed is set to open
			cost[i][j] = 1000000.0f; //cost set to large number
			linkX[i][j] = -1;
			linkY[i][j] = -1;
			inPath[i][j] = false;
		}
	}

	cost[bot.PositionX()][bot.PositionY()] = 0; //bot position set to 0

	int lowestCostXPos;
	int lowestCostYPos;
	float lowestCostTile;


	while (!closed[gTarget.PositionX()][gTarget.PositionY()])
	{
		lowestCostTile = 1000000.0f;

		/*Finds the current lowest cost tile in the grid*/
		for (int i = 0; i < GRIDWIDTH; i++)
		{
			for (int j = 0; j < GRIDHEIGHT; j++)
			{
				float heuristic = fabs(gTarget.PositionX() - i) + fabs(gTarget.PositionY() - j);
				if (!closed[i][j] && gLevel.isValid(i, j))
				{
					if (cost[i][j] + heuristic < lowestCostTile)
					{
						lowestCostXPos = i;
						lowestCostYPos = j;
						lowestCostTile = cost[i][j];
					}
				}
			}
		}

		/*Up Direction*/
		if (gLevel.isValid(lowestCostXPos, lowestCostYPos - 1) && !closed[lowestCostXPos][lowestCostYPos - 1])
		{
			if (cost[lowestCostXPos][lowestCostYPos - 1] > cost[lowestCostXPos][lowestCostYPos] + 1)
			{
				cost[lowestCostXPos][lowestCostYPos - 1] = cost[lowestCostXPos][lowestCostYPos] + 1;
				linkX[lowestCostXPos][lowestCostYPos - 1] = lowestCostXPos;
				linkY[lowestCostXPos][lowestCostYPos - 1] = lowestCostYPos;
			}
		}

		/*Down Direction*/
		if (gLevel.isValid(lowestCostXPos, lowestCostYPos + 1) && !closed[lowestCostXPos][lowestCostYPos + 1])
		{
			if (cost[lowestCostXPos][lowestCostYPos + 1] > cost[lowestCostXPos][lowestCostYPos] + 1)
			{
				cost[lowestCostXPos][lowestCostYPos + 1] = cost[lowestCostXPos][lowestCostYPos] + 1;
				linkX[lowestCostXPos][lowestCostYPos + 1] = lowestCostXPos;
				linkY[lowestCostXPos][lowestCostYPos + 1] = lowestCostYPos;
			}
		}

		/*Left Direction*/
		if (gLevel.isValid(lowestCostXPos - 1, lowestCostYPos) && !closed[lowestCostXPos - 1][lowestCostYPos])
		{
			if (cost[lowestCostXPos - 1][lowestCostYPos] > cost[lowestCostXPos][lowestCostYPos] + 1)
			{
				cost[lowestCostXPos - 1][lowestCostYPos] = cost[lowestCostXPos][lowestCostYPos] + 1;
				linkX[lowestCostXPos - 1][lowestCostYPos] = lowestCostXPos;
				linkY[lowestCostXPos - 1][lowestCostYPos] = lowestCostYPos;
			}
		}

		/*Right Direction*/
		if (gLevel.isValid(lowestCostXPos + 1, lowestCostYPos) && !closed[lowestCostXPos + 1][lowestCostYPos])
		{
			if (cost[lowestCostXPos + 1][lowestCostYPos] > cost[lowestCostXPos][lowestCostYPos] + 1)
			{
				cost[lowestCostXPos + 1][lowestCostYPos] = cost[lowestCostXPos][lowestCostYPos] + 1;
				linkX[lowestCostXPos + 1][lowestCostYPos] = lowestCostXPos;
				linkY[lowestCostXPos + 1][lowestCostYPos] = lowestCostYPos;
			}

		}

		

		/*Upper Right Direction*/
		if (gLevel.isValid(lowestCostXPos + 1, lowestCostYPos - 1) && !closed[lowestCostXPos + 1][lowestCostYPos - 1])
		{
			if (cost[lowestCostXPos + 1][lowestCostYPos - 1] > cost[lowestCostXPos][lowestCostYPos] + 1.4f)
			{
				cost[lowestCostXPos + 1][lowestCostYPos - 1] = cost[lowestCostXPos][lowestCostYPos] + 1.4f;
				linkX[lowestCostXPos + 1][lowestCostYPos - 1] = lowestCostXPos;
				linkY[lowestCostXPos + 1][lowestCostYPos - 1] = lowestCostYPos;
			}
		}

		/*Upper Left Direction*/
		if (gLevel.isValid(lowestCostXPos - 1, lowestCostYPos - 1) && !closed[lowestCostXPos - 1][lowestCostYPos - 1])
		{
			if (cost[lowestCostXPos - 1][lowestCostYPos - 1] > cost[lowestCostXPos][lowestCostYPos] + 1.4f)
			{
				cost[lowestCostXPos - 1][lowestCostYPos - 1] = cost[lowestCostXPos][lowestCostYPos] + 1.4f;
				linkX[lowestCostXPos - 1][lowestCostYPos - 1] = lowestCostXPos;
				linkY[lowestCostXPos - 1][lowestCostYPos - 1] = lowestCostYPos;
			}
		}

		/*Lower Right Direction*/
		if (gLevel.isValid(lowestCostXPos + 1, lowestCostYPos + 1) && !closed[lowestCostXPos + 1][lowestCostYPos + 1])
		{
			if (cost[lowestCostXPos + 1][lowestCostYPos + 1] > cost[lowestCostXPos][lowestCostYPos] + 1.4f)
			{
				cost[lowestCostXPos + 1][lowestCostYPos + 1] = cost[lowestCostXPos][lowestCostYPos] + 1.4f;
				linkX[lowestCostXPos + 1][lowestCostYPos + 1] = lowestCostXPos;
				linkY[lowestCostXPos + 1][lowestCostYPos + 1] = lowestCostYPos;
			}
		}

		/*Lower Left Direction*/
		if (gLevel.isValid(lowestCostXPos - 1, lowestCostYPos + 1) && !closed[lowestCostXPos - 1][lowestCostYPos + 1])
		{
			if (cost[lowestCostXPos - 1][lowestCostYPos + 1] > cost[lowestCostXPos][lowestCostYPos] + 1.4f)
			{
				cost[lowestCostXPos - 1][lowestCostYPos + 1] = cost[lowestCostXPos][lowestCostYPos] + 1.4f;
				linkX[lowestCostXPos - 1][lowestCostYPos + 1] = lowestCostXPos;
				linkY[lowestCostXPos - 1][lowestCostYPos + 1] = lowestCostYPos;
			}
		}

		//Set the current lowest cost grid as closed or 'visited'
		closed[lowestCostXPos][lowestCostYPos] = true;
	}

	bool finished = false; //set to true when back at bot position
	int nextClosedXPos = gTarget.PositionX(); //start of path X position
	int nextClosedYPos = gTarget.PositionY(); //start of path Y position
	while (!finished)
	{
		inPath[nextClosedXPos][nextClosedYPos] = true;
		int tempX = nextClosedXPos;
		int tempY = nextClosedYPos;
		nextClosedXPos = linkX[tempX][tempY];
		nextClosedYPos = linkY[tempX][tempY];
		if ((nextClosedXPos == bot.PositionX()) && (nextClosedYPos == bot.PositionY()))
			finished = true;
	}

	//A* algorithm is complete
	completed = true;
}
cAstar gAstar;