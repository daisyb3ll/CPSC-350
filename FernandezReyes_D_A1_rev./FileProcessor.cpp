/*
daisy fernandez-reyes
2397470
CPSC-350-01
PA_1; Robber Language Translation
fileProcessor.cpp
*/
#include "Translator.h"
#include "Model.h"
#include "FileProcessor.h"
#include <string>
#include <fstream>
#include <iostream>

Translator fileProcessor::translate;

// construcy destrucy
fileProcessor::fileProcessor() {}
fileProcessor::~fileProcessor() {}

// core functions
// turns input into bold
string fileProcessor::textBold(string b)
{
    return "<b>" + b + "<b>";
}
// turns input into itallics
string fileProcessor::textItalics(string i)
{
    return "<i>" + i + "<i>";
}
// uhhusuhshshsuhu hhdusuhshhhuhshshshhh
// processes file (input.txt) and iterates through it using translator to then output using html
void fileProcessor::processFile(string inputFile, string outputFile)
{
    string inputText;
    string processedText;
    ifstream input(inputFile);
    ofstream output(outputFile);
    int lineNumber = 1;

    if (input.is_open())
    {
        while (getline(input, inputText))
        {
            processedText += translate.translateEnglishWord(inputText);
            if (lineNumber == 1)
            {
                output << processedText(inputText) << "<br>";
            }else{
                output << textItalics(inputText) << "<br>";
            }
            lineNumber++;
        }
    
    }
    // if somethings wrong it displays this
    else
    {
        cout << "oops! your files funk! try again!" << endl;
    }
}