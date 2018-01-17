#include "trinagulatordelaunaygreedy.h"
#include "geometrystrutctures.h"
#include "trianglegraph.h"

#include <iostream>

TriangleGraph TrinagulatorDelaunayGreedy::triangulatePointCloud(const std::vector<Point3D> &points)
{
    if (points.size() < TriangleGraph::trianglePointsCount)
    {
        std::cout << "The count of points is not enough for triangulation" << std::endl;
        return TriangleGraph();
    }

    TriangleGraph result(points[0], points[1], points[2]);    //the first triangle is built from three first points

    for (size_t i = TriangleGraph::trianglePointsCount; i < points.size(); ++i)
    {
        addPointToTriangulation(result, points[i]);
    }

    return result;
}

void TrinagulatorDelaunayGreedy::addPointToTriangulation(TriangleGraph &triangulation, const Point3D &point)
{
    //TODO realize
}

TrinagulatorDelaunayGreedy::Position TrinagulatorDelaunayGreedy::insideTriangle(const Point3D &p,
                                                                                const Point3D &A,
                                                                                const Point3D &B,
                                                                                const Point3D &C)
{
    int ABProduct = (A - p) ^ (B - p);
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
