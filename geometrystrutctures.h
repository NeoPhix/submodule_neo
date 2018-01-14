#ifndef GEOMETRYSTRUTCTURES_H
#define GEOMETRYSTRUTCTURES_H

using uint = unsigned int;

struct Point3D
{
    uint x;
    uint y;
    uint z;
};

struct Line
{
    Point3D begin;
    Point3D end;
};

/**
 * @brief The Triangle struct of ABC triangle. Contain 3 points.
 */
struct Triangle
{
    Point3D A;
    Point3D B;
    Point3D C;
};

#endif // GEOMETRYSTRUTCTURES_H
