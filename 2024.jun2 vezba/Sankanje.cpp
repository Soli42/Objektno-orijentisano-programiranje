#include "Sankanje.h"
#include "Skijanje.h"

Sankanje::Sankanje()
{
	zapremina = 0;
	gustinaSkija = 0;
}

Sankanje::Sankanje(const char* ime, const char* sifraSedista, int zapremina, double gustinaSedista)
	: Putnik(ime, sifraSedista)
{
	this->zapremina = zapremina;
	this->gustinaSkija = gustinaSkija;
}

Sankanje::~Sankanje()
{
}

Sankanje::Sankanje(const Sankanje& p)
	: Putnik(p)
{
	this->zapremina = p.zapremina;
	this->gustinaSkija = p.gustinaSkija;
}

Sankanje& Sankanje::operator=(const Sankanje& p)
{
	if(this != &p)
	{
		this->ime = new char[strlen(this->ime) + 1];
		strcpy(this->ime, p.ime);
		this->sifraSedista = new char[strlen(this->sifraSedista) + 1];
		strcpy(this->sifraSedista, p.sifraSedista);
		this->zapremina = p.zapremina;
		this->gustinaSkija = p.gustinaSkija;
	}
	return *this;
}
void Sankanje::Print()
{
	Putnik::Print();
	cout << "Zapremina: " << vratiZapreminu() << endl;
	cout << "Gustina skija: " << vratiGustinuSkija() << endl;

}




float Sankanje::masaOpreme()
{
	return vratiGustinuSkija() * vratiZapreminu();
}

Putnik* Sankanje::kopiraj() const
{
	return new Sankanje(*this);
}
