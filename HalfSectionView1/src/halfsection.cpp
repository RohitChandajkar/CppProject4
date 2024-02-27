#include <limits>
#include <iostream>
#include <bits/stdc++.h>
#include "../headers/halfsection.h"
#include "../headers/writer.h"

// Calculate bounding box of the object
void Geometry ::HalfSection::calculateBoundingBox(Point3D &minVertex, Point3D &maxVertex, Triangulation &triangulation)
{
  minVertex = {std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max()};
  maxVertex = {std::numeric_limits<float>::min(), std::numeric_limits<float>::min(), std::numeric_limits<float>::min()};

  for (const auto &vertex : triangulation.uniquePoints())
  {
    minVertex.setX(std::min(minVertex.x(), vertex.x()));
    minVertex.setY(std::min(minVertex.y(), vertex.y()));
    minVertex.setZ(std::min(minVertex.z(), vertex.z()));

    maxVertex.setX(std::max(maxVertex.x(), vertex.x()));
    maxVertex.setY(std::max(maxVertex.y(), vertex.y()));
    maxVertex.setZ(std::max(maxVertex.z(), vertex.z()));
  }
}

// Calculate the center of the bounding box
Geometry::Point3D Geometry ::HalfSection::calculateBoundingBoxCenter(const Point3D &minVertex, const Point3D &maxVertex)
{
  Point3D center;
  center.setX((minVertex.x() + maxVertex.x()) / 2);
  center.setY((minVertex.y() + maxVertex.y()) / 2);
  center.setZ((minVertex.z() + maxVertex.z()) / 2);
  return center;
}

// Cut the object into two pieces based on the center point
void Geometry ::HalfSection ::cutObject(const Geometry::Point3D &center, Triangulation &triangulation)
{
  Geometry::Writer writer;
  string filePath1 = "output/halfsection1.txt";
  string filePath2 = "output/halfsection2.txt";

  std::vector<Triangle> H_Triangles1;
  std::vector<Triangle> H_Triangles2;
  vector<Point3D> &points = triangulation.uniquePoints();
  Point3D p11(0, 0, 0);
  Point3D p12(0, 0, 0);
  Point3D p13(0, 0, 0);

  Point3D p21(0, 0, 0);
  Point3D p22(0, 0, 0);
  Point3D p23(0, 0, 0);
  int index1;
  int index2;
  int index3;
  int index4;
  int index5;
  int index6;
  for (const auto &triangle : triangulation.triangles())
  {
    double offset = 0.05;
    if (points[triangle.v1()].x() >= center.x()) // for YZ plane
    {
      index1 = triangulation.uniquePoints().size();
      p11.setX(center.x() - offset);
      p11.setY(points[triangle.v1()].y());
      p11.setZ(points[triangle.v1()].z());
      triangulation.uniquePoints().push_back(p11);

      index2 = triangulation.uniquePoints().size();
      p21.setX(points[triangle.v1()].x() + offset);
      p21.setY(points[triangle.v1()].y());
      p21.setZ(points[triangle.v1()].z());
      triangulation.uniquePoints().push_back(p21);
    }
    else
    {
      index1 = triangulation.uniquePoints().size();
      p11.setX(points[triangle.v1()].x() - offset);
      p11.setY(points[triangle.v1()].y());
      p11.setZ(points[triangle.v1()].z());
      triangulation.uniquePoints().push_back(p11);

      index2 = triangulation.uniquePoints().size();
      p21.setX(center.x() + offset);
      p21.setY(points[triangle.v1()].y());
      p21.setZ(points[triangle.v1()].z());
      triangulation.uniquePoints().push_back(p21);
    }

    if (points[triangle.v2()].x() >= center.x())
    {
      index3 = triangulation.uniquePoints().size();
      p12.setX(center.x() - offset);
      p12.setY(points[triangle.v2()].y());
      p12.setZ(points[triangle.v2()].z());
      triangulation.uniquePoints().push_back(p12);

      index4 = triangulation.uniquePoints().size();
      p22.setX(points[triangle.v2()].x() + offset);
      p22.setY(points[triangle.v2()].y());
      p22.setZ(points[triangle.v2()].z());
      triangulation.uniquePoints().push_back(p22);
    }
    else
    {
      index3 = triangulation.uniquePoints().size();
      p12.setX(points[triangle.v2()].x() - offset);
      p12.setY(points[triangle.v2()].y());
      p12.setZ(points[triangle.v2()].z());
      triangulation.uniquePoints().push_back(p12);

      index4 = triangulation.uniquePoints().size();
      p22.setX(center.x() + offset);
      p22.setY(points[triangle.v2()].y());
      p22.setZ(points[triangle.v2()].z());
      triangulation.uniquePoints().push_back(p22);
    }

    if (points[triangle.v3()].x() >= center.x())
    {
      index5 = triangulation.uniquePoints().size();
      p13.setX(center.x() - offset);
      p13.setY(points[triangle.v3()].y());
      p13.setZ(points[triangle.v3()].z());
      triangulation.uniquePoints().push_back(p13);

      index6 = triangulation.uniquePoints().size();
      p23.setX(points[triangle.v3()].x() + offset);
      p23.setY(points[triangle.v3()].y());
      p23.setZ(points[triangle.v3()].z());
      triangulation.uniquePoints().push_back(p23);
    }
    else
    {
      index5 = triangulation.uniquePoints().size();
      p13.setX(points[triangle.v3()].x() - offset);
      p13.setY(points[triangle.v3()].y());
      p13.setZ(points[triangle.v3()].z());
      triangulation.uniquePoints().push_back(p13);

      index6 = triangulation.uniquePoints().size();
      p23.setX(center.x() + offset);
      p23.setY(points[triangle.v3()].y());
      p23.setZ(points[triangle.v3()].z());
      triangulation.uniquePoints().push_back(p23);
    }

    Triangle H_Triangle1(index1, index3, index5);
    H_Triangles1.push_back(H_Triangle1);

    Triangle H_Triangle2(index2, index4, index6);
    H_Triangles2.push_back(H_Triangle2);
  }

  writer.write(filePath1, H_Triangles1, triangulation.uniquePoints());
  writer.write(filePath2, H_Triangles2, triangulation.uniquePoints());
}