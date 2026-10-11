#pragma once
#include<fstream>
#include<iostream>
using namespace std;

template<class T>
class Kombi
{
private:
	int trenutniBr;
	int kapacitet;
	T* niz;
public:
	Kombi();
	Kombi(int kapacitet);
	~Kombi();
	Kombi(const Kombi<T>& k);
	Kombi<T>& operator= (const Kombi<T>& k);
	void Dodaj(T noviEl);
	float UkupnaMasaOpreme();
	void print();
	T MinOprema();
	void Izbaci(int br);
	void Ucitaj(const char* imeFajla);
	friend ostream& operator<<(ostream& izlaz, const Kombi<T>& k)
	{
		izlaz << "Kapacitet kombija: " << k.kapacitet << endl;
		izlaz << "Trenutni broj putnika u kombiju: " << k.trenutniBr << endl;
		for (int i = 0; i < k.trenutniBr; i++)
		{
			izlaz << k.niz[i] << endl;
		}
		return izlaz;
	}
};

template<class T>
inline Kombi<T>::Kombi()
{
	trenutniBr = 0;
	kapacitet = 0;
	niz = nullptr;
}


template<class T>
inline Kombi<T>::Kombi(int kapacitet)
{
	trenutniBr = 0;
	this->kapacitet = kapacitet;
	niz = new T[kapacitet];
}

template<class T>
inline Kombi<T>::~Kombi()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}

template<class T>
inline Kombi<T>::Kombi(const Kombi<T>& k)
{
	trenutniBr = k.trenutniBr;
	kapacitet = k.kapacitet;
	for (int i = 0; i < k.trenutniBr; i++)
	{
		niz[i] = k.niz[i];
	}
}

template<class T>
inline Kombi<T>& Kombi<T>::operator=(const Kombi<T>& k)
{
	if (this != &k)
	{
		trenutniBr = k.trenutniBr;
		kapacitet = k.kapacitet;
		for (int i = 0; i < k.trenutniBr; i++)
		{
			niz[i] = k.niz[i];
		}
	}
	return *this;
}
	
template<class T>
inline void Kombi<T>::Dodaj(T noviEl)
{
	if (trenutniBr < kapacitet) 
	{
		niz[trenutniBr] = noviEl;
		trenutniBr++;
	}
	else
	{
		throw exception("Kombi je pun! Nema  mesta za dodavanje novog putnika!"); 
	}
}

template<class T>
inline float Kombi<T>::UkupnaMasaOpreme()
{
	float suma = 0.0f;
	for (int i = 0; i < trenutniBr; i++)
	{
		suma = suma + niz[i];
	}
	return suma;
}

template<class T>
inline void Kombi<T>::print()
{
	cout << "Kapacitet kombija: " << kapacitet << endl;
	cout << "Trenutni broj putnika u kombiju: " << trenutniBr << endl;
	for (int i = 0; i < trenutniBr; i++)
	{
		cout << niz[i] << endl;
	}
}

template<class T>
inline T Kombi<T>::MinOprema()
{
	T min = niz[0];
	for (int i = 1; i < trenutniBr; i++)
	{
		if (niz[i] < min)
		{
			min = niz[i];
		}
	}
	return min;
}

template<class T>
inline void Kombi<T>::Izbaci(int br)
{
	if (br<0 || br>trenutniBr - 1)
	{
		throw exception("Nije moguce izbaciti element sa nevalidnog indeksa!");
	}
	else
	{
		for (int i = br; i < trenutniBr - 1; i++)
		{
			niz[i] = niz[i + 1];
		}
		trenutniBr--;
	}
}

template<class T>
inline void Kombi<T>::Ucitaj(const char* imeFajla)
{
	ifstream fajl(imeFajla);
	if (!fajl.good())
	{
		throw exception("Fajl nije dobar!");
	}
	fajl >> kapacitet;
	if (niz != nullptr)
	{
		delete[] niz;
	}
	niz = new T[kapacitet];
	fajl >> trenutniBr;
	for (int i = 0; i < trenutniBr; i++)
	{
		fajl >> niz[i];
	}
	fajl.close();
}

