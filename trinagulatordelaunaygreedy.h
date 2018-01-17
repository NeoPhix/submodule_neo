#ifndef TRINAGULATORDELAUNAYGREEDY_H
#define TRINAGULATORDELAUNAYGREEDY_H

#include "triangulatorinterface.h"

class TrinagulatorDelaunayGreedy : public TriangulatorInterface
{
public:
    TrinagulatorDelaunayGreedy() = default;
    ~TrinagulatorDelaunayGreedy() = default;

    TriangleGraph triangulatePointCloud(const std::vector<Point3D> &points) override;

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
    void addPointToTriangulation(TriangleGraph &triangulation, const Point3D &point);

    Position insideTriangle(const Point3D &p,
                            const Point3D &A,
                            const Point3D &B,
                            const Point3D &C);

};

#endif // TRINAGULATORDELAUNAYGREEDY_H
