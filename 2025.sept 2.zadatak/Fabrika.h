#pragma once
#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class Fabrika
{
private:
	int trenutniBr;
	int kapacitet;
	T* niz;
public:
	Fabrika();
	Fabrika(int kapacitet);
	~Fabrika();
	Fabrika(const Fabrika<T>& f);
	Fabrika<T>& operator=(const Fabrika<T>& f);

	void Ispisi(ostream& izlaz);
	friend ostream& operator<<(ostream& izlaz, const Fabrika<T>& f)
	{
		izlaz << "Kapacitet fabrike: " << f.kapacitet << endl;
		izlaz << "Trenutni broj: " << f.trenutniBr << endl;
		for (int i = 0; i < f.trenutniBr; i++)
		{
			izlaz << f.niz[i]<< " ";
		}
		return izlaz;
	}

	void Dodaj(T novi);
	void Izbaci(T el);
	float Ukupno();
	int UkupnaAmbalazaIZapremina(T el, float* uk); 
	int NajmanjeAmbalaza(double br);
	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);
};

template<class T>
inline Fabrika<T>::Fabrika()
{
	kapacitet = 0;
	trenutniBr = 0;
	niz = nullptr;
}

template<class T>
inline Fabrika<T>::Fabrika(int kapacitet)
{
	this->kapacitet = kapacitet;
	this->trenutniBr = 0;
	this->niz = new T[this->kapacitet];
}

template<class T>
inline Fabrika<T>::~Fabrika()
{
	if (niz != nullptr)
	{
		delete[] niz;
	}
}

template<class T>
inline Fabrika<T>::Fabrika(const Fabrika<T>& f)
{
	this->kapacitet = f.kapacitet;
	this->trenutniBr = f.trenutniBr;
	this->niz = new T[this->f.kapacitet];
	for (int i = 0; i < f.trenutniBr; i++)
	{
		niz[i] = f.niz[i];
	}
}

template<class T>
inline Fabrika<T>& Fabrika<T>::operator=(const Fabrika<T>& f)
{
	if (this != &f)
	{
		this->kapacitet = f.kapacitet;
		this->trenutniBr = f.trenutniBr;
		this->niz = new T[this->f.kapacitet];
		for (int i = 0; i < f.trenutniBr; i++)
		{
			niz[i] = f.niz[i];
		}
	}
	return *this;
}

template<class T>
inline void Fabrika<T>::Ispisi(ostream& izlaz)
{
	izlaz << "Kapacitet fabrike: " << kapacitet << endl;
	izlaz << "Trenutni broj: " << trenutniBr << endl;
	for (int i = 0; i < trenutniBr; i++)
	{
		izlaz << niz[i];
	}
}

template<class T>
inline void Fabrika<T>::Dodaj(T novi) //rastuci    3 9 12 18 20 25
{
	if (trenutniBr < kapacitet)
	{
		bool nadjen = false;
		int i = 0;
		while (i < trenutniBr && nadjen == false)
		{
			if (niz[i] < novi)
			{
				i++;
			}
			else
			{
				nadjen = true;
			}
		}
		if (nadjen == true) //dodajemo novi el. u sredinu ili na pocetak niza
		{
				for (int j = trenutniBr; j > i; j--)
				{
					niz[j] = niz[j - 1];
				}
				niz[i] = novi;
				trenutniBr++;
		}
		else //ako je nadjen==false, novi element dodajemo na kraj niza
		{
			niz[trenutniBr] = novi;
			trenutniBr++;
		}
	}
	else
	{
		throw exception("Fabrika je puna! Nema mesta za dodavanje novog soka!");
	}
}

template<class T>
inline void Fabrika<T>::Izbaci(T el)
{
	int i = 0;
	bool nadjen = false;
	while (i < trenutniBr && nadjen == false)
	{
		if (niz[i] == el)
		{
			nadjen = true;
		}
		else
		{
			i++;
		}
	}
	if (nadjen == true)
	{
		for (int j = i; j < trenutniBr-1; j++)
		{
			niz[j] = niz[j + 1];
		}
		trenutniBr--;
	}
	else
	{
		throw exception("U fabrici ne postoji pice date zapremine!");
	}
}

template<class T>
inline float Fabrika<T>::Ukupno()
{
	float suma = 0.0f;
	for (int i = 0; i < trenutniBr; i++)
	{
		suma = suma + niz[i];
	}
	return suma;
}

template<class T>
inline int Fabrika<T>::UkupnaAmbalazaIZapremina(T el, float* uk)
{
	int brojac = 0;
	for (int i = 0; i < trenutniBr; i++)
	{
		if (niz[i] == el)
		{
			brojac++;
			*uk = *uk + niz[i];
		}
	}
	//*uk=brojac*el;
	return brojac;
}

template<class T>
inline int Fabrika<T>::NajmanjeAmbalaza(double br) //0.2 0.2 0.2 0.5 0.5 1 1 br=2.8	
{
	int brojac = 0;
	float suma = 0.0f;
	int i = trenutniBr - 1;
	while (i > 0 && suma < br)
	{
		suma = suma + niz[i];
		brojac++;
		i--;
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
inline void Fabrika<T>::Sacuvaj(const char* imeFajla)
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
		fajl << niz[i]<<" ";
	}
	fajl.close();
}

template<class T>
inline void Fabrika<T>::Ucitaj(const char* imeFajla)
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
