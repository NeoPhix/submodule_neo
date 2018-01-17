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

std::list<Triangle> TriangleGraph::getTriangles()
{
    std::list<Triangle> result;

    addTriangleToList(result, !passed);

    return result;
}

void TriangleGraph::addTriangleToList(std::list<Triangle> &list, bool passingFlag)
{
    if (passed != passingFlag)
    {
        passed = passingFlag;

        const Point3D &A = *points[0];
        const Point3D &B = *points[1];
        const Point3D &C = *points[2];

        list.push_back( Triangle {A, B, C} );

        for (auto iter = triangles.begin(); iter != triangles.end(); ++iter)
        {
            if (*iter != nullptr)
                (*iter)->addTriangleToList(list, passingFlag);
        }
    }
}

