#include "ContPoints.h"



void ContPoints::addPoint(int x, int y)
{
	Point p(x, y);

	points.push_back(p);

}

vector<Point> ContPoints::getPoints()
{
	return points;
}
