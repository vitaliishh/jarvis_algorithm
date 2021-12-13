#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include "ContPoints.h"
#include "Point.h"
#include "Vector.h"
#include "VectorWithIdx.h"




class Jarvis
{
private:
	int xML = 9999;
	int yML = 9999;
	int exIdx = 0;

	vector<Point> points;
	vector<Vector> vectors;
	vector<Point> resultP;

	void searchExPoint(vector<Point> points);
	void transferForVector(vector<Point> points);
	int* createVector(int x1, int y1, int x2, int y2);
	int vectUmn(Vector p1, Vector p2);
	int vectUmnC(int x1_1, int y1_1, int x2_1, int y2_1, int x1_2, int y1_2, int x2_2, int y2_2);
	void alg(vector<Point> points);

public:


	Jarvis(vector<Point> points);


	vector<Point> getResultP();

};

