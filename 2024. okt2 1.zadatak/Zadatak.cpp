#include "Zadatak.h"
Zadatak::Zadatak()
	: IspitniMaterijal()
{
	brLinija = 0;
}

Zadatak::Zadatak(int id, float tezina, int brLinija)
	:IspitniMaterijal(id,tezina)
{
	this->brLinija = brLinija;
}

Zadatak::~Zadatak()
{
}

Zadatak::Zadatak(const Zadatak& p)
	: IspitniMaterijal(p)
{
	this->brLinija = p.brLinija;
}

Zadatak& Zadatak::operator=(const Zadatak& p)
{
	if (this != &p) {
		this->id = p.id;
		this->tezina = p.tezina;
		this->savladan = false;
		this->brLinija = p.brLinija;
	}
	return *this;
}

float Zadatak::vremeSavladavanja(float procenjenoVreme)
{
	return vratiBrojLinija() * vratiTezinu() * procenjenoVreme * 0.05; 
}

void Zadatak::Prikazi()
{
	IspitniMaterijal::Prikazi();
	cout << "Broj linija koda zadatka: " << vratiBrojLinija() << endl;
}