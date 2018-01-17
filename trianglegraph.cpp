#include "trianglegraph.h"

TriangleGraph::TriangleGraph()
{
    for (size_t i = 0; i < trianglePointsCount; ++i)
    {
        points[i] = nullptr;
        triangles[i] = nullptr;
    }

    passed = false;
}

TriangleGraph::TriangleGraph(const Point3D &A, const Point3D &B, const Point3D &C)
    : TriangleGraph()
{
    points[0] = &A;
    points[1] = &B;
    points[2] = &C;
}

TriangleGraph::~TriangleGraph()
{
    for (size_t i = 0; i < trianglePointsCount; ++i)
    {
        if (triangles[i] != nullptr)
        {
            delete triangles[i];
            triangles[i] = nullptr;
        }
    }
}
