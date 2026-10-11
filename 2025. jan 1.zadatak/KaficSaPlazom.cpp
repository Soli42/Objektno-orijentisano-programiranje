#include "KaficSaPlazom.h"

KaficSaPlazom::KaficSaPlazom()
{
	niz = nullptr;
	trenutniBr = 0;
	kapacitet = 0;
	vrednostNovca = 0;
}

KaficSaPlazom::KaficSaPlazom(int kapacitet)
{
	this->kapacitet = kapacitet;
	this->trenutniBr = 0;
	this->vrednostNovca = 0;
	niz = new ParLezaljki * [kapacitet];
}

KaficSaPlazom::~KaficSaPlazom()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < trenutniBr; i++)
		{
			if (niz[i] != nullptr)
			{
				delete niz[i];
			}
		}
		delete[] niz;
	}
}

KaficSaPlazom::KaficSaPlazom(const KaficSaPlazom& p)
{
	this->kapacitet = p.kapacitet;
	this->trenutniBr = p.trenutniBr;
	this->vrednostNovca = p.vrednostNovca;
	niz = new ParLezaljki * [p.kapacitet];
	for (int i = 0; i < p.trenutniBr; i++)
	{
		niz[i] = p.niz[i];
	}
}

KaficSaPlazom& KaficSaPlazom::operator=(const KaficSaPlazom& p)
{
	if (this != &p)
	{
		this->kapacitet = p.kapacitet;
		this->trenutniBr = p.trenutniBr;
		this->vrednostNovca = p.vrednostNovca;
		niz = new ParLezaljki * [p.kapacitet];
		for (int i = 0; i < p.trenutniBr; i++)
		{
			niz[i] = p.niz[i];
		}
	}
	return *this;
}

void KaficSaPlazom::Dodaj(ParLezaljki* p)
{
	if (trenutniBr < kapacitet)
	{
		niz[trenutniBr] = p;
		trenutniBr++;
		
	}
	else
	{
		cout << "Nije moguce dodavanje" << endl;
	}
}

void KaficSaPlazom::Oslobodi(int oznaka)
{
	if (oznaka > 0 && oznaka <= trenutniBr)
	{
		vrednostNovca = vrednostNovca + niz[oznaka-1]->svotaZaNaplatu();
		for (int i = oznaka - 1; i < trenutniBr - 1; i++)
		{
			niz[i] = niz[i + 1];
		}
		trenutniBr--;
		
	}
	else
	{
		cout << "Nevalidan redni broj" << endl;
	}
}

int KaficSaPlazom::UkupnoLezaljki()
{
	int suma = 0;
	for (int i = 0; i < trenutniBr; i++)
	{
		suma += niz[i]->brLezaljki();
	}
	return suma;
	
}

int KaficSaPlazom::UkupnaSvotaNovca()
{
	int suma = 0;
	for (int i = 0; i < trenutniBr; i++)
	{
		suma += niz[i]->brLezaljki() * niz[i]->svotaZaNaplatu();
	}
	return suma;
}

bool KaficSaPlazom::PostojiGdeTrebaPlatiti(int svota)
{
	for (int i = 0; i < trenutniBr; i++)
	{
		if (niz[i]->brLezaljki() * niz[i]->svotaZaNaplatu() > svota)
		{
			return true;
		}
	}
	return false;

}

void KaficSaPlazom::VratiNajskuplje(ParLezaljki** min, ParLezaljki** max)
{
	*min = niz[0];
	*max = niz[0];
	for (int i = 1; i < trenutniBr; i++)
	{
		if (niz[i]->vratiCenuPica() > (*max)->vratiCenuPica())
		{
			*max = niz[i];
		}
		if (niz[i]->brLezaljki() * niz[i]->svotaZaNaplatu() > (*min)->brLezaljki() * (*min)->svotaZaNaplatu())
		{
			*min = niz[i];
		}
	}
}
