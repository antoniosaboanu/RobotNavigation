#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

class Edge
{
public:
    Edge(Node *fromNodeId, Node *toNodeId);
    ~Edge();

    Node *getFromNode() const;
    Node *getToNode() const;

    bool isDiscoveryEdge() const;
    void setDiscoveryEdge(bool isDiscovery);

private:
    Node *fromNodeId_;
    Node *toNodeId_;
    bool isDiscoveryEdge_;
};

#endif // EDGE_H