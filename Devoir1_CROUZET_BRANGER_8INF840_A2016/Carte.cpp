#include <cstdlib>
#include <iostream>
#include "Carte.h"
#include "Bonus.h"

using namespace std;

int entier_alea(int min, int max);

Carte::Carte()
{
	bonus = Bonus(entier_alea(1, 4));
	valeur = Valeur(entier_alea(1, 10));
	couleur = static_cast<Couleur>(entier_alea(0, 1));
}

int Carte::getBonus() const
{
	return bonus.getBonus();
}

int Carte::getValeur() const
{
	return valeur.getValeur();
}

Couleur Carte::getCouleur() const
{
	return (couleur);
}


int entier_alea(int min, int max)
{
	return rand() % (max - min + 1) + min;
}


ostream& operator<<(ostream &flux, Carte const& c)
{
	flux << "----------------" << endl;	
	for (int i = 0; i < 3; i++) {
		flux << "|              |" << endl;
	}
	flux << "| " << c.getValeur() << "  (" << c.getBonus() << "-";
	if (c.getCouleur() == Couleur::NOIR) {
		flux << "NOIR) ";
	}
	else {
		flux << "ROUGE)";
	}
	flux << " |" << endl;
	for (int i = 0; i < 3; i++) {
		flux << "|              |" << endl;
	}
	flux << "----------------" << endl;
	return flux;
}

