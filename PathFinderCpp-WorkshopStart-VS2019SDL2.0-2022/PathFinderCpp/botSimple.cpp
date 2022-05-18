#include "bots.h"

//initial botSimple algorithm -- bot cannot move around obstacles
void cBotSimple1::ChooseNextGridPosition()
{
	bool done = false;

	while (!done)
	{
		if (PositionX() < gTarget.PositionX())
		{
			done = SetNext(PositionX() + 1, PositionY(), gLevel);
		}
		else if (PositionX() > gTarget.PositionX())
		{
			done = SetNext(PositionX() - 1, PositionY(), gLevel);
		}
		else if (PositionY() < gTarget.PositionY())
		{
			done = SetNext(PositionX(), PositionY() + 1, gLevel);
		}
		else
		{
			done = SetNext(PositionX(), PositionY() - 1, gLevel);
		}
	}
}

//improved bot simple algorithm -- allows for bot to move around obstacles
void cBotSimple2::ChooseNextGridPosition()
{
	if (PositionX() < gTarget.PositionX())
	{
		if (SetNext(PositionX() + 1, PositionY(), gLevel) == 0)
		{
			SetNext(PositionX(), PositionY() + 1, gLevel);
		}
	}
	else if (PositionY() < gTarget.PositionY())
	{
		SetNext(PositionX(), PositionY() + 1, gLevel);
	}
	else if (PositionY() > gTarget.PositionY())
	{
		SetNext(PositionX(), PositionY() - 1, gLevel);
	}
}