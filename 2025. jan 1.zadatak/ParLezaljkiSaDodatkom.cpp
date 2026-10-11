#include "ParLezaljkiSaDodatkom.h"
ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom()
	:ParLezaljki()
{
	brDodatnihLez = 0;
}

ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom(int redniBr, int red, int cenaLez, int cenaPica, int brDodatnihLez)
	:ParLezaljki(redniBr,red,cenaLez,cenaPica)
{
	this->brDodatnihLez = brDodatnihLez;
}

ParLezaljkiSaDodatkom::~ParLezaljkiSaDodatkom()
{
}

ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom(const ParLezaljkiSaDodatkom& p)
	: ParLezaljki(p)
{
	this->brDodatnihLez = p.brDodatnihLez;
}

int ParLezaljkiSaDodatkom::brLezaljki()
{
	return 2 + vratiBrDodatnih();
}

ParLezaljkiSaDodatkom& ParLezaljkiSaDodatkom::operator=(const ParLezaljkiSaDodatkom& p)
{
	if (this != &p)
	{
		this->redniBr = p.redniBr;
		this->red = p.red;
		this->cenaLez = p.cenaLez;
		this->cenaPica = p.cenaPica;
		this->brDodatnihLez = p.brDodatnihLez;
	}
	return *this;
}

void ParLezaljkiSaDodatkom::Prikazi()
{
	ParLezaljki::Prikazi();
	cout << "Broj dodatnih lezaljki: " << vratiBrDodatnih() << endl;
}
//на цену лежаљки увећану (1+0.4∙bdl) пута дода цена напитака умањена за (40-2∙br-5∙bdl)%,
// где је br ред у ком се лежаљке налазе и bdl број додатних лежаљки.
int ParLezaljkiSaDodatkom::svotaZaNaplatu()
{
	int uvecanaCena = vratiCenuLez() * (1 + 0.4 * vratiBrDodatnih());
	int umanjenaCenaNapitka = ((100 - (40 - 2 * vratiRed() - 5 * vratiBrDodatnih())) / 100) * vratiCenuPica();
	return uvecanaCena + umanjenaCenaNapitka;
}
