#pragma once
#include "IspitniMaterijal.h"
using namespace std;
class IspitPriprema
{
private:
	IspitniMaterijal** niz;
	int trenutni;
	int kapacitet;
public:
	IspitPriprema();
	IspitPriprema(int kapacitet);
	~IspitPriprema();
	IspitPriprema(const IspitPriprema& p);
	IspitPriprema& operator=(const IspitPriprema& p);
	void print();
	void Dodaj(IspitniMaterijal* novi);
	void Obrisi(int id);
	void Savladaj(int k);
	int UkupnoSavladanih();
	float UkupnoVreme(float vJedinicno);
	void VratiNaj(float vJedinicno, IspitniMaterijal** Min, IspitniMaterijal** Max);

	friend ostream& operator<<(ostream& izlaz, const IspitPriprema& isp)
	{
		izlaz << "Kapacitet ispitne pripreme: " << isp.kapacitet << endl;
		izlaz << "Trenutni broj ispitnih materijala: " << isp.trenutni << endl;
		for (int i = 0; i < isp.trenutni; i++)
		{
			isp.niz[i]->Prikazi(); //cout<<niz[i] ne pisem ovde nego u operatoru<<
		}
		return izlaz;
	}
};

