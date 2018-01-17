#include "geometrystrutctures.h"

Triangle::Triangle()
{
    for (size_t i = 0; i < trianglePointsCount; ++i)
    {
        points[i] = nullptr;
        triangles[i] = nullptr;
    }
}

Triangle::Triangle(const Point3D &A, const Point3D &B, const Point3D &C)
    : Triangle()
{
    points[0] = &A;
    points[1] = &B;
    points[2] = &C;
}

Triangle::~Triangle()
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
