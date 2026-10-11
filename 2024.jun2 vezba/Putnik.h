#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Putnik
{
protected:
	char* ime;
	char* sifraSedista;
public:
	Putnik();
	Putnik(const char* ime, const char* sifraSedista);
	virtual ~Putnik();
	char* vratiIme() const { return ime; }
	char* vratiSifruSedista() const { return sifraSedista; }
	Putnik(const Putnik& k);
	virtual Putnik& operator=(const Putnik& p);
	virtual Putnik* kopiraj() const = 0;
	virtual void Print();
	virtual float masaOpreme() = 0;
	friend ostream& operator<<(ostream& izlaz, const Putnik& p)
	{
		izlaz << "Ime putnika: " << p.vratiIme() << endl;
		izlaz << "Sifra sedista putnika: " << p.vratiSifruSedista() << endl;
		return izlaz;
	}







};

