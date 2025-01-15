/*
    a. Daisy Zahory Fernandez-Reyes
    b. 2397370
    c. CPSC-350-01
    d. Programming Assignment 3; Do You See What I See
    e. SpeakerView.h
    balls
*/


#include "SpeakerView.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

// 1. takes plain text files .(takes inputfile name and creates a stack of 30 ( im sure its more than enough))
SpeakerView::SpeakerView(string nameOfFile)
{
    infileName = nameOfFile;
    stack = new MonoStack<double>(30, 'd'); // im only setting it to 30 bc it seems like a 5 by 4 grid is 20, 30 seems like more than enough maybe 50 to be safe? \
/* jnsdocoamsca;sc



}

//destructor for trash 
SpeakerView::~SpeakerView()
{
    delete stack;
}

// 2. takes input as doubles seperated by spaces
//3. uses a mono decreasing stack to find num people in the columns that can see
void SpeakerView::fileReader()
{
        ifstream inputFile(infileName);
        string line;

        int numLines = 0;
        int numColumns = 0;

        // First pass to count number of lines and columns
        if (inputFile.is_open())
        {
            while (getline(inputFile, line))
            {
                /*`
                REFERENCED SOLUTION:
                npos : https://www.naukri.com/code360/library/string-npos-in-cpp
                */
                if (line.find("BEGIN") != std::string::npos || line.find("END") != std::string::npos)
                {
                    continue; // Skip BEGIN and END lines
                }
                /*
                REFERENCED SOLUTION:
                https://cplusplus.com/forum/beginner/157617/
                    forum comment by user, TarikNeaj (2580): 
                        "A very simple way of counting the amount of spaces is
                        1
                        2
                        3
                        4
                        5
                        int main() {
                            string s = "Hello there, world!";
                        SOURCE OF COMPILATION ERROR: cout << count( s.begin(), s.end(), ' ' ) << sendl;
                                                            ^ count is a part of <algorithm. library
                        }
                        This is the only way I know.
                        This will be the output -
                        2
                        Because there is 2 spaces in "Hello there, world!"
                    */
                numLines++; // Increment line count

                if (numLines == 1) // Count columns only for the first valid line
                {
                    //actual intended solution:
                    // numColumns = count(line.begin(), line.end(), ' ')+ 1; compilation error 
                    
                    numColumns = 1; 
                    for (char c : line)
                    {
                        if (c == ' ')
                        {
                            numColumns++;
                        }
                    }
                }
            }
            inputFile.close(); // Close after counting
        }
        else
        {
            cerr << "Unable to open file: " << infileName << endl;
            return;
        }

        // Allocate memory for viewerHeight 2D array
        viewerHeight = new double *[numLines];
        for (int i = 0; i < numLines; i++)
        {
            viewerHeight[i] = new double[numColumns];
        }

        // Reopen file to read data into array
        inputFile.open(infileName);
        if (inputFile.is_open())
        {
            int lineNum = 0;

            while (getline(inputFile, line))
            {
                if (line.find("BEGIN") != std::string::npos || line.find("END") != std::string::npos)
                {
                    continue;
                }

                int cols = 0;
                stringstream ss(line);
                string temp;

                while (ss >> temp) // Read each space-separated value in the line
                {
                    try
                    {
                        viewerHeight[lineNum][cols] = stod(temp); // Convert string to double
                        cols++;
                    }
                    catch (const invalid_argument &e)
                    {
                        cerr << "Error: Invalid number '" << temp << "' at line " << lineNum << endl;
                    }
                }

                lineNum++;
            }
            

            inputFile.close(); // Close after reading all data
        }
        else
        {
            cerr << "Unable to open file: " << infileName << endl;
        }

        this->numCols = numColumns;
        this->numRows = numLines;
    }

//4. output is displayed to terminal
void SpeakerView::displayOutput()
    {
        for (int columns = 0; columns < numCols; columns++)
            {
                double maxHeight = 0;
               // stack->push(viewerHeight[i][columns]);
                
                //adds people to stack based on height
                for (int i = 0; i < numRows ; i++)
                {
                    if (viewerHeight[i][columns] > maxHeight) // if the curr viewer is taller than the maxHeight person
                    {
                        stack->push(viewerHeight[i][columns]); //pushed new tallest to Stack
                        maxHeight = viewerHeight[i][columns]; // maxHeight re-declared to curr
                    }
                }
            
            cout << "In column " << columns << " there are " << stack->size() << " that can see. Their heights are: "; //outputs to teminal
            while (!stack->isEmpty()) //pops and prints heights while stack is still populated
            {
                cout << stack->pop();
                if (!stack->isEmpty()) 
                {
                    cout << ","; //this sucked to print btw- i could not figure this out for the life of me. Shoutout to Julianna!!! 
                }
                else
                {
                    cout << " inches." << endl;
                }
            }
        }
    }

