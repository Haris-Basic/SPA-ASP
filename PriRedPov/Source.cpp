#include <iostream>
#include "PRedPov.h"
#include "PRedSek.h"
#include "HeshUlancavanjem.h"
#include "HeshOtvorenoAdresiranje.h"
using namespace std;

int main()
{	
	PrioritetniRedPov PRP;
	PRP.Dodaj(Tacka2D(5, 6));
	PRP.Dodaj(Tacka2D(7, -6));
	PRP.Dodaj(Tacka2D(8, 7));
	PRP.Ispis();
	PRP.Ukloni();
	cout << "_____________________" << endl;
	PRP.Ispis();

	cout << "________________________________________________________________________" << endl;
	cout << "|______________________________________________________________________|" << endl;

	PrRedSek PRS;
	PRS.dodaj(Tacka2D(8, 2));
	PRS.dodaj(Tacka2D(3, 9));
	PRS.dodaj(Tacka2D(5, 7));
	PRS.dodaj(Tacka2D(15, 1));
	cout << "_____________________" << endl;
	PRS.Ispis();
	cout << "_____________________" << endl;
	PRS.Ukloni();
	PRS.Ispis();

	cout << "________________________________________________________________________" << endl;
	cout << "|______________________________________________________________________|" << endl;

	HesiranjeUlancavanjem HeshUl;
	HeshUl.Dodaj(Tacka3D(1, 3, 4));
	HeshUl.Dodaj(Tacka3D(2, 7, 1));
	HeshUl.Dodaj(Tacka3D(4, 8, 6));
	HeshUl.Dodaj(Tacka3D(1, 6, 3));
	HeshUl.Dodaj(Tacka3D(21, 0, 8));
	HeshUl.Ispis();
	cout << "_____________________" << endl;
	HeshUl.Ukloni(Tacka3D(1, 3, 4));

	cout << "________________________________________________________________________" << endl;
	cout << "|______________________________________________________________________|" << endl;

	HesiranjeOtvorenoAdresiranje HeshOtAd;
	HeshOtAd.Dodaj(Tacka3D(1, 5, 12));
	HeshOtAd.Dodaj(Tacka3D(9, 8, 1));
	HeshOtAd.Dodaj(Tacka3D(3, 4, 6));
	HeshOtAd.Dodaj(Tacka3D(10, 2, 17));
	HeshOtAd.Ispis();
	cout << "_____________________" << endl;
	HeshOtAd.Ukloni(Tacka3D(3, 4, 6));
	HeshOtAd.Ispis();

	cout << "________________________________________________________________________" << endl;
	cout << "|______________________________________________________________________|" << endl;

	return 0;
}