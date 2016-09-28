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
	void enfiler(const T& elt) throw ();
	T defiler() throw ();
	
	// sélecteurs     
	int taille() const { return vec.size(); };
	bool estVide() const { return vec.empty(); };
	bool estPleine() const { 
		//std::cout << taille() << " " << taille_max << endl;
		//std::cout << taille() << " " << taille_max << endl;
		//std::cout << taille() << " " << taille_max << endl;
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
	for (int i = f.vec.begin(); i < f.vec.end(); i++) {
		vec.push_back(f.vec[i]);
	}
	m.unlock();
}

template<typename T>
const File<T>& File<T>::operator=(const File<T>& f)
{
	vec(0);
	taille_max(f.taille_max);
	m.lock();
	for (int i = f.vec.begin(); i < f.vec.end(); i++) {
		vec.push_back(f.vec[i]);
	}
	m.unlock();
	return (*this);
}

template<typename T>
void File<T>::enfiler(const T& elt) throw (){
	m.lock();
	if (!estPleine()) {
		vec.push_back(elt);
		m.unlock();
	}
	else {
		m.unlock();
		cout << "throw pile pleine : " << endl;
		throw new length_error("Pile pleine");
	}
};


template<typename T>
T File<T>::defiler() throw () {
	m.lock();
	if (!estVide()) {
		T elt = vec.front();
		vec.erase(vec.begin(), vec.begin() + 1);
		m.unlock();
		return elt;
	}
	else {
		m.unlock();
		cout << "throw pile vide" << endl;
		throw length_error("pile vide");
	}
};

#endif
