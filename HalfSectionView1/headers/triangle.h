#pragma once
#include "point3d.h"

namespace Geometry
{
    class Triangle
    {
    public:
        Triangle(int v1, int v2, int v3);
        ~Triangle();
        const int v1() const;
        const int v2() const;
        const int v3() const;
        const int normalIndex() const;
        void setV1(int v1);
        void setV2(int v2);
        void setV3(int v3);
        void setNormalIndex(int index);

    private:
        int mV1;
        int mV2;
        int mV3;
        int mNormalIndex;
    };
}