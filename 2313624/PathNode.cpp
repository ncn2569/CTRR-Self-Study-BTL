#include "PathNode.h"

PathNode::PathNode(std::string name, double f, double g, double h)
    : name(name), f(f), g(g), h(h), next(nullptr) {}

PathNode::PathNode(){
    name = "";
    f = 0.0;
    g = 0.0;
    h = 0.0;
    next = nullptr;
}
