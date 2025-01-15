// /**
// a. daisy zahory fernandez-reyes
// b. 2397470
// c. fernandezreyes@chapman.edu
// d. cpsc 350-01
// e. not so super mario bros; PA2
// f. Levels.h
// **/

// #ifndef LEVELS_H
// #define LEVELS_H
// #include "Grid.h"
// #include "fileReader.h"
// #include <fstream>
// #include <iostream>
// #include <string>
// using namespace std;

// class Levels
// {
//     public:
//     fileReader reader;
//     Grid gridObj; //creates grid object
//     Levels();
//     ~Levels();

//     void levelStatus(string levelNumber, bool isntFinalLevel); // prints level status
//     void flatEarth();//rules of the torus 
//     void wasdMove(); // marios movements -> calls grid printing to Log with every single movement 
//     void marioCoords();//places mario on a random noting spot in the grid ( parse the grid to find 'x')
//     void warpCoords(); //places warp pipe on a random nothing spot in the grid ( parses the grid to find x)
//                         // contains logic to move up to next level 

//     private:

// };
// #endif