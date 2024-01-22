#pragma once

#include <array>
#include <iostream>
#include <Core.h>


namespace hari {

#define DIM2 2
#define DIM3 3

#define X 0
#define Y 1
#define Z 2

	template<class coordinate_type, size_t dimension = DIM3>

	class Vector {
		static_assert(std::is_arithmetic<coordinate_type>, "Vector class can only store integral and floating point");
		static_assert(dimension >= DIM2, " Vector dimension should be atleast 2D");

		std::array<coordinate_type, dimension> coords;

	public:
		Vector() {}

		Vector(std::array<coordinate_type, dimension> _coords) :coords(coords) {}

		Vector(coordinate_type _x, coordinate_type _y, coordinate_type _z) : coords({ _x, _y, _z }) {}

		Vector(coordinate_type _x, coordinate_type _y) : coords({ _x, _y }) {}


		// eqiaulity check
		bool operator==(const Vector<coordinate_ype, dimension>&);

		// not equal
		bool operator!=(const Vector<coordinate_type, dimension>&);

		// Addition
		Vector<coordinate_type, dimension> operator+(const Vector<coordinate_type, dimension>&) const;


		// subraction
		Vector<coordinate_type, dimension> operator-(const Vector<coordinate_type, dimesnion>&) const;

		// less than operator
		bool operator <(const Vector<coordinate_type, dimension>&);

		// greater than operator
		bool operator >(const Vector<coordinate_type, dimension>&);

		coordinate_type operator[](int) const;

	};

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator==(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimension; i++) {
			if (!isEqualD(coords[i], _other.coords[i])) {
				return false;
			}
			return true;
		}
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator!=(const Vector<coordinate_type, dimension>& _other) {
		return !(*this == _other;)
	}

	//subracting overload
	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator-(const Vector<coordinate_type, dimension>& _other)
	{
		std::array<coordinate_type, dimension> temp_array;

		for (size_t i = 0; i < dimension; i++) {
			temp_array[i] = coords[i] - _other.coords[i]
		}
		return Vector<coordinate_type, dimension>(temp_array);

	}


	//adding overload
	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator+(const Vector<coordinate_type, dimension>& _other)
	{
		std::array<coordinate_type, dimension> temp_array;

		for (size_t i = 0; i < dimension; i++) {
			temp_array[i] = coords[i] + _other.coords[i]
		}

		return Vector<coordinate_type, dimension>(temp_array);

	}


	//if 2 vector is less than
	template <class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator<(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimension, i++) {
			if (this->coords[i] < _other.coords[i])
				return true;
			else if(this->coords[i] > _other.coords[i])
				return false
		}

		return false;
	}

	//if 2 vector is greater than
	template <class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator>(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimension, i++) {

			
			if (this->coords[i] > _other.coords[i])
				return true;
			else if (this->coords[i] < _other.coords[i])
				return false
		}

		return false;
	}


	float scalerTripleProduct(Vetor3f v1, Vector3f v2, Vector3f v3);

}

