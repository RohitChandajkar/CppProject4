#include "../headers/triangle.h"

Geometry::Triangle::Triangle(int v1, int v2, int v3) : mV1(v1), mV2(v2), mV3(v3) {}

Geometry::Triangle::~Triangle()
{
}
const int Geometry::Triangle::v1() const
{
    return mV1;
}

const int Geometry::Triangle::v2() const
{
    return mV2;
}

const int Geometry::Triangle::v3() const
{
    return mV3;
}

const int Geometry::Triangle::normalIndex() const
{
    return mNormalIndex;
}

void Geometry::Triangle::setV1(int v1)
{
    mV1 = v1;
}
void Geometry::Triangle::setV2(int v2)
{
    mV2 = v2;
}
void Geometry::Triangle::setV3(int v3)
{
    mV3 = v3;
}
void Geometry::Triangle::setNormalIndex(int index)
{
    mNormalIndex = index;
}