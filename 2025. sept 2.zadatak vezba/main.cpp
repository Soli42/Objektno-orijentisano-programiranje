#include <iostream>
#include <fstream>
#include "NovcanicaValuta.h"
#include "Novcanik.h"
#include <cstring>
using namespace std;



void main()
{
	int maxPodataka = 8, brojPodataka = 7;
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	try
	{
		int dinari[] = { 100, 20, 50, 100, 50, 20, 20 };
		Novcanik<int> nov(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			nov.Dodaj(dinari[i]);
		cout << nov << endl; //nov.Ispisi(cout);
		// 1 bod
		nov.Izbaci(dinari[1]);
		cout << nov << endl; //nov.Ispisi(cout);
		// 1 bod
		float ukupno = nov.Ukupno();
		cout << ukupno << endl; // 340
		// 1 bod
		int vrednost = 100; float ukupnaVrednost = 0;
		int broj = nov.UkupniBrojVrednost(vrednost, &ukupnaVrednost);
		cout << broj << " " << ukupnaVrednost << endl; // 2 200
		// 1 bod
		int najmanjeNovcanica = nov.NajmanjeNovcanica(280);
		cout << najmanjeNovcanica << endl; // 4
		// 1 bod
		nov.Sacuvaj("NovDin.txt");
		// 1 boda
		Novcanik<int> novUcitan(maxPodataka);
		novUcitan.Ucitaj("NovDin.txt");
		cout << novUcitan << endl; //novUcitan.Ispisi(cout);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	//{
	//	char oz[][4] = { "RSD", "EUR", "RSD", "RSD", "RSD", "EUR", "RSD" };
	//	int vred[] = { 100, 20, 50, 100, 50, 20, 20 };
	//	float kurs[] = { 1, 117.2f, 1, 1, 1, 117.2f, 1 };
	//	Novcanik<NovcanicaValuta> novVal(maxPodataka);
	//	// 1 bod
	//	for (int i = 0; i < brojPodataka; i++) {
	//		novVal.Dodaj(NovcanicaValuta(oz[i], vred[i], kurs[i]));
	//	}
	//	// 1 bod
	//	cout << novVal << endl; //novVal.Ispisi(cout);
	//	// 1 bodova
	//	novVal.Izbaci(NovcanicaValuta(oz[1], vred[1], kurs[1]));
	//	cout << novVal << endl; //novVal.Ispisi(cout);
	//	// 2 bod
	//	float ukupno = novVal.Ukupno();
	//	cout << ukupno << endl; // 2664
	//	// 2 bod
	//	NovcanicaValuta vr(oz[0], vred[0], kurs[0]);
	//	float ukupnaVrednost = 0;
	//	int broj = novVal.UkupniBrojVrednost(vr, &ukupnaVrednost);
	//	cout << broj << " " << ukupnaVrednost << endl; // 2 200
	//	// 2 bod
	//	int najmanjeNovcanica = novVal.NajmanjeNovcanica(2500);
	//	cout << najmanjeNovcanica << endl; // 3
	//	// 0 bod
	//	novVal.Sacuvaj("NovVal.txt");
	//	// 1 bod
	//	Novcanik<NovcanicaValuta> novValUc(maxPodataka);
	//	novValUc.Ucitaj("NovVal.txt");
	//	cout << novValUc << endl; //novValUc.Ispisi(cout);
	//}
}
