#pragma once
#include<iostream>
using namespace std;
#include<cstring>
class LekcijaNormalna
{
private:
	char* naziv;
	float duzina;
	float procTezina;
public:
	LekcijaNormalna();
	LekcijaNormalna(const char* naziv, float procTezina, float duzina);
	~LekcijaNormalna();
	LekcijaNormalna(const LekcijaNormalna& l);
	LekcijaNormalna& operator=(const LekcijaNormalna& l);

	const char* vratiNaziv() const { return naziv; }
	float vratiDuzinu() const { return duzina; }
	float vratiProcTezinu() const { return procTezina; }

	bool operator<(const LekcijaNormalna& l);
	bool operator>(const LekcijaNormalna& l);

	float vratiTezinu() const { return vratiDuzinu() * vratiProcTezinu(); }
	operator float()
	{
		return vratiTezinu();
	}
	friend ostream& operator<<(ostream& izlaz, const LekcijaNormalna& l)
	{
		izlaz << l.vratiNaziv() << " " << l.vratiProcTezinu() << " " << l.vratiDuzinu();
		return izlaz;
	}

	friend istream& operator>>(istream& ulaz, LekcijaNormalna& l)
	{
		char* pom = new char[20];
		ulaz >> pom >> l.procTezina >> l.duzina;
		l.naziv = new char[strlen(pom) + 1];
		strcpy(l.naziv, pom);
		delete pom;
		return ulaz;
	}
};

