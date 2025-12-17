#ifndef ROBOT_H
#define ROBOT_H

#include "Edge.h"
#include "Maze.h"
#include <vector>

class Robot
{
public:
    virtual std::vector<Edge *> move(Maze &maze) = 0; // Pure virtual function for moving in the maze
};

#endif // ROBOT_H