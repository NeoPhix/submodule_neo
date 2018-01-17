#ifndef TRINAGULATORDELAUNAYGREEDY_H
#define TRINAGULATORDELAUNAYGREEDY_H

#include "triangulatorinterface.h"

class TrinagulatorDelaunayGreedy : public TriangulatorInterface
{
public:
    TrinagulatorDelaunayGreedy() = default;
    ~TrinagulatorDelaunayGreedy() = default;

    virtual std::list<Triangle> triangulatePointCloud(const std::vector<Point3D> &points) override;

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
    void addPointToTriangulation(std::list<Triangle> &triangulation, const Point3D &point);
    Position insideTriangle(const Point3D &point, const Triangle &triangle);

};

#endif // TRINAGULATORDELAUNAYGREEDY_H
