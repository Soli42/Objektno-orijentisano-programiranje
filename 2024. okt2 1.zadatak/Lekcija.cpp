#include "Lekcija.h"

Lekcija::Lekcija()
	:IspitniMaterijal()
{
	duzinaStranica = 0;
}

Lekcija::Lekcija(int id, float tezina, float duzinaStranica)
	:IspitniMaterijal(id,tezina)
{
	this->duzinaStranica = duzinaStranica;
}

Lekcija::~Lekcija()

{

}

Lekcija::Lekcija(const Lekcija& p)
	: IspitniMaterijal(p)
{
	this->duzinaStranica = p.duzinaStranica;
}

Lekcija& Lekcija::operator=(const Lekcija& p)
{
	if (this != &p) {
		this->id = p.id;
		this->tezina = p.tezina;
		this->savladan = false;
		this->duzinaStranica = p.duzinaStranica;
	}
	return *this;
}

float Lekcija::vremeSavladavanja(float procenjenoVreme)
{
	return vratiDuzinuStranica() * vratiTezinu() * procenjenoVreme;
}

void Lekcija::Prikazi()
{
	IspitniMaterijal::Prikazi();
	cout << "Duzina stranica lekcije: " << vratiDuzinuStranica() << endl;
}