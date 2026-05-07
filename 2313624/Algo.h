#ifndef ALGO_H
#define ALGO_H

#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "PathNode.h"

// Task 1
PathNode* findShortestPathMatrix(double adjMatrix[100][100], int start, int goal);

// Task 2
PathNode* findShortestPath2D(double adjMatrix[100][100], int coords[100][2], 
                             int start, int goal, int mode);

// Task 3
PathNode* findPathInMaze(int maze[100][100], int m, int n,
                         int startX, int startY, int goalX, int goalY);

// Task 4
int coordToVertex(int x, int y, int n);
void vertexToCoord(int v, int n, int& x, int& y);
void buildWeightMatrix(int maze[100][100], int m, int n, double weightMatrix[100][100]);
PathNode* findPathInMaze2(int maze[100][100], int m, int n,
                          int startX, int startY, int goalX, int goalY,
                          double weightMatrix[100][100]);

#endif
