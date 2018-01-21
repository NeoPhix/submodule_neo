#include <vector>
#include <ctime>
#include "depthfiller.h"

static constexpr size_t maxWidth = 30;
static constexpr size_t maxHeight = 30;
static constexpr uint maxDepth = 8;

bool test()
{
    srand(time(0));

    size_t width = 1 + rand() % maxWidth;
    size_t height = 1 + rand() % maxHeight;

    std::vector<uint> depthArray(width * height);
    std::vector<uint> vertexArray(width * height, maxDepth);

    for (uint &depth : depthArray)
        depth = rand() % (maxDepth + 1);

    for (size_t i = 0; i < vertexArray.size(); ++i)
    {
        vertexArray[i] = maxDepth + 1 - depthArray[i];
    }

//////////////////////////////

    std::cout << "Input vertices:" << std::endl;

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            std::cout << vertexArray[y * width + x] << ", ";
        }
        std::cout << std::endl;
    }

    DepthFiller filler(vertexArray, width, height);
    std::vector<uint> deep = filler.getDepthArray();

    std::cout << "Output depth:" << std::endl;

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            std::cout << deep[y * width + x] << ", ";
        }
        std::cout << std::endl;
    }

    return true;
}
