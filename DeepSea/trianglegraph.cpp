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
            triangles[i] = nullptr;
        }
    }
    std::cout << "deleted" << std::endl;
}

std::list<Triangle> TriangleGraph::getTrianglesList()
{
    std::list<Triangle> result;

    addTriangleToList(result, !passed);

    return result;
}

void TriangleGraph::addTriangleToGraph(const Point3D &point, const size_t edge)
{
    assert(edge < trianglePointsCount); //We have only 3 triangle edges

    if (triangles[edge] != nullptr)
    {
        std::cout << "this edge is not empty" << std::endl;
        return;
    }

    auto triangle = new TriangleGraph();
    triangle->passed = passed;

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


Triangle TriangleGraph::getCurrentTriangle()
{
    return Triangle {*points[0], *points[1], *points[2]} ;
}


void TriangleGraph::getPoints(Point3D &A, Point3D &B, Point3D &C)
{
    A = *points[0];
    B = *points[1];
    C = *points[2];
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

//void TriangleGraph::addPointToTriangulation(TriangleGraph &graph, const Point3D &point)
//{
//    Point3D A, B, C;
//    graph.addTriangleToGraph(point, 0);

//}

TriangleGraph::Position TriangleGraph::insideTriangle(const Point3D &p,
                                                      const Point3D &A,
                                                      const Point3D &B,
                                                      const Point3D &C)
{
    int ABProduct = (A - p) ^ (B - p); //vector product
    int BCProduct = (B - p) ^ (C - p);
    int CAProduct = (C - p) ^ (A - p);

    if (ABProduct == 0)
        return Position::OnEdgeAB;
    else if (BCProduct == 0)
        return Position::OnEdgeBC;
    else if (CAProduct == 0)
        return Position::OnEdgeCA;

    bool allNegative = (ABProduct < 0) && (BCProduct < 0) && (CAProduct < 0);
    bool allPositive = (ABProduct > 0) && (BCProduct > 0) && (CAProduct > 0);

    if (allNegative || allPositive)
        return Position::Inside;

    return Position::Outside;
}
