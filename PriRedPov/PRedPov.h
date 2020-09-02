#pragma once
#include <iostream>
#include "Tacka2D.h"
using namespace std;


struct cvor
{
	Tacka2D info;
	cvor* next;

	cvor(Tacka2D info = 0, cvor* next = nullptr)
	{
		this->info = info;
		this->next = next;
	}
};

struct PrioritetniRedPov
{
	cvor* prvi = nullptr;

	int Udaljenost(Tacka2D tacka) // racunanje udaljenosti tacaka
	{
		return (int)sqrt(pow(10 - tacka.x, 2) + pow(-5 - tacka.y, 2)); // Formula za udaljenost, dobije se na ispitu
	}

	void Dodaj(Tacka2D tacka) {

		cvor* n = new cvor(tacka, nullptr);
		cvor* t = prvi;
		cvor* pt = nullptr;

		while (t != nullptr)
		{
			if (Udaljenost(t->info) > Udaljenost(tacka)) // poredi udaljenosti
			{
				break;
			}
			pt = t;
			t = t->next;
		}
		if (pt == nullptr) // ako nova tacka ima manju udaljenost od prve tacke u redu, stavlja se nova tacka na pocetak reda
			prvi = n;
		else
			pt->next = n;

		n->next = t;
	}

	void Ukloni() // Uklanja prvi elemnt, jer je na prvom mjestu reda, tacka koja ima najmanju udaljenost
	{
		cvor* t = prvi;
		prvi = prvi->next;
		delete t;
	}

	bool JelPrazan()
	{
		return prvi == nullptr;
	}

	void Ispis()
	{
		cvor* t = prvi;

		while (t != nullptr)
		{
			t->info.Ispis(); // ispise prvo tacku
			cout << "| Udaljenost: " << Udaljenost(t->info) << endl; // pa onda udaljenost
			t = t->next;
		}
		cout << endl;
	}
};