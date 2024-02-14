#include <fstream>
#include <stdexcept>
#include <iostream>
#include "../headers/writer.h"

void Geometry ::Writer ::write(std::string &filePath, std::vector<Triangle> H_Triangles,std::vector<Point3D> &points)
{
    std::ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        std::cout << "Error while opening the file for writing."<<std::endl;
    }

    // Write triangles to the STL file
    for (const Triangle &triangle : H_Triangles)
    {
        // Write each vertex of the triangle to the STL file
        outFile <<points[triangle.v1()].x() << " " << points[triangle.v1()].y() << " " << points[triangle.v1()].z() << std::endl;
        outFile <<points[triangle.v2()].x() << " " << points[triangle.v2()].y() << " " << points[triangle.v2()].z() << std::endl;
        outFile <<points[triangle.v3()].x() << " " << points[triangle.v3()].y() << " " << points[triangle.v3()].z() << std::endl;
    }
    std::cout<<"Data written successfully"<<std::endl;
    // Close the STL file
    outFile.close();
}
