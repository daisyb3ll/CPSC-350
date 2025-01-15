/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. PA 5 ScareGames; RunScareGame.h
*/

#ifndef RUNSCAREGAMES_H
#define RUNSCAREGAMES_H

#include "DOTFileGeneratorMethods.cpp"
#include "TournamentTree.h"
#include "Monster.h"
#include <vector>
#include <string>

using namespace std;
class runScareGames
{
    public:
        //constructy
        runScareGames(const std::string& inputFile, const std::string& format, const std::string &winnerOutputFile, const std::string &loserOutputFile);
        //destructy
        ~runScareGames();
        //method method
        void runTournament();

    private:
        std::vector<Monster*> competitors; 
        std::string format;     
        //IO
        std::string inputFile;
        std::string winnerOutputFile;
        std::string loserOutputFile;
};
#endif