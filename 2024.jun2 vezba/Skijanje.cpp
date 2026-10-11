#include "Skijanje.h"
Skijanje::Skijanje()
{
	duzinaSkija = 0;
	masaSkija = 0;
	masaPancerica = 0;
}

Skijanje::Skijanje(const char* ime, const char* sifraSedista, int duzinaSkija, int masaSkija, int masaPancerica)
	: Putnik(ime, sifraSedista)
{
	this->duzinaSkija = duzinaSkija;
	this->masaSkija = masaSkija;
	this->masaPancerica = masaPancerica;
}

Skijanje::~Skijanje()
{
}

Skijanje::Skijanje(const Skijanje& p)
	: Putnik(p)
{
	this->duzinaSkija = p.duzinaSkija;
	this->masaSkija = p.masaSkija;
	this->masaPancerica = p.masaPancerica;
}

Skijanje& Skijanje::operator=(const Skijanje& p)
{
	if (this != &p)
	{
		this->ime = new char[strlen(p.ime) + 1];
		strcpy(this->ime, p.ime);
		this->sifraSedista = new char[strlen(p.sifraSedista) + 1];
		strcpy(this->sifraSedista, p.sifraSedista);
		this->duzinaSkija = duzinaSkija;
		this->masaSkija = masaSkija;
		this->masaPancerica = masaPancerica;
	}
	return *this;
}
void Skijanje::Print()
{
	Putnik::Print();
	cout << "Duzina skija: " << vratiDuzinuSkija() << endl;
	cout << "Masa skija: " << vratiMasuSkija() << endl;
	cout << "Masa pancerica: " << vratiMasuPancerica() << endl;

}
float Skijanje::masaOpreme()
{
	return vratiMasuSkija() + vratiMasuPancerica();
}
Putnik* Skijanje::kopiraj() const
{
	return new Skijanje(*this);
}