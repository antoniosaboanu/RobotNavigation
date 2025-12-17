#ifndef WAVEFRONT_ROBOT_H
#define WAVEFRONT_ROBOT_H

#include "Robot.h"

class WavefrontRobot : public Robot
{
public:
    WavefrontRobot() {};
    ~WavefrontRobot() {};
    std::vector<Edge *> move(Maze &maze) override;
    void BFS(Maze &maze);
};

#endif // WAVEFRONT_ROBOT_H