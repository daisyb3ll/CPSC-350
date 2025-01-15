/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. PA 5 ScareGames; runScareGames.cpp
*/

#include "runScareGames.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Constructor
runScareGames::runScareGames(const std::string &inputFile, const std::string &format, const std::string &winnerOutputFile, const std::string &loserOutputFile)
    : inputFile(inputFile), format(format), winnerOutputFile(winnerOutputFile), loserOutputFile(loserOutputFile) {} // Missing semicolon fixed

// Destructor
// referenced!!!
// deleting pinters in a vector
//  https://stackoverflow.com/questions/2983383/destructor-and-copy-constructor-calling-why-does-it-get-called-at-these-times
runScareGames::~runScareGames()
{
    for (Monster *monster : competitors)
    {
        if(monster)
            delete monster;
    }
    competitors.clear();
}

// runTournament: Handles tournament setup and execution
void runScareGames::runTournament()
{
    // Open input file
    std::ifstream infile(inputFile);
    if (!infile.is_open())
    {
        std::cerr << "Error: Unable to open file " << inputFile << ". Please check the file and try again." << std::endl;
        return;
    }

    // Parse input file
    std::string line;
    while (std::getline(infile, line))
    {
        std::stringstream ss(line);
        std::string name;
        int screamPower;

        if (std::getline(ss, name, ',') && (ss >> screamPower))
        {
            competitors.push_back(new Monster(name, screamPower));
        }
    }
    infile.close();

    // Validate format
    bool isDoubleElimination = (format == "double");
    if (format != "single" && format != "double")
    {
        std::cerr << "Error: Invalid format '" << format << "'. Use 'single' or 'double'." << std::endl;
        return;
    }

    // Create the tournament tree
    TournamentTree<Monster> tree(competitors, isDoubleElimination);
    tree.runTournament();

    // Save results to DOT files
    tree.saveTreeAsDot(winnerOutputFile); // Winner's bracket
    if (isDoubleElimination)
    {
        tree.saveTreeAsDot(loserOutputFile); // Loser's bracket
    }

    // Print results
    std::cout << "Tournament results saved to " << winnerOutputFile;
    if (isDoubleElimination)
    {
        std::cout << " and " << loserOutputFile;
    }
    std::cout << std::endl;
}