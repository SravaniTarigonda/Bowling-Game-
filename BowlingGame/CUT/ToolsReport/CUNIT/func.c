#include "header.h"

int strike_condition(int balls, int current_score)
{
	if(balls == 1 && current_score == 10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int spare_condition(int current_score, int previous_ball)
{
	if((current_score + previous_ball) == 10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int extra_balls(int balls)
{
	if(balls == 1)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}
