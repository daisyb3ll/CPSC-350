/*
a. Daisy Zahory Fernandez-Reyes
b. 2397370
c. CPSC-350-01
d. PA 5 ScareGames; TournamentNode.cpp
*/
/*
SOLUTION REFERENCED:
@geeksforgeeks 'Tournament Tree(Winner Tree) and Binary Heap'
https://www.geeksforgeeks.org/tournament-tree-and-binary-heap/
  */

#ifndef TOURNAMENTTREE_H
#define TOURNAMENTTREE_H
#include "TournamentNode.h"
#include <vector>
#include <string>


template <typename T>
class TournamentTree
{
  public:   
    //constructor
    TournamentTree(vector<T*>&  competitors, bool doubleElimination = false);
    //destructor
    ~TournamentTree();
    
    //tree functions
    void saveTreeAsDot(const std::string &filename); //saves tre output for dotfile
    void singleElimination(); //single elimination tree
    void doubleElimination(); //double elimination logic
    void runTournament(); //runs tourney
  
  private : 

    TournamentNode<T>* root; //rootnode for root (winner or loser)
    TournamentNode<T>* loserRoot; //loser root
    std::vector<T*> competitors;//  competitor nodes
    std::vector<T*> losers; //node to hold losers info
    bool isDoubleElimination; // bool for double eiminaiton logic

    void initializeSingleElimination(); //runs double or single
    void initializeDoubleElimination();
    void processMatches(std::vector<TournamentNode<T> *> &currentRound); //processes matches between two nodes
    TournamentNode<T> *resolveMatch(TournamentNode<T> *node1, TournamentNode<T> *node2); //resolves matches between nodes
    void cleanBracket(TournamentNode<T>* node); //helper function for node deletion destructor
};

// CONSTRUCTOR
// based on double or single elimination
template <typename T>
TournamentTree<T>::TournamentTree(std::vector<T *> &competitor, bool doubleElimination)
    : competitors(std::move(competitor)), isDoubleElimination(doubleElimination), root(nullptr), loserRoot(nullptr) {}

// DESTRUCTOR
template <typename T>
TournamentTree<T>::~TournamentTree() {
    cleanBracket(root);
    cleanBracket(loserRoot);
}

template <typename T>
void TournamentTree<T>::cleanBracket(TournamentNode<T>* node) {
    if (node) {
        cleanBracket(node->getLeft());
        cleanBracket(node->getRight());
        delete node; //deletes current nod3
    }
}


template<typename T>
void TournamentTree<T>::runTournament()
//calls initializations bools
{
  if(isDoubleElimination)
  {
    initializeDoubleElimination();
  }else{
    initializeSingleElimination(); 
  }
}

// Single elimination tournament
template <typename T>
void TournamentTree<T>::initializeSingleElimination()
{
  std::vector<TournamentNode<T> *> currentRound;
  for (T *competitor : competitors)
  {
    currentRound.emplace_back(new TournamentNode<T>(competitor));
  }
  while (currentRound.size() > 1)
  {
    processMatches(currentRound);
  }
  root = currentRound.empty() ? nullptr : currentRound.front();
}

//Double elimination tournament

/*---------------NOT MY ORIGINAL CODE!!!
REFERENCE:
Implemetnation assistance and debugging from CHATGPT
"I cant figure out whats wrong with my double elimination please help me please thank you."
START OF CODE:
*/


template <typename T>
void TournamentTree<T>::initializeDoubleElimination()
  {
    std::vector<TournamentNode<T> *> mainBracket;

    for (T *competitor : competitors)
    {
      mainBracket.emplace_back(new TournamentNode<T>(competitor));
    }

    while (mainBracket.size() > 1)
    {
      std::vector<TournamentNode<T> *> nextRound;
      for (size_t i = 0; i + 1 < mainBracket.size(); i += 2)
      {
        TournamentNode<T> *winnerNode = resolveMatch(mainBracket[i], mainBracket[i + 1]);
        nextRound.push_back(winnerNode);

        T *loser = (winnerNode->getWinner() == mainBracket[i]->getWinner())
                      ? mainBracket[i + 1]->getWinner()
                      : mainBracket[i]->getWinner();
        losers.push_back(loser);
      }

      if (mainBracket.size() % 2 == 1)
      {
        nextRound.push_back(mainBracket.back());
      }

      mainBracket = std::move(nextRound);
    }

    root = mainBracket.empty() ? nullptr : mainBracket.front();

    std::vector<TournamentNode<T> *> losersBracket;
    for (T *loser : losers)
    {
      losersBracket.emplace_back(new TournamentNode<T>(loser));
    }

    while (losersBracket.size() > 1)
    {
      processMatches(losersBracket);
    }

    loserRoot = losersBracket.empty() ? nullptr : losersBracket.front();

    root = resolveMatch(root, loserRoot);
  }

//END OF CODE ------------     

//process match

// Process matches in a round
template <typename T>
void TournamentTree<T>::processMatches(std::vector<TournamentNode<T> *> &currentRound)
{
  std::vector<TournamentNode<T> *> nextRound;

  for (size_t i = 0; i + 1 < currentRound.size(); i += 2)
  {
    nextRound.push_back(resolveMatch(currentRound[i], currentRound[i + 1]));
  }

  if (currentRound.size() % 2 == 1)
  {
    nextRound.push_back(currentRound.back());
  }

  currentRound = std::move(nextRound);
}

//resolve match
template <typename T>
TournamentNode<T>* TournamentTree<T>::resolveMatch(TournamentNode<T>* node1, TournamentNode<T>* node2) {
    T* winner = (*node1->getWinner() > *node2->getWinner()) ? node1->getWinner() : node2->getWinner();
    TournamentNode<T>* matchNode = new TournamentNode<T>(winner);

    matchNode->setLeft(node1);
    matchNode->setRight(node2);

    return matchNode;
}

// save as a dot file
template <typename T>
void TournamentTree<T>::saveTreeAsDot(const std::string &filename)
{
  ::saveTreeAsDot(filename, root);
}

#endif //TOURNAMENTTREE_H
