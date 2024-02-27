#include "..\headers\triangulation.h"

Geometry::Triangulation::Triangulation()
{
}
Geometry::Triangulation::~Triangulation()
{
}

std::vector<Geometry::Triangle> &Geometry::Triangulation::triangles()
{
    return mTriangles;
}

std::vector<Geometry::Point3D> &Geometry::Triangulation::uniquePoints()
{
    return mUniquePoints;
}

std::vector<Geometry::Point3D> &Geometry::Triangulation :: uniqueNormals()
{
    return mUniqeNormals;
}