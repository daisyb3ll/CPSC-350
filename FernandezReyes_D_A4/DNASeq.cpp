/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. Programming Assignment 4; Genetic Palindrome
e. DNASeq.cpp
*/

#include "DNASeq.h"
#include <iostream>
#include <string>
using namespace std;

DNASeq::DNASeq(){}
DNASeq :: ~DNASeq()
{
   //delete strand
}

DNASeq ::DNASeq(string s)
{
    for (char c : s)
    {
        dnaStrand.addBack(c);
    }
    dnaSequence = s;
} 
DNASeq DNASeq ::complement()
{
    DNASeq complement; 
    for (int i = 0; i < dnaStrand.getSize(); i++)
    { 
        char nucleotide = dnaStrand.get(i);

            // A <-> T complements 
        if (nucleotide == 'A')
        {
            complement.dnaStrand.addBack('T');
        }
        else if (nucleotide == 'T')
        {
            complement.dnaStrand.addBack('A');
        }
            // C <-> G  complements
        else if (nucleotide == 'C')
        {
            complement.dnaStrand.addBack('G');
        }
        else if (nucleotide == 'G')
        {
            complement.dnaStrand.addBack('C');
        }
        }
    return complement;
}

DNASeq DNASeq ::substring(int s, int e) const
{
    DNASeq subStrand;
    for (int i = s; i< e; ++i)
    {
        subStrand.dnaStrand.addBack(dnaStrand.get(i));
    }
    return subStrand;
}

bool DNASeq :: isGeneticPalindrome()
{
    DNASeq complementStrand = this -> complement();
    int slength = dnaStrand.getSize();
    for (int i = 0; i < slength; ++i)
    {
        if (dnaStrand.get(i) != complementStrand.dnaStrand.get(slength -i -1))
        {
            return false;
        }
    }
    return true;
}

bool DNASeq::isValid ()
{
    //if the string is empty
    if (dnaStrand.getSize() == 0)
    {
        return false; 
    }
    //if the string conatinas non ATGC values
    for(int i = 0; i <dnaStrand.getSize(); i++)
    {
        if ((dnaStrand.get(i) != 'A') && (dnaStrand.get(i) != 'T') && (dnaStrand.get(i) != 'G')&& (dnaStrand.get(i) != 'C'))
        return false;
    }
    //if the string is evem long enough to be a palindrome
    // at least 2 chars long i.e. at, gc, ta, cg 
    if(dnaStrand.getSize()<2)
    
        return false;
    }
    return true;
}
}
