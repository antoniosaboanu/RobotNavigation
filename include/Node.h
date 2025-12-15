#ifndef NODE_H
#define NODE_H

#include "Edge.h"
#include <vector>

class Node
{
public:
    Node(int x, int y);
    ~Node();

    int getX() const;
    int getY() const;
    int getDepth() const;
    void setDepth(int depth);

    void addEdge(const Edge &edge);
    const std::vector<Edge> &getEdges() const;

private:
    int x_;
    int y_;
    int depth_;
    std::vector<Edge> edges_;
};

#endif // NODE_H
