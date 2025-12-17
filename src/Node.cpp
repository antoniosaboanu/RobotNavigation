#include "Node.h"
#include "Edge.h"
#include <iostream>

Node::Node(int x, int y)
    : x_(x), y_(y), depth_(-1) // Initialize depth to -1 (unvisited)
{
}
Node::~Node()
{
    for (auto edge : edges_)
    {
        delete edge;
    }
}
int Node::getX() const
{
    return x_;
}
int Node::getY() const
{
    return y_;
}
int Node::getDepth() const
{
    return depth_;
}

void Node::setDepth(int depth)
{
    depth_ = depth;
}
void Node::addEdge(Edge *edge)
{
    edges_.push_back(edge);
}
const std::vector<Edge *> &Node::getEdges() const
{
    return edges_;
}
std::string Node::toString() const
{
    std::string nodeString = "Node(" + std::to_string(x_) + ", " + std::to_string(y_) + ", depth=" + std::to_string(depth_) + ")\n";
    for (const auto edge : edges_)
    {
        nodeString += "\t" + edge->toString() + "\n";
    }
    return nodeString;
}