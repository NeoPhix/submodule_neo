#ifndef TRIANGLEGRAPH_H
#define TRIANGLEGRAPH_H

#include "geometrystrutctures.h"

/**
 * @brief The Triangle tree struct of ABC triangles. Contain 3 points pointers and 3 triangles pointers.
 */
class TriangleGraph
{
public:
    static constexpr size_t trianglePointsCount = 3;

    TriangleGraph();
    TriangleGraph(const Point3D &A, const Point3D &B, const Point3D &C);

    ~TriangleGraph();

private:
    std::array<const Point3D*, trianglePointsCount> points;       /// Array of trinagle points pointers. Clockwise order
    std::array<TriangleGraph*, trianglePointsCount> triangles;         /// Array of triangles pointers. Clockwise order

    bool passed;
};

#endif // TRIANGLEGRAPH_H
