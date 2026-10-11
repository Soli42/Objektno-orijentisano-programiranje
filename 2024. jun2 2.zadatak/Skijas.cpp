#include "Skijas.h"



Skijas::Skijas()
{
	masaSkija = masaPancerica = kaciga = 0;
}

Skijas::Skijas(int masas, int masap, bool kac)
{
	if (masap <= 3000 && masas <= 3000 && (kac == 0 || kac == 1))
	{
		masaSkija = masas;
		masaPancerica = masap;
		kaciga = kac;
	}
	else
	{
		//masaSkija = masaPancerica = kaciga = 0;
		throw exception("Jedan od atributa ima nevalidnu vrednost!");
	}
}

Skijas::~Skijas()
{
}

Skijas::Skijas(const Skijas& s)
{
	masaSkija = s.masaSkija;
	masaPancerica = s.masaPancerica;
	kaciga = s.kaciga;
}

Skijas& Skijas::operator=(const Skijas& s)
{
	if (this != &s)
	{
		masaSkija = s.masaSkija;
		masaPancerica = s.masaPancerica;
		kaciga = s.kaciga;
	}
	return *this;
}

