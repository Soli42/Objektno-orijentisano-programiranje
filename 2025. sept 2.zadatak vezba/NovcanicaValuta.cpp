#include "NovcanicaValuta.h"

NovcanicaValuta::NovcanicaValuta()
{
	kod = nullptr;
	vrednostNovcanice = 0;
	kurs = 0;
}

NovcanicaValuta::NovcanicaValuta(const char* kod, int vrednostNovcanica, float kurs)
{
	this->kod = new char[strlen(kod) + 1];
	strcpy(this->kod, kod);
	this->vrednostNovcanice = vrednostNovcanice;
	this->kurs = kurs;
}

NovcanicaValuta::~NovcanicaValuta()
{
	if (kod != nullptr)
	{
		delete[] kod;
	}
}

NovcanicaValuta::NovcanicaValuta(const NovcanicaValuta& p)
{
	this->kod = new char[strlen(p.kod) + 1];
	strcpy(this->kod, p.kod);
	this->vrednostNovcanice =p. vrednostNovcanice;
	this->kurs = p.kurs;
}

NovcanicaValuta& NovcanicaValuta::operator=(const NovcanicaValuta& p)
{
	if (this != &p)
	{
		this->kod = new char[strlen(p.kod) + 1];
		strcpy(this->kod, p.kod);
		this->vrednostNovcanice = p.vrednostNovcanice;
		this->kurs = p.kurs;
	}
	return *this;
}

bool NovcanicaValuta::operator<(const NovcanicaValuta& e)
{
	if (vratiVrednostDin() < e.vratiVrednostDin())
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool NovcanicaValuta::operator>(const NovcanicaValuta& e1)
{
	if (vratiVrednostDin() > e1.vratiVrednostDin())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool NovcanicaValuta::operator==(const NovcanicaValuta& e2)
{
	if (vratiVrednostDin() == e2.vratiVrednostDin())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool NovcanicaValuta::operator!=(const NovcanicaValuta& e3)
{
	if (vratiVrednostDin() != e3.vratiVrednostDin())
	{
		return true;
	}
	else
	{
		return false;
	}
}
