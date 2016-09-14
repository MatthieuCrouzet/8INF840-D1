#ifndef CARTE_H
#define CARTE_H

#include "Bonus.h"
#include "Valeur.h"
#include "Couleur.h"



class Carte
{
public:
	Carte();
	int getBonus();
	int getValeur();
	Couleur getCouleur();

private:
	Bonus* bonus;
	Valeur* valeur;
	Couleur couleur;
};

#endif
