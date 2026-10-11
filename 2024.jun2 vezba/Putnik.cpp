#include "Putnik.h"
#include "Sankanje.h"

Putnik::Putnik()
{
	ime = nullptr;
	sifraSedista = nullptr;
    
}

Putnik::Putnik(const char* ime, const char* sifraSedista)
{
	this->ime = new char[strlen(ime) + 1];
	strcpy(this->ime, ime);
	this->sifraSedista = new char[strlen(sifraSedista) + 1];
	strcpy(this->sifraSedista, sifraSedista);
}

Putnik::~Putnik()
{
	if (ime != nullptr)
	{
		delete[] ime;
	}
	if (sifraSedista != nullptr)
	{
		delete[] sifraSedista;
	}
}

Putnik::Putnik(const Putnik& k)
{
	this->ime = new char[strlen(k.ime) + 1];
	strcpy(this->ime, k.ime);
	this->sifraSedista = new char[strlen(k.sifraSedista) + 1];
	strcpy(this->sifraSedista, k.sifraSedista);
}

Putnik& Putnik::operator=(const Putnik& p)
{
	if(this != &p)
	{
		this->ime = new char[strlen(p.ime) + 1];
		strcpy(this->ime, p.ime);
		this->sifraSedista = new char[strlen(p.ime) + 1];
		strcpy(this->sifraSedista, p.sifraSedista);
	}
	return *this;
}



void Putnik::Print()
{
	cout << "Ime putnika: " << vratiIme() << endl;
	cout << "Sifra sedista putnika: " << vratiSifruSedista() << endl;
}
	
