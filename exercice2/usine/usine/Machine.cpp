#include <iostream>

#include "Machine.h"
#include "Windows.h"

using namespace std;

Machine::Machine(Piece p) :
	arret(false), production(p)
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


std::ostream& operator<<(std::ostream & os, Piece const& p)
{
	switch (p)
	{
	case Piece::AXE:
		os << "AXE";
		break;
	case Piece::JUPE:
		os << "JUPE";
		break;
	case Piece::TETE:
		os << "TETE";
		break;
	case Piece::PISTON:
		os << "PISTON";
		break;
	}
	return os;
}

void Machine::panne() {
	if (entier_alea(1, 100) > entier_alea(75, 100))
	{
		int temp = entier_alea(50, 100);
		cout << "Panne de la machine : " << production << endl;
		Sleep(temp);
	}
}

int entier_alea(int min, int max)
{
	return rand() % (max - min + 1) + min;
}



