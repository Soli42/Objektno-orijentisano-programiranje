#include "IspitniMaterijal.h"
#include "Zadatak.h"

IspitniMaterijal::IspitniMaterijal()
{
	id = 0;
	tezina = 0.0;
	savladan = false;
}
//
//IspitniMaterijal::IspitniMaterijal(int id, double tezina, bool savladan)
//{
//	this->id = id;
//	this->tezina = tezina;
//	this->savladan = savladan;
//}

IspitniMaterijal::IspitniMaterijal(int id, double tezina)
{
	this->id = id;
	this->tezina = tezina;
	this->savladan = false;
}

IspitniMaterijal::IspitniMaterijal(const IspitniMaterijal& p)
{
	this->id = p.id;
	this->tezina = p.tezina;
	this->savladan = false;
}

IspitniMaterijal& IspitniMaterijal::operator=(const IspitniMaterijal& p)
{
	if (this != &p)
	{
		this->id = p.id;
		this->tezina = p.tezina;
		this->savladan = false;
	}
	return *this;
}

IspitniMaterijal::~IspitniMaterijal()
{
}



void IspitniMaterijal::Prikazi()
{
	cout << "Id materijala: " << id << endl;
	cout << "Tezina materijala: "<< tezina << endl;
	cout << "Savladan materijal: " << savladan << endl;
}
