#pragma once
#include<iostream>
using namespace std;
struct Tacka2D
{
	int x, y;

	Tacka2D(int xx = 0, int yy = 0) :x(xx), y(yy) {}

	void Ispis()
	{
		cout << "(" << x << ":" << y << ")";
	}
};
