#ifndef MACHINE_H
#define MACHINE_H

#include "File.h"
#include "Piece.h"
#include <Windows.h>


int entier_alea(int min, int max);

class Machine
{
public:
	Machine(Piece p);
	~Machine();

	File<Piece>* getFileSortie() const { return fileSortie; };
	bool getArret() const { return arret; };

	virtual void traiter();
	void arreter() { arret = true; };

	//jusqu'à 25% ou 25% de chances de tomber en panne ?
	//void panne() { if (entier_alea(1, 4)>3) Sleep(entier_alea(50, 100)); };
	void panne();

private:
	File<Piece>* fileSortie;
	bool arret;
	Piece production;
};




#endif