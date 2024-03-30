#pragma once
#include <vector>
#include "Point3D.h"
#include "Triangle.h"
#include "Triangulation.h"

using namespace std;

namespace Geometry
{
    class HalfSection
    {
    public:
        void calculateBoundingBox(Point3D &minVertex, Point3D &maxVertex, Triangulation &triangulation);
        Point3D calculateBoundingBoxCenter(const Point3D &minVertex, const Point3D &maxVertex);
        void cutObject(const Point3D &center, Triangulation &triangulation);
    };
}