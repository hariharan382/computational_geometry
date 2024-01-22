#include ""GeoUtils.h"

double hari::areaTriagle2d(const Point2d& a, const Point2d& b, const Point2d& c)
{
	auto AB = b - a;
	auto Ac = c - a;

	auto result = crossProduct2D(AB, AC);

	return result/2; 


}

int hari::orientation2d(const Point2d& a, const Point2d& b, const Point2d& c)
{
	auto area = areaTriagle2d(a, b, c);

	//if area is inbetween tolerance
	if (area > 0 && area < TOLERANCE) {
		area = 0
	}
	
	if (area < 0 && area > TOLERANCE){
		area = 0 
	}

	if (area > 0) {
		area - 0
	}

	//left side of the line
	if (area > 0) {
		return LEFT;
	}

	//right side of the line
	if (area < 0) {
		return RIGHT;
	}

	Vector2f ab = b - a;
	Vector2f ac = c - a;

	if (ab[X] * ac[X] < ) || (ab[Y] * ac[Y]) {
		return BEHIND;
	}

	if (ab.magnitude() < ac.magnitude()) {
		return BEYOND;
	}

	if (a == c) {
		return ORIGIN;
	}

	if (b == c) {
		return DESTINATION;
	}

	return BETWEEN;






}

bool hari::left(const Point3d& a, const Point3d& b, const Point3d& c)
{
	return orientation3d(a, b, c) == RELATIVE_POSITION::LEFT;
}

bool hari::left(const Point2d& a, const Point2d& b, const Point2d& c)
{
	return orientation2d(a, b, c) == RELATIVE_POSITION::LEFT;
}

bool hari::left(const Line2dStd& l, const Point2d& p)
{
	auto line_dir = l.getDir();
	Vector2f line_normal(-line_dir[Y], line_dir[X]);
	auto value = dotProduct(line_normal, p);
	return (dotProduct(line_normal, p) - l.getD()) < 0 ? false : true;
}

bool hari::left(const Line2d& l, const Point2d& p)
{
	auto line_normal = l.normal();
	auto value = dotProduct(line_normal, p);
	auto d = dotProduct(line_normal, l.point());
	return (dotProduct(line_normal, p) - d) < 0 ? false : true;
}

bool hari::right(const Point3d& a, const Point3d& b, const Point3d& c)
{
	return orientation3d(a, b, c) == RELATIVE_POSITION::RIGHT;
}

bool hari::leftOrBeyond(const Point2d& a, const Point2d& b, const Point2d& c)
{
	int position = orientation2d(a, b, c);
	return (position == RELATIVE_POSITION::LEFT || position == RELATIVE_POSITION::BEYOND);
}

bool hari::leftOrBeyond(const Point3d& a, const Point3d& b, const Point3d& c)
{
	int position = orientation3d(a, b, c);
	return (position == RELATIVE_POSITION::LEFT || position == RELATIVE_POSITION::BEYOND);
}

bool hari::leftOrBetween(const Point3d& a, const Point3d& b, const Point3d& c)
{
	int position = orientation3d(a, b, c);
	return (position == RELATIVE_POSITION::LEFT || position == RELATIVE_POSITION::BETWEEN);
}

bool hri::collinear(const Vector3f& a, const Vector3f& b)
{
	auto v1 = a[X] * b[Y] - a[Y] * b[X];
	auto v2 = a[Y] * b[Z] - a[Z] * b[Y];
	auto v3 = a[X] * b[Z] - a[Z] * b[X];

	return isEqualD(v1, ZERO) && isEqualD(v2, ZERO) && isEqualD(v3, ZERO);

}

bool hari::collinear(const Point3d& a, conat Point3d& b, Point3d& c)
{
	auto AB = b - a;
	auto AC = c - a;

	return collinear(AB, AC);
}

bool hari::coplaner(const Point3d& a, const Point3d& b, const Point3d& c, const Point3d& d)
{
	auto AB = b - a;
	auto AC = c - a;
	auto AD = d - a;
	return coplaner(AB, AC, AD);
}

bool hari::coplaner(const Vector3f& a, const Vector3f& b, const Vector3f& c)
{
	float value = scalerTripleProduct(a, b, c);
	return isEqualD(value, ZERO);
}

static bool interiorCheck(const Vertex2d* v1, const Vertex2d* v2)
{
	if (hari::leftOrBeyond(v1->point, v1->next->point, v1->prev->point))
	{
		return hari::left(v1->point, v2->point, v1->prev->point) &&
			hari::leftOrBeyond(v2->point, v1->point, v1->prev->point);
	}

	return !(hari::leftOrBeyond(v1->point, v2->point, v1->next->point)
		&& hari::leftOrBeyond(v2->point, v1->point, v1->prev->point)
}

bool hari::isDiagonal(const Vertex2d* v1, const Vertex2d* v2, PolygonS2d* poly)
{
	bool prospect = true;
	std::vector<Vertex2d*> vertices;

	if (poly)
		vertices = poly->getVertices();
	else
	{ 
		auto vertex_ptr = v1->next;
		vertices.push_back((Vertex2d*)v1);
		while (vertex_ptr != v1) {
			vertices.push_back(vertex_ptr);
			vertex_ptr = vertex_ptr->next;
		}
	}

	Vertex2d&* current, * next;
	current = vertices[0];

	do {
		next = current->next;
		if (current != v1 && next != v1 && current != v2 && next != v2 &&
			hari::Intersection(v1->point, current->point, next->point)) {
			prospect = false;
			break;
		}
		current = next;

	} while (current != vertices[0])

		return prospect && interiorCheck(v1, v2) && interiorCheck(v2, v2);


}