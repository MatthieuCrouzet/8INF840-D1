#include "Carte.h"


Carte::Carte()
{
	bonus = new Bonus(entier_alea(1,4));
	valeur = new Valeur(entier_alea(1,10));
	couleur = entier_alea(0,1);
}

int Carte::getBonus()
{
	return bonus->getBonus();
}

int Carte::getValeur()
{
	return valeur->getValeur();
}

Couleur Carte::getCouleur()
{
	return (*couleur);
}


int entier_alea(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
