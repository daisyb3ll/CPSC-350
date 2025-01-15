/*
    a. Daisy Zahory Fernandez-Reyes
    b. 2397370
    c. CPSC-350-01
    d. Programming Assignment 3; Do You See What I See
    e. SpeakerView.h
*/

/*
Your goal is to build a class, SpeakerView, that can take a plain text file that consists of N+2 lines.
The first line of the file will be the string  “BEGIN.” The last line of the file will be the string “END.”
Each of the N lines between the first and last will consist of P doubles (representing heights) separated by spaces. 
Your program will then use a monotonically decreasing stack to determine the number of people in each column 
of seats that are able to see the speaker clearly, as well as the heights of those people. 
Your output can be displayed to the terminal but should be descriptive so it is easy to understand. 
Your SpeakerView class should be as OO as possible.

1. takes plain text files 
2. takes input as doubles seperated by spaces
3. uses a mono decreasing stack to find num people in the columns that can see
4. output is displayed to terminal
*/


/*
REFERENCED SOLUTTION:
Parsing I/O values into a 2D Array
"while stack is not empty AND top of stack is more
than the current element pop element from the stack"
https://youtu.be/VVaPI5RSJCM?si=N4Iwk5-XHGq7wRxQ
*/

#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.h"
#include <iostream>
using namespace std; 

class SpeakerView
{
public:
    SpeakerView(string inputFileName); //takes in filename 
    ~SpeakerView(); // deconstructor
    void fileReader(); // reads file input ( initialized to 30 bc i didnt think we would need more)
    void displayOutput(); // displays the output in terminal 

    int lineNum; // keeps track of the number of lines in the code
    int colNum; // used to keep track of columns made from first line
private:
    string infileName; //takes input file name arg from terminal
    int numRows; // duh
    int numCols; // mb that was rude ^ keeps track of number of rows , this keeps track of numColumns
    MonoStack<double>* stack; //creates monostack instance
    double** viewerHeight; //stores viewerHeights
};

#endif