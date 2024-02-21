#include "../headers/point3d.h"

Geometry ::Point3D::Point3D() : mX(0), mY(0), mZ(0) {}

Geometry ::Point3D::Point3D(double x, double y, double z) : mX(x), mY(y), mZ(z) {}

Geometry ::Point3D::~Point3D() {}

double Geometry ::Point3D::x() const
{
    return mX;
}

double Geometry ::Point3D::y() const
{
    return mY;
}

double Geometry ::Point3D::z() const
{
    return mZ;
}

void Geometry ::Point3D::setX(double x)
{
    mX = x;
}
void Geometry ::Point3D::setY(double y)
{
    mY = y;
}

void Geometry ::Point3D::setZ(double z)
{
    mZ = z;
}

bool Geometry ::Point3D::operator<(const Point3D &other) const
{
    if (mX < other.mX)
        return true;
    if (mX > other.mX)
        return false;

    if (mY < other.mY)
        return true;
    if (mY > other.mY)
        return false;

    return mZ < other.mZ;
}

bool Geometry ::Point3D::operator==(const Point3D &other) const
{
    return (mX == other.mX) && (mY == other.mY) && (mZ == other.mZ);
}