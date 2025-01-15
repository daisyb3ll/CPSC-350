/**
a. daisy zahory fernandez-reyes
b. 2397470
c. fernandezreyes@chapman.edu
d. cpsc 350-01
e. not so super mario bros; PA2
f. fileReader.h
**/

#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <iostream>
#include <string> 
using namespace std;

class fileReader{
    public:
        fileReader();
        ~fileReader();
        int readAndPrintFile(const string& fileName);

        //member variables
        int amountLevels;
        int gridSize;
        int totalLives;
        int percentCoins;
        int percentNothing;
        int percentKoopas;
        int percentGoombas;
        int percentMushrooms;

        //getters
        int getLevels() const;
        int getDimension() const;
        int getLives() const;
        //percent things
        int getCoins() const;
        int getNothing() const;
        int getGoombas() const;
        int getKoopas() const;
        int getMushrooms() const;

    private:
    int textArr[8]; //creates an empty array of 8 to hold input file values

};
#endif