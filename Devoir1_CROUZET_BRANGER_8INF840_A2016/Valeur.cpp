#include <cstdlib>
#include <iostream>
#include "Valeur.h"


Valeur::Valeur(int i)
{
	value = i;
}

int Valeur::getValeur() const
{
	return value;
}

