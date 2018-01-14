#ifndef TRIANGULATORINTERFACE_H
#define TRIANGULATORINTERFACE_H

#include <list>
#include <vector>

struct Point3D;
struct Triangle;

class TriangulatorInterface
{
public:
    virtual std::list<Triangle> triangulatePointCloud(std::vector<Point3D> points) = 0;
};

#endif // TRIANGULATORINTERFACE_H
