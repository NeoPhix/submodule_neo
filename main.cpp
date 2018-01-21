#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <assert.h>

#include "depthfiller.h"

//bool isSink(size_t x, size_t y, std::vector<uint> vertexArray, size_t width, size_t height); //ask Anya about variables order in func signature

int main()
{    
    size_t width = 10;
    size_t height = 10;

    std::vector<uint> vertexArray = {0, 0, 0, 0, 0, 0, 1, 0, 5, 1,
                                     0, 5, 5, 5, 5, 0, 1, 0, 5, 1,
                                     0, 5, 2, 3, 5, 0, 1, 0, 5, 1,
                                     0, 5, 2, 3, 5, 5, 5, 5, 5, 1,
                                     0, 5, 2, 3, 5, 4, 2, 6, 5, 1,
                                     0, 5, 2, 3, 5, 4, 2, 6, 5, 1,
                                     0, 5, 2, 3, 5, 4, 2, 6, 5, 1,
                                     0, 5, 2, 3, 5, 4, 2, 6, 5, 1,
                                     0, 5, 2, 3, 5, 4, 2, 6, 5, 1,
                                     0, 5, 5, 5, 5, 5, 5, 5, 5, 1};



    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            std::cout << vertexArray[y * width + x] << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    DepthFiller filler(vertexArray, width, height);
    std::vector<uint> deep = filler.getDepthArray();

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            std::cout << deep[y * width + x] << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}
























