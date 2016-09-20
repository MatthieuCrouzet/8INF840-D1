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
	if (typePieceTraitee == Piece::PISTON) {
		std::cout << fileObjetsTraites->taille() << " pistons créés ! " << endl;
	}
	while ((typePieceTraitee==Piece::PISTON && fileObjetsTraites->estPleine()) || typePieceTraitee!=Piece::PISTON || !arret) {
		if (entier_alea(1, 4) > 1) {
			switch (typePieceTraitee) {
			case Piece::AXE:
				if (!fileAxes->estVide()) {
					Sleep(2500);
					fileObjetsTraites->enfiler(fileAxes->defiler());
				}
				break;
			case Piece::JUPE:
				if (!fileJupes->estVide()) {
					Sleep(3000);
					fileObjetsTraites->enfiler(fileJupes->defiler());
				}
				break;
			case Piece::PISTON:
				if (!fileAxes->estVide() && !fileJupes->estVide() && !fileTetes->estVide()) {
					Sleep(1000);
					fileObjetsTraites->enfiler(fileAxes->defiler());
					fileObjetsTraites->enfiler(fileJupes->defiler());
					fileObjetsTraites->enfiler(fileTetes->defiler());
					fileObjetsTraites->enfiler(Piece::PISTON);
				}
				break;
			case Piece::TETE:
				if (!fileTetes->estVide()) {
					Sleep(2000);
					fileObjetsTraites->enfiler(fileTetes->defiler());
				}
				break;
			}
		}
		else {
			int tmp = entier_alea(5,10);
			switch (typePieceTraitee) {
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
			}
			Sleep(tmp*1000);			
		}
	}
	arret = false;
	std::cout << "Les 100 pistons sont créés !" << endl;
}
