#pragma once
#include "Putnik.h"

class Skijanje : public Putnik
{
private:
	int duzinaSkija;
	int masaSkija;
	int masaPancerica;
public:
	Skijanje();
	Skijanje(const char* ime, const char* sifraSedista, int duzinaSkija, int masaSkija, int masaPancerica);
	~Skijanje();
	Skijanje(const Skijanje& p);
	Skijanje& operator=(const Skijanje& p);
	int vratiDuzinuSkija() const { return duzinaSkija; }
	int vratiMasuSkija() const { return masaSkija; }
	int vratiMasuPancerica() const { return masaPancerica; }
	void Print();
	float masaOpreme();
	Putnik* kopiraj() const;
	friend ostream& operator<<(ostream& izlaz, const Skijanje& p)
	{
		izlaz << "Duzina skija: " << p.vratiDuzinuSkija() << endl;
		izlaz << "Masa skija: " << p.vratiMasuSkija() << endl;
		izlaz << "Masa pancerica: " << p.vratiMasuPancerica() << endl;
		return izlaz;
	}



};

