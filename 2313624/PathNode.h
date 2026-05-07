#ifndef PATHNODE_H
#define PATHNODE_H

#include <string>

struct PathNode {
    std::string name;
    double f;
    double g;
    double h;
    PathNode* next;
    PathNode();
    PathNode(std::string name, double f, double g, double h);
};

#endif
