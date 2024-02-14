#pragma once

#include <vector>
#include <map>
#include "triangle.h"

namespace Geometry
{
    class Triangulation
    {
    public:
        Triangulation();
        ~Triangulation();
        std::vector<Triangle> &triangles();
        std::vector<Point3D> &uniquePoints();
        std::vector<Point3D> &uniqueNormals();

    private:
        std::vector<Triangle> mTriangles;
        std::vector<Point3D> mUniquePoints;
        std::vector<Point3D> mUniqeNormals;
    };
}