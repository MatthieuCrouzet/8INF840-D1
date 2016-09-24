#include <iostream>

#include "Machine.h"
#include "Windows.h"

using namespace std;

Machine::Machine(Piece p):
	arret(false),
	typePieceTraitee(p)
{
	fileAxes = new File<Piece>();
	fileJupes = new File<Piece>();
	fileTetes = new File<Piece>();
	fileObjetsTraites = new File<Piece>();
}

Machine::Machine(Piece p, File<Piece>* axes, File<Piece>* jupes, File<Piece>* tetes) :
	fileAxes(axes),
	fileJupes(jupes),
	fileTetes(tetes),
	arret(false),
	typePieceTraitee(p)
{
	fileObjetsTraites = new File<Piece>();
}


Machine::~Machine()
{
	delete fileObjetsTraites;
	delete fileAxes;
	delete fileJupes;
	delete fileTetes;
}

int entier_alea(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Machine::traiter()
{
	while ((typePieceTraitee == Piece::PISTON && !fileObjetsTraites->estPleine()) && (typePieceTraitee != Piece::PISTON && !arret)) {

		if (typePieceTraitee == Piece::PISTON) {
			std::cout << " ---- " << fileObjetsTraites->estPleine() << endl;

			std::cout << fileObjetsTraites->getTaille() << " pistons créés ! " << endl;
		}

		if (entier_alea(1, 4) > 1) {
		
			switch (typePieceTraitee) {
			case Piece::AXE:
				if (!fileAxes->estVide()) {
					Sleep(25);
					try
					{
						fileObjetsTraites->enfiler(fileAxes->defiler());
					}
					catch (const std::exception& e)
					{
						std::cout << e.what() << endl;
					}
				}
				break;
			case Piece::JUPE:
				if (!fileJupes->estVide()) {
					Sleep(30);
					try
					{
						fileObjetsTraites->enfiler(fileJupes->defiler());
					}
					catch (const std::exception& e)
					{
						std::cout << e.what() << endl;
					}
				}
				break;
			case Piece::PISTON:
				if (!fileAxes->estVide() && !fileJupes->estVide() && !fileTetes->estVide()) {
					Sleep(10);
					try {
						fileAxes->defiler();
						fileJupes->defiler();
						fileTetes->defiler();
						fileObjetsTraites->enfiler(Piece::PISTON);
					}
					catch (const std::exception& e)
					{
						std::cout << e.what() << endl;
					}
				}
				break;
			case Piece::TETE:
				if (!fileTetes->estVide()) {
					Sleep(20);
					try {
						fileObjetsTraites->enfiler(fileTetes->defiler());
					}
					catch (const std::exception& e)
					{
						std::cout << e.what() << endl;
					}
				}
				break;
			}
		}
		else {
			int tmp = entier_alea(5, 10);
			/*switch (typePieceTraitee) {
			case Piece::AXE:
				std::cout << "Machine pour les AXES en panne pendant " << tmp << " minutes ! " << endl;
				break;
			case Piece::JUPE:
				std::cout << "Machine pour les JUPES en panne pendant " << tmp << " minutes ! " << endl;
				break;
			case Piece::PISTON:
				std::cout << "Machine pour les PISTONS en panne pendant " << tmp << " minutes ! " << endl;
				break;
			case Piece::TETE:
				std::cout << "Machine pour les TETES en panne pendant " << tmp << " minutes ! " << endl;
				break;
			}*/
			Sleep(tmp * 10);
		}
	}
	arret = false;
	std::cout << "Les 100 pistons sont créés !" << endl;
}
