// a.Daisy Zahory Fernandez - Reyes
// b.2397370
// c.Data Structures: CPSC - 350 - 01
// d.Programming Assignment 6: Spanning the Gamut
// e. WGraph.h

#ifndef WGRAPH_H
#define WGRAPH_H

#include <tuple>
#include <vector>
#include <limits>
#include <set>
#include <iostream>

/*
A majority of this coding solution was heavily referenced from
- @dr.steven's in class WGraph.cpp & WGraph.h code implemetation
- @dr.Eel's WGraph.cpp & WGraph.cpp implementations
    in
    https://dreel.notion.site/FA-24-CPSC-350-WITH-DR-EEL-b7472d7b2ced4fc2a55ce6cd6550c60c?p=b64f73ed0e974d4d8d9e77a9600fd91d&pm=s
    for Graphs 4, lecture 28
- @GeeksForGeeks:Union-Find algorithm
    https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
- @Haroon Ahamed Kittu on @ SimpliLearn's Kruskals: Key to Minimum Spanning Tree implementaiton ( reference for parent vectors)
    https://www.simplilearn.com/tutorials/data-structure-tutorial/kruskal-algorithm
*/

// Define a vertex ID
typedef unsigned int VertexID;

// Weighted Graph Implementation
class WGraph {
public:
    // Constructor
    WGraph(unsigned int sz);
    // Destructor
    ~WGraph();

    // Add an edge
    void addEdge(VertexID i, VertexID j, double w);
    // Remove an edge
    void removeEdge(VertexID i, VertexID j);
    // Check adjacency
    bool areAdjacent(VertexID i, VertexID j);
    // Compute the cheapest cost
    double cheapestCost(VertexID i, VertexID j);
    // Calculate Floyd-Warshall
    void calcFW();
    // Compute MST using Kruskal's algorithm
    double computeMST();

private:
    double **m_adj;      // Adjacency matrix
    double **m_conn;     // Connectivity matrix (Floyd-Warshall)
    unsigned int m_size; // Number of vertices
    double **m_mst;      // MST adjacency matrix

    // List of edges (source, destination, weight)
    std::vector<std::tuple<int, int, double>> edges;

    // Union-Find data structures for Kruskal's algorithm
    std::vector<int> parent;
    std::vector<int> rank;

    int find(int vertex);        // Find root of vertex
    void unionSets(int u, int v); // Union two sets

    // Helper to sort edges by weight
    void sortEdges();
};
#endif
