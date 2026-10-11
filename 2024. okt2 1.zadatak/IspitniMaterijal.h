#pragma once
#include<iostream>
using namespace std;
class IspitniMaterijal
{
protected:
	int id;
	double tezina;
	bool savladan;
public:
	IspitniMaterijal();
	//IspitniMaterijal(int id, double tezina, bool savladan);
	IspitniMaterijal(int id, double tezina);
	IspitniMaterijal(const IspitniMaterijal& p);
	IspitniMaterijal& operator=(const IspitniMaterijal& p);
	virtual ~IspitniMaterijal();
	int vratiId() const { return id; }
	double vratiTezinu() const { return tezina; }
	bool vratiSavladan() const { return savladan; }
	void setStatus(bool sav) { savladan = sav; }
	virtual float vremeSavladavanja(float procenjenoVreme) = 0;
	virtual void Prikazi();

	friend ostream& operator<<(ostream& izlaz, const IspitniMaterijal& is)
	{
		izlaz << "Id materijala: " << is.vratiId() << endl;
		izlaz << "Tezina materijala: " << is.vratiTezinu() << endl;
		izlaz << "Savladan materija;: " << is.vratiSavladan() << endl;
		return izlaz;
	}	
};

