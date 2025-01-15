/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. PA 5 ScareGames; Monster.h
*/

/*
Monster Class:
Represents each competitor in the tournament.
Attributes: Each Monster object has a name and a scream power level.
Implement comparison operators in this class to compare monsters based on their scream power levels, which will be essential for determining match outcomes in the tournament.

frick roar omega roar all the homies HATE R
*/

#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include <iostream>
using namespace std;

class Monster
{  
    public: 
        //monster constructor
        Monster(string m_name, int screamPowerLevel); 
        //getters
        string getName() const{return m_name;}
        int getscreamPowerLevel() const ; 

        //comparison operations
        bool operator <(const Monster& other) const; //less than
        bool operator>(const Monster &other) const; //greater than
        bool operator==(const Monster &other) const;//equal to (this ones gonna be tricky i know it ) 
    
    private: 
    string m_name; 
    int screamPowerLevel; 
};
#endif