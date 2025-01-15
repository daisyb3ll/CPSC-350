#include <iostream>
#include "fileReader.h" // Assuming you have the file_reader.h header in the same directory
#include "Grid.h"

int main()
{
    srand(time(NULL));
    fileReader reader;
    const std::string fileName = "input.txt"; // Replace with your desired file name

    reader.readAndPrintFile(fileName);

    // int gridSize =  reader.gridSize;

    // Grid gridOut ( gridSize, gridSize);
    // gridOut.render();
    int gridSize = reader.gridSize;
    Grid gridOut (gridSize, gridSize);

    // Read the obstacle probabilities
    int chanceCoins = reader.percentCoins;
    int chanceMushrooms = reader.percentMushrooms;
    int chanceNothing = reader.percentNothing;
    int chanceKoopas = reader.percentKoopas;
    int chanceGoombas = reader.percentGoombas;

    // Populate the grid
    gridOut.populate(chanceCoins, chanceMushrooms, chanceNothing, chanceKoopas, chanceGoombas);

    gridOut.render();
    return 0;
    
}