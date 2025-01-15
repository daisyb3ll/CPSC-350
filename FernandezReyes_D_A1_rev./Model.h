/*
Daisy Fernandez-Reyes
2397470
CPSC-350-01
PA_1; Robber Language Translation
Model.h
*/

/*
The Model Class
You will build a class named Model that will encode the rules of the Robber language. The class will contain the following public methods:
● A default constructor
● A default destructor
● translateSingleConsonant– takes a single consonant character as input and returns a
string representing its encoding in Rövarspråket. Capitalization should be preserved.
● translateSingleVowel – takes a single vowel character as input and returns a string
representing its encoding in Rövarspråket. Capitalization should be preserved.*/

/*
    The formula for encoding is simple.
    Every consonant (spelling matters, not pronunciation) is doubled, p -> pp
    and an o is inserted in between. p -> pop
    Vowels are left intact.
    stubborn -> sos tot u bobbob o ror non -> sostotubobboborornon
*/

#ifndef MODEL_H
#define MODEL_H
#include <string>
#include <iostream>
using namespace std;

class Model
{
public:
    // constructy
    Model();
    //destructy
    ~Model();

    // core functions
    static string translateSingleConsonant(char c);
    static string translateSingleVowel(char c);
    // checks for vowels -> if isConsosnant is true then -> translate single consonant etc.
    static bool isConsonant(char c);
};

#endif