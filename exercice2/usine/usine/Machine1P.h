#ifndef MACHINE1P_H
#define MACHINE1P_H

#include "Machine.h"

class Machine1P :
	public Machine
{
public:
	Machine1P();
	~Machine1P();
	virtual void traiter();
	File<Piece>* getFileEntree() { return fileEntree; }
private:
	File<Piece>* fileEntree;
};

#endif