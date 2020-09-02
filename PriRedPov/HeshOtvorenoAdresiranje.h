#pragma once
#include<iostream>
#include<cmath>
#include "Tacka3D.h"
using namespace std;


int h1(Tacka3D k) { return sqrt(pow((k.x + k.y + k.z), 2)); }

int h2(Tacka3D k) { return sqrt(pow(k.x, 2) / 3 + pow(k.y, 2) / 3 + pow(k.z, 2) / 3); }

struct HesiranjeOtvorenoAdresiranje
{
	int max = 10;
	Tacka3D* niz = new Tacka3D[max];
	bool* Zauzeto = new bool[max];
	int brojac = 0;

	HesiranjeOtvorenoAdresiranje()
	{
		for (int i = 0; i < max; i++)
			Zauzeto[i] = false;
	}

	int HashFunkcija(Tacka3D k, int i) { return (h1(k) + i * h2(k)) % max; }

	void Dodaj(Tacka3D k)
	{
		if (JelPun())
		{
			cout << "Greska-> Nema prostora." << endl;
			return;
		}
		int i = 0;
		int p;

		while (true)
		{
			i++;
			p = HashFunkcija(k, i);
			if (!Zauzeto[p])
				break;
		}
		niz[p] = k;
		Zauzeto[p] = true;
		brojac++;
	}

	void Ukloni(Tacka3D k)
	{
		if (JelPrazan())
		{
			cout << "Greska-> Nema elemenata." << endl;
			return;
		}
		int i = 0;
		int p;

		while (true)
		{
			i++;
			p = HashFunkcija(k, i);

			if (Zauzeto[p] && niz[p].JednakaSa(k))
			{
				Zauzeto[p] = false;
				brojac--;
				return;
			}
		}

	}

	void Ispis()
	{
		for (int i = 0; i < max; i++)
		{
			if (Zauzeto[i])
			{
				cout << i << ". ";
				niz[i].Ispis();
			}
			else
				cout << i << ". " << endl;
		}
	}

	bool JelPun() { return brojac == max; }

	bool JelPrazan() { return brojac == 0; }
};
