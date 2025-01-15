/*
Daisy Fernandez-Reyes
2397470
CPSC-350-01
PA_1; Robber Language Translation
Translator.h
*/

/*
The Translator Class
You will build a class named Translator that will translate English sentences to Rövarspråket sentences using the Model class. The class will contain the following public methods:
● A default constructor
● A default destructor
● translateEnglishWord – takes a single string representing a single English word as input
and returns a string representing the Rövarspråket translation.
● translateEnglishSentence – takes a single string representing a single English sentence
as input and returns a string representing the Rövarspråket translation. Make sure to account for punctuation.
*/

#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include "Model.h"
#include <string>
#include <iostream>
using namespace std;

class Translator
{
public:
    //constructy destructy
    Translator();
    ~Translator();
    // core functions
    string translateEnglishWord(string singleWord);
    string translateEnglishSentence(string sentence);

private:
    // creates an instance of Model Object for declaration
    Model model;
};
#endif
