#pragma once
#include<iostream>
#include <cstring>
using namespace std;
class ParLezaljki
{
protected:
	int redniBr;
	int red;
	int cenaLez;
	int cenaPica;
public:
	ParLezaljki();
	ParLezaljki(int redniBr, int red, int cenaLez, int cenaPica);
	virtual ~ParLezaljki();
	ParLezaljki(const ParLezaljki& p);
	ParLezaljki& operator=(const ParLezaljki& p);

	int vratiRedni() const { return redniBr; }
	int vratiRed() const { return red; }
	int vratiCenuLez() const { return cenaLez; }
	int vratiCenuPica() const { return cenaPica; }

	virtual void Prikazi();
	virtual int svotaZaNaplatu();
	virtual int brLezaljki();
	friend ostream& operator<<(ostream& izlaz, const ParLezaljki& p)
	{

		izlaz << "Redni broj lezaljke: " << p.vratiRedni() << endl;
		izlaz << "Red u kome se lezaljka nalazi: " << p.vratiRed() << endl;
		izlaz<< "Cena lezaljke: " << p.vratiCenuLez() << endl;
    	izlaz<< "Cena pica: " << p.vratiCenuPica() << endl;

		return izlaz;
	}
};

