#ifndef EDGE_H
#define EDGE_H

#include <string>

#pragma once
class Node;

class Edge
{
public:
    Edge(Node *fromNodeId, Node *toNodeId);

    Node *getFromNode() const;
    Node *getToNode() const;

    bool isDiscoveryEdge() const;
    void setDiscoveryEdge(bool isDiscovery);
    std::string toString() const;

private:
    Node *fromNodeId_;
    Node *toNodeId_;
    bool isDiscoveryEdge_;
};

#endif // EDGE_H