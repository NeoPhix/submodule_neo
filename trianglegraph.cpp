#include "trianglegraph.h"

#include <iostream>
#include <assert.h>

TriangleGraph::TriangleGraph()
{
    for (size_t i = 0; i < trianglePointsCount; ++i)
    {
        points[i] = nullptr;
        triangles[i] = nullptr;
    }

    passed = false;
    destructible = false;
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
    destructible = true;
    for (size_t i = 0; i < trianglePointsCount; ++i)
    {
        if (triangles[i] != nullptr && triangles[i]->destructible != true)
        {
            delete triangles[i];
            std::cout << "deleted" << std::endl;
            triangles[i] = nullptr;
        }
    }
}

std::list<Triangle> TriangleGraph::getTriangles()
{
    std::list<Triangle> result;

    addTriangleToList(result, !this->passed);

    return result;
}

void TriangleGraph::addTriangle(const Point3D &point, const size_t edge)
{
    assert(edge < trianglePointsCount); //We have only 3 triangle edges

    if (triangles[edge] != nullptr)
    {
        std::cout << "this edge is not empty" << std::endl;
    }

    auto triangle = new TriangleGraph();
    triangle->passed = this->passed;

    switch (edge)
    {
    case 0:
        triangle->points[0] = points[0];
        triangle->points[1] = points[1];
        triangle->points[2] = &point;
        break;
    case 1:
        triangle->points[0] = points[1];
        triangle->points[1] = points[2];
        triangle->points[2] = &point;
        break;
    case 2:
        triangle->points[0] = points[2];
        triangle->points[1] = points[0];
        triangle->points[2] = &point;
        break;
    default:
        break;
    }

    triangles[edge] = triangle;
}

void TriangleGraph::addTriangleToList(std::list<Triangle> &list, bool passingFlag)
{
    if (passed != passingFlag)
    {
        this->passed = passingFlag;

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

