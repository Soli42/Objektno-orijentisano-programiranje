#pragma once
#include"ParLezaljki.h"
class KaficSaPlazom
{
private:
	ParLezaljki** niz;
	int trenutniBr;
	int kapacitet;
	int vrednostNovca;

public:
	KaficSaPlazom();
	KaficSaPlazom(int kapacitet);
	~KaficSaPlazom();
	KaficSaPlazom(const KaficSaPlazom& p);
	KaficSaPlazom& operator=(const KaficSaPlazom& p);

	void Dodaj(ParLezaljki* p);
	void Oslobodi(int oznaka);
	int UkupnoLezaljki();
	int UkupnaSvotaNovca();
	bool PostojiGdeTrebaPlatiti(int svota);
	void VratiNajskuplje(ParLezaljki** min, ParLezaljki** max);
	friend ostream& operator<<(ostream& izlaz, const KaficSaPlazom& k)
	{
		izlaz << "Kapacitet: " << k.kapacitet << endl;
		izlaz << "TrenutniBr: " << k.trenutniBr << endl;
		izlaz << "Vrednost novca: " << k.vrednostNovca << endl;
		for (int i = 0; i < k.trenutniBr; i++)
		{
			izlaz << *k.niz[i] << endl;
		}
		return izlaz;
	}
};

