# #pragma once

#include "Primitives\Line.h"
#include "Primitives\Plane.h"

namespace hari {
	float AngleLines2D(const Line2d& l1, const Line2d& l2);

	float AngleLines3d(const Line3d& l1, const Line3d& l2);

	float AngleLinePlane(const Line3d& l1, const Planef& p);

	float AnglePlanes(const Planef& p1, const Planef& p2);
}
