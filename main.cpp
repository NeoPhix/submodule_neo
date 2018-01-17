#include <iostream>
#include <vector>
#include <list>

#include "geometrystrutctures.h"
#include "triangulatorinterface.h"
#include "trinagulatordelaunaygreedy.h"

using namespace std;

int main(int argc, char *argv[])
{
    TrinagulatorDelaunayGreedy triangulator;

    std::vector<Point3D> points = {
                                      Point3D {0, 1, 2},
                                      Point3D {1, 2, 4},
                                      Point3D {5, 3, 4},
                                      Point3D {7, 6, 9},
                                      Point3D {2, 2, 4},
                                      Point3D {1, 1, 1}
                                  };

    auto result = triangulator.triangulatePointCloud(points);

    std::cout << "Complete triangles:" << std::endl;
    for (auto iter = result.begin(); iter != result.end(); ++iter)
    {
        std::cout << "A: {" << iter->points[0]->x << ", " << iter->points[0]->y << ", " << iter->points[0]->z << "}, "
                  << "B: {" << iter->points[1]->x << ", " << iter->points[1]->y << ", " << iter->points[1]->z << "}, "
                  << "C: {" << iter->points[2]->x << ", " << iter->points[2]->y << ", " << iter->points[2]->z << "} "
                  << std::endl;
    }

    std::cout << "Hello, world! ;)" << std::endl;

    return 0;
}
