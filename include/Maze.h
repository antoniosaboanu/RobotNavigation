#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>

#include "Node.h"
class Maze
{
public:
    Maze(std::string &filePath); // Constructor that takes a file path and memorizes the maze string representation
    ~Maze();

    void generate(); // Generate the graph from the string representation of the maze
    Node *getStartNode() const;
    const std::vector<Node *> &getEndNode() const;
    const std::vector<Node *> &getNodes() const;
    std::string toString() const;      // String representation of the graph
    std::string getMazeString();       // Get the original maze string
    std::string displayString() const; // Display the maze with coordinates and the depths of the nodes
    void cleanLastRun();

private:
    std::string mazeString_;       // Original maze string representation
    std::vector<Node *> nodes_;    // All nodes in the graph
    Node *startNode_;              // Pointer to the start node
    std::vector<Node *> endNodes_; // Pointers to the end nodes
    int maxX_;                     // Maximum X dimension of the maze reached from the original maze string
    int maxY_;                     // Maximum Y dimension of the maze reached from the original maze string
};

#endif // MAZE_H