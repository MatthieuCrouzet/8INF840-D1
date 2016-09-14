<<<<<<< HEAD
// Devoir1_CROUZET_BRANGER_8INF840_A2016.cpp : Defines the entry point for the console application.
//


#include "Pile.h"
#include "Carte.h"
#include "Joueur.h"
#include <cstdlib>
=======
#include <iostream>
>>>>>>> 9a30287aa97899bf901c7170552fd31adf893268

int entier_alea(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void remplir_pile(Pile<Carte> & p)
{
	for (int i = 0; i < 100;i++)
	{
		Carte c = new Carte();
		//c.couleur = entier_alea(0,1);
		//c.val = entier_alea(1,10);
		//c.bonus = entier_alea(1,4);
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

}

int main(void)
{

	//Création de la pile de 100 éléments
	Pile<Carte> pioche();
	remplir_pile(pioche);
	//Création des joueurs
	Joueur j1();
	Joueur j2();

	//Distribution des cartes tour à tour
	distribuer_joueurs(50, pioche, j1, j2);

	//Boucle de jeu
	while(!j1.tas.estVide() && !j1.tas.estVide())
	{
		jouer_un_tour(j1,j2);
	}

	//Affichage du score
	afficher_score(j1, j2);

    return 0;
}



