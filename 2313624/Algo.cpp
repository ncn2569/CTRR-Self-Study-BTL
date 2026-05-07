#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Algo.h"
#include "PathNode.h"

int computeHeuristic(int start, int goal, double adjMatrix[100][100]){
    std::vector<int> dist(100, -1);
    dist[start] = 0;

    std::vector<int> q;
    q.push_back(start);

    for(int i = 0; i < (int)q.size(); i++){
        int u = q[i];
        if (u == goal) return dist[u];

        for(int v = 0; v < 100; v++){
            if(adjMatrix[u][v] > 0 && dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push_back(v);
            }
        }
    }

    return 1000000; // unreachable
}

PathNode* findShortestPathMatrix(double adjMatrix[100][100], int start, int goal) {

    // int n=60;
    // for(int i=0; i<n; i++){
    //     // cout<<"{"
    //     for(int j=0; j<n; j++){
    //         cout<<adjMatrix[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    const double INF = 1e9;

    double g[100], h[100], f[100];
    int parent[100];
    bool visited[100];

    for(int i = 0; i < 100; i++){
        g[i] = INF;
        h[i] = 0;
        f[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }

    auto heuristic = [&](int n) {
        return (double)computeHeuristic(n, goal, adjMatrix);
    };


    g[start] = 0;
    h[start] = heuristic(start);
    f[start] = g[start] + h[start];

    while (true) {
        int u = -1;
        for (int i = 0; i < 100; i++) {
            if (!visited[i]) {
                if(u == -1)
                u = i;
                 
                else{
                    if(f[i] < f[u])
                    u = i;
                    
                    else if(f[i] == f[u]){
                        if(h[i] < h[u])
                        u = i;
                        
                        else if(h[i] == h[u]){
                            if(g[i] > g[u])
                            u = i;
                            
                        }
                    }
                }
            }
        }

        if (u == -1) break;
        visited[u] = true;
        if (u == goal) break;

        // relax các cạnh
        for(int v = 0; v < 100; v++){
            if(adjMatrix[u][v] > 0){
                double newG = g[u] + 1;
                double newH = heuristic(v);
                double newF = newG + newH;

                if(newF < f[v]){
                    g[v] = newG;
                    h[v] = newH;
                    f[v] = newF;
                    parent[v] = u;
                }
            }
        }
    }

    // Build linked list result
    std::vector<int> order;
    int cur = goal;

    while(cur != -1){
        order.push_back(cur);
        cur = parent[cur];
    }

    std::reverse(order.begin(), order.end());

    PathNode* head = nullptr;
    PathNode* tail = nullptr;

    for(int v : order){
        PathNode* node = new PathNode(
            std::to_string(v),
            f[v], g[v], h[v]
        );

        if(!head) head = node;
        else tail->next = node;

        tail = node;
    }

    return head;
}

////////////////////////

PathNode* findShortestPath2D(double adjMatrix[100][100], int coords[100][2], int start, int goal, int mode){
    const double INF = 1e12;
    double g[100], h[100], f[100];
    int parent[100];
    bool visited[100];

    for(int i = 0; i < 100; i++){
        g[i] = INF;
        h[i] = 0;
        f[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }

    auto heuristic = [&](int n){
        int x1 = coords[n][0], y1 = coords[n][1];
        int x2 = coords[goal][0], y2 = coords[goal][1];

        if(mode == 1)
            return (double)(abs(x1 - x2) + abs(y1 - y2)); 
        else{
            double dx = x1 - x2;
            double dy = y1 - y2;
            return sqrt(dx * dx + dy * dy);
        }
    };

    g[start] = 0;
    h[start] = heuristic(start);
    f[start] = g[start] + h[start];

    while(true){
        int u = -1;

        for(int i = 0; i < 100; i++){
            if(!visited[i]){
                if(u == -1) u = i;
                else{
                    if(f[i] < f[u]) u = i;
                    else if(f[i] == f[u]){
                        if (h[i] < h[u]) u = i;
                        else if(h[i] == h[u]){
                            if (g[i] > g[u]) u = i;
                        }
                    }
                }
            }
        }

        if(u == -1) break;
        visited[u] = true;

        if(u == goal) break;

        for(int v = 0; v < 100; v++){
            if(adjMatrix[u][v] > 0){
                double newG = g[u] + adjMatrix[u][v];

                double newH = heuristic(v);
                double newF = newG + newH;

                if(newF < f[v]){
                    g[v] = newG;
                    h[v] = newH;
                    f[v] = newF;
                    parent[v] = u;
                }
            }
        }
    }

    std::vector<int> path;
    int cur = goal;
    while(cur != -1){
        path.push_back(cur);
        cur = parent[cur];
    }
    std::reverse(path.begin(), path.end());

    PathNode* head = nullptr;
    PathNode* tail = nullptr;

    for(int v : path){
        std::string label = "(" + std::to_string(coords[v][0]) + "," + std::to_string(coords[v][1]) + ")";

        PathNode* node = new PathNode(label, f[v], g[v], h[v]);

        if(!head) head = node;
        else tail->next = node;
        tail = node;
    }

    return head;
}

//////////////////

struct AStarNode{
    int x, y;
    double g, h, f;
    AStarNode* parent;
    std::string direction;
    
    AStarNode(int x, int y, double g, double h, AStarNode* parent, std::string dir)
    : x(x), y(y), g(g), h(h), f(g+h), parent(parent), direction(dir) {}
};

double distance(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

bool valid(int x, int y, int m, int n, int maze[100][100]){
    return x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0;
}

struct Move{
    int dx, dy;
    double cost;
    std::string name;
};

Move dichuyen[8] = {
    {-1, 0, 1.0, "Up"},
    {1, 0, 1.0, "Down"},
    {0, -1, 1.0, "Left"},
    {0, 1, 1.0, "Right"},
    {-1, -1, 1.5, "Up-Left"},
    {-1, 1, 1.5, "Up-Right"},
    {1, -1, 1.5, "Down-Left"},
    {1, 1, 1.5, "Down-Right"}
};

PathNode* findPathInMaze(int maze[100][100], int m, int n, int startX, int startY, int goalX, int goalY){
    if(!valid(startX, startY, m, n, maze) || !valid(goalX, goalY, m, n, maze))
    return nullptr;
    
    if(startX == goalX && startY == goalY)
    return nullptr; 
    
    std::vector<AStarNode*> openList;
    bool closed[100][100] = {false};
    
    double h_start = distance(startX, startY, goalX, goalY);
    AStarNode* startNode = new AStarNode(startX, startY, 0, h_start, nullptr, "");
    openList.push_back(startNode);
    
    AStarNode* goalNode = nullptr;
    
    while(!openList.empty()){
        int minIdx = 0;
        for(int i = 1; i < openList.size(); i++){
            if (openList[i]->f < openList[minIdx]->f)
            minIdx = i;
        }
        
        AStarNode* current = openList[minIdx];
        openList.erase(openList.begin() + minIdx);
        
        closed[current->x][current->y] = true;
        
        if(current->x == goalX && current->y == goalY){
            goalNode = current;
            break;
        }
        
        for(int i = 0; i < 8; i++){
            int newX = current->x + dichuyen[i].dx;
            int newY = current->y + dichuyen[i].dy;
            
            if(!valid(newX, newY, m, n, maze) || closed[newX][newY]) 
            continue;
            
            
            double newG = current->g + dichuyen[i].cost;
            double newH = distance(newX, newY, goalX, goalY);
            double newF = newG + newH;
            
            bool inOpen = false;
            for(auto node : openList){
                if(node->x == newX && node->y == newY){
                    if(newG < node->g){
                        node->g = newG;
                        node->f = newF;
                        node->parent = current;
                        node->direction = dichuyen[i].name;
                    }
                    inOpen = true;
                    break;
                }
            }
            
            if(!inOpen){
                AStarNode* newNode = new AStarNode(newX, newY, newG, newH, current, dichuyen[i].name);
                openList.push_back(newNode);
            }
        }
    }
    
    if (goalNode == nullptr)
    return nullptr;
    
    PathNode* head = nullptr;
    AStarNode* current = goalNode;
    
    while(current->parent != nullptr){
        PathNode* newNode = new PathNode();
        newNode->name = current->direction;
        newNode->g = current->g;
        newNode->h = current->h;
        newNode->f = current->f;
        newNode->next = head;
        head = newNode;
        
        current = current->parent;
    }
    
    return head;
}

////////////////////

int coordToVertex(int x, int y, int n){
    return x * n + y;
}

void vertexToCoord(int vertex, int n, int& x, int& y){
    x = vertex / n;
    y = vertex % n;
}

double manhattanDistance(int x1, int y1, int x2, int y2){
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

void buildWeightMatrix(int maze[100][100], int m, int n, double weightMatrix[100][100]) {
    int totalVertices = m * n;
    
    for(int i = 0; i < totalVertices; i++){
        for (int j = 0; j < totalVertices; j++)
        weightMatrix[i][j] = 0;
    }
    
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    double cost[] = {1.0, 1.0, 1.0, 1.0, 1.5, 1.5, 1.5, 1.5};
    
    for(int x = 0; x < m; x++){
        for(int y = 0; y < n; y++){
            if (maze[x][y] == 1) continue;
            
            int fromVertex = coordToVertex(x, y, n);
            
            for(int dir = 0; dir < 8; dir++){
                int newX = x + dx[dir];
                int newY = y + dy[dir];
                
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && maze[newX][newY] == 0){  
                    int toVertex = coordToVertex(newX, newY, n);
                    weightMatrix[fromVertex][toVertex] = cost[dir];
                }
            }
        }
    }
}

struct AStarNode2 {
    int vertex; 
    int x, y;    
    double g, h, f;
    AStarNode2* parent;
    
    AStarNode2(int v, int x, int y, double g, double h, AStarNode2* p) : vertex(v), x(x), y(y), g(g), h(h), f(g+h), parent(p) {}
};

PathNode* findPathInMaze2(int maze[100][100], int m, int n, int startX, int startY, int goalX, int goalY, double weightMatrix[100][100]) {
    
    buildWeightMatrix(maze, m, n, weightMatrix);
    
    if(maze[startX][startY] == 1 || maze[goalX][goalY] == 1)
    return nullptr;
    
    if(startX == goalX && startY == goalY)
    return nullptr;
    
    int totalVertices = m * n;
    int startVertex = coordToVertex(startX, startY, n);
    int goalVertex = coordToVertex(goalX, goalY, n);
    
    std::vector<AStarNode2*> openList;
    bool closed[10000] = {false}; 
    
    double h_start = manhattanDistance(startX, startY, goalX, goalY);
    AStarNode2* startNode = new AStarNode2(startVertex, startX, startY, 0, h_start, nullptr);
    openList.push_back(startNode);
    
    AStarNode2* goalNode = nullptr;
    
    while(!openList.empty()){
        int minIdx = 0;
        for(int i = 1; i < openList.size(); i++){
            if (openList[i]->f < openList[minIdx]->f) 
            minIdx = i;    
        }
        
        AStarNode2* current = openList[minIdx];
        openList.erase(openList.begin() + minIdx);
        
        closed[current->vertex] = true;
        
        if(current->vertex == goalVertex){
            goalNode = current;
            break;
        }
        
        for(int neighbor = 0; neighbor < totalVertices; neighbor++){
            if(weightMatrix[current->vertex][neighbor] <= 0) 
            continue;
            
            if (closed[neighbor]) continue;
            
            int nx, ny;
            vertexToCoord(neighbor, n, nx, ny);
            
            double edgeWeight = weightMatrix[current->vertex][neighbor];
            double newG = current->g + edgeWeight;
            double newH = manhattanDistance(nx, ny, goalX, goalY);
            double newF = newG + newH;
            
            bool inOpen = false;
            for(auto node : openList){
                if(node->vertex == neighbor){
                    if(newG < node->g){
                        node->g = newG;
                        node->h = newH;
                        node->f = newF;
                        node->parent = current;
                    }
                    inOpen = true;
                    break;
                }
            }
            
            if(!inOpen){
                AStarNode2* newNode = new AStarNode2(neighbor, nx, ny, newG, newH, current);
                openList.push_back(newNode);
            }
        }
    }
    
    if(goalNode == nullptr) 
    return nullptr;
    
    PathNode* head = nullptr;
    AStarNode2* current = goalNode;
    
    while(current != nullptr){
        std::string nodeName = "(" + std::to_string(current->x) + ", " + std::to_string(current->y) + ")";
        
        PathNode* newNode = new PathNode(nodeName, current->f, current->g, current->h);
        newNode->next = head;
        head = newNode;
        
        current = current->parent;
    }
    
    return head;
}
