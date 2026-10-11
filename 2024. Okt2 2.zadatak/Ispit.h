#pragma once
#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class Ispit
{
private:
	int trenutniBr;
	int kapacitet;
	T* niz;
public:
	Ispit();
	Ispit(int kapacitet);
	~Ispit();
	Ispit(const Ispit<T>& s);
	Ispit<T>& operator=(const Ispit<T>& s);

	void Dodaj(T novi);
	void Izbaci(int pocIn, int br);
	float Ukupno();
	int UkupniBrojVrednost(float vrednost, float* suma);
	void minMax(int br1, int br2, T* min, T* max);
	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);


	void Ispisi(ostream& izlaz)
	{
		izlaz << "Kapacitet kolekcije: " << kapacitet << endl;
		izlaz << "Trenutni broj lekcija u kolekciji: " << trenutniBr << endl;
		for (int i = 0; i < trenutniBr; i++)
		{
			izlaz << niz[i];
		}
	}
	friend ostream& operator<<(ostream& izlaz, const Ispit<T>& s)
	{
		izlaz << "Kapacitet kolekcije: " << s.kapacitet << endl;
		izlaz << "Trenutni broj lekcija u kolekciji: " << s.trenutniBr << endl;
		for (int i = 0; i < s.trenutniBr; i++)
		{
			izlaz << s.niz[i];
		}
		return izlaz;
	}
};

template<class T>
inline Ispit<T>::Ispit()
{
	trenutniBr = 0;
	kapacitet = 0;
	niz = nullptr;
}

template<class T>
inline Ispit<T>::Ispit(int kapacitet)
{
	trenutniBr = 0;
	this->kapacitet = kapacitet;
	niz = new T[this->kapacitet];
}

template<class T>
inline Ispit<T>::~Ispit()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}

template<class T>
inline Ispit<T>::Ispit(const Ispit<T>& s)
{
	this->trenutniBr = s.trenutniBr;
	this->kapacitet = s.kapacitet;
	niz = new T[this->s.kapacitet];
	for (int i = 0; i < s.trenutniBr; i++)
	{
		niz[i] = s.niz[i];
	}
}

template<class T>
inline Ispit<T>& Ispit<T>::operator=(const Ispit<T>& s)
{
	if (this != &s)
	{
		this->trenutniBr = s.trenutniBr;
		this->kapacitet = s.kapacitet;
		niz = new T[this->s.kapacitet];
		for (int i = 0; i < s.trenutniBr; i++)
		{
			niz[i] = s.niz[i];
		}
	}
	return *this;
}

template<class T>
inline void Ispit<T>::Dodaj(T novi)
{
	if (trenutniBr < kapacitet)
	{
		niz[trenutniBr] = novi;
		trenutniBr = trenutniBr + 1;
	}
	else
	{
		throw exception("Kolekcija je puna! Nema mesta za dodavanje nove lekcije!");
	}
}

template<class T>
inline void Ispit<T>::Izbaci(int pocIn, int br) //4 6 8 3 5 7 4 6 6 8 trenutniBr=10
{                                               //4 6 8 5 7 4 6 6 8
	if (pocIn - 1 < trenutniBr && pocIn - 1 + br - 1 < trenutniBr)
	{
		int gornja = br;
		for (int i = 0; i < br; i++)
		{
			for (int j = pocIn - 1; j < trenutniBr - 1; j++)
			{
				niz[j] = niz[j + 1]
			}
			trenutniBr = trenutniBr - 1;
		}
			///*for (int j = pocIn - 1; j < pocIn - 1 + gornja;j++)
			//{
			//	niz[j] = niz[j + 1];
			//}
			//trenutniBr = trenutniBr - 1;
			//j = j - 1;
			//gornja = gornja - 1;*/
	}
	else
	{
		throw exception("Ne postoji lekcija koju treba izbaciti!");
	}
}
//j=3;j<6;j++ br=2 j=3;j<3+2;j++ br=1 j=3;j<4;j++
template<class T>
inline float Ispit<T>::Ukupno()
{
	float suma = 0.0f;
	for (int i = 0; i < trenutniBr; i++)
	{
		suma += niz[i];
	}
	return suma;
}
template<class T>
inline int Ispit<T>::UkupniBrojVrednost(float vrednost, float* suma)
{
	int brojac = 0;
	*suma = 0.0f;
	for (int i = 0; i < trenutni; i++)
	{
		if (niz[i] > vrednosti)
		{
			brojac++;
			*suma = *suma + niz[i];
		}
	}
	return brojac;
}
template<class T>
inline void Ispit<T>::minMax(int br1, int br2, T* min, T* max)
{
	if (br1 - 1 < trenutniBr && br2 - 1 < trenutniBr)
	{
		*min = niz[br1 - 1];
		*max = niz[br1 - 1];
		for (int i = br1; i < br2 - 1; i++)
		{
			if (niz[i] < *min)
			{
				*min = niz[i];
			}
			if (niz[i] > *max)
			{
				*max = niz[i];
			}
		}
	}
	else
	{
		throw exception("Redni brojevi su van kolekcije");
	}
}

template<class T>
inline void Ispit<T>::Sacuvaj(const char* imeFajla)
{
	ofstream fajl(imeFajla);
	if (!fajl.good())
	{
		throw exception("Fajl nije dobar!");
	}
	fajl << kapacitet << endl;
	fajl << trenutniBr << endl;
	for (int i = 0; i < trenutniBr; i++)
	{
		fajl << niz[i] << endl;
	}
	fajl.close();
}

template<class T>
inline void Ispit<T>::Ucitaj(const char* imeFajla)
{
	ifstream fajl(imeFajla);
	if (!fajl.good())
	{
		throw exception("Fajl nije dobar!");
	}
	fajl >> kapacitet;
	fajl >> trenutniBr;
	if (niz != nullptr)
	{
		delete[] niz;
	}
	niz = new T[kapacitet];
	for (int i = 0; i < trenutniBr; i++)
	{
		fajl >> niz[i];
	}
	fajl.close();
}
