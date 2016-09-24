#ifndef MACHINE_H
#define MACHINE_H

#include "File.h"
#include "Piece.h"

#include <mutex>


class Machine
{
public:
	Machine(Piece p);
	Machine(Piece p, File<Piece>* axes, File<Piece>* jupes, File<Piece>* tetes);
	~Machine();

	File<Piece>* getObjetsTraites() const {	return fileObjetsTraites;	};
	File<Piece>* getAxes() const {	return fileAxes;	};
	File<Piece>* getJupes() const {	return fileJupes;	};
	File<Piece>* getTetes() const {	return fileTetes;	};
	bool getArret() const { return arret; };

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