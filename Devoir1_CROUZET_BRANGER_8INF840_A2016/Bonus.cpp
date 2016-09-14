#include <cstdlib>

#include "Bonus.h"


Bonus::Bonus(int i)
{
	value = i;
}

int Bonus::getBonus() const
{
	return value;
}


