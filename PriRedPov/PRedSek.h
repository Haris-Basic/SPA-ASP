#pragma once
#include<iostream>
#include<exception>
#include<cmath>
#include "Tacka2D.h"
using namespace std;

struct PrRedSek
{
	int max = 5;
	int brojac = 0;
	Tacka2D* N = new Tacka2D[max];

	int udaljenost(Tacka2D& t) // racunanje udaljenosti
	{
		return (int)sqrt(pow(5 - t.x, 2) + pow(5 - t.y, 2)); // forumula se dobije na ispitu
	}

	void dodaj(const Tacka2D& t) {
		if (JelPun())
		{
			cout << "Red je pun" << endl; return;
		}
		N[brojac++] = t;
	}
	void Ukloni()
	{
		if (JelPrazan())
		{
			cout << "Greska-> Red je prazan" << endl; return;
		}
		int nI = 0;
		int nV = udaljenost(N[0]); // udaljenost prve tacke

		for (int i = 1; i < brojac; i++) // prolazi kroz cijeli red
		{
			if (udaljenost(N[i]) < nV) // kada nadje tacku sa najmanjom udaljenosti
			{
				nI = i; // biljezi poziciju te tacke u "nI"
				nV = udaljenost(N[i]); // sprema udaljenost te tacke u "nV"
			}
		}
		brojac--;
		N[nI] = N[brojac]; // na mjesto gdje je bila tacka sa najmanjom udaljenoscu, postavlja zadnju tacku
	}
	bool JelPrazan() { return brojac == 0; }

	bool JelPun() { return brojac == max; }

	void Ispis()
	{
		for (int i = 0; i < brojac; i++)
		{
			N[i].Ispis(); // Prvo ispise tacku
			cout << "-> udaljenost je " << udaljenost(N[i]) << endl;
		}
	}

};
