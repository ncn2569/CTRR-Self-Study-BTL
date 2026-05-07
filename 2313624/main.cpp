#include <iostream>
#include "Algo.h"
#include "PathNode.h"

using namespace std;

// Hàm in path
void printPath(PathNode* head) {
    cout << "Solution Path:\n";
    while (head != nullptr) {
        cout << "Node: " << head->name
             << " | f: " << head->f
             << " | g: " << head->g
             << " | h: " << head->h << "\n";
        head = head->next;
    }
}

// Hàm giải phóng memory
void freePath(PathNode* head) {
    while (head != nullptr) {
        PathNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    cout << "==============================================\n";
    cout << "TASK 1: Shortest Path Using A* with Adjacency Matrix\n";
    cout << "==============================================\n";
    
    double adjMatrix1[100][100] = {0};
    // Ví dụ graph nhỏ từ đặc tả (Fig. 1)
    adjMatrix1[0][1] = 1; // S -> A
    adjMatrix1[0][2] = 4; // S -> B
    adjMatrix1[1][3] = 2; // A -> D
    adjMatrix1[2][4] = 2; // B -> C
    adjMatrix1[3][5] = 1; // D -> G
    adjMatrix1[4][3] = 1; // C -> D
    
    PathNode* path1 = findShortestPathMatrix(adjMatrix1, 0, 5);
    printPath(path1);
    freePath(path1);
    
    cout << "\n==============================================\n";
    cout << "TASK 2: Shortest Path in 2D Space\n";
    cout << "==============================================\n";
    
    double adjMatrix2[100][100] = {0};
    int coords[100][2] = {0};
    
    // Tạo graph 5 nodes với tọa độ
    coords[0][0] = 0; coords[0][1] = 0;  // Node 0 at (0,0)
    coords[1][0] = 1; coords[1][1] = 1;  // Node 1 at (1,1)
    coords[2][0] = 2; coords[2][1] = 0;  // Node 2 at (2,0)
    coords[3][0] = 2; coords[3][1] = 2;  // Node 3 at (2,2)
    coords[4][0] = 3; coords[4][1] = 1;  // Node 4 at (3,1)
    
    adjMatrix2[0][1] = 1.5;  // 0 -> 1
    adjMatrix2[0][2] = 2.0;  // 0 -> 2
    adjMatrix2[1][3] = 1.5;  // 1 -> 3
    adjMatrix2[2][4] = 1.5;  // 2 -> 4
    adjMatrix2[3][4] = 1.5;  // 3 -> 4
    
    cout << "\n--- Mode 1: Manhattan Distance ---\n";
    PathNode* path2_mode1 = findShortestPath2D(adjMatrix2, coords, 0, 4, 1);
    printPath(path2_mode1);
    freePath(path2_mode1);
    
    cout << "\n--- Mode 2: Euclidean Distance ---\n";
    PathNode* path2_mode2 = findShortestPath2D(adjMatrix2, coords, 0, 4, 2);
    printPath(path2_mode2);
    freePath(path2_mode2);
    
    cout << "\n==============================================\n";
    cout << "TASK 3: Maze Navigation with Obstacles\n";
    cout << "==============================================\n";
    
    int maze3[100][100] = {0};
    // Maze 5x5
    int mazeData3[5][5] = {
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            maze3[i][j] = mazeData3[i][j];
        }
    }
    
    cout << "\nMaze Layout (0=passable, 1=wall):\n";
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << maze3[i][j] << " ";
        }
        cout << "\n";
    }
    
    PathNode* path3 = findPathInMaze(maze3, 5, 5, 0, 0, 4, 4);
    cout << "\nPath from (0,0) to (4,4):\n";
    printPath(path3);
    freePath(path3);
    
    cout << "\n==============================================\n";
    cout << "TASK 4: Maze Navigation with Obstacles 2\n";
    cout << "==============================================\n";
    
    int maze4[100][100] = {0};
    double weightMatrix[100][100] = {0};
    
    // Maze 3x3
    int mazeData4[3][3] = {
        {0, 0, 1},
        {0, 0, 0},
        {1, 0, 0}
    };
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            maze4[i][j] = mazeData4[i][j];
        }
    }
    
    cout << "\nMaze Layout (0=passable, 1=wall):\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << maze4[i][j] << " ";
        }
        cout << "\n";
    }
    
    PathNode* path4 = findPathInMaze2(maze4, 3, 3, 0, 0, 2, 2, weightMatrix);
    cout << "\nPath from (0,0) to (2,2):\n";
    printPath(path4);
    freePath(path4);
    
    cout << "\nWeight Matrix (first 9x9 for 3x3 maze):\n";
    int totalVertices = 3 * 3;
    for(int i = 0; i < totalVertices; i++) {
        for(int j = 0; j < totalVertices; j++) {
            cout << weightMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n==============================================\n";
    cout << "ALL TASKS COMPLETED SUCCESSFULLY!\n";
    cout << "==============================================\n";
    
    return 0;
}