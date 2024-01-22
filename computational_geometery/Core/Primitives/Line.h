#pragma once

#include "../Base/Vector.h"

namespace hari {

	template<class coord_type, size_t dim = DIM3>
	class Line {
		Vector<coord_type, dim> point;
		Vector<coord_type, dim> dir;

	public:
		Line(){}

		Line(vector<coord_type, dim>& p1, Vector<coord_type, dim>& p2)
		{
			dir = p2 - p1;
			dir.normalize()
			point = p1;
		}

		Vector<coord_type, dime> getPoint();
		Vector<coord_type, dim> getDir();

		void setDirection(Vector<coord_type, dim>& _dir);

		void setPoint(Vector<coord_type, dim>& _point);
			
	};

	typedef Line<float, DIM2> Line2d;
	typedef Line<float, DIM3> Line3d;

	template<class  coord_type, size_t dim>
	inline Vector<coord_type, dim> Line<coord_type, dim>::getPoint()
	{
		return point;
	}

	template<class coord_type, size_t dim>
	inline Vector<coord_type, dim> line<coord_type, dim>::getDir()
	{
		return dir;
	}

	template<class coord_type, size_t dim>
	inline void Line<coord_type, dim>::setDirection(Vector<coord_type, dim>& _dir)
	{
		dir = _dir;
	}

	template<class coord_type, size_t dim>
	inline void Line<coord_type, dim>::setPoint(Vector<coord_type, dim>& _point)
	{
		point = _point;
	}
}