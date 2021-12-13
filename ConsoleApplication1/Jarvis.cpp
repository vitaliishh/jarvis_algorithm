#include "Jarvis.h"



vector<Point> Jarvis::getResultP()
{
	return resultP;
}


Jarvis::Jarvis(vector<Point> points)
{

	this->points = points;

	alg(points);
}



void Jarvis::searchExPoint(vector<Point> points)
{
	for (int i = 0; i < points.size(); i++)
	{

		if (points[i].x < xML)
		{
			xML = points[i].x;
			yML = points[i].y;

			exIdx = i;
		}

		if (points[i].x == xML)
		{
			if (points[i].y < yML)
			{
				xML = points[i].x;
				yML = points[i].y;

				exIdx = i;
			}
		}
	}
}

void Jarvis::transferForVector(vector<Point> points)
{
	for (int i = 0; i < points.size(); i++)
	{
		int k = 0;

		if (i + 1 == points.size())
		{

			k = points.size();
		}

		int x = points[i + 1 - k].x - points[i].x;
		int y = points[i + 1 - k].y - points[i].y;

		vectors.push_back(Vector(x, y));
	}
}

int* Jarvis::createVector(int x1, int y1, int x2, int y2)
{
	int x = x2 - x1;
	int y = y2 - y1;

	int res[]{ x,y };

	return res;
}



int Jarvis::vectUmn(Vector p1, Vector p2)
{
	int res = p1.a * p2.b - p1.b * p2.a;

	return res;
}




int Jarvis::vectUmnC(int x1_1, int y1_1, int x2_1, int y2_1, int x1_2, int y1_2, int x2_2, int y2_2)
{

	int a1 = x2_1 - x1_1;
	int b1 = y2_1 - y1_1;

	int a2 = x2_2 - x1_2;
	int b2 = y2_2 - y1_2;


	int res = a1 * b2 - b1 * a2;

	return res;
}



void Jarvis::alg(vector<Point> points)
{
	searchExPoint(points);
	transferForVector(points);


	vector<Point> copyPointsV = points;


	resultP.push_back(Point(xML, yML));


	vector<int> bannedIdx = { 9999 };



	for (int i = 0; i < copyPointsV.size() - 1; i++)
	{



		vector<VectorWithIdx> temporaryV;


		for (int j = 0; j < copyPointsV.size(); j++)
		{

			bool flagCheckBannedIdx = true;

			for (int k = 0; k < bannedIdx.size(); k++)
			{
				if (j == bannedIdx[k])
				{
					flagCheckBannedIdx = false;
				}
			}

			if (flagCheckBannedIdx)
			{
				int a = createVector(resultP[i].x, resultP[i].y, copyPointsV[j].x, copyPointsV[j].y)[0];
				int b = createVector(resultP[i].x, resultP[i].y, copyPointsV[j].x, copyPointsV[j].y)[1];

				if (!(a == 0 && b == 0))
				{
					temporaryV.push_back(VectorWithIdx(a, b, j));
				}
			}

		}

		for (int j = 0; j < temporaryV.size(); j++)
		{

			if (j + 1 == temporaryV.size())
			{
				break;
			}

			Vector v1(temporaryV[j].a, temporaryV[j].b);
			Vector v2(temporaryV[j + 1].a, temporaryV[j + 1].b);


			int resUmn = vectUmn(v1, v2);

			if (resUmn == 0)
			{



				VectorWithIdx v1(temporaryV[j + 1]);
				VectorWithIdx v2(temporaryV[j]);

				float lenghtL1 = sqrt(pow(v1.a, 2) + pow(v1.b, 2));
				float lenghtL2 = sqrt(pow(v2.a, 2) + pow(v2.b, 2));


				if (lenghtL2 < lenghtL1)
				{
					temporaryV[j + 1] = v2;
					temporaryV[j] = v1;
				}

			}
			else if (resUmn > 0)
			{

				VectorWithIdx v1(temporaryV[j + 1]);
				VectorWithIdx v2(temporaryV[j]);

				temporaryV[j + 1] = v2;
				temporaryV[j] = v1;
			}


		}


		int usefulIdx = temporaryV[temporaryV.size() - 1].idx;


		if (i > 1)
		{
			if (copyPointsV[usefulIdx].x == xML && copyPointsV[usefulIdx].y == yML)
			{
				break;
			}
		}

		resultP.push_back(copyPointsV[usefulIdx]);


		bannedIdx.push_back(usefulIdx);

	}
}
