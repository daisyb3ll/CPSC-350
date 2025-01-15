// a.Daisy Zahory Fernandez-Reyes
// b.2397370
// c.Data Structures: CPSC - 350 - 01
// d.Programming Assignment 6: Spanning the Gamut
// e. WGraph.cpp

/*
A majority of this coding solution was heavily referenced from
@dr.steven's in class WGraph.cpp & WGraph.h code implemetation
as well as
@dr.Eel's WGraph.cpp & WGraph.cpp implementations in
https://dreel.notion.site/FA-24-CPSC-350-WITH-DR-EEL-b7472d7b2ced4fc2a55ce6cd6550c60c?p=b64f73ed0e974d4d8d9e77a9600fd91d&pm=s
for Graphs 4, lecture 28
as well as 
@GeeksForGeeks 
Union-Find algorithm
https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
*/

#include "WGraph.h"
#include <algorithm>
#include <iostream>
#include <limits>

//overloaded constructy
WGraph::WGraph(unsigned int sz) : m_size(sz)
{
    m_adj = new double *[m_size];
    m_conn = new double *[m_size];
    m_mst = new double *[m_size];
    parent.resize(m_size);
    rank.resize(m_size, 0);

    for (unsigned int i = 0; i < m_size; i++)
    {
        m_adj[i] = new double[m_size];
        m_conn[i] = new double[m_size];
        m_mst[i] = new double[m_size];

        for (unsigned int j = 0; j < m_size; j++)
        {
            m_adj[i][j] = std::numeric_limits<double>::infinity();
            m_mst[i][j] = 0.0;
        }
        parent[i] = i;
    }
}

// destructy
WGraph::~WGraph()
{
    for (unsigned int i = 0; i < m_size; i++)
    {
        delete[] m_adj[i];
        delete[] m_conn[i];
        delete[] m_mst[i];
    }
    delete[] m_adj;
    delete[] m_conn;
    delete[] m_mst;
}

// Adds edge
void WGraph::addEdge(VertexID i, VertexID j, double w)
{
    if (i < m_size && j < m_size)
    {
        m_adj[i][j] = w;
        m_adj[j][i] = w;
        edges.push_back(std::make_tuple(i, j, w)); // Use std::tuple
    }
}

// removes edge
void WGraph::removeEdge(VertexID i, VertexID j)
{
    if (i < m_size && j < m_size)
    {
        m_adj[i][j] = std::numeric_limits<double>::infinity();
        m_adj[j][i] = std::numeric_limits<double>::infinity();
    }
}

// checks adjacency -> smh this couldve helped on that final question T-T
bool WGraph::areAdjacent(VertexID i, VertexID j)
{
    return m_adj[i][j] != std::numeric_limits<double>::infinity();
}

//returns vertex root (parent)
int WGraph::find(int vertex)
{
    if (parent[vertex] != vertex)
    {
        parent[vertex] = find(parent[vertex]);
    }
    return parent[vertex];
}

//! REFERENCED FROM @GEEKSFORGEEKS!! 
// Union of two sets
void WGraph::unionSets(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV)
    {
        if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else
        {
            parent[rootU] = rootV;
            rank[rootU]++;
        }
    }
}

// Sort edges by weight
// REFERENCED BY GEMENI RECCOMENDED SOLUTION
//NOT MY ORIGINAL CODE  IDEA  -----   
// "// Sort edges by weight using a lambda function for comparison
// Lambda allows for custom sorting logic, introduced in C++11
// Inspired by Kruskal's algorithm for MST computation "
//thank u gemeni and shoutout @Google
void WGraph::sortEdges()
{
    std::sort(edges.begin(), edges.end(), [](const std::tuple<int, int, double> &a, const std::tuple<int, int, double> &b)
            {
                  return std::get<2>(a) < std::get<2>(b); // Compare weights
            });
}
//END OF CODE ------  

//KRUSKALS BAYBEEE!!!
double WGraph::computeMST()
{
    sortEdges();

    double MSTCost = 0.0;
    unsigned int edgeCount = 0;

    for (const auto &edge : edges)
    {
        int u = std::get<0>(edge);
        int v = std::get<1>(edge);
        double weight = std::get<2>(edge);

        if (find(u) != find(v))
        { // Check for cycle
            unionSets(u, v);
            MSTCost += weight;

            m_mst[u][v] = weight;
            m_mst[v][u] = weight;

            edgeCount++;
            if (edgeCount == m_size - 1)
            { // Stop if MST is complete
                break;
            }
        }
    }

    // Print MST
    std::cout << "MST cost is: " << MSTCost << std::endl;
    for (unsigned int i = 0; i < m_size; ++i)
    {
        for (unsigned int j = 0; j < m_size; ++j)
        {
            std::cout << m_mst[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return MSTCost;
}

// Calculate Floyd-Warshall
void WGraph::calcFW()
{
    for (unsigned int i = 0; i < m_size; ++i)
    {
        for (unsigned int j = 0; j < m_size; ++j)
        {
            m_conn[i][j] = m_adj[i][j];
        }
        m_conn[i][i] = 0.0;
    }

    for (unsigned int k = 0; k < m_size; ++k)
    {
        for (unsigned int i = 0; i < m_size; ++i)
        {
            for (unsigned int j = 0; j < m_size; ++j)
            {
                if (m_conn[i][k] != std::numeric_limits<double>::infinity() &&
                    m_conn[k][j] != std::numeric_limits<double>::infinity() &&
                    m_conn[i][j] > m_conn[i][k] + m_conn[k][j])
                {
                    m_conn[i][j] = m_conn[i][k] + m_conn[k][j];
                }
            }
        }
    }
}

// Get cheapest cost between two vertices
double WGraph::cheapestCost(VertexID i, VertexID j)
{
    return m_conn[i][j];
}
