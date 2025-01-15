/**
a. daisy zahory fernandez-reyes
b. 2397470
c. fernandezreyes@chapman.edu
d. cpsc 350-01
e. not so super mario bros; PA2
f.fileReader.cpp
**/
#include "fileReader.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// initialize constructor & populate w nothing
fileReader::fileReader()
{
    amountLevels = 0;
    gridSize = 0;
    totalLives= 0;
    percentCoins = 0;
    percentKoopas = 0;
    percentGoombas = 0;
    percentMushrooms = 0;
}
// destructor
fileReader::~fileReader() {}

int fileReader:: readAndPrintFile(const string &fileName)
{
    //opes the file
    ifstream input(fileName);
    ofstream logFile("log.txt");

    std::string text;
    // opening the file
    cout << "reading input file !!!!" << endl;
    cout << "building world ..." << endl;
    
    logFile<<" Not So Super Mario Bros; gameplay log.txt" << endl;
    // if (!input.is_open())
    // {
    //     cout << "oops! somethings wring with your input file!!" << endl;
    //     return 1;
    // }
    
    if (!logFile.is_open()) {
        cerr << "Failed to open log file" << endl;
        return 1;
    }


    if (input.is_open())
    {
        cout << "input file is open!! reading the odds rnrnr" << endl;

        int i = 0;
        while (getline(input,text) && i < 9)
        {

            // NOT MY CODE:
            // PROMPT ASKED "why am I stuck in a "while loop check"
            //daisy@computadora FernandezReyes_D_A2 % ./plug
            //reading input file !!!!
            //building world ...
            //input file is open!! reading the odds rnrnr
            //while loop check
            //while loop check
            //while loop check
            //while loop check
            //while loop check
            //while loop check
            //while loop check
            //daisy@computadora FernandezReyes_D_A2 % "
            // CODE STARTS HERE:

            try
            {
                textArr[i] = stoi(text);
                logFile<<"line #  "<< i+1 << " : " << textArr[i] << endl;

                switch(i){
                case 1:
                    amountLevels = textArr[0];
                    break;
                case 2:
                    gridSize = textArr[1];
                    break;
                case 3:
                    totalLives = textArr[2];
                    break;
                case 4:
                    percentCoins = textArr[3];
                    break;
                case 5:
                    percentNothing = textArr[4];
                    break;
                case 6:
                    percentGoombas = textArr[5];
                    break;
                case 7:
                    percentKoopas = textArr[6];
                    break;
                case 8:
                    percentMushrooms = textArr[7];
                    break;
                }
                i++;

                // if (i == 1)
                // {
                //     amountLevels = textArr[0]; // # levels is stored at textArr[0]
                // }
                // //"check for progress"
                // else if (i == 2)
                // {
                //     gridSize = textArr[1]; // dimension of grid is stored at textArr[1]
                // }
                // else if (i == 3)
                // {
                //     totalLives = textArr[2]; // # of initial lives is stored at textArr[2]
                // }
                // else if (i == 4)
                // {
                //     percentCoins = textArr[3]; // % of coins is stored at textArr[3]
                // }
                // else if (i == 5)
                // {
                //     percentNothing = textArr[4]; // % of nothing is stored at textArr[4]
                // }
                // else if (i == 6)
                // {
                //     percentGoombas = textArr[5]; // % of goombas is stored at textArr[5]
                // }
                // else if (i == 7)
                // {
                //     // idk why tf gemeni is insitent on killing this
                //     percentKoopas = textArr[6]; // % of koopas is stored at textArr[6]
                // }
                // else if (i == 8)
                // {
                //    percentMushrooms = textArr[7]; // % of mushrooms is stored at textArr[6]
                // }
            }
            catch (const std::invalid_argument &e)
            {

                cerr << "Error: invalid input on line" << i + 1 << endl;
                return 1;
            }
        }
        if(i < 9){
            cout<<"this runs (check for less than 8 lines)"<<endl;
            cerr<<"Error: Input file has fewer than 8 lines"<<endl;
            return 1;
        }
        input.close();
    }
    return 0;
}

int fileReader::getLevels() const
{
    return amountLevels;
}

int fileReader::getDimension() const
{
    return gridSize;
}

int fileReader::getLives() const
{
    return totalLives;
}

int fileReader::getCoins() const
{
    return percentCoins;
}

int fileReader::getNothing() const
{
    return percentNothing;
}

int fileReader::getGoombas() const
{
    return percentGoombas;
}

int fileReader::getKoopas() const
{
    return percentKoopas;
}

int fileReader::getMushrooms() const
{
    return percentMushrooms;
}