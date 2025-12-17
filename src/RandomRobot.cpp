#include "RandomRobot.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
std::vector<Edge *> RandomRobot::move(Maze &maze)
{
    std::vector<Edge *> path;
    std::vector<Edge *> possibleMoves;
    Node *currentNode = maze.getStartNode();
    std::vector<Node *> endNodes = maze.getEndNode();

    while (count(endNodes.begin(), endNodes.end(), currentNode) == 0) // continues until currentNode is one of the end nodes
    {

        // Collect all edges from the current node
        possibleMoves = currentNode->getEdges();
        // Randomly select an edge to move along
        int randomIndex = rand() % possibleMoves.size();
        Edge *selectedEdge = possibleMoves[randomIndex];
        path.push_back(selectedEdge);
        currentNode = selectedEdge->getToNode();
    }

    return path;
}