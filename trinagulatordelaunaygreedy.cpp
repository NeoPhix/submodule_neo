#include "trinagulatordelaunaygreedy.h"
#include "geometrystrutctures.h"

#include <iostream>

static constexpr size_t trianglePointsCount = 3;

std::list<Triangle> TrinagulatorDelaunayGreedy::triangulatePointCloud(std::vector<Point3D> points)
{
    if (points.size() < trianglePointsCount)
    {
        std::cout << "The count of points is not enough for triangulation" << std::endl;
        return std::list<Triangle>();
    }

    std::list<Triangle> result;

    result.push_back( Triangle{ points[0], points[1], points[2] } );    //the first triangle is built from three first points

    for (size_t i = trianglePointsCount; i < points.size(); ++i)
    {
        addPointToTriangulation(result, points[i]);
    }

    return result;
}

void TrinagulatorDelaunayGreedy::addPointToTriangulation(std::list<Triangle> &triangulation, const Point3D &point)
{
    //TODO realize
}

TrinagulatorDelaunayGreedy::Position TrinagulatorDelaunayGreedy::insideTriangle(const Point3D &p, const Triangle &t)
{
    int ABProduct = (t.A - p) ^ (t.B - p);
    int BCProduct = (t.B - p) ^ (t.C - p);
    int CAProduct = (t.C - p) ^ (t.A - p);

    bool allNegative = (ABProduct < 0) && (BCProduct < 0) && (CAProduct < 0);
    bool allPositive = (ABProduct > 0) && (BCProduct > 0) && (CAProduct > 0);

    if (allNegative || allPositive)
        return Position::Inside;

    if (ABProduct == 0)
        return Position::OnEdgeAB;
    else if (BCProduct == 0)
        return Position::OnEdgeBC;
    else if (CAProduct == 0)
        return Position::OnEdgeCA;

    return Position::Outside;
}
