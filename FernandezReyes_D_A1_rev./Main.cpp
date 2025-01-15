/*
Daisy Fernandez-Reyes
2397470
CPSC-350-01
PA_1; Robber Language Translation
Main.cpp
*/

#include <iostream>
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
int main()
{
    // Create an instance of the Model class
    Model model;
    Translator translator;
    fileProcessor file;
    // testing fileProcessor
    file.processFile("input.txt", "output.html");
    // message to check a run
    cout << "this totally works" << endl;
    return 0;
};