// Devoir1_CROUZET_BRANGER_8INF840_A2016.cpp : Defines the entry point for the console application.
#include <cstdlib>
#include <iostream>

#include "Pile.h"
#include "Carte.h"
#include "Joueur.h"
#include <ctime>


using namespace std;


void remplir_pile(Pile<Carte> & p)
{
	for (int i = 0; i < 100;i++)
	{
		Carte c = Carte();
		p.empiler(c);
	}
}

void distribuer_joueurs(int nb_cartes, Pile<Carte> p, Joueur* j1, Joueur* j2)
{
	for (int i = 0; i < nb_cartes*2; i++)
	{
		try
		{
			Carte c = p.depiler();
			if (i % 2 == 0)
			{
				j1->getEnMain()->empiler(c);
			}
			else
			{
				j2->getEnMain()->empiler(c);
			}
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
			break;
		}

	}
}


void jouer_un_tour(Joueur* j1, Joueur* j2)
{

	try
	{
		Carte c1 = j1->getEnMain()->depiler();
		Carte c2 = j2->getEnMain()->depiler();

		if (c1.getValeur() < c2.getValeur())
		{
			j2->getGain()->empiler(c1);
			j2->getGain()->empiler(c2);
		}
		else if (c1.getValeur() > c2.getValeur())
		{
			j1->getGain()->empiler(c1);
			j1->getGain()->empiler(c2);
		}
		else
		{
			if (c1.getCouleur() == Couleur::ROUGE && c2.getCouleur() == Couleur::NOIR)
			{
				j1->getGain()->empiler(c1);
				j1->getGain()->empiler(c2);
			}
			else if (c2.getCouleur() == Couleur::ROUGE && c1.getCouleur() == Couleur::NOIR)
			{
				j2->getGain()->empiler(c1);
				j2->getGain()->empiler(c2);
			}
			else
			{
				j1->getGain()->empiler(c1);
				j2->getGain()->empiler(c2);
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

}

double compter_points (Joueur j)
{
	double compte = 0.;
	while(!j.getGain()->estVide())
	{
		Carte c = j.getGain()->depiler();
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
	double score1, score2;
	score1 = compter_points(j1);
	score2 = compter_points(j2);
	cout << "Resultats de la partie : " << endl;
	cout << "Joueur 1 : " << score1 << endl;
	cout << "Joueur 2 : " << score2 << endl;
	if(score1>score2)
	{
		cout << "Le joueur 1 a gagne " << endl;
	}
	else if (score1<score2)
	{
		cout << "Le joueur 2 a gagne " << endl;
	}
	else
	{
		cout << "Egalite" << endl;
	}
}

int main(void)
{
	srand(time(NULL));
	//Création de la pile de 100 éléments
	Pile<Carte> pioche = Pile<Carte>();
	remplir_pile(pioche);

	//Création des joueurs
	Joueur* j1 = new Joueur();
	Joueur* j2 = new Joueur();	

	//Distribution des cartes tour à tour
	distribuer_joueurs(50, pioche, j1, j2);

	int i(0);
	//Boucle de jeu
	while(!j1->getEnMain()->estVide() && !j2->getEnMain()->estVide())
	{
		jouer_un_tour(j1,j2);
		i++;
		cout << i << endl;
	}

	//Affichage du score
	afficher_score(*j1, *j2);
	system("pause");

    return 0;
}
