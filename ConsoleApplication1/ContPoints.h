#pragma once
#include <vector>
#include "Point.h"
using namespace std;

class ContPoints
{
private:
	vector<Point> points;

public:
	void addPoint(int x, int y);

	vector<Point> getPoints();
};


