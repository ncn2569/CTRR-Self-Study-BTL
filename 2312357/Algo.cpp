#include "Algo.h"
inline PathNode *build_linked_list(
    const vector<int> &path, // tham chiếu đỡ phải copy toàn bộ dữ liệu
    const double g[], const double h[], const string names[]) {
  PathNode *head = nullptr;
  PathNode *tail = nullptr;

  for (int idx : path) {
    PathNode *node = new PathNode(names[idx], g[idx] + h[idx], g[idx], h[idx]);
    if (!head) { // node đầu tiên
      head = tail = node;
    } else {
      tail->next = node; // nối node vào cuối
      tail = node;       // gán tail vào node
    };
  };
  return head;
};
void heuristic_task_1(int goal, double matrix[100][100], double h[100]) {
  // mô phỏng queue bằng head + q.size() FIFO
  // head giữ index từng hàng, hết hàng thì out
  vector<int> q;
  q.push_back(goal);
  h[goal] = 0.0;
  int head = 0;
  while (head < q.size()) {
    int u = q[head];
    for (int i = 0; i < 100; i++) {
      if (matrix[i][u] == 1.0) { // đồ thị có hướng
        if (h[u] + 1 < h[i]) {
          h[i] = h[u] + 1;
          q.push_back(i);
        };
      };
    };
    head = head + 1;
  };
};
const double MAX = 999999;

PathNode *findSocialPath(double adjMatrix[100][100], int startPerson,
                         int goalPerson) {
  double g[100], h[100];
  int parent[100];
  string names[100];
  bool visited[100];
  vector<int> path;
  MinHeap ncn;
  if (startPerson == goalPerson) {
    PathNode *head = nullptr;
    string name = to_string(startPerson);
    head = new PathNode(name, 0, 0, 0);
    return head;
  };

  for (int i = 0; i < 100; ++i) {
    g[i] = MAX;
    h[i] = MAX;
    names[i] = to_string(i);
    visited[i] = false;
    parent[i] = -1;
  };
  heuristic_task_1(goalPerson, adjMatrix, h);

  g[startPerson] = 0;
  ncn.push(g[startPerson] + h[startPerson], h[startPerson], startPerson);
  while (!ncn.empty()) {
    HeapNode temp = ncn.pop();
    if (visited[temp.id] == true)
      continue;
    if (temp.id == goalPerson) {
      break;
    };

    visited[temp.id] = true;

    for (int i = 0; i < 100; ++i) {
      if (adjMatrix[temp.id][i] == 1.0) {
        if (g[temp.id] + 1 < g[i]) {
          g[i] = g[temp.id] + 1;
          parent[i] = temp.id;
          ncn.push(g[i] + h[i], h[i], i);
        };
      };
    };
  };

  if (parent[goalPerson] == -1)
    return nullptr;
  int i = goalPerson;
  while (parent[i] != -1) {
    path.push_back(parent[i]);
    i = parent[i];
  };
  reverse(path.begin(), path.end());
  path.push_back(goalPerson);
  return build_linked_list(path, g, h, names);
};

double heuristic_task_2(int x1, int x2, int y1, int y2, int mode) {
  if (mode == 1) {
    return abs(x1 - x2) + abs(y1 - y2);
  };
  if (mode == 2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
  };
  if (mode == 3) {
    return max(abs(x1 - x2), abs(y1 - y2));
  };
  return 0.0;
};

