// Devoir1_CROUZET_BRANGER_8INF840_A2016.cpp : Defines the entry point for the console application.
#include <cstdlib>
#include <iostream>

#include "Pile.h"
#include "Carte.h"
#include "Joueur.h"


using namespace std;

int entier_alea(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void remplir_pile(Pile<Carte> & p)
{
	for (int i = 0; i < 100;i++)
	{
		Carte c = Carte();
		p.empiler(c);
	}

}

void distribuer_joueurs(int nb_cartes, Pile<Carte> p,Joueur j1,Joueur j2)
{
	for (int i = 0; i < nb_cartes; i++)
	{
		Carte c = p.depiler();
		if(i%2==0)
		{
			j1.pile.empiler(c);
		}
		else
		{
			j2.pile.empiler(c);
		}
	}
}

void jouer_un_tour(Joueur j1, Joueur j2)
{
	Carte c1 = j1.pile.depiler();
	Carte c2 = j2.pile.depiler();

	if (c1.getValeur()<c2.getValeur())
	{
		j2.pileFinale.empiler(c1);
		j2.pileFinale.empiler(c2);
	}
	else if (c1.getValeur()>c2.getValeur())
	{
		j1.pileFinale.empiler(c1);
		j1.pileFinale.empiler(c2);
	}
	else
	{
		if (c1.getCouleur() == Couleur::ROUGE && c2.getCouleur() == Couleur::NOIR)
		{
			j1.pileFinale.empiler(c1);
			j1.pileFinale.empiler(c2);
		}
		else if (c2.getCouleur() == Couleur::ROUGE && c1.getCouleur() == Couleur::ROUGE)
		{
			j2.pileFinale.empiler(c1);
			j2.pileFinale.empiler(c2);
		}
		else
		{
			j1.pileFinale.empiler(c1);
			j2.pileFinale.empiler(c2);
		}
	}
}

float compter_points (Joueur j)
{
	float compte = 0.;
	while(!j.pileFinale.estVide())
	{
		Carte c = j.pileFinale.depiler();
		if(c.getCouleur() == Couleur::ROUGE)
		{
			compte += 1.5*c.getBonus() * c.getValeur();
		}
		else
		{
			compte += c.getBonus()* c.getValeur();
		}
	}
	return compte;
}

void afficher_score(Joueur j1, Joueur j2)
{
	float score1, score2;
	score1 = compter_points(j1);
	score2 = compter_points(j2);
	cout << "R�sultats de la partie : " << endl;
	cout << "Joueur 1 : " << score1 << endl;
	cout << "Joueur 2 : " << score1 << endl;
	if(score1<score2)
	{
		cout << "Le joueur 1 a gagn� " << endl;
	}
	else if (score1>score2)
	{
		cout << "Le joueur 2 a gagn� " << endl;
	}
	else
	{
		cout << "Egalit�" << endl;
	}
}

int main(void)
{

	//Cr�ation de la pile de 100 �l�ments
	Pile<Carte> pioche();
	remplir_pile(pioche);
	//Cr�ation des joueurs
	Joueur j1();
	Joueur j2();

	//Distribution des cartes tour � tour
	distribuer_joueurs(50, pioche, j1, j2);

	//Boucle de jeu
	while(!j1.pile.estVide() && !j1.pile.estVide())
	{
		jouer_un_tour(j1,j2);
	}

	//Affichage du score
	afficher_score(j1, j2);

    return 0;
}



