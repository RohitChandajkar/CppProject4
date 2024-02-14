// STLWriter.h
#pragma once
#include <string>
#include "Triangulation.h"

namespace Geometry
{
    class Writer
    {
    public:
        // Function to write geometry data to an STL file
        void write(std::string &filePath, std::vector<Triangle> H_Triangles,std::vector<Point3D> &points);
    };
}