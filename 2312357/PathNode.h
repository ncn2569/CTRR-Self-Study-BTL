#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


struct PathNode {
    string name;
    double f;
    double g;
    double h;
    PathNode* next;
    PathNode(string name, double f, double g, double h)
    : name(name), f(f), g(g), h(h), next(nullptr) {}
};
