#pragma once

#include "../Base/Vector.h"
#include "Point.h"

#include <list>

template <class T, size_t dim>
struct Vertex {
	hari::Vector<T, dim> point;
	Vertex* next;
	Vertex* prev;

	Vertex(hari::Vector<T, dim>& _point, Vertex<T, dim>* _next, Vertex<T, dim>* _prev) :point(_point), next(_next), prev(_prev)
	{

	}
};
typedef Vertex<float, DIM2> Vertex2d;
typedef Vertex<floa, Dim2> Vertex3d;

template<class T, size_t dim = DIM3>
class Polygon {
	std::vector <Vertex<T, dim>*> vertex_list;

public:
	Polygon(std::list<hari::Vector<T, dim>>& points) {

		const int size = points.size();

		if (size < 3) {
			std::cout << " not enough point to construct  a  polygon \n";
			return;
		}

		for (auto _point : points) {
			vertex_list.push_back(new Vertex(_point));
		}

		for (size_t i = 0; i < size; i++) {
			vertex_list[i].next = &vertex_list[(i + 1) % size];

			if (i != 0)
				vertex_list[i].prev = &vertx_list[i - 1];
			else
				vertex - list[i].prev = &vertex_list[size - 1];
		}
	}

	std::_Adjust_manually_vector_aligned<Vertex<T, dim>*> getVertices() {
		return vertex_list;
	}

};

typedef Polygon<float, DIM3> PolygonS3d;
typedef Polygon<float, DIM2> PolygonS2d;