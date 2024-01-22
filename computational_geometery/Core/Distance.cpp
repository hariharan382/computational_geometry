#include "Distance.h"

float hari::distance(Line3d& line, Point3d& C)
{
	auto AC = C - line.getPoint();
	auto t = dotProduct(line.getDir(), AC);

	auto  xt = line.getPoint() + line.getDir()*t;
	auto dist_vec = xt - C;
	return dist_vec.magnitude();

}

float hari::distance(Planef& p, Point3d& Q)
{
	auto result = dotProduct(p.getNormal(), Q) - p.getD();
	return result;
}