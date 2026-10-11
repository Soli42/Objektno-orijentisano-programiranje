#pragma once
#include<iostream>
using namespace std;
#include<cstring>

class Sokovi
{
	private:
		char* ukus;
		float zapremina;
		int procenat;
	public:
		Sokovi();
		Sokovi(const char* ukus, float zapremina, int procenat);
		~Sokovi();
		Sokovi(const Sokovi& s);
		Sokovi& operator=(const Sokovi& s);

		const char* vratiUkus() const { return ukus; }
		float vratiZap() const { return zapremina; }
		int vratiProc() const { return procenat; }

	bool operator<(const Sokovi& s);
	bool operator>(const Sokovi& s);
	bool operator==(const Sokovi& s);
	bool operator!=(const Sokovi& s);

	void setujUkus(const char* noviUkus)
	{
		this->ukus = new char[strlen(noviUkus) + 1];
		strcpy(this->ukus, noviUkus);
	}

	friend ostream& operator<<(ostream& izlaz, const Sokovi& s)
	{
		izlaz << s.vratiUkus() << " " << s.vratiZap() << " " << s.vratiProc() << endl;
		return izlaz;
	}
	friend istream& operator>>(istream& ulaz, Sokovi& s)
	{
		char* pom = new char[20]; //pomocna promenljiva za ucitavanje ukusa, jer puca program u vecini slucajeva kada navedemo direktno privatni atribut tipa char*
		ulaz >> pom >> s.zapremina >> s.procenat;
		s.setujUkus(pom);
		delete[] pom;
		return ulaz;
	}

	operator float()
	{
		return vratiZap();
	}
};

