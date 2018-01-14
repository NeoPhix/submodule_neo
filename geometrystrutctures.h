#ifndef GEOMETRYSTRUTCTURES_H
#define GEOMETRYSTRUTCTURES_H

struct Point3D
{
    int x;
    int y;
    int z;

    const Point3D operator+ (const Point3D &p) const { return Point3D {x + p.x, y + p.y, z + p.z} ; }
    const Point3D operator- (const Point3D &p) const { return Point3D {x - p.x, y - p.y, z - p.z} ; }
    const int operator^ (const Point3D &p) const     { return x * p.y - y * p.x; }                      ///vector product of 2d part
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
