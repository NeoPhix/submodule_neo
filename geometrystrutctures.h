#ifndef GEOMETRYSTRUTCTURES_H
#define GEOMETRYSTRUTCTURES_H

#include <array>

static constexpr size_t trianglePointsCount = 3;

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
 * @brief The Triangle struct of ABC triangle. Contain 3 points.
 */
struct Triangle
{
    Triangle();
    Triangle(const Point3D &A, const Point3D &B, const Point3D &C);

    ~Triangle();

    std::array<const Point3D*, trianglePointsCount> points;       /// Array of trinagle points pointers. Clockwise order
    std::array<Triangle*, trianglePointsCount> triangles;   /// Array of triangles pointers. Clockwise order
};

#endif // GEOMETRYSTRUTCTURES_H
