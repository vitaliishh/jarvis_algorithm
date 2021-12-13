// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "ContPoints.h"
#include "Point.h"
#include "Jarvis.h"

using namespace std;



int main()
{
	setlocale(LC_ALL, "ru");

	ContPoints points;

	points.addPoint(9, 2);
	points.addPoint(6, 5);
	points.addPoint(3, 8);
	points.addPoint(2, 4);
	points.addPoint(10, 0);
	points.addPoint(8, -2);
	points.addPoint(10, 2);
	points.addPoint(2, -1);
	points.addPoint(4, 1);




	Jarvis j(points.getPoints());

	
	vector<Point> res = j.getResultP();

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].x << " ," << res[i].y << endl;
	}


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
