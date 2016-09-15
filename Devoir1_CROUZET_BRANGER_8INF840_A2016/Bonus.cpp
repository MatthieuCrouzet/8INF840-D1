#include <cstdlib>
#include <iostream>
#include "Bonus.h"


Bonus::Bonus(int i)
{
	value = i;
}

int Bonus::getBonus() const
{
	return value;
}


