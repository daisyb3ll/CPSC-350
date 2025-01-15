/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. PA 5 ScareGames; TournamentNode.cpp
*/
#ifndef TOURNAMENTNODE_H
#define TOURNAMENTNODE_H
#include "Monster.h"

template<typename T >
class TournamentNode {

public:
    //constructor
        TournamentNode(T*competitor); //(bc the brackets) hold competitor info
    //destructor
        ~TournamentNode();
    
    void setWinner(T* winner); //sets node as winner

    //getters
    T* getWinner() const {return winner;} //retruns winner info
    
    TournamentNode<T>* getLeft() const{ return left;} //retruns left bracket 
    TournamentNode<T>* getRight() const{return right;} //retruns right bracket

    //setters
    void setLeft(TournamentNode<T> *node) { left = node; } //sets left
    void setRight(TournamentNode<T> *node) { right = node; }//sets right


private:
    T *winner;//points winner
    TournamentNode<T> *left; // points left
    TournamentNode<T> *right; //points to right
};

//constructor
//creates tournamenrt node that holds competitor info
template<typename T>
TournamentNode<T>::TournamentNode(T* competitor)
    : winner(competitor), left(nullptr), right(nullptr)
    {
    }

//desctructor; depopulates single tournament node
template<typename T>
TournamentNode<T>::~TournamentNode()
{
    if (left) 
    {
        delete left; 
        left =nullptr;
    }
    if (right)
    {
        delete right;
        right = nullptr;
    }
}

//sets the winner
template<typename T>
void TournamentNode<T>::setWinner(T*winner)
{
    this->winner = winner;
}

#endif 