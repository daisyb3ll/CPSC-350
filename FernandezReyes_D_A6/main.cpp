// a. Daisy Zahory Fernandez-Reyes
// b. 2397370
// c. Data Structures: CPSC - 350 - 01
// d. Programming Assignment 6: Spanning the Gamut
// e. main.cpp

#include "WGraph.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    //fileread implementation 
    try
    {
        // Open input file & takes input filename "input.txt"
        std::ifstream inputFile(filename);
        if (!inputFile)
        {
            //obligatory throw
            throw std::runtime_error("Error: Unable to open file " + filename);
        }

        //declare int
        unsigned int size;
        //takes graph size from input node 1 i.e.7
        inputFile >> size;

        if (size == 0)
        {
            throw std::runtime_error("graph empty :(");
        }

        // Initialize WGraph with size
        WGraph graph(size);

        // reads matrix and adds
        for (unsigned int i = 0; i < size; ++i)
        {
            for (unsigned int j = 0; j < size; ++j)
            {
                double weight;//initializes weight as double
                inputFile >> weight;//outputs from file
                    //adds weights
                    graph.addEdge(i, j, weight);
                
            }
        }

        //runs until "END"
        std::string end;
        inputFile >> end;
        if (end != "END")
        {
            throw std::runtime_error("file must end with END- or it'll just go forever!!!");
        }
        inputFile.close();
        //output MST
        double mstCost = graph.computeMST();
        std::cout << "The MST Cost is: " << mstCost << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
