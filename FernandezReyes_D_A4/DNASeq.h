/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. Programming Assignment 4; Genetic Palindrome 
e. DNASeq.h
*/

/*
DNASeq - a class to represent a single DNA sequence. It should contain:
A default constructor
A default destructor
An overloaded constructor that creates a sequence from a character string
A method DNASeq complement()that returns a DNA Sequence representing the complement.
A method DNASeq substring(int s, int e)that returns a DNA Sequence based on the substring from position s (inclusive) to position e (exclusive).
A method bool isGeneticPalindrome()that returns true if the sequence is a genetic palindrome and false otherwise.
*/

#ifndef DNASEQ_
#define DNASEQ_
#include <iostream>
#include <string>

#include "DblList.h"

using namespace std; 

class DNASeq
{
    public: 
    DNASeq();//constructor
    ~DNASeq();//destructor

    DNASeq(string s)
    {
    string dnaSequence = s; 
    };
    DNASeq complement();    // that returns a DNA Sequence representing the complement.
    DNASeq substring(int s, int e) const; // returns a DNA Sequence based on the substring from position s (inclusive) to position e (exclusive).
    bool isGeneticPalindrome();       // returns true if the sequence is a genetic palindrome and false otherwise.
    bool isValid();
    DblList<char>dnaStrand;//creates a dblList of nucleotides (a dna strand)
    string getDNASequence() const { return dnaSequence; } //!chat gpt rec; CAUTION!!!!

private:
    int length;
    string dnaSequence;
};
#endif
