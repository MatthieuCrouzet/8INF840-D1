#include <iostream>
#include <ctime>
#include <thread>
#include <iomanip>

#include "Machine1P.h"
#include "Machine3P.h"

using namespace std;



#pragma region VARIABLES_GLOBALES
Machine1P* MA = new Machine1P();
Machine1P* MJ = new Machine1P();
Machine1P* MT = new Machine1P();
Machine3P* MP = new Machine3P(MA->getFileSortie(), MJ->getFileSortie(), MT->getFileSortie());

clock_t depart, fin;
bool fini = false;
#pragma endregion VARIABLES GLOBALES

#pragma region THREADS_MACHINES
void threadMA() {
	MA->traiter();
	MA->~Machine1P();
}

void threadMJ() {
	MJ->traiter();
	MJ->~Machine1P();
}

void threadMT() {
	MT->traiter();
	MT->~Machine1P();
}

void threadMP() {
	MP->traiter();
	fin = clock();
	MA->arreter();
	MJ->arreter();
	MT->arreter();
	fini = true;
	MP->~Machine3P();
}


#pragma endregion THREADS_MACHINES



void threadMain() {
	while (!fini) {

		try
		{
			switch (entier_alea(1, 3)) {
			case 1:
				MA->getFileEntree()->enfiler(Piece::AXE);
				break;
			case 2:
				MJ->getFileEntree()->enfiler(Piece::JUPE);
				break;
			case 3:
				MT->getFileEntree()->enfiler(Piece::TETE);
				break;
			}
		}
		catch (const std::exception& e)
		{
		}
	}
}

int main(void) {
	srand(time_t(NULL));
	depart = clock();
	thread T[5];
	T[0] = thread(threadMA);
	T[1] = thread(threadMJ);
	T[3] = thread(threadMT);
	T[2] = thread(threadMP);
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
	cout << setprecision(0) << "La production a durée " << temps << " millisecondes." << endl;
	system("PAUSE");

	return 0;
}
