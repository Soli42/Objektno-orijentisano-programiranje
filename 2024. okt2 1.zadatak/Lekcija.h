#pragma once
#include"IspitniMaterijal.h"
class Lekcija:public IspitniMaterijal
{
private:
	float duzinaStranica;

public:
	Lekcija();
	Lekcija(int id, float tezina, float duzinaStranica);
	~Lekcija();
	float vratiDuzinuStranica() const { return duzinaStranica; }
	Lekcija(const Lekcija& p);
	Lekcija& operator=(const Lekcija& p);
	float vremeSavladavanja(float procenjenoVreme);
	void Prikazi();

	friend ostream& operator<<(ostream& izlaz, const Lekcija& l)
	{
		izlaz << "Id lekcije: " << l.vratiId() << endl;
		izlaz << "Tezina lekcije: " << l.vratiTezinu() << endl;
		izlaz << "Savladana lekcija: " << l.vratiSavladan() << endl;
		izlaz << "Broj stranica lekcije: " << l.vratiDuzinuStranica() << endl;

		return izlaz;
	}
};

