/**
a. daisy zahory fernandez-reyes
b. 2397470
c. fernandezreyes@chapman.edu
d. cpsc 350-01
e. not so super mario bros; PA2
f. Grid.cpp
**/

//@authors note: I am fighting for my life!!!

#include "Grid.h"
#include "fileReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

fileReader reader;
Grid::Grid(int rows, int columns) : rows(rows), columns(columns)
{
    grid = new char *[rows];

    for (int i = 0; i < rows; i++){
        grid[i] = new char [columns];
        for(int j = 0; j < columns ; j++){
            grid[i][j] = ' ';
        }
    }
}

Grid::~Grid(){
    // Deallocate each row
    for (int i = 0; i < rows; ++i)
    {
        delete[] grid[i];
    }
    // Deallocate the array of pointers
    delete[] grid;
}

void Grid :: render(){
    ofstream logFile("log.txt",ios::app);
    if(!logFile.is_open()){
        cerr<< "failed to open log.txt from the grid.cpp!! " << endl;
        return;
    }

    if(logFile.is_open()){

    logFile <<" Level: " << reader.amountLevels << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            logFile << "[" << grid[i][j] << " ]";
        }
        logFile << endl;
    }
    logFile.close();
    }
}
//int* x_coords, int* y_coords, int totalCells,
void Grid::populate(int chanceCoins, int chanceMushrooms, int chanceNothing, int chanceKoopas, int chanceGoombas)
{
    int totalCells = rows * columns;
    int* x_coords = new int[totalCells];
    int* y_coords = new int[totalCells];
    
//     for (int i = 0; i <totalCells; i++){
//         int x = x_coords[i];
//         int y = y_coords[i];
//         int random = rand () % 100;

//     if (random < chanceCoins)
//     {
//         grid[x][y] = 'c';
//     }
//     else if (random < chanceCoins + chanceMushrooms)
//     {
//         grid[x][y] = 'm';
//     }
//     else if (random < chanceCoins + chanceMushrooms + chanceKoopas)
//     {
//         grid[x][y] = 'k';
//     }
//     else if (random < chanceCoins + chanceMushrooms + chanceKoopas + chanceGoombas)
//     {
//         grid[x][y] = 'g';
//     }
//     else
//     {
//         grid[x][y] = ' '; 
//     }
// }
 for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int random = rand() % 100;

            if (random < chanceCoins) {
                grid[i][j] = 'c';
            } else if (random < chanceCoins + chanceMushrooms) {
                grid[i][j] = 'm';
            } else if (random < chanceCoins + chanceMushrooms + chanceKoopas) {
                grid[i][j] = 'k';
            } else if (random < chanceCoins + chanceMushrooms + chanceKoopas + chanceGoombas) {
                grid[i][j] = 'g';
            } else {
                grid[i][j] = ' ';
            }
        }
    }
}




void Grid:: populationGamble(){
    fileReader gettingValues;
    
    int size_N;
    int chanceCoins;
    int chanceMushrooms;
    int chanceNothing;
    int chanceKoopas;
    int chanceGoombas;

    chanceCoins = gettingValues.percentCoins;
    chanceMushrooms = gettingValues.percentMushrooms;
    chanceNothing = gettingValues.percentNothing;
    chanceKoopas = gettingValues.percentKoopas;
    chanceGoombas = gettingValues.percentGoombas;
    size_N = gettingValues.gridSize;

    int totalCells = size_N * size_N;
    int* x_coords = new int[totalCells];
    int* y_coords = new int[totalCells];


        int index = 0;
        for (int x = 0; x < size_N; ++x)
        {
            for (int y = 0; y < size_N; ++y)
            {
                x_coords[index] = x;
                y_coords[index] = y;
                ++index;
            }
        }
        for (int i = totalCells - 1; i > 0; --i)
        {
            int j = rand() % (i + 1);
            std::swap(x_coords[i], x_coords[j]);
            std::swap(y_coords[i], y_coords[j]);
        }

populate(chanceCoins, chanceMushrooms, chanceNothing, chanceKoopas, chanceGoombas);
//x_coords, y_coords, totalCells
delete[] x_coords;
delete[] y_coords;
}