#include <vector>
#include <list>
#include <ctime>
#include <fstream>
#include <string>
#include "depthfiller.h"
#include "test.h"

static constexpr size_t maxWidth = 30;
static constexpr size_t maxHeight = 30;
static constexpr uint maxDepth = 8;

bool testAll(const char *filePath)
{
    std::ifstream file(filePath, std::ios_base::in);
    std::string str;

    bool succesfully = true;

    while ( std::getline(file, str) )
    {
        if ( test( str.c_str() ) )
        {
            std::cout << "test " << str.c_str() << " has passed successfully" << std::endl;
        }
        else
        {
            std::cout << "test " << str.c_str() << " has failed" << std::endl;
            succesfully = false;
        }
    }

    return succesfully;
}

bool test(const char *filePath)
{
    std::ifstream file(filePath, std::ios_base::in);

    size_t width = 0;
    size_t height = 0;
    std::vector<uint> vertexArray;
    std::vector<uint> depthArray;

    if ( file.is_open() )
    {
        file >> width;
        file >> height;

        vertexArray.resize(width * height);
        depthArray.resize(width * height);

        for (size_t i = 0; i < vertexArray.size(); ++i)        //input array
            file >> vertexArray[i];

        for (size_t i = 0; i < depthArray.size(); ++i)         //right output
            file >> depthArray[i];
    }
    else
    {
        std::cout << "cannot open input test file" << std::endl;
        return false;
    }

    file.close();

    DepthFiller filler(vertexArray, width, height);
    std::vector<uint> estimatedDepthArray = filler.getDepthArray();

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            if (estimatedDepthArray[y * width + x] != depthArray[y * width + x])    //mismatch
                return false;
        }
    }

    return true;
}
