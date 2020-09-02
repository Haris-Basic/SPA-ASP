#pragma once
#include<iostream>
#include<cmath>
#include "Tacka3D.h"
using namespace std;

struct Cvor
{
	Tacka3D info;
	Cvor* next;

	Cvor(Tacka3D info = 0, Cvor* next = nullptr)
	{
		this->info = info;
		this->next = next;
	}
};

struct ListaPov
{
	Cvor* prvi = nullptr;

	void DodajNaPocetak(Tacka3D e)
	{
		if (Prazno())
		{
			prvi = new Cvor(e, nullptr);
			return;
		}
		Cvor* n = new Cvor(e, prvi);
		prvi = n;
	}
	void DodajNaKraj(Tacka3D e)
	{
		if (prvi == nullptr)
		{
			prvi = new Cvor(e, nullptr);
			return;
		}

		Cvor* t = prvi;
		while (t->next != nullptr)
		{
			t = t->next;
		}
		t->next = new Cvor(e, nullptr);

	}
	void UkloniSaPocetka()
	{
		if (Prazno()) { cout << "Greska-> Nema elemenata." << endl; return; }
		Cvor* t = prvi;
		prvi = prvi->next;
		delete t;
	}
	void UkloniSaKraja()
	{
		if (Prazno()) { cout << "Greska-> Nema elemenata." << endl; return; }

		Cvor* t = prvi;
		Cvor* pt = nullptr;
		while (t->next != nullptr)
		{
			pt = t;
			t = t->next;
		}

		if (pt == nullptr) {
			prvi = pt;
		}
		else
			pt->next = nullptr;
	}
	void UkloniByKey(Tacka3D kljuc)
	{
		if (prvi == nullptr)
		{
			cout << endl << "Greska-> tacka: "; kljuc.Ispis(); cout << " nije pronadjena" << endl;
			return;
		}
		Cvor* t = prvi;
		Cvor* pt = nullptr;
		while (t->next != nullptr)
		{
			if (kljuc.JednakaSa(t->info))
				break;
			pt = t;
			t = t->next;
		}
		if (pt != nullptr)
		{
			pt->next = t->next;
		}
		if (pt == nullptr)
		{
			prvi = t->next;
		}
		delete t;
	}
	bool PretraziByKey(Tacka3D kljuc)
	{
		Cvor* t = prvi;
		Cvor* pt = nullptr;
		while (t->next != nullptr)
		{
			if (kljuc.JednakaSa(t->info))
				return true;
			pt = t;
			t = t->next;
		}
		return false;
	}
	void Ispis(int triger = 0)
	{
		Cvor* t = prvi;
		while (t != nullptr)
		{
			t->info.Ispis();
			t = t->next;
		}
		cout << endl;
	}
	bool Prazno() { return prvi == nullptr; }
};

int h(Tacka3D t) { return sqrt(pow(t.x + t.y + t.z, 2) / 3); }

struct HesiranjeUlancavanjem
{
	int max = 10;
	ListaPov* niz = new ListaPov[max];

	int HashFunkcija(Tacka3D t) { return h(t) % max; }

	void Dodaj(Tacka3D t)
	{
		int p = HashFunkcija(t);
		niz[p].DodajNaPocetak(t);
	}
	void Ukloni(Tacka3D t)
	{
		int p = HashFunkcija(t);
		niz[p].UkloniByKey(t);
	}
	void Ispis()
	{
		for (int i = 0; i < max; i++)
		{
			cout << "Lista " << i << ": ";
			niz[i].Ispis();
		}
	}
};