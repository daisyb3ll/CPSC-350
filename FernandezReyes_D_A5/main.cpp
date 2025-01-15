/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. PA 5 ScareGames; main.cpp
*/

//HEADERSHEADRERSHEADERS 
#include "Monster.h"
#include "runScareGames.h"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "You're missing a bit! Make sure the arguments are [./ScareGames <input_file> <single or double tournament>]" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <input_file> <tournament_format>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1]; //takes input file name
    std::string format = argv[2]; // takes single or double

    // Validate format
    if (format != "single" && format != "double")
    {
        std::cerr << "Error: Invalid format! Use 'single' or 'double'." << std::endl;
        return 1;
    }

    // Set output file names
    std::string winnerOutputFile = "winners_Bracket.dot";
    std::string loserOutputFile = "losers_Bracket.dot";

    // Run the Scare Game
    runScareGames game(inputFile, format, winnerOutputFile, loserOutputFile);
    game.runTournament();

    return 0;
}