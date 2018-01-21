#include "depthfiller.h"

DepthFiller::DepthFiller(std::vector<uint> vertexArray_, size_t width_, size_t height_)
    : vertexArray(vertexArray_),
      width(width_),
      height(height_)
{
    assert(vertexArray.size() == width * height);
    depthArray.resize(vertexArray.size(), 0);
}

std::vector<uint> DepthFiller::getDepthArray() //todo vector.size == 0
{
    fillRegion(6, 3);
    return depthArray;
    return vertexArray;
}

void DepthFiller::fillRegion(int x, int y)
{
    auto fillingRegion = getEqualRegion(x, y);
    auto upBorderList = getBorderListUp(fillingRegion);
    auto downBorderList = getBorderListDown(fillingRegion);

    uint currentHeight = vertexArray[y * width + x];

    if (downBorderList.empty())
    {
        bool connected = connectedWithBorder(fillingRegion);
        auto min = getMinimalHeight(upBorderList);

        for (auto iter = fillingRegion.begin(); iter != fillingRegion.end(); ++iter)
        {
            int xn = iter->first;
            int yn = iter->second;

            if (!connected)
                depthArray[yn * width + xn] += min - vertexArray[yn * width + xn];

            vertexArray[yn * width + xn] = min;
        }
    }
    else
    {
        for (auto iter = downBorderList.begin(); iter != downBorderList.end(); ++iter)
        {
            int xn = iter->first;
            int yn = iter->second;

            uint downHeight = vertexArray[yn * width + xn];
            if (downHeight < currentHeight)
                fillRegion(xn, yn);
        }
    }

    for (auto iter = upBorderList.begin(); iter != upBorderList.end(); ++iter)
    {
        std::vector<bool> passed(width * height, false);
        int xn = iter->first;
        int yn = iter->second;

        auto down = getNearestDown(xn, yn, passed);

        if (!down.empty())
            fillRegion(xn, yn);
    }

//    debugOutput();
}

std::list<coords> DepthFiller::getEqualRegion(int x, int y)
{
    std::vector<bool> passed(width * height, false);
    std::list<coords> region;
    region.push_back(coords(x, y));

    for (auto iter = region.begin(); iter != region.end(); ++iter)
    {
        int xn = iter->first;
        int yn = iter->second;

        auto equals = getNearestEqual(xn, yn, passed);
        region.splice(region.end(), equals);
    }
    return region;
}


std::list<coords> DepthFiller::getBorderListUp(std::list<coords> region)
{
    std::vector<bool> passed(width * height, false);
    std::list<coords> result;
    for (auto iter = region.begin(); iter != region.end(); ++iter)
    {
        int xn = iter->first;
        int yn = iter->second;

        auto nearestUp = getNearestUp(xn, yn, passed);
        result.splice(result.end(), nearestUp);
    }
    return result;
}


std::list<coords> DepthFiller::getBorderListDown(std::list<coords> region)
{
    std::vector<bool> passed(width * height, false);
    std::list<coords> result;
    for (auto iter = region.begin(); iter != region.end(); ++iter)
    {
        int xn = iter->first;
        int yn = iter->second;

        auto nearestUp = getNearestDown(xn, yn, passed);
        result.splice(result.end(), nearestUp);
    }
    return result;
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

uint DepthFiller::getMinimalHeight(std::list<coords> region)
{
    uint min = std::numeric_limits<uint>::max();
    for (auto iter = region.begin(); iter != region.end(); ++iter)
    {
        int xn = iter->first;
        int yn = iter->second;

        if (min > vertexArray[yn * width + xn])
            min = vertexArray[yn * width + xn];
    }
    return min;
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

bool DepthFiller::connectedWithBorder(std::list<coords> region)
{
    for (auto iter = region.begin(); iter != region.end(); ++iter)
    {
        int xn = iter->first;
        int yn = iter->second;

        if ( onEdgeOfSurface(xn, yn) )
            return true;
    }
    return false;
}

void DepthFiller::debugOutput()
{
    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            std::cout << vertexArray[y * width + x] << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            std::cout << depthArray[y * width + x] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------" << std::endl;
}
