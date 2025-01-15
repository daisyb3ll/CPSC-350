/*
a. Daisy Zahory Fernandez-Reyes
b. 2397470
c. CPSC-350-01
d. PA 5 ScareGames; DOTFileGeneratorMethods.cpp
*/

/*
You will use these methods in your code to save your winner and/ or loser bracket trees as DOT files
Then, you'll be able to visualize your trees at this link: https://dreampuf.github.io/GraphvizOnline/
*/

#include <fstream>
#include <iostream>
#include "TournamentNode.h"


// Function to save the tree as a DOT file
template <typename T>
void saveTreeAsDot(const std::string& filename, TournamentNode<T>* rootNode) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for DOT output: " << filename << "\n";
        return;
    }

    file << "digraph TournamentTree {\n";
    int nodeID = 0;
    saveTreeAsDotHelper(rootNode, file, nodeID);
    file << "}\n";
    file.close();
}

// Recursive helper function for DOT file generation
template <typename T>
void saveTreeAsDotHelper(TournamentNode<T>* node, std::ofstream& file, int& nodeID) {
    if (node == NULL) return;

    int currentID = nodeID++;
    file << "    node" << currentID << " [label=\"" << node->getWinner()-> getName()
        << " (Power: " << node->getWinner()-> getscreamPowerLevel() << ")\"];\n";

    if (node->getLeft()) {
        int leftID = nodeID;
        saveTreeAsDotHelper(node->getLeft(), file, nodeID);
        file << "    node" << currentID << " -> node" << leftID << ";\n";
    }

    if (node->getRight()) {
        int rightID = nodeID;
        saveTreeAsDotHelper(node->getRight(), file, nodeID);
        file << "    node" << currentID << " -> node" << rightID << ";\n";
    }
}
