/*
    a. Daisy Zahory Fernandez-Reyes
    b. 2397370
    c. CPSC-350-01
    d. Programming Assignment 3; Do You See What I See
    e. SpeakerView.h
*/

#include "SpeakerView.h"
#include <iostream>


//yoinked this from gemeni that is entirely on me.  I couldnt figure out the 
//cerr part. 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./SpeakerView<inputFileName>";
        return 1;
    }
    
    SpeakerView speakerView(argv[1]);
    speakerView.fileReader();
    speakerView.displayOutput();
    
    return 0;
}