PathNode *findDronePath(double adjMatrix[100][100], int coords[100][2],
                        int startPoint, int goalPoint, int mode) {
  double g[100], h[100];
  bool visited[100];
  MinHeap ncn;
  string names[100];
  int parents[100];
  vector<int> path;
  if (startPoint == goalPoint) {
    PathNode *head = nullptr;
    string name = "(" + to_string(coords[startPoint][0]) + "," +
                  to_string(coords[startPoint][1]) + ")";
    head = new PathNode(name, 0, 0, 0);
    return head;
  }
  for (int i = 0; i < 100; i++) {
    g[i] = MAX;
    h[i] = MAX;
    visited[i] = false;
    parents[i] = -1;
    names[i] =
        "(" + to_string(coords[i][0]) + "," + to_string(coords[i][1]) + ")";
  };
  g[startPoint] = 0;
  h[startPoint] =
      heuristic_task_2(coords[startPoint][0], coords[goalPoint][0],
                       coords[startPoint][1], coords[goalPoint][1], mode);

  ncn.push(g[startPoint] + h[startPoint], h[startPoint],
           startPoint); // tutu tính
  while (!ncn.empty()) {
    HeapNode temp = ncn.pop();
    if (temp.id == goalPoint)
      break;
    if (visited[temp.id] == true)
      continue;
    visited[temp.id] = true;
    for (int i = 0; i < 100; ++i) {
      if (adjMatrix[temp.id][i] != 0.0) {
        if (g[temp.id] + adjMatrix[temp.id][i] < g[i]) {
          g[i] = g[temp.id] + adjMatrix[temp.id][i];
          parents[i] = temp.id;
          h[i] = heuristic_task_2(coords[i][0], coords[goalPoint][0],
                                  coords[i][1], coords[goalPoint][1], mode);
          ncn.push(g[i] + h[i], h[i], i);
        };
      };
    };
  };
  if (parents[goalPoint] == -1)
    return nullptr;
  int i = goalPoint;

  while (parents[i] != -1) {
    path.push_back(parents[i]);
    i = parents[i];
  };
  reverse(path.begin(), path.end());
  path.push_back(goalPoint);
  return build_linked_list(path, g, h, names);
};

double heuristic_task_3_4(int x1, int x2, int y1, int y2, int mode) {
  if (mode == 1) {
    return abs(x1 - x2) + abs(y1 - y2);
  }
  if (mode == 2) {
    return max(abs(x1 - x2), abs(y1 - y2));
  }
  return 0.0;
};
// Task 3 dùng flattening
// id=x*100+y
// x=id/100
// y=id%100
PathNode *findWarehousePath(int warehouse[100][100], int m, int n, int startX,
                            int startY, int goalX, int goalY, int mode) {
  double g[10000], h[10000];
  bool visited[10000];
  MinHeap ncn;
  string names[10000];
  int parents[10000];
  vector<int> path;
  // helper from 2d to 1d
  const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
  const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
  const double m_cost[] = {1.0, 1.0, 1.0, 1.0, 1.5, 1.5, 1.5, 1.5};
  const string directions[] = {"Up",        "Down",      "Left",
                               "Right",     "Up-Left",   "Up-Right",
                               "Down-Left", "Down-Right"};

  int startPoint = startX * 100 + startY;
  int goalPoint = goalX * 100 + goalY;

  if (startPoint == goalPoint) {
    PathNode *head = nullptr;
    string name = "(" + to_string(startX) + "," + to_string(startY) + ")";
    head = new PathNode(name, 0, 0, 0);
    return head;
  }

  for (int i = 0; i < 10000; i++) {
    g[i] = MAX;
    h[i] = MAX;
    visited[i] = false;
    parents[i] = -1;
  };
  g[startPoint] = 0;
  h[startPoint] = heuristic_task_3_4(startX, goalX, startY, goalY, mode);
  names[startPoint] = "(" + to_string(startX) + "," + to_string(startY) + ")";
  ncn.push(g[startPoint] + h[startPoint], h[startPoint],
           startPoint); // tutu tính

  while (!ncn.empty()) {
    HeapNode temp = ncn.pop();
    if (temp.id == (goalPoint))
      break;
    if (visited[temp.id] == true)
      continue;
    visited[temp.id] = true;
    int tx = temp.id / 100;
    int ty = temp.id % 100;
    for (int i = 0; i < 8; i++) {
      int nx = tx + dx[i];
      int ny = ty + dy[i];
      if ((nx >= 0 && nx <= m - 1 && ny >= 0 && ny <= n - 1)) {
        if (warehouse[nx][ny] == 0) {
          int new_id = nx * 100 + ny;
          double g_new = g[temp.id] + m_cost[i];
          if (g_new < g[new_id]) {
            double h_new = heuristic_task_3_4(nx, goalX, ny, goalY, mode);
            ncn.push(g_new + h_new, h_new, new_id);
            parents[new_id] = temp.id;
            names[new_id] = directions[i];
            g[new_id] = g_new;
            h[new_id] = h_new;
          }
        } else if (warehouse[nx][ny] == 1)
          continue;
      }
    }
  }
  if (parents[goalPoint] == -1)
    return nullptr;
  int i = goalPoint;

  while (parents[i] != -1) {
    path.push_back(parents[i]);
    i = parents[i];
  };
  reverse(path.begin(), path.end());
  path.push_back(goalPoint);
  PathNode *trick;
  trick = build_linked_list(path, g, h, names);
  if (trick == nullptr)
    return nullptr;
  PathNode *head = trick->next;
  delete trick; // Dọn dẹp node Start dư thừa
  return head;
};

