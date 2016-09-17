#include <iostream>
#include "Pile.h"


template<typename T>
Pile<T>::Pile(int max = MAX_PILE) {
		tab = new T[max]; 
		sommet = -1; 
		tailleMax = max;
}

template<typename T>
Pile<T>::Pile(const Pile& p)
{
	tab = new T[p.tailleMax];
	sommet = p.sommet;
	tailleMax = p.tailleMax;
	for (int i = 0; i <= tailleMax; i++) {
		tab[i] = p.tab[i];
	}
}

template<typename T>
Pile<T>::~Pile()
{
	delete [] tab;
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
	cout << "Erreur pile vide !" << endl;
	return NULL;
}

template<typename T>
bool Pile<T>::estVide() const
{
	return sommet > -1;
}

template<typename T>
int Pile<T>::taille() const
{
	return sommet+1;
}

template<typename T>
const T & Pile<T>::getSommet() const
{
	if (!estVide()) {
		return tab[sommet];
	}
	cout << "Erreur pile vide !" << endl;
	return NULL;
}

template<typename T>
const Pile<T>& Pile<T>::operator=(const Pile<T> p)
{
	~Pile();
	tab = new T[p.tailleMax];
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
	for (int i = sommet; i > -1; i--) {
		s << p.tab[i];
	}
	s << "*******BASE*******" << endl;
	return s;
}