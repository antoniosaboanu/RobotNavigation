#ifndef RANDOM_ROBOT_H
#define RANDOM_ROBOT_H

#include "Robot.h"

class RandomRobot : public Robot
{
public:
    RandomRobot() {};
    ~RandomRobot() {};
    std::vector<Edge *> move(Maze &maze) override;
};

#endif // RANDOM_ROBOT_H