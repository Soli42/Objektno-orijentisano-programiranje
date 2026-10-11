#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class NovcanicaValuta
{
private:
	 char* kod;
	 int vrednostNovcanice;
	 float kurs;
public:
	NovcanicaValuta();
	NovcanicaValuta(const char* kod, int vrednostNovcanica, float kurs);
	~NovcanicaValuta();
	NovcanicaValuta(const NovcanicaValuta& p);
	NovcanicaValuta& operator=(const NovcanicaValuta& p);
	void Prikazi();
	const char* vratiKod() const { return kod; }
	int vratiVrednostNovcanice() const { return vrednostNovcanice; }
	float vratiKurs() const { return kurs; }
	void setujKod(const char* noviKod)
	{
		this->kod = new char[strlen(noviKod) + 1];
		strcpy(this->kod, noviKod);
	}
	friend ostream& operator<<(ostream& izlaz, const NovcanicaValuta& s)
	{
		izlaz << s.vratiKod() << " " << s.vratiVrednostNovcanice() << " " << s.vratiKurs() << endl;
		return izlaz;
	}
	friend istream& operator>>(istream& ulaz, NovcanicaValuta& s)
	{
		char* pom = new char[20]; // pomocni niz za ucitavanje
		ulaz >> pom >> s.vrednostNovcanice >> s.kurs;
		s.setujKod(pom);
		delete[] pom;
		return ulaz;
	}
	bool operator<(const NovcanicaValuta& e);
	bool operator>(const NovcanicaValuta& e1);
	bool operator==(const NovcanicaValuta& e2);
	bool operator!=(const NovcanicaValuta& e3);
	float vratiVrednostDin() const { return vratiKurs() * vratiVrednostNovcanice(); }
	operator float()
	{
		return vratiVrednostDin();
	}

};

