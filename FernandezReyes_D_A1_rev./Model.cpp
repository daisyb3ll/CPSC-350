/*
Daisy Fernandez-Reyes
2397470
CPSC-350-01
PA 1; Robber Language Translation
Model.cpp
*/

#include "Model.h"
#include <string>
#include <iostream>
using namespace std;

// constructy
Model::Model() {}
// destructy
Model::~Model() {}

// checks for vowels -> if isConsosnant is true then -> translate single consonant etc.
bool Model::isConsonant(char c)
{
    // if input c is a letter then it runs through the next condition
    if (isalpha(c))
    {
        // if c is NOT vowel (including caps) then isConsonant is true
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
        {
            // bc duh
            return true;
        }
    } // returns false if any of c are vowels
    return false;
}
// takes a single consonant and returns it doubled and adds an 'o' + returns as a string
string Model::translateSingleConsonant(char c)
{
    string input = "";
    if (isConsonant(c))
    {                          // runs if isConsonant is true
        input = string(1, c);  // creates string for input and adds c
        input += 'o';          // adds 'o' to string
        input += string(1, c); // adds another c (the same one -> doubled the consonant Yipee!!)
        return input;          // returns the change
    }
    return string(1, c);
}
// leaves vowels unchanged + returns as a string
string Model::translateSingleVowel(char c)
{
    // unchanged, is added/ made into to a string
    return string(1, c);
}