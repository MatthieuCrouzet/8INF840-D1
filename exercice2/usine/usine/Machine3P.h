#ifndef MACHINE3P_H
#define MACHINE3P_H

#include "Machine.h"

class Machine3P:
	public Machine
{
public:
	Machine3P(Piece p,File<Piece>* axes, File<Piece>* jupes, File<Piece>* tetes);
	~Machine3P();
	virtual void traiter();
private:
	File<Piece>* fileAxe;
	File<Piece>* fileJupe;
	File<Piece>* fileTete;
};

#endif