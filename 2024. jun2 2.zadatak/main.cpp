#include "Skijas.h"
#include "Kombi.h"


void main()
{
	try
	{


		Kombi<Skijas> k1(4);
		for (int i = 1; i < 5; i++)
		{
			k1.Dodaj(Skijas(i * 500, i * 300, i % 2));
		}
		k1.Dodaj(Skijas(4000, 3500, 0));
		//1 poen
		//k1.print();
		cout << k1 << endl;
		//2 poena
		cout << k1.UkupnaMasaOpreme() << endl;
		//2 poena
		Skijas s = k1.MinOprema();
		cout << s << endl;
		//1 poen
		k1.Izbaci(6);
		for (int i = 0; i < 4; i++)
		{
			k1.Izbaci(i);
		}
		//2 poena
		k1.Ucitaj("skijasi.txt");
		//k1.print();
		cout << k1 << endl;
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	try
	{
		//2 poena
		Kombi<int> k2(4);
		for (int i = 1; i < 5; i++)
		{
			k2.Dodaj(i * 500);
		}
		k2.Dodaj(3000);
		//1 poen
		//k2.print();
		cout << k2 << endl;
		//1 poen
		cout << k2.UkupnaMasaOpreme() << endl;
		//1 poen
		cout << k2.MinOprema() << endl;
		//1 poen
		k2.Izbaci(6);
		for (int i = 0; i < 4; i++)
		{
			k2.Izbaci(i);
		}
		//1 poen
		k2.Ucitaj("sankanje.txt");
		//k2.print();
		cout << k2 << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}