#include "Maze.h"
#include "Edge.h"
#include "Node.h"
#include <fstream>
#include <iostream>

Maze::Maze(std::string &filePath)
    : startNode_(nullptr), maxX_(0), maxY_(0)
{
    std::ifstream file(filePath);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            mazeString_ += line + "\n";
        }
        file.close();
    }
    else
    {
        throw std::runtime_error("Could not find file: " + filePath);
    }
}

Maze::~Maze()
{
    for (auto node : nodes_)
    {
        delete node;
    }
    startNode_ = nullptr;
    endNodes_.clear();
}

/*
This function generates the graph representation of the maze from the string representation.
first creates the nodes based on the viable cells (S, E, and spaces) in the maze string keeping track of the start and the end nodes.
Then, it establishes edges between nodes that are adjacent (Moore neighborhood).
*/

void Maze::generate()
{
    int x = 0;
    for (char ch : mazeString_)
    {
        if (ch == '\n')
        {
            maxY_++;

            if (x > maxX_)
                maxX_ = x;
            x = 0;
        }
        else
        {
            if (ch == 'S')
            {
                Node *startNode = new Node(x, maxY_);
                nodes_.push_back(startNode);
                startNode_ = startNode;
            }
            else if (ch == 'E')
            {
                Node *endNode = new Node(x, maxY_);
                nodes_.push_back(endNode);
                endNodes_.push_back(endNode);
            }
            else if (ch == ' ')
            {
                Node *pathNode = new Node(x, maxY_);
                nodes_.push_back(pathNode);
            }
            x++;
        }
    }

    for (auto node : nodes_)
    {
        for (auto otherNode : nodes_)
        {
            if (node != otherNode)
            {
                if ((std::abs(node->getX() - otherNode->getX()) <= 1) && (std::abs(node->getY() - otherNode->getY()) <= 1))
                {
                    Edge *edge = new Edge(node, otherNode);
                    node->addEdge(edge);
                }
            }
        }
    }
}

Node *Maze::getStartNode() const
{
    return startNode_;
}
const std::vector<Node *> &Maze::getEndNode() const
{
    return endNodes_;
}
const std::vector<Node *> &Maze::getNodes() const
{
    return nodes_;
}
std::string Maze::toString() const
{
    std::string nodeString = "";
    for (auto node : nodes_)
    {
        nodeString += node->toString() + "\n";
    }

    nodeString += "Start Node: (" + startNode_->toString() + ")\n";
    for (const auto &endNode_ : endNodes_)
        nodeString += "End Node: (" + endNode_->toString() + ")\n";

    return nodeString;
}

std::string Maze::getMazeString()
{
    return mazeString_;
}

std::string Maze::displayString() const
{
    std::string display = "  ";
    for (int i = 0; i < maxX_; i++)
    {
        if (i < 10)
            display += "  " + std::to_string(i);
        else
            display += " " + std::to_string(i);
    }
    display += "\n";
    bool isEndNode = false;
    for (int i = 0; i < maxY_; i++)
    {
        if (i < 10)
            display += " " + std::to_string(i);
        else
            display += std::to_string(i);
        for (int j = 0; j < maxX_; j++)
        {
            bool isNode = false;
            for (auto node : nodes_)
            {
                if (node->getX() == j && node->getY() == i)
                {
                    if (node == startNode_)
                        display += "  S";
                    else
                    {
                        for (const auto &endNode_ : endNodes_)
                        {
                            if (node == endNode_)
                            {
                                display += "  E";
                                isEndNode = true;
                                break;
                            }
                        }
                        if (!isEndNode)
                        {
                            if (node->getDepth() >= 10 || node->getDepth() < 0)
                                display += " ";
                            else
                                display += "  ";
                            display += std::to_string(node->getDepth());
                        }
                        isEndNode = false;
                    }
                    isNode = true;
                    break;
                }
            }
            if (!isNode)
                display += "  #";
        }
        display += "\n";
    }

    return display;
}
/*

This function resets the maze state by setting all node depths to -1 (unvisited).
The idea behind this function is that if multiple runs or algorithms are to be executed on the same maze instance,
it is essential to clear any previous state information (like node depths and discovery edges) to ensure accurate and independent results for each run.

*/
void Maze::cleanLastRun()
{
    for (auto node : nodes_)
    {
        node->setDepth(-1);
        for (auto edge : node->getEdges())
        {
            edge->setDiscoveryEdge(false);
        }
    }
}
