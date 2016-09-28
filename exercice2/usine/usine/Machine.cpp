#include <iostream>

#include "Machine.h"
#include "Windows.h"

using namespace std;

Machine::Machine():
	arret(false)
{
	fileSortie = new File<Piece>();
}


Machine::~Machine()
{
	delete fileSortie;
}

void Machine::traiter()
{
}

int entier_alea(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
