#ifndef TRIANGLEGRAPH_H
#define TRIANGLEGRAPH_H

#include <list>

#include "geometrystrutctures.h"

/**
 * @brief The Triangle tree struct of ABC triangles. Contain 3 points pointers and 3 triangles pointers.
 */
class TriangleGraph
{
public:
    static constexpr size_t trianglePointsCount = 3;

public:
    TriangleGraph();
    TriangleGraph(const Point3D &A, const Point3D &B, const Point3D &C);
    ~TriangleGraph();

    TriangleGraph* getTriangleGraph(const size_t edge);
    void addTriangleToGraph(const Point3D &point, const size_t edge);

    Triangle getCurrentTriangle();
    void getPoints(Point3D &A, Point3D &B, Point3D &C);

    std::list<Triangle> getTrianglesList();

private:
    enum class Position
    {
        Inside,
        OnEdgeAB,
        OnEdgeBC,
        OnEdgeCA,
        Outside
    };

private:
    Position insideCurrentTriangle(const Point3D &p);
    Position insideTriangle(const Point3D &p, const Point3D &A, const Point3D &B, const Point3D &C);

    void addTriangleToList(std::list<Triangle> &list, bool passingFlag);

private:
    std::array<const Point3D*, trianglePointsCount> points;       /// Array of trinagle points pointers. Clockwise order
    std::array<TriangleGraph*, trianglePointsCount> triangles;    /// Array of triangles pointers. Clockwise order

    bool passed;
    bool destructible;
};

#endif // TRIANGLEGRAPH_H
