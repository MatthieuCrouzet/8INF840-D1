#include <cstdlib>
#include <iostream>
#include "Valeur.h"


Valeur::Valeur(int i)
{
	value = i;
}

Valeur::Valeur()
{
	value = -1;
}

int Valeur::getValeur() const
{
	return value;
}

