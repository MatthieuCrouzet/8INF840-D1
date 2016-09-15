#ifndef CARTE_H
#define CARTE_H

#include "Bonus.h"
#include "Valeur.h"
#include "Couleur.h"



class Carte
{
public:
	Carte();
	int getBonus() const;
	int getValeur() const;
	Couleur getCouleur() const;

private:
	Bonus* bonus;
	Valeur* valeur;
	Couleur couleur;
};

#endif
