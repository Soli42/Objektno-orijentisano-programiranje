#pragma once
#include"IspitniMaterijal.h"
class Zadatak:public IspitniMaterijal
{
private:
	int brLinija;
public:
	Zadatak();
	//Zadatak(int id, float tezina, bool savladan, int brLinija);
	Zadatak(int id, float tezina, int brLinija);
	~Zadatak();
	Zadatak(const Zadatak& p);
	Zadatak& operator=(const Zadatak& p);
	int vratiBrojLinija() const { return brLinija; }
	float vremeSavladavanja(float procenjenoVreme);
	void Prikazi();

	friend ostream& operator<<(ostream& izlaz, const Zadatak& z)
	{
		izlaz << "Id zadatka: " << z.vratiId() << endl;
		izlaz << "Tezina zadatka: " << z.vratiTezinu() << endl;
		izlaz << "Savladan zadatak: " << z.vratiSavladan() << endl;
		izlaz << "Broj linija koda: " << z.vratiBrojLinija() << endl;
		return izlaz;
	}
};

