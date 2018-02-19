#ifndef TRIANGULATIONINTERFACE_H
#define TRIANGULATIONINTERFACE_H

#include <vector>

class TriangleGraph;
class Point3D;

class TriangulationInterface
{
public:
    virtual TriangleGraph* triangulatePoints(std::vector<Point3D> points) = 0;
};

#endif // TRIANGULATIONINTERFACE_H
