#include <iostream>
#include <ctime>
#include <thread>
#include <iomanip>

#include "Machine.h"

using namespace std;



#pragma region VARIABLES_GLOBALES
Machine* MA = new Machine(Piece::AXE);
Machine* MJ = new Machine(Piece::JUPE);
Machine* MT = new Machine(Piece::TETE);
Machine* MP = new Machine(Piece::PISTON, MA->getObjetsTraites(), MJ->getObjetsTraites(), MT->getObjetsTraites());

clock_t depart, fin;
bool fini = false;
#pragma endregion VARIABLES GLOBALES

#pragma region THREADS_MACHINES
void threadMA() {
	MA->traiter();
	MA->~Machine();
}

void threadMJ() {
	MJ->traiter();
	MJ->~Machine();
}

void threadMP() {
	MP->traiter();
	fin = clock();
	MA->arreter();
	MJ->arreter();
	MT->arreter();
	fini = true;
	MP->~Machine();
}

void threadMT() {
	MT->traiter();
	MT->~Machine();
}
#pragma endregion THREADS_MACHINES



void threadMain() {
	while (!fini) {
		switch (entier_alea(1, 1)) {
		case 1:
			MA->getAxes()->enfiler(Piece::AXE);
			break;
		case 2:
			MJ->getJupes()->enfiler(Piece::JUPE);
			break;
		case 3:
			MT->getTetes()->enfiler(Piece::TETE);
			break;
		}
	}
}

int main(void) {
	srand(time(NULL));
	depart = clock();
	thread T[5];
	T[0] = thread(threadMA);
	//T[1] = thread(threadMJ);
	//T[3] = thread(threadMT);
	//T[2] = thread(threadMP);
	T[4] = thread(threadMain);

	for (int i = 0; i < 5; i++) {
		if (T[i].joinable())
		{
			T[i].join();
		}
	}
	for (int i = 0; i < 5; i++) {
		T[i].~thread();
	}

	cout << "FIN" << endl;
	double temps = (fin - depart) / CLOCKS_PER_SEC;
	cout << setprecision(0) << "La production a durée " << temps*100 << " minutes." << endl;
	system("PAUSE");

	return 0;
}
