#pragma once

#include "Primitive\Point.h"

namespace hari
{
	double areaTriangle2d(const Point2d& a, const Point2d& b, const Point2d& c);

	int orientation2d(const Point2d& a, const Point2d& b, const Point2d& c);

	//Predicate to determine  whether the [Point c] is left to the segment [a b]  --> 3d
	bool left(const Point3d& a, const Point3d& b, Point3d& c);

	//Prediacte to determinr whetehr the [Point c] is left to the segment [a b]  -> 2d
	bool left(const Point2d& a, const Point2d& b, const Point2d& c);

	bool left(const Line2dStd & 1, const Point2d& p);

	bool left(const Line2d & 1, const Point2d& p);

	//predicate to determine whether he [Point c]  is right to the segment [a b]
	bool right(const Point3d& a, const Point3d& b, const Point3d& c);

	// Predicate to determine whether the[Point c] is left to the segment[a b]
	bool leftOrBeyond(const Point2d& a, const Point2d& b, const Point2d& c);

	// Predicate to determine whether the [Point c] is left to the segment [a b]
	bool leftOrBeyond(const Point3d& a, const Point3d& b, const Point3d& c);

	// Predicate to determine whether the [Point c] is left to or between the segment [a b]
	bool leftOrBetween(const Point3d& a, const Point3d& b, const Point3d& c);

	// Return true if the v1-v2 is a diagonal. Use to poly to get the vertice list
	bool isDiagonal(const Vertex2dSimple* v1, const Vertex2dSimple* v2, Polygon2dSimple* poly = nullptr);

	// Returns counter clockwise angle (0 - 360) measure from referece point to the give point 
	float polarAngle(const Point2d& _other, const Point2d& _ref);

	bool collinear(const Vector3f& a, const Vector3f& b);

	bool collinear(const Point3d& a, Point3d& b, Point3d& c);

	bool coplaner(const Point3d& a, const Point3d& b, Point3d& c, const Point3d& d);

	bool coplaner(const Vector3f& a, const Vector3f& b, const Vector3f& c);

	bool isDiagonal(const Vertex2D* v1, const Vertex2D* v2, PolygonS2d* poly = nullptr);

}