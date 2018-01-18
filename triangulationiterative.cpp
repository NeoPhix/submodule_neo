#include "triangulationiterative.h"

#include <iostream>

#include "geometrystrutctures.h"
#include "trianglegraph.h"

TriangleGraph *TriangulationIterative::triangulatePoints(std::vector<Point3D> points)
{
    if (points.size < TriangleGraph::trianglePointsCount)
    {
        std::cout << "No enough points for triangulation" << std::endl;
        return nullptr;
    }

    TriangleGraph* graph = new TriangleGraph(points[0], points[1], points[2]);
}
