#include "Edge.h"
#include "Node.h"

Edge::Edge(Node *fromNodeId, Node *toNodeId)
    : fromNodeId_(fromNodeId), toNodeId_(toNodeId), isDiscoveryEdge_(false)
{
}
Node *Edge::getFromNode() const
{
    return fromNodeId_;
}
Node *Edge::getToNode() const
{
    return toNodeId_;
}
bool Edge::isDiscoveryEdge() const
{
    return isDiscoveryEdge_;
}
void Edge::setDiscoveryEdge(bool isDiscovery)
{
    isDiscoveryEdge_ = isDiscovery;
}
std::string Edge::toString() const
{
    return "Edge(from: (" + std::to_string(fromNodeId_->getX()) + ", " + std::to_string(fromNodeId_->getY()) + "), to: (" + std::to_string(toNodeId_->getX()) + ", " + std::to_string(toNodeId_->getY()) + "), isDiscovery: " + (isDiscoveryEdge_ ? "true" : "false") + ")";
}
