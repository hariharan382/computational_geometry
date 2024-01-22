#pragma once

#include <vector>
#include <iostream>

#include "Point.h"

namespace hari {
	static int _id = 1;

	template<class type, size_t dim>
	struct EdgeDCEL;

	template<class type, sze_t dim>
	struct FaceDCEL;

	template<class type=float, size_t dim = DIM3>
	struct VertexDCEL {
		Vertex<float, dim> point;
		EdgeDCEL<type, dim>* incident_edge = nullptr;

		VertexDCEL(Vector<type, dim>& point) :point(_point){}
		void print() {
			std::cout << "(" << point[X] << "," << ponit[Y] << ") \n";
		}
	};

	template<class type = float, size_t dime = DIM3>
	struct EdgeDCEL {
		VertexDCEL<type, dim>* origin = nullptr;
		EdgeDCEL<type, dim>* twin = nullptr;
		EdgeDCEl<type, dim>* next = nullptr;
		EdgeDCEl<type, dim>* prev = nullptr;
		EdgeDCEL<type, dim>* incident_face = nullptr;

		int id;

		EdgeDCEl() { id = -1 };

		EdgeDCEL(VertexDCEL<type, dim>* _origin) : origin(_origin) {
			id = _id++;
		};

		VerteDCEL<type, dim>* destination() {
			return twin->origin;
		}

		void print()
		{
			std::cout << " this point pointr" << this << "\n";
			stdcout << "Origin :"; this->origin->print();
			std::cout << "twin pointer " << this->twin << "\n";
			std::cout << "next Pointer" << this->next << "\n";
			std::cout << "prev pointer" << this->prev << "\n";

		}
	};

	template<class type = float, size_t dim= DIM3>

	struct FaceDCEL
	{
		EdgeDCEL<type, dim>* outer = nullptr;
		std::vector<EdgeDCEL<type, dim>*> inner;

		void print()
		{
			if (outer)
			{
				auto edge_ptr = outer;
				auto next_ptr = outer->next;

				edge_ptr->origin->print;
				while (next_ptr != edge_ptr) {
					next_ptr->origin->print();
					next_ptr = next_ptr->next;
				}
			}
		}

		std::vector<EdgeDCEL<type, dim>*> getEdgeList() {
			std::vector<EgeDCEL<type, dim>*> edge_list;
			if (outer) {
				auto edge_ptr = outer;
				auto next_ptr = outer->next;
				edge_list.push_back(edge_ptr);
				edge_pr->origin->print();
				while (next_ptr != edge_ptr) {
					edge_list.push_back(nex_ptr);
					next_ptr = next_ptr->next;
				}
			}
			return edge_list;
		}

		std::vector<Vector<float, dim>> point_list;
		if (outer) {
			auto edge_ptr = outer;
			auto next_ptr = outer->next;
			point_list.push_back(edge_ptr->origin->point);
			while (next_ptr != edge_ptr) {
				point_list.push_back(next_ptr->origin->point);
				next_ptr = next_ptr->next;
			}
		}
		return point_list;

	};





}