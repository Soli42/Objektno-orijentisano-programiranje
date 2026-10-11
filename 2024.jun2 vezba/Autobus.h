#pragma once
#include "Putnik.h"
#include "Sankanje.h"
#include "Skijanje.h"
#include <fstream>
using namespace std;
class Autobus
{
private:
	Putnik** niz;
	int trenutni;
	int kapacitet;
public:
	Autobus();
	Autobus(int kapacitet);
	~Autobus();
	Autobus(const Autobus& p);
	Autobus& operator=(const Autobus& p);
	int BrojPutnika() const;
	void Dodaj(Putnik* p);
	Autobus operator+(Autobus& a2);
	Putnik* MaxOprema();
	float UkupnaOprema();
	void Print();
	void Upisi(const char* imeFajla);
	friend ostream& operator<<(ostream& izlaz, const Autobus& s)
	{
		izlaz << "Kapacitet autobusa: " << s.BrojPutnika() << endl;
		izlaz << "Trenutni broj putnika: " << s.trenutni << endl;
		izlaz << "Lista putnika: " << endl;
		for (int i = 0; i < s.trenutni; i++)
		{
			cout<< *s.niz[i];
		}
		return izlaz;
	}
};

