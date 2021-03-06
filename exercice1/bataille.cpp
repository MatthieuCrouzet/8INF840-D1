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

		
		cout << "Carte du joueur 1 :" << endl << c1 << endl;
		cout << "Carte du joueur 2 :" << endl << c2 << endl;

		if (c1.getValeur() < c2.getValeur())
		{
			j2->getGain()->empiler(c1);
			j2->getGain()->empiler(c2);
			cout << "Le joueur 2 gagne !" << endl;
		}
		else if (c1.getValeur() > c2.getValeur())
		{
			j1->getGain()->empiler(c1);
			j1->getGain()->empiler(c2);
			cout << "Le joueur 1 gagne !" << endl;
		}
		else
		{
			if (c1.getCouleur() == Couleur::ROUGE && c2.getCouleur() == Couleur::NOIR)
			{
				j1->getGain()->empiler(c1);
				j1->getGain()->empiler(c2);
				cout << "Le joueur 1 gagne !" << endl;
			}
			else if (c2.getCouleur() == Couleur::ROUGE && c1.getCouleur() == Couleur::NOIR)
			{
				j2->getGain()->empiler(c1);
				j2->getGain()->empiler(c2);
				cout << "Le joueur 2 gagne !" << endl;
			}
			else
			{
				j1->getGain()->empiler(c1);
				j2->getGain()->empiler(c2);
				cout << "Egalite !" << endl;
			}
		}
		system("pause");
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
	bool continuer=true;
	
	char recommencer;
	while (continuer)
	{
		bool entreeValide = false;
		int nbCartes = 0;
		while (nbCartes <= 0 || nbCartes>50) {
			cout << "Choisissez le nombre de carte par joueurs (entre 1 et 50)" << endl;
			cin >> nbCartes;
		}
		//Cr�ation de la pile de 100 �l�ments
		Pile<Carte> pioche = Pile<Carte>();
		remplir_pile(pioche);

		//Cr�ation des joueurs
		Joueur* j1 = new Joueur();
		Joueur* j2 = new Joueur();



		//Distribution des cartes tour � tour
		distribuer_joueurs(nbCartes, pioche, j1, j2);

		//Boucle de jeu
		while (!j1->getEnMain()->estVide() && !j2->getEnMain()->estVide())
		{
			jouer_un_tour(j1, j2);
		}

		//Affichage du score
		afficher_score(*j1, *j2);

		while (!entreeValide) {
			cout << "Voulez-vous recommencer ? (O/N)" << endl;

			cin >> recommencer;
			switch (recommencer)
			{
			case 'O':
			case 'o':
				entreeValide = true;
				break;
			case 'N':
			case 'n':
				continuer = false;
				entreeValide = true;
				break;
			default:
				cout << "Entrez une valeur valide ? (O/N)" << endl;
				entreeValide = false;
				break;
			}
		}
		
	} 

    return 0;
}
