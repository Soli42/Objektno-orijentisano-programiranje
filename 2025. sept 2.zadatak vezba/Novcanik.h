#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
template <class T>
class Novcanik
{
private:
	T* niz;
	int trenutni;
	int kapacitet;
public:
	Novcanik();
	Novcanik(int kapacitet);
	~Novcanik();
	Novcanik(const Novcanik<T>& p);
	Novcanik<T>& operator=(const Novcanik<T>& p);
	void Dodaj(T novi);
	void Izbaci(T el);
	float Ukupno();
	int UkupniBrojVrednost(T br, float* ukupnaVrednost);
	int NajmanjeNovcanica(int br);
	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);
	void Ispisi();
	friend ostream& operator<<(ostream& izlaz, const Novcanik<T>& s)
	{
		izlaz << "Trenutni: " << s.trenutni << endl;
		izlaz << "Kapacitet: " << s.kapacitet << endl;
		for (int i = 0; i < s.trenutni; i++)
		{
			cout << s.niz[i] << " ";
		}
		return izlaz;
	}




};

template<class T>
inline Novcanik<T>::Novcanik()
{
	niz = nullptr;
	trenutni = 0;
	kapacitet = 0;
}

template<class T>
inline Novcanik<T>::Novcanik(int kapacitet)
{
	this->trenutni = 0;
	this->kapacitet = kapacitet;
	niz = new T[kapacitet];
}

template<class T>
inline Novcanik<T>::~Novcanik()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}

template<class T>
inline Novcanik<T>::Novcanik(const Novcanik<T>& p)
{
	this->trenutni = 0;
	this->kapacitet = p.kapacitet;
	niz = new T[p.kapacitet];
	for (int i = 0; i < p.trenutni; i++)
	{
		niz[i] = p.niz[i];
	}
}

template<class T>
inline Novcanik<T>& Novcanik<T>::operator=(const Novcanik<T>& p)
{
	if (this != &p)
	{
		this->trenutni = 0;
		this->kapacitet = p.kapacitet;
		niz = new T[p.kapacitet];
		for (int i = 0; i < p.trenutni; i++)
		{
			niz[i] = p.niz[i];
		}
	}
	return *this;
}

template<class T>
inline void Novcanik<T>::Dodaj(T novi)
{
	if (trenutni < kapacitet)
	{
		int i = 0;
		bool nadjen = false;

		// Tražimo poziciju za umetanje tako da poredak ostane nerastu?i (>=)
		while (i < trenutni&& nadjen == false)
		{
			if (niz[i] >= novi) // ve? je ve?e ili jednako, idemo dalje desno
				i++;
			else
				nadjen = true; // našli smo mesto gde novi treba da se ubaci
		}

		// Umetanje sa pomeranjem udesno
		for (int j = trenutni; j > i; j--)
			niz[j] = niz[j - 1];

		niz[i] = novi;
		trenutni++;
	}
	else
	{
		throw exception("Nije moguce dodavanje");
	}
}


template<class T>
inline void Novcanik<T>::Izbaci(T el)
{
	int i = 0;
	int j;
	bool nadjen = false;
	while (i < trenutni && nadjen == false)
	{
		if (niz[i] == el)
		{
			j = i;
			nadjen = true;
		}
	}
	if (nadjen == true)
	{
		for (int j = i; j < trenutni - 1; j++)
		{
			niz[j] = niz[j + 1];
		}
		trenutni--;
	}
	else
	{
		throw exception("Nije moguce izbacivanje");
	}
}

template<class T>
inline float Novcanik<T>::Ukupno()
{
	float suma = 0;
	for (int i = 0; i < trenutni; i++)
	{
		suma += niz[i];
	}
	return suma;
}

template<class T>
inline int Novcanik<T>::UkupniBrojVrednost(T br, float* ukupnaVrednost)
{
	int brojac = 0;
	for (int i = 0; i < trenutni; i++)
	{
		if (niz[i] == br)
		{
			brojac++;
			*ukupnaVrednost = *ukupnaVrednost + niz[i];
		}
	}
	return brojac;
}

template<class T>
inline int Novcanik<T>::NajmanjeNovcanica(int br)
{
	int suma = 0, i = 0, brojac = 0;
	while (i < trenutni && suma < br)
	{
		brojac++;
		i++;
		suma += niz[i];
	}
	if (suma >= br)
	{
		return brojac;
	}
	else
	{
		return 0;
	}
	
}

template<class T>
inline void Novcanik<T>::Sacuvaj(const char* imeFajla)
{
	ofstream fajl(imeFajla);
	if (!fajl.good())
	{
		throw exception("Fajl nije dobar");
	}
	fajl << trenutni << endl;
	fajl << kapacitet << endl;
	for (int i = 0; i < trenutni; i++)
	{
		fajl << niz[i] << endl;
	}
	fajl.close();
}

template<class T>
inline void Novcanik<T>::Ucitaj(const char* imeFajla)
{
	ifstream fajl(imeFajla);
	if (!fajl.good())
	{
		throw exception("Fajl nije dobar");
	}
	fajl >> trenutni;
	fajl >> kapacitet;
	if (niz != nullptr)
	{
		delete[] niz;
	}
	niz = new T[kapacitet];
	for (int i = 0; i < trenutni; i++)
	{
		fajl >> niz[i];
	}
	fajl.close();
}

template<class T>
inline void Novcanik<T>::Ispisi()
{
	cout << "Trenutni: " << trenutni << endl;
	cout << "Kapacitet: " << kapacitet << endl;
	for (int i = 0; i < trenutni; i++)
	{
		cout << niz[i];
	}
}

