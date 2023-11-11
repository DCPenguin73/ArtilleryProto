#pragma once
#include <array>

class TestDatabase;

class Database {
public:
	friend TestDatabase;
	double domain[20];
	double range[20];
	int length;
public:
	Database(double aDomain[], double aRange[], int aLength)
	{
		for (int i = 0; i < aLength; i++) {
			domain[i] = aDomain[i];
		}
		for (int i = 0; i < aLength; i++) {
			range[i] = aRange[i];
		}
		length = aLength;
	}
private:
	inline double linearInter(double pos1X, double pos1Y, double pos2X, double pos2Y, double pointX);
public:
	double searchDatabase(double pointX);
};
