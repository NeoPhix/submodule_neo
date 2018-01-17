#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <iostream>
#include <vector>
#include <list>

#include "geometrystrutctures.h"
#include "triangulatorinterface.h"
#include "trinagulatordelaunaygreedy.h"
#include "trianglegraph.h"

using namespace std;

//void printTrinagles(TriangleGraph *triangle)
//{
//    std::cout << "A: {" << result->points[0]->x << ", " << result->points[0]->y << ", " << result->points[0]->z << "}, "
//              << "B: {" << result->points[1]->x << ", " << result->points[1]->y << ", " << result->points[1]->z << "}, "
//              << "C: {" << result->points[2]->x << ", " << result->points[2]->y << ", " << result->points[2]->z << "} "
//              << std::endl;

//    for (auto iter = result.begin(); iter != result.end(); ++iter)
//}

int main(int argc, char *argv[])
{
    TrinagulatorDelaunayGreedy triangulator;

    std::vector<Point3D> points = {
                                      Point3D {0,  10, 20},
                                      Point3D {10, 20, 40},
                                      Point3D {50, 30, 40},
                                      Point3D {70, 60, 90},
                                      Point3D {20, 20, 40},
                                      Point3D {10, 10, 10}
                                  };

    auto result = triangulator.triangulatePointCloud(points);

    std::cout << "Complete triangles:" << std::endl;

//    for (;;)
//    {
//        std::cout << "A: {" << result->points[0]->x << ", " << result->points[0]->y << ", " << result->points[0]->z << "}, "
//                  << "B: {" << result->points[1]->x << ", " << result->points[1]->y << ", " << result->points[1]->z << "}, "
//                  << "C: {" << result->points[2]->x << ", " << result->points[2]->y << ", " << result->points[2]->z << "} "
//                  << std::endl;

//        for (auto iter = result.begin(); iter != result.end(); ++iter)
//        {

//        }
//    }

//    for (auto iter = result.begin(); iter != result.end(); ++iter)
//    {
//        std::cout << "A: {" << iter->points[0]->x << ", " << iter->points[0]->y << ", " << iter->points[0]->z << "}, "
//                  << "B: {" << iter->points[1]->x << ", " << iter->points[1]->y << ", " << iter->points[1]->z << "}, "
//                  << "C: {" << iter->points[2]->x << ", " << iter->points[2]->y << ", " << iter->points[2]->z << "} "
//                  << std::endl;
//    }

    std::cout << "Hello, world! ;)" << std::endl;


////////////////////////////////////
///  simple visualization part!  ///
////////////////////////////////////
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 400, 400);

//    for (auto iter = result.begin(); iter != result.end(); ++iter)
//    {
//        const Point3D &A = *iter->points[0];
//        const Point3D &B = *iter->points[1];
//        const Point3D &C = *iter->points[2];

//        scene.addLine(A.x, A.y, B.x, B.y);
//        scene.addLine(B.x, B.y, C.x, C.y);
//        scene.addLine(C.x, C.y, A.x, A.y);
//    }

    QGraphicsView view(&scene);
    view.show();

    return a.exec();
}
