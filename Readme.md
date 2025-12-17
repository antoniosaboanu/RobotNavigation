This is the project of Antonio Saboanu. You can see the assignment in the pdf file in this directory. 

The first part of this assignment is to answer some questions. 

## Q: What is a template?
A: A template is a C++ feature that enables generic programming. It allows developers to define functions or classes using placeholder types (parameters) instead of specific data types. This eliminates the need to rewrite identical code for different types. When the template is used, the compiler generates (instantiates) the specific version of the code at compile-time based on the types passed to it.

## Q: How can you make a class abstract?
A: A class is made abstract by declaring at least one of its member functions as a pure virtual function. This is done by appending = 0 to the function declaration (ex., virtual void func() = 0;). This prevents the compiler from instantiating the class and forces derived classes to implement that specific function.

## Q: What is a virtual function and how does it differ from a non-virtual function?
A: A virtual function uses dynamic binding. This means that when a function is called through a base class pointer or reference, the program checks the actual object type at runtime to decide which implementation to execute.
It differs from a non-virtual function which uses static binding. With non-virtual functions, the compiler decides which version to call based solely on the pointer type, ignoring the actual object type.

## Q: What is a base class?
A: A base class (or parent class) is a class from which other classes, known as derived classes, inherit attributes and member functions. 

## Q: What makes a class derived?
A: A class is derived when it is defined to inherit attributes and behaviors from another class (called the base class). In C++, this is explicitly declared in the class definition by placing a colon (:) after the class name, followed by the access specifier (like public) and the name of the base class.

## Q: How does a pure virtual function differ from other virtual functions?
A: A pure virtual function differs because it has no implementation in the base class and is declared with the syntax = 0. Unlike a standard virtual function (which provides a default implementation that derived classes can override), a pure virtual function forces derived classes to implement it. If they don't, they become abstract classes themselves and cannot be instantiated.

## Q: What does overriding mean?
A: Overriding is the mechanism by which a derived class provides a specific implementation for a function that is already defined in its base class. To override a function, the function in the base class must be declared as virtual, and the derived class must define a function with the exact same signature (name and parameters).


After this questions it is given an assignment. The goal is to read from a file the structure of a maze and then to programme a robot that finds a path from START to EXIT. For the detailed assignment read [assignment.pdf](Assignment.pdf).


The project solves the robot navigation problem by modeling the maze as a dynamically allocated graph.

## Key Components:

### Maze: Reads the input file and generates a graph. Traversable tiles become nodes linked by edges based on Moore neighborhood rules.

### Node & Edge: The building blocks of the graph. Nodes store BFS depth information, while Edges connect adjacent nodes.

### Robot (Base Class): Defines the virtual interface for movement.

### RandomRobot: Implements a brute-force random walk strategy (success not guaranteed).

### WavefrontRobot: Implements a Breadth-First Search (BFS) to intelligently calculate the shortest path to the exit.

### Why a Graph? 
Although a simple matrix approach would have sufficed, I chose a pointer-based graph structure allocated on the heap. This "overkill" design makes the application highly modular and ready for future expansions, such as handling weighted paths or complex maze topologies.

# AI Usage Declaration
Artificial Intelligence tools were utilized during the development of this project to enhance efficiency and code quality. The usage was strictly limited to the following areas:

## Debugging:
 AI was used to analyze segmentation faults and logic errors (specifically regarding memory management and iterator invalidation).

## Code Commenting & Refinement:
 AI assisted in refining comments for grammatical correctness and lexical precision to ensure code readability.

## Visual Studio Copilot: 
Used for code autocompletion and generating boilerplate syntax to speed up the implementation process.

# Build and Compilation
This project uses CMake to ensure cross-platform compatibility.

## Prerequisites:

CMake (Version 3.10+)

C++ Compiler (GCC, Clang, or MSVC)

## Step-by-Step Instructions:

Navigate to the project root directory.

## Create a build directory:

Bash
mkdir build
cd build
cmake ..

Bash
cmake --build . 
for windows, otherwhise "make" it will be enough

Bash
./RobotNavigation
(Replace RobotNavigation with your specific executable name if different).