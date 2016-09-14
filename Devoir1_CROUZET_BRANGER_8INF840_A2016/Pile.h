#pragma once
template <typename T>
class Pile
{
public:
	// constructeurs et destructeurs
	Pile(int max = MAX PILE); //constructeur
	Pile(const Piles);//constructeur copie
	~Pile();//destructeur
			// Modificateurs
	void empiler(const T&);
	T depiler();
	//Selecteurs
	bool estVide()const;
	int taille() const;
	constT& sommet() const; // consulte l'element au Sommet
	//surcharge d'operateurs
	const Pile<T>& operator = (const Pile<T>);
	template <typename U> friend std::ostream& operator<<
		(std::ostreams, const Pile<U>&);
private: //Modele d' implantation

};
