#ifndef PILE_H
#define PILE_H

template <typename T>
class Pile
{
public:
	// constructeurs et destructeurs
	Pile(int max = MAX_PILE); //constructeur
	Pile(const Pile& p);//constructeur copie
	~Pile();//destructeur
			// Modificateurs
	void empiler(const T& elt);
	T depiler();
	//Selecteurs
	bool estVide()const;
	int taille() const;
	const T& getSommet() const; // consulte l'element au Sommet
	//surcharge d'operateurs
	const Pile<T>& operator = (const Pile<T> p);
	template <typename U> friend std::ostream& operator<<
		(std::ostream s, const Pile<U>& p);
private: //Modele d' implantation
	T* tab; 
	int sommet; // indice de l’élément au sommet 
	int tailleMax; 
	static const int MAX_PILE = 100;
};





#endif