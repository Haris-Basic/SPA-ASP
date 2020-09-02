#pragma once
#include<iostream>
using namespace std;

struct Tacka3D
{
	int x;
	int y;
	int z;

	Tacka3D(int xx = 0, int yy = 0, int zz = 0) :x(xx), y(yy), z(zz) {}

	void Ispis() { cout << " t(" << x << "," << y << "," << z << ") |"; }

	bool JednakaSa(Tacka3D t)
	{
		if (x == t.x && y == t.y && z == t.z)
			return true;
		else
			return false;
	}
};