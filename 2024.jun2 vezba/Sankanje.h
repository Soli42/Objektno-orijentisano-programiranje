#pragma once
#include "Putnik.h"
class Sankanje : public Putnik
{
private:
	int zapremina;
	double gustinaSkija;
public:
	Sankanje();
	Sankanje(const char* ime, const char* sifraSedista, int zapremina, double gustinaSedista);
	~Sankanje();
	Sankanje(const Sankanje& p);
	Sankanje& operator=(const Sankanje& p);
	int vratiZapreminu() { return zapremina; }
	double vratiGustinuSkija() { return gustinaSkija; }
	void Print();	
	float masaOpreme();
	Putnik* kopiraj() const;
	friend ostream& operator<<(ostream& izlaz, const Sankanje& p)
	{
		izlaz << "Zapremina: " << p.zapremina << endl;
		izlaz << "Gustina skija: " << p.gustinaSkija << endl;
		return izlaz;
	}
};

