#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <assert.h>
#include <fstream>

#include "depthfiller.h"
#include "test.h"

void processDataFromFile(const char *filename);

int main(int argc, char *argv[])
{
    switch (argc)
    {
    case 1:
        std::cout << "no input data" << std::endl;
        return 1;
    case 3:
        testAll(argv[2]);
        break;
    }

    processDataFromFile(argv[1]);

    return 0;
}

void processDataFromFile(const char *filename)
{
    std::ifstream file(filename, std::ios_base::in);

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
}






















