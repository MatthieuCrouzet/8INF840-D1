
#include "Joueur.h"
#include "Carte.h"


Joueur::Joueur()
{
	gain = Pile<Carte>();
	enMain = Pile<Carte>();
}


Joueur::~Joueur()
{

}

Pile<Carte> Joueur::getEnMain() const
{
	return enMain;
}

Pile<Carte> Joueur::getGain() const
{
	return gain;
}
