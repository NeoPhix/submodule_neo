#ifndef DEPTHFILLER_H
#define DEPTHFILLER_H

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <assert.h>

using uint = unsigned int;
using coords = std::pair<int, int>;

class DepthFiller
{
public:
    DepthFiller() = delete;
    DepthFiller(std::vector<uint> vertexArray_, size_t width_, size_t height_);
    ~DepthFiller() = default;

    std::vector<uint> getDepthArray();

private:
    void fillRegion(int x, int y);

    std::list<coords> getEqualRegion(int x, int y);
    std::list<coords> getBorderListUp(std::list<coords> region);
    std::list<coords> getBorderListDown(std::list<coords> region);

    std::list<coords> getNearestUp   (int x, int y, std::vector<bool> &passed);
    std::list<coords> getNearestEqual(int x, int y, std::vector<bool> &passed);
    std::list<coords> getNearestDown (int x, int y, std::vector<bool> &passed);

    uint getMinimalHeight(std::list<coords> region);

    bool insideEdges(int x, int y);
    bool onEdgeOfSurface(int x, int y);
    bool connectedWithBorder(std::list<coords> region);

private:
    std::vector<uint> vertexArray;
    size_t width;
    size_t height;

    std::vector<uint> depthArray;

    static constexpr size_t directionsCount = 8;
    static constexpr std::array<int, directionsCount> dx = {-1,  0,  1, -1, 1, -1, 0, 1};
    static constexpr std::array<int, directionsCount> dy = {-1, -1, -1,  0, 0,  1, 1, 1};
};

#endif // DEPTHFILLER_H
