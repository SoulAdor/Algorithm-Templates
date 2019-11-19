#include <bits/stdc++.h>
using namespace std;

double PI = atan(1) * 4;

struct Point
{
	long long x, y;
};

vector <Point> points (100001);

// Number of boundary points of a simple polygon. 
// For each line, counts number of points on it - 1
// Last point is the first again
long long GetNumBoundaryPoints ()
{
	long long num_boundary_points = 0;
	for (int i = 0; i < points.size(); ++i)
		num_boundary_points += __gcd (abs (points[i].x - points[i + 1].x), abs (points[i].y - points[i + 1].y)); 
	return num_boundary_points;
}

// Twice the area of a simple polygon. Area = Inside points - 1 + Boundary/2
long double GetArea ()
{
	long double area = 0;
	for (int i = 0; i < points.size(); ++i)
		area += points[i].x * points[i + 1].y - points[i].y * points[i + 1].x;
	return abs (area) / 2;
}

// Point and angles

double DegreeToRadian (double degree)
{
	return degree * PI / 180;
}

// Returns true if angle is inside interval of radians, works for any interval
bool Inside (double start, double finish, double angle)
{
	while (angle < start) angle += 2 * PI;
	while (angle > finish) angle -= 2 * PI;
	return (angle >= start && angle <= finish);
}

// Returns an angle point makes with origin in [-PI/2 : 3 * PI/2) range
double GetAngle (double x, double y)
{
	return x == 0 ? y > 0 ? PI/2 : -PI/2 :
		x > 0 ? atan (y/x) : PI - atan (y/-x);
}