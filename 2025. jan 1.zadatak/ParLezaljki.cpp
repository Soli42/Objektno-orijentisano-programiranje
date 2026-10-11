#include "ParLezaljki.h"
#include "ParLezaljkiSaDodatkom.h"

ParLezaljki::ParLezaljki()
{
	redniBr = red = cenaLez = cenaPica = 0;
}

ParLezaljki::ParLezaljki(int redniBr, int red, int cenaLez, int cenaPica)
{
	this->redniBr = redniBr;
	this->red = red;
	this->cenaLez = cenaLez;
	this->cenaPica = cenaPica;
}

ParLezaljki::~ParLezaljki()
{
}
ParLezaljki::ParLezaljki(const ParLezaljki& p)
{
	this->redniBr = p.redniBr;
	this->red = p.red;
	this->cenaLez = p.cenaLez;
	this->cenaPica = p.cenaPica;
}
ParLezaljki& ParLezaljki::operator=(const ParLezaljki& p)
{
	if (this != &p)
	{
		this->redniBr = p.redniBr;
		this->red = p.red;
		this->cenaLez = p.cenaLez;
		this->cenaPica = p.cenaPica;

	}
	return *this;
}
int ParLezaljki :: brLezaljki()
{
	return 2;
}
void ParLezaljki::Prikazi()
{
	cout << "Redni broj lezaljke: " << vratiRedni() << endl;
	cout << "Red u kome se lezaljka nalazi: " << vratiRed() << endl;
	cout << "Cena lezaljke: " << vratiCenuLez() << endl;
	cout << "Cena pica: " << vratiCenuPica() << endl;
}
//цену лежаљки дода цена напитака умањена за (40-2∙br)%, где је br ред у ком се лежаљке налазе.
int ParLezaljki::svotaZaNaplatu()
{
	int svota = vratiCenuLez() + ((100 - (40 - 2 * vratiRed()))/100) * vratiCenuPica();
	return svota;
	//cenaPica 100%
	// -(40-2*br)%
}
