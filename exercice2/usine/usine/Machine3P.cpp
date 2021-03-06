#include "Machine3P.h"



Machine3P::Machine3P(Piece p, File<Piece>* axes, File<Piece>* jupes, File<Piece>* tetes) : Machine(p),
	fileAxe(axes),
	fileJupe(jupes),
	fileTete(tetes)
{
}


Machine3P::~Machine3P()
{
	//delete fileAxe;
	//delete fileJupe;
	//delete fileTete;
}

void Machine3P::traiter()
{
	while (!getFileSortie()->estPleine()) {
		panne();
		//Si toutes les files ont au moins un element
		if (!(fileAxe->estVide() || fileJupe->estVide() || fileTete->estVide())) {
			try
			{
				fileAxe->defiler();
				fileJupe->defiler();
				fileTete->defiler();
				Sleep(10);
				getFileSortie()->enfiler(Piece::PISTON);
				cout << "\nCreation d'un piston : " << getFileSortie()->taille() << endl;
				cout << "Apres creation : Axes : " << fileAxe->taille() << " -- Jupes : " << fileJupe->taille() << " -- Tetes : " << fileTete->taille() << endl;

			}
			catch (const std::exception& e)
			{
				cout << "Error traitement Machine3P : " << e.what() << endl;
			}
		}
	}
	arreter();
}

