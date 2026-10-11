#pragma once
#include"ParLezaljki.h"
class ParLezaljkiSaDodatkom:public ParLezaljki
{
private:
	int brDodatnihLez;
public:
	ParLezaljkiSaDodatkom();
	ParLezaljkiSaDodatkom(int redniBr, int red, int cenaLez, int cenaPica, int brDodatnihLez);
	~ParLezaljkiSaDodatkom();
	ParLezaljkiSaDodatkom(const ParLezaljkiSaDodatkom& p);
	ParLezaljkiSaDodatkom& operator=(const ParLezaljkiSaDodatkom& p);

	int vratiBrDodatnih() const { return brDodatnihLez; }

	void Prikazi();
	int svotaZaNaplatu();
	int brLezaljki();

	friend ostream& operator<<(ostream& izlaz, const ParLezaljkiSaDodatkom& p)
	{
		izlaz << "Redni broj lezaljke: " << p.vratiRedni() << endl;
		izlaz << "Red u kome se lezaljka nalazi: " << p.vratiRed() << endl;
		izlaz << "Cena lezaljke: " << p.vratiCenuLez() << endl;
		izlaz << "Cena pica: " << p.vratiCenuPica() << endl;
		izlaz << "Broj dodatnih lezaljki: " << p.vratiBrDodatnih() << endl;
		return izlaz;
	}
};

