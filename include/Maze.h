#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>

#include "Node.h"
class Maze
{
public:
    Maze(std::string filePath);
    ~Maze();

    void generate();
    Node *getStartNode() const;
    Node *getEndNode() const;
    const std::vector<Node> &getNodes() const;
    std::string toString() const;

private:
    std::string mazeString_;
    std::vector<Node> nodes_;
    Node *startNode_;
    Node *endNode_;
    // Additional private members for maze representation
};

#endif // MAZE_H