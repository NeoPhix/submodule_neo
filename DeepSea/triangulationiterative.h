#ifndef TRIANGULATIONITERATIVE_H
#define TRIANGULATIONITERATIVE_H

#include "triangulationinterface.h"

class TriangulationIterative : public TriangulationInterface
{
public:
    TriangulationIterative() = default;
    ~TriangulationIterative() = default;

    virtual TriangleGraph* triangulatePoints(std::vector<Point3D> points) override;
};

#endif // TRIANGULATIONITERATIVE_H
