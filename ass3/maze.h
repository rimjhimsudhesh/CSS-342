// header function for maze.cpp
// 
//

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
  // Writes the contents of the Maze object to the specified output stream.
  friend ostream &operator<<(ostream &Out, const Maze &Maze);
private:
  // Max size of maze 
  const static int MAX_SIZE = 100;
  // 2D array of Maze 
  char Field[MAX_SIZE][MAX_SIZE]; 
  // width and heigh of maze
  int Width, Height;
  // row and column of the maze's exit
  int ExitRow, ExitColumn;
public:
  explicit Maze(const string &FileName);
  // This method marks a given location in the maze as part of the solution path.
  bool isClear(int Row, int Col) const;
  void markAsPath(int Row, int Col);
  // This method marks a given location in the maze as visited (i.e. not part of the solution path).
  void markAsVisited(int Row, int Col);
  // method returns the row coordinate of the exit location in the maze
  int getExitRow() const;
  // method returns the column coordinate of the exit location in the maze
  int getExitColumn() const;
  // This method checks if a given location in the maze has been visited.
  bool isVisited(int Row, int Col) const;
  // This method checks if a given location in the maze is part of the solution path.
  bool isPath(int Row, int Col) const;

};

#endif //ASS3_MAZE_H
