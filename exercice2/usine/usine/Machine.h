#ifndef MACHINE_H
#define MACHINE_H

#include "File.h"
#include "Piece.h"
#include <Windows.h>

#include <mutex>
static mutex m;

class Machine
{
public:
	Machine();
	~Machine();

	File<Piece>* getFileSortie() const { return fileSortie; };
	bool getArret() const { return arret; };

	virtual void traiter();
	void arreter() { arret = true; };

private:
	File<Piece>* fileSortie;
	bool arret;
};

int entier_alea(int min, int max);

#endif