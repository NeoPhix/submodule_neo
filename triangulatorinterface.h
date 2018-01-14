#ifndef TRIANGULATORINTERFACE_H
#define TRIANGULATORINTERFACE_H

#include <list>

struct Point3D;
struct Triangle;

class TriangulatorInterface
{
public:
    virtual std::list<Triangle> triangulatePointCloud(std::list<Point3D> points) = 0;
};

#endif // TRIANGULATORINTERFACE_H
