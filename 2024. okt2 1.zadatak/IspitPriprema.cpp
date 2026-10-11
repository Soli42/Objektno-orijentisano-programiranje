#include "IspitPriprema.h"


IspitPriprema::IspitPriprema()
{
	niz = nullptr;
	trenutni = 0;
	kapacitet = 0;
}

IspitPriprema::IspitPriprema(int kapacitet)
{
	this->kapacitet = kapacitet;
	trenutni = 0;
	niz = new IspitniMaterijal* [kapacitet];
}

IspitPriprema::~IspitPriprema()
{
	if(niz != nullptr)
	{
		for(int i = 0; i < trenutni; i++)
		{
			if(niz[i] != nullptr)
			{
				delete niz[i];
			}
		}
		delete[] niz;
	}
}

IspitPriprema::IspitPriprema(const IspitPriprema& p)
{
	this->kapacitet = kapacitet;
	trenutni = 0;
	niz = new IspitniMaterijal * [kapacitet];
	for (int i = 0; i < kapacitet; i++)
	{
		p.niz[i] = niz[i];
	}
}

IspitPriprema& IspitPriprema::operator=(const IspitPriprema& p)
{
	if (this != &p)
	{
		this->kapacitet = kapacitet;
		trenutni = 0;
		niz = new IspitniMaterijal * [kapacitet];
		for (int i = 0; i < kapacitet; i++)
		{
			p.niz[i] = niz[i];
		}
	}
	return *this;
}

void IspitPriprema::print()
{
	cout << "Kapacitet ispitne pripreme: " << kapacitet << endl;
	cout << "Trenutni broj ispitnih materijala: " << trenutni << endl;
	for (int i = 0; i < trenutni; i++)
	{
		niz[i]->Prikazi(); //cout<<niz[i] ne pisem ovde nego u operatoru<<
	}
}

void IspitPriprema::Dodaj(IspitniMaterijal* novi)
{
	if (trenutni < kapacitet)
	{
		niz[trenutni] = novi;
		trenutni++;
	}
	else
	{
		cout << "Nema mesta u aplikaciji za dodavanje novog materijala!";
	}
	
}

void IspitPriprema::Obrisi(int id)
{
	int i = 0, j;
	bool nadjen = false;
	while (i < trenutni && nadjen == false)
	{
		if (niz[i]->vratiId() == id)
		{
			j = i;
			nadjen = true;
		}
		i++;
	}
	if (nadjen == true)
	{
		if (niz[j]->vratiSavladan() == false)
		{
			for (i = j; i < trenutni - 1; i++)
			{
				niz[i] = niz[i + 1];
			}
			trenutni--;
		}
		else
		{
			cout << "Pronasli smo matrijal sa pogresnim id-jem, ali jeste savladan!";
		}
	}
	else
	{
		cout << "Ne postoji u aplikaciji materijal sa prosledjenim id-jem!";
	}
}

void IspitPriprema::Savladaj(int k)
{
	int i = 0, j;
	bool nadjen = false;
	while (i < trenutni && nadjen == false)
	{
		if (niz[i]->vratiId() == k)
		{
			j = i;
			nadjen = true;
		}
		i++;
	}
	if (nadjen == true && niz[j]->vratiSavladan()==false)
	{
		niz[j]->setStatus(true);
	}
}

int IspitPriprema::UkupnoSavladanih()
{
	int brojac = 0;
	for (int i = 0; i < trenutni; i++)
	{
		if (niz[i]->vratiSavladan() == true)
		{
			brojac++;
		}
	}
	return brojac;
}

float IspitPriprema::UkupnoVreme(float vJedinicno)
{
	float vreme = 0;
	for (int i = 0; i < trenutni; i++)
	{
		vreme = vreme + niz[i]->vremeSavladavanja(vJedinicno);
	}
	return vreme;
}

void IspitPriprema::VratiNaj(float vJedinicno, IspitniMaterijal** Min, IspitniMaterijal** Max)
{
	int indMin = 0;
	int indMax = 0;
	for (int i = 1; i < trenutni; i++)
	{
		if (niz[i]->vremeSavladavanja(vJedinicno) < niz[indMin]->vremeSavladavanja(vJedinicno))
		{	
			indMin = i;
		}
		if (niz[i]->vremeSavladavanja(vJedinicno) > niz[indMax]->vremeSavladavanja(vJedinicno))
		{
			indMax = i;
		}
	}
	*Min = niz[indMin];
	*Max = niz[indMax];	
}
