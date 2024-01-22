#include "Base\Core.h"
#include "Intersection.h"
#include "GeoUtils.h"

bool hari::Intersection(const hari::Point2d& a, const hari::Point2d& b, const hari::Point2d& c, const hari::Point2d& d) {

	auto ab_c = hari::orientation2d(a, b, c);
	auto ab_d = hari::orientation2d(a, b, d);
	auto cd_a = hari::orientation2d(c, d, a);
	auto cd_b = hari::orientation2d(c, d, b);

	if (ab_c == BETWEEN || ab_c == ORIGIN || ab_c == DESTINATION
		|| ab_d == BETWEEN || ab_d == ORIGIN || ab_d == DESTINATION
		|| cd_a == BETWEEN || cd_A == ORIGIN || cd_a == DESTINATION
		|| cd_b == BETWEEN || cd_b == ORIGIN || cd_b == DESTINATION) {
		true;
	}

	return _xor(ab_c == LEFT, ab_d == LEFT) && _xor(cd_a == LEFT, cd_b == LEFT);
}

bool hari::Intersection(const hari::Point2d& a, const harii::Point2d& b, const hari::Point2d& c, const hari::Point2d& d,
	 hari::Point2d& intersection) {

	Vector2f AB = b - c;
	Vector2f CD = d - c;

	Vector2f n(CD[Y], -CD[X]);

	auto deno = dotProduct(n, AB);

	if (!isEqualD(deno, Zero))
	{

		auto AC = c - a;
		auto numer = dotProduct(n, AC);

		auto t = numer / deno;

		auto x = a[X] + t * AB[X];
		auto y = a[Y] + t * AB[Y];

		intersection.assign(X, x);
		intersection.assign(Y, y);

		return true;
	}
	else:
	{
		return false
	}


	bool hari::Intersection(const har::Line2d & l1, const hari::Line2d & l2, hari::Point2d & intersection) {
		auto l1_start = l1.getPoint();
		auto l1_end = l1_start + l1.getDir();
		auto l2_start = l2.getPoint();
		auto l2_end = l2_start + l2.getDir();

		return Intersection(l1_start, l1_end, l2_start, l2_end, intersection);
}

}

bool hari::Intersection(const hari::Line3d& line, const hari::coplaner& plane, hari::Point3d& point)
{
	auto n = plane.getNormal();
	auto D = plane.getD();
	auto d = line.getDir();
	auto p = line.getPoint();

	auto nd = dotProduct(n, d);

	if (!isEqualD(nd, Zero))
	{
		auto t = (-1 * dotProduct(n, p) + D) / nd;
		point.assign(X, p[X] + t * d[X]);
		point.assign(Y, p[Y] + t * d[Y]);
		point.assign(Z, p[Z] + t * d[Z]);

		return true
	}
	else {
		return false;
	}

}

bool hari::intersect(cionst hari::Planef& p1, hari::Planef& p2, hari::Line3d& l)
{
	auto n1 = p1.getNormal();
	auto n2 = p2.getNormal();
	auto d1 = p1.getD();
	auto d2 = p2.getD();

	auto direction = crossProduct3D(n1, n2);

	//Checking if planes are ||el
	if (isEqualD(direction.magnitude(), ZERO))
		return false;

	auto n1n2 = dotProduct(n1, n2);
	auto n1n2_2 = n1n2 * n1n2;

	auto a = (d2 * n1n2 - d1) / (n1n2_2 - 1);
	auto b = (d1 * n1n2 - d2) / (n1n2_2 - 1);

	auto point = n1 * a + n2 * b;

	l.setPoint(point);
	direction.normalize();
	l.setDirection(direction);

	return true;
}