/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. Programming Assignment 4; Genetic Palindrome
e. PalindromeFinder.h
*/

#ifndef PALINDROMEFINDER_H
#define PALINDROMEFINDER_H

#include "DNASeq.h"
#include <iostream>
using namespace std; 

class PalindromeFinder
{
public:
    PalindromeFinder(); // DNT
    PalindromeFinder(const std::string &inputFileName);
    //PalindromeFinder(const std::string& inputFileName);
    void findPalindromes();
    void setSequence(string s);

private:
    string inputFileName;
    DNASeq* sequence;
};
#endif