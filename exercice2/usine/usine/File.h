#ifndef FILE_H
#define FILE_H

#include <vector>

template<typename T> class File {
public: // constructeurs et destructeurs:  
	File(int max = 100) ;    
	File(const File & f);   
	// modificateurs  
	void enfiler(const T& elt) { if (!estPleine()) { vec.push_back(elt); } };
	T defiler() {
		if (!estVide()) { T elt = vec.front(); vec.erase(vec.begin(), vec.begin() + 1); return elt; }
		else throw logic_error("pile vide");
	};
	
	// sélecteurs     
	int taille() const { return vec.size(); };
	bool estVide() const { return vec.empty(); };
	bool estPleine() const { 
		std::cout << taille() << " " << taille_max <<endl;
		return taille() >= taille_max; };
	const T& premier() const { return vec[vec.begin()]; }; //  tête de la file  
	const T& dernier() const { return vec[vec.end()]; };; // queue de la file  
	// surcharges d'opérateurs  
	const File<T>& operator = (const File<T>& f);  
	//UNUSED
	//template <typename U> friend std::ostream& operator <<  (std::ostream& f, const File<U>& q); 
private: // ...Modèle d'implantation 
	std::vector<T> vec;
	const int taille_max ;

}; 


using namespace std;
template<typename T>
File<T>::File(int max = 100) :
	vec(0),
	taille_max(max)
{	
}

template<typename T>
File<T>::File(const File & f) :
	vec(0),
	taille_max(f.taille_max)
{
	for (int i = f.vec.begin(); i < f.vec.end(); i++) {
		vec.push_back(f.vec[i]);
	}
}

template<typename T>
const File<T>& File<T>::operator=(const File<T>& f)
{
	vec(0);
	taille_max(f.taille_max);
	for (int i = f.vec.begin(); i < f.vec.end(); i++) {
		vec.push_back(f.vec[i]);
	}
	return (*this);
}

#endif
