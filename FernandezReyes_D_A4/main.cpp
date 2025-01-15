/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. Programming Assignment 4; Genetic Palindrome 
e. main.cpp
*/

#include <iostream>
#include "DblList.h"
#include "DNASeq.h"
#include "PalindromeFinder.h"
using namespace std;

int main(int argc, char *argv[])
{

    // Check if the user provided a file name as an argument
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <input_file_name>" << endl;
        return 1; // Exit with an error code
    }

    // Get the input file name from command line arguments
    string inputFileName = argv[1];

    cout << "=====this is testing my DblList.h=====" <<endl;
    DblList<int> myList;
    for(int i = 0; i < 10; ++i){
        myList.add(i,i);
    }

    myList.add(5,222);
    myList.addFront(14);
    myList.addBack(28);

    for(int i = 0; i < myList.getSize(); ++i){
        cout << myList.get(i) << endl;
    }

    cout << "======================" << endl;

    myList.removeFront();
    myList.remove(5);

    for(int i = 0; i < myList.getSize(); ++i){
        cout << myList.get(i) << endl;
    }

    cout << "===========DNA SEQ TEST===========" << endl; 

    // Test creating a DNA sequence
    DNASeq dna("ATCGAT"); // Example DNA strand
    cout << "Original DNA sequence: ";
    for (int i = 0; i < dna.dnaStrand.getSize(); ++i)
    {
        cout << dna.dnaStrand.get(i);
    }
    cout << endl;

    // Test complement
    DNASeq complement = dna.complement();
    cout << "Complement DNA sequence: ";
    for (int i = 0; i < complement.dnaStrand.getSize(); ++i)
    {
        cout << complement.dnaStrand.get(i);
    }
    cout << endl;

    // Test substring
    dna.substring(1, 4);
    cout << "Substring of DNA sequence (1 to 4): ";
    for (int i = 1; i < 4; ++i)
    {
        cout << dna.dnaStrand.get(i);
    }
    cout << endl;

    // Test isGeneticPalindrome
    bool isPalindrome = dna.isGeneticPalindrome();
    cout << "Is the DNA sequence a genetic palindrome? "
        << (isPalindrome ? "Yes" : "No") << endl;

    cout << "===========PALINDROMEFINDER===========" << endl;

    // Specify the input file name containing the DNA sequences
    // string inputFileName = "dna_sequences.txt";

    // Create a PalindromeFinder object, passing the input file name
    PalindromeFinder palindromeFinder(inputFileName);

    // Run the findPalindromes method to process the file and output results
    palindromeFinder.findPalindromes();

    return 0;
}