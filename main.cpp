#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <iostream>
#include <vector>
#include <list>

#include "geometrystrutctures.h"
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
    std::vector<Point3D> points = {
                                      Point3D {   0,   50, 5 },
                                      Point3D {  50,  -20, 40},
                                      Point3D { -50,  -20, 40},
                                      Point3D { 100,  100, 90},
                                      Point3D {-0,   -100, 40},
                                      Point3D {-100, 100, 10}
                                  };

    TriangleGraph graph(points[0], points[1], points[2]);

    graph.addTriangleToGraph(points[3], 0);
    graph.addTriangleToGraph(points[4], 1);
    graph.addTriangleToGraph(points[5], 2);

    auto result = graph.getTrianglesList();
    std::cout << "Complete triangles:" << std::endl;

    for (auto iter = result.begin(); iter != result.end(); ++iter)
    {
        std::cout << "A: {" << iter->A.x << ", " << iter->A.y << ", " << iter->A.z << "}, "
                  << "B: {" << iter->B.x << ", " << iter->B.y << ", " << iter->B.z << "}, "
                  << "C: {" << iter->C.x << ", " << iter->C.y << ", " << iter->C.z << "} "
                  << std::endl;
    }

    std::cout << "Hello, world! ;)" << std::endl;


////////////////////////////////////
///  simple visualization part!  ///
////////////////////////////////////
    QApplication a(argc, argv);

    QGraphicsScene scene;
    size_t width = 500;
    size_t height = 500;
    scene.setSceneRect(0, 0, width, height);

    Point3D center { width / 2, height / 2, 0 };

    for (auto iter = result.begin(); iter != result.end(); ++iter)
    {
        const Point3D A = iter->A + center;
        const Point3D B = iter->B + center;
        const Point3D C = iter->C + center;

        scene.addLine(A.x, A.y, B.x, B.y);
        scene.addLine(B.x, B.y, C.x, C.y);
        scene.addLine(C.x, C.y, A.x, A.y);
    }

    QGraphicsView view(&scene);
    view.show();

    return a.exec();
}
