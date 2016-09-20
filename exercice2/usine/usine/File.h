#ifndef FILE_H
#define FILE_H

#include <vector>

template<typename T> class File {
public: // constructeurs et destructeurs:  
	File(int max = 100) ;    
	File(const File & f);   
	// modificateurs  
	void enfiler(const T& elt) { vec.push_back(elt); };
	T defiler() { T elt = vec.front(); vec.erase(vec.begin(), vec.begin() + 1); return elt; };
	// sélecteurs     
	int taille() const { return vec.size(); };
	bool estVide() const { return vec.empty(); };
	bool estPleine() const { return taille() == taille_max; };
	const T& premier() const { return vec[vec.begin()]; }; //  tête de la file  
	const T& dernier() const { return vec[vec.end()]; };; // queue de la file  
	// surcharges d'opérateurs  
	const File<T>& operator = (const File<T>& f);  
	//UNUSED
	//template <typename U> friend std::ostream& operator <<  (std::ostream& f, const File<U>& q); 
private: // ...Modèle d'implantation 
	std::vector<T> vec;
	int taille_max;

}; 


using namespace std;
template<typename T>
File<T>::File(int max = 100) :
	vec(0),
	taille_max(100)
{	
}

template<typename T>
File<T>::File(const File & f) :
	debut(f.vec.begin()),
	fin(f.vec.end()),
	taille_max(f.taille_max)
{
	for (int i = f.vec.begin(); i < f.vec.end(); i++) {
		vec[i] = f.vec[i];
	}
}

template<typename T>
const File<T>& File<T>::operator=(const File<T>& f)
{
	debut = f.vec.begin();
	fin = f.vec.end();
	taille_max = f.taille_max;
	for (int i = f.vec.begin(); i < f.vec.end(); i++) {
		vec[i] = f.vec[i];
	}
	return (*this);
}

#endif
