#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <vector>
#include <mutex>

template<typename T> class File {
public: // constructeurs et destructeurs:  
	File(int max = 100) ;    
	File(const File & f);   
	// modificateurs  
	void enfiler(const T& elt);
	T defiler();
	
	// sélecteurs     
	int taille() const { return vec.size(); };
	bool estVide() const { return vec.empty(); };
	bool estPleine() const { return taille() >= taille_max; };
	const T& premier() const { return vec.front(); }; //  tête de la file  
	const T& dernier() const { return vec.end(); }; // queue de la file  
	// surcharges d'opérateurs  
	const File<T>& operator = (const File<T>& f);  
	//UNUSED
	//template <typename U> friend std::ostream& operator <<  (std::ostream& f, const File<U>& q); 
private: // ...Modèle d'implantation 
	std::vector<T> vec;
	const int taille_max ;
	std::mutex m;
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
	m.lock();
	for (vector<T>::iterator i =f.vec.begin(); i < f.vec.end(); i++) {
		vec.push_back(*i);
	}
	m.unlock();
}

template<typename T>
const File<T>& File<T>::operator=(const File<T>& f)
{
	vec(0);
	taille_max(f.taille_max);
	m.lock();
	for (vector<T>::iterator i = f.vec.begin(); i < f.vec.end(); i++) {
		vec.push_back(*i);
	}
	m.unlock();
	return (*this);
}

template<typename T>
void File<T>::enfiler(const T& elt) {
	m.lock();
	if (!estPleine()) {
		vec.push_back(elt);
		m.unlock();
	}
	else {
		m.unlock();
		throw length_error("Pile pleine");
	}
};


template<typename T>
T File<T>::defiler() {
	m.lock();
	if (!estVide()) {
		T elt = vec.front();
		vec.erase(vec.begin());
		m.unlock();
		return elt;
	}
	else {
		m.unlock();
		throw length_error("pile vide");
	}
};

#endif
