#include "fileReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <set>
using namespace std;

/*
making the grid and populating it based on chances 
*/

class chancesandPercents{
    public:
    int size_N;
    int chanceCoins;
    int chanceMushrooms;
    int chanceNothing;
    int chanceKoopas;
    int chanceGoombas;

    chancesandPercents(){
        fileReader gettingValues;
        chanceCoins = gettingValues.percentCoins;
        chanceMushrooms = gettingValues.percentMushrooms;
        chanceNothing = gettingValues.percentNothing;
        chanceKoopas = gettingValues.percentKoopas;
        chanceGoombas = gettingValues.percentGoombas;
        size_N = gettingValues.gridSize;
    }

    void generate_all_coordinates(int* x_coords, int* y_coords, int totalCells){
        int index = 0;

        for ( int x = 0 ; x < size_N; ++x){
            for (int  y = 0; y < size_N ; ++y){
                x_coords[index] = x;
                y_coords[index] = y;
                ++index;
            }
        }

        // Shuffle the coordinates to randomize their order
        for (int i = totalCells - 1; i > 0; --i)
        {
            int j = rand() % (i + 1);
            std::swap(x_coords[i], x_coords[j]);
            std::swap(y_coords[i], y_coords[j]);
        }
    }

    };

    // pair<int, int> generate_random_coordinate(int N, set<pair<int, int > > &used_coordinates){
    //     std::random_device rd;
    //     std::mt19937 gen(rd());
    //     std::uniform_int_distribution<> dis(0, N - 1);

    //     while (true)
    //     {
    //         int x = dis(gen);
    //         int y = dis(gen);
    //         std::pair<int, int> coordinate = std::make_pair(x, y);

    //         if (used_coordinates.find(coordinate) == used_coordinates.end())
    //         {
    //             used_coordinates.insert(coordinate);
    //             return coordinate;
    //         }
    //     }
    // }
    // };
    // // pair[int,int]generate_random_coordinate(int gridSize, set)



    // int main()
    // {
    //     // Seed the random number generator for more diverse results
    //     chancesandPercents game;
    //     int N = game.size_N;
    //     set<pair<int, int > > used_coordinates;

    //     // Generate and print 10 random coordinates
        
    //     for (int i = 0; i < 10; ++i)
    //     {
    //         pair<int, int> coordinate = game.generate_random_coordinate(N, used_coordinates);
    //         cout << "Coordinate: (" << coordinate.first << ", " << coordinate.second << ")" << endl;
    //     }

    //     return 0;
    // }

    int main()
    {
        srand(time(NULL)); // Seed the random number generator

        chancesandPercents game;
        int N = game.size_N;
        int totalCells = N * N;

        int *x_coords = new int[totalCells];
        int *y_coords = new int[totalCells];

        game.generate_all_coordinates(x_coords, y_coords, totalCells);

        std::cout << "Generated " << totalCells << " coordinates for a " << N << "x" << N << " grid:" << std::endl;
        for (int i = 0; i < totalCells; ++i)
        {
            std::cout << "Coordinate: (" << x_coords[i] << ", " << y_coords[i] << ")" << std::endl;
        }

        delete[] x_coords;
        delete[] y_coords;

        return 0;
    }