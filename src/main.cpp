#include "Maze.h"
#include "RandomRobot.h"
#include "WavefrontRobot.h"
#include <iostream>

int main(int argc, char *argv[])
{

    /*
    If you want to try other paths, located in your pc, just decomment the code below and provide the path when prompted.
    std::string filePath;
    std::cout << "Enter maze file path(be aware that we are in RobotNavigation/build): ";
    std::cin >> filePath;
    Maze maze(filePath);
    maze.generate();

    std::cout << maze.toString();
    std::cout << maze.displayString();

    RandomRobot robotRandom;
    int count = 0;
    std::cout << "Random Robot Path:\n";
    std::vector<Edge *> path = robotRandom.move(maze);
    count = path.size();
    std::cout << "Total moves by Random Robot: " << countMoves << "\n";

    std::cout << "Wavefront Robot Path:\n";

    WavefrontRobot robotWavefront;
    for (const auto &edge : robotWavefront.move(maze))
    {
        std::cout << edge->toString() << "\n";
    }

    std::cout << maze.displayString();

    */

    /*
    It's nearly the same code for every maze file provided in the input folder.
    We create a maze from the file, generate the graph, display the maze based on the graph created, create both robots and display their paths and the maze after the WavefrontRobot has run.
    The random robot path is not provided because it's too long to be displayed in the console, so we just count the number of moves it made to solve the maze.
    */

    std::string assignmentFilePath1 = "../input/file1.txt";
    Maze maze(assignmentFilePath1);
    maze.generate();
    std::cout << "Maze from " << assignmentFilePath1 << " created from the graph generated:\n";
    std::cout << maze.displayString();
    RandomRobot robotRandom;
    std::cout << "Random Robot Path:\n";
    std::vector<Edge *> path = robotRandom.move(maze);
    int countMoves = path.size();
    std::cout << "Total moves by Random Robot: " << countMoves << "\n";

    std::cout << "Wavefront Robot Path:\n";
    WavefrontRobot robotWavefront;
    for (const auto &edge : robotWavefront.move(maze))
    {
        std::cout << edge->toString() << "\n";
    }
    std::cout << maze.displayString();

    std::string assignmentFilePath2 = "../input/file2.txt";
    Maze maze2(assignmentFilePath2);
    maze2.generate();
    std::cout << "Maze from " << assignmentFilePath2 << " created from the graph generated:\n";
    std::cout << maze2.displayString();
    std::cout << "Random Robot Path:\n";
    path = robotRandom.move(maze2);
    countMoves = path.size();
    std::cout << "Total moves by Random Robot: " << countMoves << "\n";
    std::cout << "Wavefront Robot Path:\n";
    for (const auto &edge : robotWavefront.move(maze2))
    {
        std::cout << edge->toString() << "\n";
    }
    std::cout << maze2.displayString();

    std::string multi_exit_file_path = "../input/maze_multi_exit_9x9.txt";
    Maze maze3(multi_exit_file_path);
    maze3.generate();
    std::cout << "Maze from " << multi_exit_file_path << " created from the graph generated:\n";
    std::cout << maze3.displayString();
    std::cout << "Random Robot Path:\n";
    path = robotRandom.move(maze3);
    countMoves = path.size();
    std::cout << "Total moves by Random Robot: " << countMoves << "\n";

    std::cout << "Wavefront Robot Path:\n";
    for (const auto &edge : robotWavefront.move(maze3))
    {
        std::cout << edge->toString() << "\n";
    }
    std::cout << maze3.displayString();

    std::string maze_plane_file_path = "../input/maze_plane_15x15.txt";
    Maze maze4(maze_plane_file_path);
    maze4.generate();
    std::cout << "Maze from " << maze_plane_file_path << " created from the graph generated:\n";
    std::cout << maze4.displayString();
    std::cout << "Random Robot Path:\n";
    path = robotRandom.move(maze4);
    countMoves = path.size();
    std::cout << "Total moves by Random Robot: " << countMoves << "\n";

    std::cout << "Wavefront Robot Path:\n";
    for (const auto &edge : robotWavefront.move(maze4))
    {
        std::cout << edge->toString() << "\n";
    }
    std::cout << maze4.displayString();

    std::string maze_standard_file_path = "../input/maze_standard_9x9.txt";
    Maze maze5(maze_standard_file_path);
    maze5.generate();
    std::cout << "Maze from " << maze_standard_file_path << " created from the graph generated:\n";
    std::cout << maze5.displayString();
    countMoves = 0;
    std::cout << "Random Robot Path:\n";
    path = robotRandom.move(maze5);
    for (const auto &edge : path)
    {
        countMoves++;
    }
    std::cout << "Total moves by Random Robot: " << countMoves << "\n";

    std::cout << "Wavefront Robot Path:\n";
    for (const auto &edge : robotWavefront.move(maze5))
    {
        std::cout << edge->toString() << "\n";
    }
    std::cout << maze5.displayString();
    return 0;
}