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
        std::cout << "A: {" << iter->A.x << ", " << iter->A.y << ", " << iter->A.z << "}, "
                  << "B: {" << iter->B.x << ", " << iter->B.y << ", " << iter->B.z << "}, "
                  << "C: {" << iter->C.x << ", " << iter->C.y << ", " << iter->C.z << "} "
                  << std::endl;
    }

    std::cout << "Hello, world! ;)" << std::endl;

    return 0;
}
