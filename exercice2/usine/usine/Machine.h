#ifndef MACHINE_H
#define MACHINE_H

#include "File.h"
#include "Piece.h"

class Machine
{
public:
	Machine(Piece p);
	Machine(Piece p, File<Piece>* axes, File<Piece>* jupes, File<Piece>* tetes);
	~Machine();

	File<Piece>* getObjetsTraites()	{	return fileObjetsTraites;	};;
	File<Piece>* getAxes()			{	return fileAxes;	};
	File<Piece>* getJupes()			{	return fileJupes;	};
	File<Piece>* getTetes()			{	return fileTetes;	};
	bool getArret() { return arret; };

	void traiter();
	void arreter() { arret = true; };

private:
	File<Piece>* fileObjetsTraites;
	File<Piece>* fileAxes;
	File<Piece>* fileJupes;
	File<Piece>* fileTetes;
	bool arret;
	Piece typePieceTraitee;
};

int entier_alea(int min, int max);

#endif