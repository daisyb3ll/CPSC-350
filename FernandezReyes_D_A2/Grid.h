/**
a. daisy zahory fernandez-reyes
b. 2397470
c. fernandezreyes@chapman.edu
d. cpsc 350-01
e. not so super mario bros; PA2
f. Grid.h
**/

#ifndef GRID_H
#define GRID_H
#include "fileReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Grid
{
    public:
    fileReader gettingValues;
    Grid(int rows, int columns);
    ~Grid();

    void render();                                 //?renders and displays the grid
    void populationGamble(); //?rename!
    //  int *x_coords, int *y_coords, int totalCells,
    void populate( int chanceCoins, int chanceMushrooms, int chanceNothing, int chanceKoopas, int chanceGoombas); // ? populates grid coordinate with item
    void wasd(int left, int right, int up, int down);//controls marios grid position
    void marioCoor(int marioPos);// generates mario on grid 'M' and marios starting position on grid
    void warpPipeCoor(int warpPos);//generates warp pipe position on the grid 

    private:
    char **grid;
    int rows, columns;
};

#endif
