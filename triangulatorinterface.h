#ifndef TRIANGULATORINTERFACE_H
#define TRIANGULATORINTERFACE_H

#include <list>
#include <vector>

struct Point3D;
struct TriangleGraph;

class TriangulatorInterface
{
public:
    virtual TriangleGraph triangulatePointCloud(const std::vector<Point3D> &points) = 0;
};

#endif // TRIANGULATORINTERFACE_H
