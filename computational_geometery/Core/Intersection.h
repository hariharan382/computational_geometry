#pragma once

#include "Primitive\Point.h"

namespace hari {
	
	bool Intersection(const hari::Point2d&, const hari::Point2d&, const hari::Point2d& ,const hari::Point2d&);

	bool Intersection(const hari::Point2d&, const hari::Point2d&, const hari::Point2d& ,const hari::Point2d&, 
		hari:Point2d&);

	bool intersection(const hari::Line2d&, const hari::Line2d&, hari::Point2d&);

	bool intersection(const hari::Line3d&, cnst hari::Planef&, hari::POint3d&);

	bool insersect(const hari::Planef&, hari::Planef&, hari::Line3d&);


}