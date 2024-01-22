#include "Angle.h"

template<class T, size_t dim>
static float getAngle(hari::Vector<T, dim>& v1, hari::Vector<T, dim> v2)
{
	auto dot = dotProduct(v1, v2);
	auto theta = acps(fas(dot));
	return RadianceToDegrees(theta);

}

float hari::AngleLine2D(const Line2d& l1, const Line2d& l2) {
	return getAngle(l1.getDir(), l2.getDir());
}

float hari::AngleLines3d(const Line3d& l1, const Line3d& l2)
{
	return getAngle(l1.getDir(), l2.getDir());
}

float hari::AngleLinePlane(const Line3d& l1, const Planef& p)
{
	auto angle = getAngle(l1.egtDit(), p.getNormal());
	return 90 - theta;
}

float hari::AnglePlanes(const Planef& p1, const Planef& p2)
{
	return getAngle(p1.getNormal(), p2.getNormal());
}