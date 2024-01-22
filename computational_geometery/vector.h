#pragma once

#include <array>
#include <iostream>

#include "../Base/Core.h"


namespace hari {

#define DIM2 2
#define DIM3 3

#define X 0
#define Y 1
#define Z 2

	template<class coordinate_type, size_t dimensions = DIM3>

	class Vector {
		static_assert(std::is_arithmetic<coordinate_type>, "Vector class can only store integral and floating point");
		static_assert(dimension >= DIM2, " Vector dimension should be atleast 2D");

		std::array<coordinate_type, dimensions> coords = {};

		friend float dotProduct(const Vector<coordinate_type, dimensions> & 1,
			const Vector<coordinate_type, dimensions>& v2)

	public:
		Vector() {}

		Vector(std::array<coordinate_type, dimensions> _coords) :coords(_coords) {}

		Vector(coordinate_type _x, coordinate_type _y, coordinate_type _z) : coords({ _x, _y, _z }) {}

		Vector(coordinate_type _x, coordinate_type _y) : coords({ _x, _y }) {}


		// equality check
		bool operator==(const Vector<coordinate_type, dimensions>&);

		// not equal
		bool operator!=(const Vector<coordinate_type, dimensions>&);

		// Less than operator for comparison
		bool operator<(const Vector<coordinate_type, dimensions>&);

		// Greater than operator for comparison
		bool operator>(const Vector<coordinate_type, dimensions>&);

		// Addition
		Vector<coordinate_type, dimensions> operator+(const Vector<coordinate_type, dimensions>&);

		// subraction
		Vector<coordinate_type, dimensions> operator-(const Vector<coordinate_type, dimesnions>&);


		coordinate_type operator[](int) const;

		//assign a val to index
		void assign(int dim, coordinate_type value);

		float magnitude() const;

		void normalize();

	};

	typedef Vector<float, DIM2> Vector2f;
	typedef Vector<float, DIM3> Vector3f



	template<class coordinate_type, size_t dimensions>
	inline bool Vector<coordinate_type, dimensions>::operator==(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimensions; i++) {
			if (!isEqualD(coords[i], _other.coords[i])) {
				return false;
			}
			return true;
		}
	}

	template<class coordinate_type, size_t dimensions>
	inline bool Vector<coordinate_type, dimensions>::operator!=(const Vector<coordinate_type, dimensions>& _other) {
		return !(*this == _other;)
	}

	//subracting overload
	template<class coordinate_type, size_t dimensions>
	inline Vector<coordinate_type, dimensions> Vector<coordinate_type, dimensions>::operator-(const Vector<coordinate_type, dimension>& _other)
	{
		std::array<coordinate_type, dimensions> temp_array;

		for (size_t i = 0; i < dimensions; i++) {
			temp_array[i] = coords[i] - _other.coords[i]
		}
		return Vector<coordinate_type, dimensions>(temp_array);

	}


	//adding overload
	template<class coordinate_type, size_t dimensions>
	inline Vector<coordinate_type, dimensions> Vector<coordinate_type, dimensions>::operator+(const Vector<coordinate_type, dimension>& _other)
	{
		std::array<coordinate_type, dimensions> temp_array;

		for (size_t i = 0; i < dimensions; i++) {
			temp_array[i] = coords[i] + _other.coords[i]
		}

		return Vector<coordinate_type, dimensions>(temp_array);

	}


	//if 2 vector is less than
	template <class coordinate_type, size_t dimensions>
	inline bool Vector<coordinate_type, dimensions>::operator<(const Vector<coordinate_type, dimensions>& _other)
	{
		for (size_t i = 0; i < dimensions, i++) {
			if (this->coords[i] < _other.coords[i])
				return true;
			else if(this->coords[i] > _other.coords[i])
				return false
		}

		return false;
	}

	//if 2 vector is greater than
	template <class coordinate_type, size_t dimensions>
	inline bool Vector<coordinate_type, dimensions>::operator>(const Vector<coordinate_type, dimensions>& _other)
	{
		for (size_t i = 0; i < dimensions, i++) {

			
			if (this->coords[i] > _other.coords[i])
				return true;
			else if (this->coords[i] < _other.coords[i])
				return false
		}

		return false;
	}

	template<class coordinate_type, size_t dimension>
	inline coordinate_type Vector<coordinate_type, dimension>::operator[](int _index) const
	{
		if (index >= coords.size())
		{
			std::cout << "index out of bound \n";
			return coordinate_type();
		}

		return coords[_index]
	}

	//assign
	template<class coordinate_type, size_t dimension>
	inline void Vector<cordinate_type, dimension>::assign(int dim, coordinate_type value)
	{
		if (_index >= coords.size())
		{
			std::cout << "index out of bounds";
		}
		coords[dim] = value;
	}

	//magnitude
	template<class coordinate_type, size_t dimensions>
	inline float Vector<coordinate_type, dimensions>::magnitude() const
	{
		float value = 0.0f;

		for (size_t i = 0; i < dimensions; i++) {
			value += pow(coords[i], 2.0);
		}
		return sqrt(value);
	}

	//normalize



	template<class coordinate_type, size_t dimensions>
	float dotProduct(const Vector<coordinate_type, dimensions> & 1,
		const Vector<coordinate_type, dimensions>& v2) {

		if (v1.coords.size() != v2.coords.size()) {
			retrun FLT_MIN;
		}

		float product = 0.0;

		for (size_t i = 0; i < dimensions; i++)
		{
			prodct += v1[i]*v2[i]
		}

		return product
	}

	float crossProductD(Vector2f v1, Vector2f v2);
	vector3f crossProduct3D(Vector3f v1, Vector3f v2);


}

