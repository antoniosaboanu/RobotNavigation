#ifndef NODE_H
#define NODE_H

#include <vector>

#pragma once
class Edge;

class Node
{
public:
    Node(int x, int y);
    ~Node();

    int getX() const;
    int getY() const;
    int getDepth() const;
    void setDepth(int depth);

    void addEdge(Edge *edge);
    const std::vector<Edge *> &getEdges() const;
    std::string toString() const;

private:
    int x_;
    int y_;
    int depth_;
    std::vector<Edge *> edges_; // Links to adiacent nodes via edges
};

#endif // NODE_H
