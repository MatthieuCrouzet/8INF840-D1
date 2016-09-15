#include "Carte.h"
#include <cstdlib>

int entier_alea(int min, int max);

Carte::Carte()
{
	bonus = new Bonus(entier_alea(1,4));
	valeur = new Valeur(entier_alea(1,10));
	couleur = static_cast<Couleur>( entier_alea(0,1));
}

int Carte::getBonus() const
{
	return bonus->getBonus();
}

int Carte::getValeur() const
{
	return valeur->getValeur();
}

Couleur Carte::getCouleur() const
{
	return (couleur);
}


int entier_alea(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