PathNode *findEvacuationPath(int floorPlan[100][100], int m, int n, int startX,
                             int startY, int exitX, int exitY,
                             double weightMatrix[100][100], int mode) {
    double g[10000], h[10000];
    bool visited[10000];
    MinHeap ncn;
    string names[10000];
    int parents[10000];
    vector<int> path;
    // helper from 2d to 1d
    const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    const double m_cost[] = {1.0, 1.0, 1.0, 1.0, 1.5, 1.5, 1.5, 1.5};
    const string directions[] = {"Up",        "Down",      "Left",
                                "Right",     "Up-Left",   "Up-Right",
                                "Down-Left", "Down-Right"};

    int startPoint = startX * 100 + startY;
    int goalPoint = exitX * 100 + exitY;

    if (startPoint == goalPoint) {
        PathNode *head = nullptr;
        string name = "(" + to_string(startX) + "," + to_string(startY) + ")";
        head = new PathNode(name, 0, 0, 0);
        weightMatrix[startX][startY] = 0;
        return head;
    }

    for (int i = 0; i < 10000; i++) {
        g[i] = MAX;
        h[i] = MAX;
        visited[i] = false;
        parents[i] = -1;
    };
    g[startPoint] = 0;
    h[startPoint] = heuristic_task_3_4(startX, exitX, startY, exitY, mode);
    names[startPoint] = "(" + to_string(startX) + "," + to_string(startY) + ")";
    ncn.push(g[startPoint] + h[startPoint], h[startPoint],
            startPoint); // tutu tính

    while (!ncn.empty()) {
        HeapNode temp = ncn.pop();
        if (temp.id == (goalPoint)) break;
        if (visited[temp.id] == true) continue;
        visited[temp.id] = true;
        int tx = temp.id / 100;
        int ty = temp.id % 100;
        for (int i = 0; i < 8; i++) {
        int nx = tx + dx[i];
        int ny = ty + dy[i];
        if ((nx >= 0 && nx <= m - 1 && ny >= 0 && ny <= n - 1)) {
            if (floorPlan[nx][ny] == 0) {
            int new_id = nx * 100 + ny;
            double g_new = g[temp.id] + m_cost[i];
            if (g_new < g[new_id]) {
                double h_new = heuristic_task_3_4(nx, exitX, ny, exitY, mode);
                ncn.push(g_new + h_new, h_new, new_id);
                parents[new_id] = temp.id;
                names[new_id] = directions[i];
                g[new_id] = g_new;
                h[new_id] = h_new;
            }
            } else if (floorPlan[nx][ny] == 1)
            continue;
        }
        }
    }
    if (parents[goalPoint] == -1)
        return nullptr;
    int i = goalPoint;

    while (parents[i] != -1) {
        path.push_back(parents[i]);
        int x = parents[i] / 100;
        int y = parents[i] % 100;
        weightMatrix[x][y] = g[parents[i]];
        i = parents[i];
    };
    reverse(path.begin(), path.end());
    path.push_back(goalPoint);
    int x = goalPoint / 100;
    int y = goalPoint % 100;
    weightMatrix[x][y] = g[goalPoint];
    PathNode *trick;
    trick = build_linked_list(path, g, h, names);
    if (trick == nullptr)
        return nullptr;
    PathNode *head = trick->next;
    delete trick; // Dọn dẹp node Start dư thừa
    return head;
};