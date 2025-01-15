/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. Programming Assignment 4; Genetic Palindrome
e. PalindromeFinder.cpp
*/


//!! UNDERCONSTRUCTIONNN!!!  
#include "PalindromeFinder.h"
#include "DNASeq.h"
#include <iostream>
#include <fstream>

using namespace std;

PalindromeFinder::PalindromeFinder()
{
    sequence = new DNASeq();
}

PalindromeFinder::PalindromeFinder(const std::string &inputFileName)
{
    this ->inputFileName = inputFileName;
    sequence = new DNASeq();
}

void PalindromeFinder::setSequence(std::string s)
{   
    sequence = new DNASeq(s);
}
void PalindromeFinder::findPalindromes()
{
    ifstream infile(inputFileName);

    if(!infile.is_open())
    {
        cout<<"error opening file. please try again. :("<<endl; 
        return;
    }
    string line;

    while(getline(infile,line))
    {
        if (line == "Input:")
        {
            continue;
        }
        if (line == "END")
        {
            break;
        }

        setSequence(line);
        cout << line;





        // palindromes(line);
        if(!sequence->isValid())
        {
            cout << " - INVALID" << endl;
            continue;
        }
        cout << " - VALID" << endl;

            if (sequence->isGeneticPalindrome())
            {
                cout << "    " << line << " - Genetic Palindrome " << endl;
            }
            else
            {
                bool foundPalindrome = false;
                    for(int len = 4; len <= sequence->dnaStrand.getSize(); len++)
                    for (int i = 0; i <=sequence -> dnaStrand() - len; i++)
                    {
                        DNASeq temp = sequence -> substring(i,i + len);
                        if (temp.isGeneticPalindrome())
                        {
                            cout < "    Substring: " << temp.dnaSequence<< " - Genetic Palindrome >:( \n";
                        } 
                    }
                }
            }
    }





                        DNASeq *temp = new DNASeq(sequence->substring(i, i + len));
                    if (temp->isGeneticPalindrome())
                    {
                        cout << " Substring: ";
                        sequence->substring(i, i + len);
                        cout << " - Genetic Palindrome\n";
                    };
                    delete temp;
                }

        
    infile.close();a
    }
}

//prev. 
// else if (!sequence->isGeneticPalindrome())
// {
//     cout << " " << line << " - Not a Genetic Palindrome" << endl;
// }
// else
// {
//     cout << "   " << line << " - INVALID" << endl;
// }

