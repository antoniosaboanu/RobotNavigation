#include "WavefrontRobot.h"

/*

This function implements the movement of the WavefrontRobot in the maze.
It first calls the BFS function to perform a breadth-first search on the maze, assigning depth values to each node.
Then, for each end node, it traces back the path to the start node using the discovery edges established during the BFS.
Finally, it selects and returns the shortest path among all traced paths.
There is a path for each end node, and the function compares their lengths to find the minimum one.

*/

std::vector<Edge *> WavefrontRobot::move(Maze &maze)
{
    std::vector<std::vector<Edge *>> paths;
    std::vector<Edge *> path;
    BFS(maze);
    int endIndex = 0;
    int minPathLength = INT_MAX;
    int minPathIndex = 0;
    for (const auto &endNode : maze.getEndNode())
    {

        Node *currentNode = endNode;
        while (currentNode != maze.getStartNode())
        {
            for (auto edge : currentNode->getEdges())
            {
                if (edge->isDiscoveryEdge() && edge->getToNode()->getDepth() < currentNode->getDepth())
                {
                    path.push_back(edge);
                    currentNode = edge->getToNode();
                    break;
                }
            }
        }

        if (path.size() < minPathLength)
        {
            minPathLength = path.size();
            minPathIndex = endIndex;
        }
        endIndex++;
        paths.push_back(path);
        path.clear();
    }
    return paths[minPathIndex];
}

/*
This function performs a Breadth-First Search (BFS) on the maze starting from the start node.
It assigns depth values to each node based on their distance from the start node and marks edges as discovery or non-discovery edges.
An edge is marked as a discovery edge if it leads to an unvisited node or a node at a lower depth.
An edge is marked as a non-discovery edge if it leads to a node at the same or higher depth that already has been discovered(so there is a faster way to reach it).
*/

void WavefrontRobot::BFS(Maze &maze)
{
    std::vector<Node *> fringe = {maze.getStartNode()};
    maze.getStartNode()->setDepth(0);
    Node *currentNode = nullptr;
    std::vector<Node *> children;
    while (!fringe.empty())
    {
        currentNode = fringe.front();
        for (auto edge : currentNode->getEdges())
        {
            Node *childNode = edge->getToNode();
            if (childNode->getDepth() == -1) // this is a different way to check if the node has been visited, instead of the vector of visited nodes
            {
                childNode->setDepth(currentNode->getDepth() + 1);
                fringe.push_back(childNode);
                edge->setDiscoveryEdge(true);
            }
            else
            {
                if (childNode->getDepth() >= currentNode->getDepth()) // if the childnode is at the same depth or higher than the current node(already visited)
                    edge->setDiscoveryEdge(false);
                else // the child is at a lower depth than the current node so it's either the parent in the BFS tree or a faster way to reach the starting point
                    edge->setDiscoveryEdge(true);
            }
        }
        fringe.erase(fringe.begin());
    }
}