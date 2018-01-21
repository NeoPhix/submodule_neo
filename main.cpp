#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <assert.h>
#include <fstream>

#include "depthfiller.h"
#include "test.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "need input data file" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1], std::ios_base::in);

    size_t width = 0;
    size_t height = 0;
    std::vector<uint> vertexArray;

    if ( file.is_open() )
    {
        file >> width;
        file >> height;

        vertexArray.resize(width * height);

        for (size_t i = 0; i < vertexArray.size(); ++i)
        {
            file >> vertexArray[i];
        }
    }
    else
    {
        std::cout << "cannot open input data file" << std::endl;
        return 2;
    }

    file.close();

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

    test();

    return 0;
}
























