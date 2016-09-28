#include "Machine1P.h"



Machine1P::Machine1P()
{
	fileEntree = new File<Piece>();
}


Machine1P::~Machine1P()
{
	delete fileEntree;
}

void Machine1P::traiter()
{
	Piece courante;
	while (!getArret()) {
		if (!fileEntree->estVide()) {
			try
			{
				courante = fileEntree->defiler();
				switch (courante) {
				case Piece::AXE:
					Sleep(25);
					break;
				case Piece::JUPE:
					Sleep(30);
					break;
				case Piece::TETE:
					Sleep(20);
					break;
				default:
					break;
				}
				getFileSortie()->enfiler(courante);
			}
			catch (const std::exception& e)
			{
				cout << "Error traitement Machine1P : " << e.what() << endl;
			}
		}
	}
}
