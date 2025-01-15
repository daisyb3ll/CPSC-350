/*
daisy fernandez-reyes
2397470
CPSC-350-01
programming assignment 1;  robber language translation
fileProcessor.h
*/

/*
The FileProcessor Class
You will build a class named FileProcessor that will take text files (.txt)
 containing English text and produce a HTML file containing the equivalent
 Rövarspråket translation that can be viewed in a standard web browser.
  The class will contain the following public methods:
● A default constructor
● A default destructor
● processFile – takes a string representing the input file (English) and a string
representing the output file (where the Rövarspråket translation will be written).
 This method has a void return type. The method should produce an HTML file that
 has the original English text in bold followed by an empty line, followed by the
  Rövarspråket translation in italics. If you are not familiar with HTML,
  a simple tutorial is available here:
   https://html.com/#Creating_Your_First_HTML_Webpage
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include "Model.h"
#include "Translator.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class fileProcessor
{
public:
    // constructy destructy
    fileProcessor();
    ~fileProcessor();
    // core functionalities
    // translates things into bolded text
    static string textBold(string b);
    // translates text into italicized text
    static string textItalics(string i);
    // processes file and calls both ^ up to output them
    static void processFile(string inputFile, string outputFile);

private:
    // creates static instance of translator
    static Translator translate;
};
#endif