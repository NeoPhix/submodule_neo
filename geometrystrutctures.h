#ifndef GEOMETRYSTRUTCTURES_H
#define GEOMETRYSTRUTCTURES_H

#include <array>

/**
 * @brief The Point3D struct
 */
struct Point3D
{
    int x;
    int y;
    int z;

    const Point3D operator+ (const Point3D &p) const { return Point3D {x + p.x, y + p.y, z + p.z} ; }
    const Point3D operator- (const Point3D &p) const { return Point3D {x - p.x, y - p.y, z - p.z} ; }
    const int operator^ (const Point3D &p) const     { return x * p.y - y * p.x; }                      ///vector product of 2d part
};

/**
 * @brief The Triangle struct
 */
struct Triangle
{
    Point3D A;
    Point3D B;
    Point3D C;
};

#endif // GEOMETRYSTRUTCTURES_H
