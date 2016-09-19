
#include "Joueur.h"
#include "Carte.h"


Joueur::Joueur()
{
	gain = new Pile<Carte>();
	enMain = new Pile<Carte>();
}


Joueur::~Joueur()
{

}

Pile<Carte>* Joueur::getEnMain() const
{
	return enMain;
}

Pile<Carte>* Joueur::getGain() const
{
	return gain;
}
