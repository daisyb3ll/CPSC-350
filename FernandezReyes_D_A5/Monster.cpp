/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. fernandezreyes@chapman.edu
d. CPSC-350-01 
e. PA 5 ScareGames; Monster.cpp
*/

/*
class description
Monster Class:
Represents each competitor in the tournament.
Attributes: Each Monster object has a name and a scream power level.
Implement comparison operators in this class to compare monsters based on their scream power levels, which will be essential for determining match outcomes in the tournament.
*/

// * reference taken from in-class for node creation references and implementations

#include "Monster.h"

//construstor 
//initializes a momster with a name and scream power level

/*CHATGPT RECCEOMEND CONSTRUCT DECLARATION:
    "Monster::Monster(string m_name, int screamPowerLevel) :
    m_name(m_name), screamPowerLevel(screamPowerLevel) {}"
    
    was reccommended over

    "Monster::Monster(string m_name, int screamPowerLevel) {
    this->m_name = m_name;
    this->screamPowerLevel = screamPowerLevel;"
}

*/
Monster::Monster(string m_name, int screamPowerLevel) : 
    m_name(m_name), screamPowerLevel(screamPowerLevel) {}

// string Monster::getName() const
// {
//     return m_name;
// }

int Monster::getscreamPowerLevel() const
{
    return screamPowerLevel;
}

//less than
bool Monster::operator<(const Monster &other) const
{
    return screamPowerLevel < other.screamPowerLevel;
}  
//greater than
bool Monster::operator>(const Monster &other) const
{
    return screamPowerLevel > other.screamPowerLevel;

} 
//equal to
bool Monster::operator==(const Monster &other) const
{
    return screamPowerLevel == other.screamPowerLevel;
}


