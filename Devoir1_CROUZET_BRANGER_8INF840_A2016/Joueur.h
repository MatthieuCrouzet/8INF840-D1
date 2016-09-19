#ifndef JOUEUR_H
#define JOUEUR_H
#include "Carte.h"
#include "Pile.h"

class Joueur
{
private:
	Pile<Carte>* enMain;
	Pile<Carte>* gain;
public:
	Pile<Carte>* getEnMain() const;
	Pile<Carte>* getGain() const;

	Joueur();
	~Joueur();
};
#endif

