// header file for creature.cpp

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>
#include <stack>

class Creature {
public:
  // Friend function that overloads the << operator to output the
  // row and column coordinates of a Creature object.
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row; // current position of the Creature 
  int Col; // current column of the Creature
  bool success; // whether or not the Creature has successfully found a path to the exit.
  std::stack<string> Path; // A stack that represents the path taken by the Creature to reach its current position.


public:
  // Constructor that initializes a Creature object with the provided row and column coordinates.
  Creature(int Row, int Col); 
  // Finds a path from the Creature's current position to the exit of the provided Maze 
  string solve(Maze &Maze); 
  // Checks whether or not the Creature is at the exit
  bool atExit(const Maze &Maze) const; 
  // Moves the Creature one step north within the provided Maze object and updates path
  string goNorth(Maze &Maze); 
  // Recursively moves the Creature one or more steps north
  bool goNorth(Maze &Maze, Creature &myCreature); 
  // Moves the Creature one step south within the provided Maze object and updates path
  string goSouth(Maze &Maze); 
  // Recursively moves the Creature one or more steps south
  bool goSouth(Maze &Maze, Creature &myCreature); 
  // Moves the Creature one step east within the provided Maze object and updates path
  string goEast(Maze &Maze);
  // Recursively moves the Creature one or more steps east
  bool goEast(Maze &Maze, Creature &myCreature);
  // Moves the Creature one step west within the provided Maze object and updates path
  string goWest(Maze &Maze);
  // Recursively moves the Creature one or more steps west
  bool goWest(Maze &Maze, Creature &myCreature);
};

#endif //ASS3_CREATURE_H
