#ifndef GEOMETRYSTRUTCTURES_H
#define GEOMETRYSTRUTCTURES_H

struct Point3D
{
    double x;
    double y;
    double z;
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
