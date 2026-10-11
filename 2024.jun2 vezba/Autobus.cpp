#include "Autobus.h"

Autobus::Autobus()
{
	niz = nullptr;
	trenutni = 0;
	kapacitet = 0;
}

Autobus::Autobus(int kapacitet)
{
	trenutni = 0;
	this->kapacitet = kapacitet;
	niz = new Putnik * [kapacitet];
}

Autobus::~Autobus()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < kapacitet; i++)
		{
			if (niz[i] != nullptr)
			{
				delete niz[i];
			}
		}
		delete[] niz;
	}
}

Autobus::Autobus(const Autobus& p)
{
	this->trenutni = p.trenutni;
	this->kapacitet = p.kapacitet;
	niz = new Putnik * [kapacitet];
	for (int i = 0; i < kapacitet; i++)
	{
		this->niz[i] = p.niz[i];
	}
}

Autobus& Autobus::operator=(const Autobus& p)
{
	if (this != &p)
	{
		this->trenutni = p.trenutni;
		this->kapacitet = p.kapacitet;
		niz = new Putnik * [kapacitet];
		for (int i = 0; i < kapacitet; i++)
		{
			this->niz[i] = p.niz[i];
		}
	}
	return *this;
}

int Autobus::BrojPutnika() const
{
	return kapacitet;
}

void Autobus::Dodaj(Putnik* p)
{
	if (trenutni < kapacitet)
	{
		bool nadjen = false;
		int i = 0;
		while (i < trenutni && nadjen == false)
		{
			if (strcmp(niz[i]->vratiSifruSedista(), p->vratiSifruSedista()) == 0)
			{
				nadjen = true;

			}
			else
			{
				i++;
			}
		}
		if (nadjen == true)
		{
			cout << "Nije moguce dodavanje zato sto postoje iste sifre" << endl;
		}
		else
		{
			niz[trenutni] = p;
			trenutni++;
		}

	}
	else
	{
		cout << "Autobus je pun, nema mesta za dodavanje" << endl;
	}

}

Autobus Autobus::operator+(Autobus& a2)
{
	Autobus* a3 = new Autobus(BrojPutnika() + a2.BrojPutnika());
	for (int i = 0; i < trenutni; i++)
	{
		a3->Dodaj(niz[i]->kopiraj());
	}
	for (int i = 0; i < trenutni; i++)
	{
		a3->Dodaj(a2.niz[i]->kopiraj());
	}
	return *a3;

}

Putnik* Autobus::MaxOprema()
{
	Putnik* max = niz[0];
	int imax = 0;
	for (int i = 1; i < trenutni; i++)
	{
		if (niz[i]->masaOpreme() > max->masaOpreme())
		{
			imax = i;
			max = niz[i];
		}
	}
	for (int i = imax; i < trenutni - 1; i++)
	{
		niz[i] = niz[i + 1];
	}
	trenutni--;
	return max;
}

float Autobus::UkupnaOprema()
{
	float suma = 0;
	for (int i = 0; i < trenutni; i++)
	{
		suma = suma + niz[i]->masaOpreme();

	}
	return suma;
}

void Autobus::Upisi(const char* imeFajla)
{
	ofstream fajl(imeFajla);
	if (!fajl.good())
	{
		cout << "Fajl nije dobar";
	}
	fajl << trenutni << endl;
	for (int i = 0; i < trenutni; i++)
	{
		fajl << *niz[i] << endl;

	}
	fajl.close();
}
void Autobus::Print()
{
	cout << "Kapacitet autobusa: " << BrojPutnika() << endl;
	cout << "Trenutni broj putnika: " << trenutni << endl;
	cout << "Lista putnika: " << endl;
	for (int i = 0; i < trenutni; i++)
	{
		niz[i]->Print();
	}
}