#include <cstdlib>
#include <iostream>
#include "Bonus.h"


Bonus::Bonus(int i)
{
	value = i;
}

Bonus::Bonus()
{
	value = -1;
}

int Bonus::getBonus() const
{
	return value;
}


