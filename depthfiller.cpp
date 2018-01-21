#include "depthfiller.h"

DepthFiller::DepthFiller(std::vector<uint> vertexArray_, size_t width_, size_t height_)
    : vertexArray(vertexArray_),
      width(width_),
      height(height_)
{
    assert(vertexArray.size() == width * height);
    depthArray.resize(vertexArray.size(), 0);
}

std::list<coords> DepthFiller::getNearestUp(int x, int y, std::vector<bool> &passed)
{
    assert( insideEdges(x, y) );

    uint currentVertex = vertexArray[y * width + x];

    std::list<coords> result;

    passed[y * width + x] = true;

    for (size_t i = 0; i < directionsCount; ++i)
    {
        int xn = x + dx[i];
        int yn = y + dy[i];

        if ( insideEdges(xn, yn) )
        {
            if ( currentVertex < vertexArray[yn * width + xn]
                 && !passed[yn * width + xn])
            {
                result.push_back(coords(xn, yn));
                passed[yn * width + xn] = true;
            }
        }
    }

    return result;
}

std::list<coords> DepthFiller::getNearestDown(int x, int y, std::vector<bool> &passed)
{
    assert( insideEdges(x, y) );

    uint currentVertex = vertexArray[y * width + x];

    std::list<coords> result;

    passed[y * width + x] = true;

    for (size_t i = 0; i < directionsCount; ++i)
    {
        int xn = x + dx[i];
        int yn = y + dy[i];

        if ( insideEdges(xn, yn) )
        {
            if ( currentVertex > vertexArray[yn * width + xn]
                 && !passed[yn * width + xn])
            {
                result.push_back(coords(xn, yn));
                passed[yn * width + xn] = true;
            }
        }
    }

    return result;
}

std::list<coords> DepthFiller::getNearestEqual(int x, int y, std::vector<bool> &passed)
{
    assert( insideEdges(x, y) );

    uint currentVertex = vertexArray[y * width + x];

    std::list<coords> result;

    passed[y * width + x] = true;

    for (size_t i = 0; i < directionsCount; ++i)
    {
        int xn = x + dx[i];
        int yn = y + dy[i];

        if ( insideEdges(xn, yn) )
        {
            if ( currentVertex == vertexArray[yn * width + xn]
                 && !passed[yn * width + xn])
            {
                result.push_back(coords(xn, yn));
                passed[yn * width + xn] = true;
            }
        }
    }

    return result;
}

std::vector<uint> DepthFiller::getDepthArray() //todo vector.size == 0
{
    fillRegion(3, 3);
    //return depthArray;
    return vertexArray;
}

bool DepthFiller::insideEdges(int x, int y)
{
    if (x < 0 || x > width - 1 || y < 0 || y > height - 1)
        return false;
    return true;
}

bool DepthFiller::onEdgeOfSurface(int x, int y)
{
    if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
        return true;
    return false;
}

void DepthFiller::fillRegion(int x, int y)
{
    std::vector<bool> passed(width * height, false);

    std::list<coords> fill, up, down;
    bool onEdge = false;
    fill.push_back( coords(x, y) );

    for (auto iter = fill.begin(); iter != fill.end(); ++iter)
    {
        int xn = iter->first;
        int yn = iter->second;

        auto nearestEqual = getNearestEqual(xn, yn, passed);
        fill.splice(fill.end(), nearestEqual);

        auto nearestUp = getNearestUp(xn, yn, passed);
        up.splice(up.end(), nearestUp);

        auto nearestDown = getNearestDown(xn, yn, passed);
        down.splice(down.end(), nearestDown);
    }

    uint min = std::numeric_limits<uint>::max();
    for (auto iter = up.begin(); iter != up.end(); ++iter)
    {
        int xn = iter->first;
        int yn = iter->second;

        if ( min > vertexArray[yn * width + xn] )
            min = vertexArray[yn * width + xn];

        if ( !onEdge && onEdgeOfSurface(xn, yn) )
            onEdge = true;
    }

    if (min == std::numeric_limits<uint>::max())
        return;

    for (auto iter = fill.begin(); iter != fill.end(); ++iter)
    {
        int xn = iter->first;
        int yn = iter->second;

        if (!onEdge)
            depthArray[yn * width + xn] += min - vertexArray[yn * width + xn];

        vertexArray[yn * width + xn] = min;
    }

    if (!down.empty())
    {
        auto &c = down.front();
        int xn = c.first;
        int yn = c.second;
        fillRegion(xn, yn);
    }

    if (!up.empty())
    {
        auto &c = up.front();
        int xn = c.first;
        int yn = c.second;
        fillRegion(xn, yn);
    }


//    std::list<coords> fill;
//    fill.push_back( coords(x, y) );

//    uint max = 0;

//    for (auto iter = fill.begin(); iter != fill.end(); ++iter)
//    {
//        int x = iter->first;
//        int y = iter->second;

//        auto nearest = getNearestUp(x, y);
//        fill.splice(fill.end(), nearest);

//        if ( max < vertexArray[y * width + x] )
//            max = vertexArray[y * width + x];
//    }

//    for (auto iter = fill.begin(); iter != fill.end(); ++iter)
//    {
//        depthArray[y * width + x] = max - vertexArray[y * width + x];
//        vertexArray[y * width + x] = max;
//    }
}
