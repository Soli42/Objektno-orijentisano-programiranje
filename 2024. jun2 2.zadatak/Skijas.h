#pragma once
#include<iostream>
using namespace std;
class Skijas
{
   private:
	int masaSkija;
	int masaPancerica;
	bool kaciga;
	
   public:
	Skijas();
	Skijas(int masas, int masap, bool kac);
	~Skijas();
	Skijas(const Skijas& s);
	Skijas& operator=(const Skijas& s);

	int vratiMasuSkija() const { return masaSkija; }
	int vratiMasuPancerica() const { return masaPancerica; }
	int vratiKacigu() const { return kaciga; }

	friend ostream& operator<<(ostream& izlaz, const Skijas& s)
	{
		izlaz << "Masa skija: " << s.vratiMasuSkija() << endl;
		izlaz << "Masa pancerica: " << s.vratiMasuPancerica() << endl;
		izlaz << "Postojanje kacige: "<<s.vratiKacigu() << endl;
		return izlaz;
	}

	friend istream& operator>>(istream& ulaz, Skijas& s)
	{
		ulaz >> s.masaSkija >> s.masaPancerica >> s.kaciga;
		return ulaz;
		}

	float vratiMasuOpreme() const
	{
		return (float)vratiMasuSkija() + (float)vratiMasuPancerica();
	}

	operator float() //kada je tip T Skijas
	{
		return vratiMasuOpreme();
	}

	//operator int() //kada je tip T int
	//{
	//	vratiMasuSkija();
	//}

	bool operator<(const Skijas& s2)
	{
		if (vratiMasuOpreme() < s2.vratiMasuOpreme())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(const Skijas& s2)
	{
		if (vratiMasuOpreme()> s2.vratiMasuOpreme())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

