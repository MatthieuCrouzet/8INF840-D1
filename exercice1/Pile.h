#ifndef PILE_H
#define PILE_H
#include <vector>
#include "Carte.h"

template <typename T>

class Pile
{
public:
	// constructeurs et destructeurs
	Pile<T>(int max = MAX_PILE); //constructeur
	Pile<T>(const Pile& p);//constructeur copie
	~Pile<T>();//destructeur
			// Modificateurs
	void empiler(const T& elt);
	T depiler();
	//Selecteurs
	bool estVide()const;
	int taille() const;
	const T& getSommet() const; // consulte l'element au Sommet
	//surcharge d'operateurs
	const Pile<T>& operator = (const Pile<T> p);
	template <typename T> friend std::ostream& operator<<
		(std::ostream s, const Pile<T>& p);
private: //Modele d' implantation
	static const int MAX_PILE = 100;
	int sommet; // indice de l’élément au sommet 
	int tailleMax; 
	T* tab;
};

using namespace std;

template<typename T>
Pile<T>::Pile(int max = MAX_PILE) {
	sommet = -1;
	tailleMax = max;
	tab = new T[tailleMax];
}

template<typename T>
Pile<T>::Pile(const Pile& p)
{
	sommet = p.sommet;
	tailleMax = p.tailleMax;
	tab = new T[tailleMax];
	for (int i = 0; i < tailleMax; i++) {
		tab[i] = p.tab[i];
	}
}

template<typename T>
Pile<T>::~Pile()
{
	delete[] tab;
}

template<typename T>
void Pile<T>::empiler(const T& elt)
{
	if (sommet  < tailleMax) {
		sommet++;
		tab[sommet] = elt;
	}
	else {
		cout << "Erreur pile déjà pleine !" << endl;
	}
}

template<typename T>
T Pile<T>::depiler()
{
	if (!estVide()) {
		T elt = tab[sommet];
		sommet--;
		return elt;
	}
	throw length_error("Erreur pile vide !");
}

template<typename T>
bool Pile<T>::estVide() const
{
	return sommet == -1;
}

template<typename T>
int Pile<T>::taille() const
{
	return sommet + 1;
}

template<typename T>
const T & Pile<T>::getSommet() const
{
	if (!estVide()) {
		return tab[sommet];
	}
	else {
		throw logic_error("Erreur pile vide !");
	}
	
}

template<typename T>
const Pile<T>& Pile<T>::operator=(const Pile<T> p)
{
	sommet = p.sommet;
	tailleMax = p.tailleMax;
	for (int i = 0; i <= tailleMax; i++) {
		tab[i] = p.tab[i];
	}

	return (*this);
}


template<typename U>
inline std::ostream & operator<<(std::ostream s, const Pile<U>& p)
{
	s << "******SOMMET******";
	for (int i = p.getSommet(); i > -1; i--) {
		s << p.tab[i];
	}
	s << "*******BASE*******" << endl;
	return s;
}



#endif