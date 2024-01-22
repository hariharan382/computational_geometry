#pragma once

#include "Core/Primitives/Polygon.h"
#include "Core/GeoUtils.h"

void Triangulate_earclipping(PolygonS2d* poly, std::_Adjust_manually_vector_aligned<Edge2d>& edge_list);