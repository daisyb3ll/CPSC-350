/*
daisy fernandez-reyes
2397470
CPSC-350-01
programming assignment 1;  robber language translation
Translator.cpp
*/

/*
The Translator Class
You will build a class named Translator that will translate English sentences to Rövarspråket sentences using the Model class. The class will contain the following public methods:
● A default constructor
● A default destructor
● translateEnglishWord – takes a single string representing a single English word as input
and returns a string representing the Rövarapråket translation.
● translateEnglishSentence – takes a single string representing a single English sentence
as input and returns a string representing the Rövarspråket translation. Make sure to account for punctuation.
*/

#include "Translator.h"
#include <iostream>
using namespace std;

Translator::Translator()
{
    // constructy
}
Translator::~Translator()
{
    // destructy
}
// uses Model rules to translate
string Translator::translateEnglishWord(string singleWord)
{
    string output = "";
    for (char c : singleWord)
    {
        if (model.isConsonant(c))
        { // if its a consonant
            // calls translate char consonoant + doubles + 'o' + strings
            output += model.translateSingleConsonant(c);
        }
        else
        {
        // else it calls translatesinglevowel and changes nothing + turns into a strings
        output += model.translateSingleVowel(c);
        }
    }
    return output;
}
//
string Translator::translateEnglishSentence(string sentence)
{   
    string output = "";
    string singleWord = ""; 
        // for the input, the entire sentence is run through the ^translateEnglishWord
        for (char c : sentence)
    {
        if (isalpha(c))
        {
            singleWord += c;
        }
        else //its not a letter (any ' ' or '-,+=!@#$%^&*()')
        {
            if (!singleWord.empty())
            {
                output += translateEnglishWord(singleWord);
                singleWord =""; // resets the word for the next iteration! -> next time it suns word will be blank

            }
            output += c; 
        }
        if (!singleWord.empty())
        {
            output += translateEnglishWord(singleWord);
        }
        return output;
    }
}
