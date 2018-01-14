#ifndef TRINAGULATORDELAUNAYGREEDY_H
#define TRINAGULATORDELAUNAYGREEDY_H

#include "triangulatorinterface.h"

class TrinagulatorDelaunayGreedy : public TriangulatorInterface
{
public:
    TrinagulatorDelaunayGreedy() = default;
    ~TrinagulatorDelaunayGreedy() = default;

    virtual std::list<Triangle> triangulatePointCloud(std::vector<Point3D> points) override;

private:

};

#endif // TRINAGULATORDELAUNAYGREEDY_H
