#include <iostream>
#include <vector>
#include "./headers/point3d.h"
#include "./headers/triangulation.h"
#include "./headers/stlreader.h"
#include "./headers/writer.h"
#include "./headers/halfsection.h"

int main()
{
    try
    {
        string filepath = "D:/Rohit_Workspace/halfSectionViewProjectCpp/Project4/half section view/resources/cube.stl";
        Geometry::Triangulation triangulation;
        Geometry::STLReader stlReader;
        Geometry::HalfSection halfsection;
        Geometry::Point3D  minVertex;
        Geometry::Point3D maxVertex;
    
        stlReader.readSTL(filepath, triangulation);

        halfsection.calculateBoundingBox (minVertex, maxVertex,triangulation);
        Geometry::Point3D center = halfsection.calculateBoundingBoxCenter(minVertex, maxVertex);
        halfsection.cutObject(center, triangulation);
        
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}