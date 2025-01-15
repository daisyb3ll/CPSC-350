// /**
// a. daisy zahory fernandez-reyes
// b. 2397470
// c. fernandezreyes@chapman.edu
// d. cpsc 350-01
// e. not so super mario bros; PA2
// f. Levels.cpp
// **/
// #include "Levels.h"
// #include "Grid.h"
// #include "fileReader.h"
// #include <fstream>
// #include <iostream>
// #include <string>
// using namespace std;

// Levels::Levels()
// {  
//    reader.getLevels();
//    gridObj.render();

// }
// Levels::~Levels()
// {}

// void Levels::marioCoords()
// {
//     gridObj.render();
//      if (emptyCoords > 0)
//      {
//         int randomCell = rand()% emptyCoords;

//         int emptyCoordsPos = 0;
//         for (int i = 0; i < rows; i++){
//             for (int j = 0; j < columns; j++){
//                 if (grid[i][j] == 'x'){
//                     if(emptyCoordsPos == randomCell){
//                         grid[i][j] == 'M'; //mario placement
//                         return i = marioX, j = marioY;
//                     }
//                     emptyCoordsPos ++;
//                 }
//             }
//         }
//      }
// }

// void Levels::wasdMove(int marioX, int marioY)
// {
//     if (marioX != -1 && marioY != -1)
//     {
//         cout << "mario is at coord [" << marioX << "], " << "[" << marioY << "]" <<endl;
//     }


//     char wasd;
//     cout << "enter direction in wasd format: ";
//     cin >> wasd;

//     if (wasd == 'w')
//     {
//         marioY += 1;
//     }
//     else if ( wasd == 's')
//     {
//         marioX -= 1;
//     }
//     else if ( wasd == 'a')
//     {
//         marioY -= 1;
//     }
//     else if (wasd == 'd')
//     {
//         marioY += 1;
//     }
// }

// #include <iostream>
// #include "Grid.h"
// #include "fileReader.h"

// int main()
// {
//     srand(time(NULL));

//     // Read input file
//     const std::string fileName = "input.txt"; // Replace with your desired file name
//     fileReader reader;
//     reader.readAndPrintFile(fileName);

//     // Get grid size from reader
//     int gridSize = reader.getDimension();

//     // Create the grid
//     Grid gridOut(gridSize, gridSize);

//     // Read obstacle probabilities
//     int chanceCoins = reader.getCoins();
//     int chanceMushrooms = reader.getMushrooms();
//     int chanceNothing = reader.getNothing(); // Assuming 'nothing' is represented by 'x'
//     int chanceKoopas = reader.getKoopas();
//     int chanceGoombas = reader.getGoombas();

//     // Populate the grid and get Mario's placement
//     int marioRow, marioCol;
//     std::tie(marioRow, marioCol) = gridOut.populate(chanceCoins, chanceMushrooms, chanceKoopas, chanceGoombas);

//     if (marioRow != -1 && marioCol != -1)
//     {
//         std::cout << "Mario is placed at row " << marioRow << ", column " << marioCol << std::endl;
//     }
//     else
//     {
//         std::cerr << "Error: Mario could not be placed." << std::endl;
//         return 1; // Indicate error if Mario placement fails
//     }

//     // Render the grid with Mario
//     gridOut.render();

//     // Basic WASD movement (optional)
//     while (true)
//     {
//         char wasd;
//         std::cout << "Enter direction (WASD) or 'q' to quit: ";
//         std::cin >> wasd;

//         if (wasd == 'q')
//         {
//             break;
//         }

//         // Update Mario's position (handle boundary checks and collisions)
//         // Update grid and render based on movement
//         // (This part requires additional logic for movement validation)
//     }

//     return 0;
// }