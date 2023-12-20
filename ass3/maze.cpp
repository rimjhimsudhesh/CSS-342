// Creates class Maze and outputs the maze 
// Has methods like isPath and isVisited to help
// with creature.cpp

#include <fstream>
#include <iostream>
#include "maze.h"
#include <string>

using namespace std;
/**
 * Pre condition: The Maze object must be initialized and valid.
 * 
 * Post condition: The contents of the Maze object are written to the output stream in row-major order.
 * The output stream is returned after writing the contents of the Maze object.
 * 
 * Purpose: This function allows the contents of a Maze object to be easily written to an output stream,
 * which can be useful for debugging and other purposes.
 * 
 * @param Out the output stream to write to.
 * @param Maze the Maze object to write.
 * @return the output stream after the Maze has been written to it.
*/
ostream &operator<<(ostream &Out, const Maze &Maze) {
  for (int Row = 0; Row < Maze.Height; ++Row) {
    for (int Col = 0; Col < Maze.Width; ++Col) {
      Out << Maze.Field[Row][Col];
    }
    Out << endl;
  }
  Out << endl;
  return Out;
}

// For Clion, need the following line in CMakeLists.txt so maze.txt is found
// at the same location as the cpp files
// # need to load data files from current directory as cpp files
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
Maze::Maze(const string &FileName) {
  ifstream InFile;
  InFile.open(FileName);
  if (!InFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  InFile >> Width >> Height;
  InFile >> ExitRow >> ExitColumn;
  string Str;
  getline(InFile, Str);
  for (int Row = 0; Row < Height; ++Row) {
    for (int Col = 0; Col < Width; ++Col) {
      InFile.get(Field[Row][Col]);
      // cout << Row << ", " << col << ": " << field[Row][col] << endl;
    }
    getline(InFile, Str);
  }

}

/**
 * Purpose: method returns the row coordinate of the exit
 * location in the maze
 * 
 * Pre-conditions: Maze object has been initialized 
 * 
 * Post condition: row coordinate of the exit location
 * is returned
 * 
 * @return int. row coordinate of the exit location
*/
int Maze::getExitRow() const {
  return ExitRow;
}

/**
 * Purpose: method returns the column coordinate of the exit
 * location in the maze
 * 
 * Pre-conditions: Maze object has been initialized 
 * 
 * Post condition: column coordinate of the exit location
 * is returned
 * 
 * @return int. column coordinate of the exit location
*/
int Maze::getExitColumn() const {
  return ExitColumn;
}

/**
 * Purpose: This method checks if a given location in the maze is clear 
 * (i.e. not a wall).
 * 
 * Pre-conditions: The Maze object must have been initialized.
 * The row and column coordinates must be within the bounds of the maze.
 * 
 * Post-conditions:
 * True is returned if the given location is clear (not a wall), false otherwise.
 * 
 * @return bool. returns true if given location is clear, false otherwise
*/
bool Maze::isClear(int Row, int Col) const {
  return Field[Row][Col] == ' ';
}


/**
 * Purpose: This method marks a given location in the maze as part 
 * of the solution path.
 * 
 * Pre-conditions:
 * The Maze object must have been initialized.
 * The row and column coordinates must be within the bounds of the maze.
 * The location must be clear (not a wall).
 * 
 * Post-conditions:
 * The given location is marked as part of the solution path.
 * 
*/
void Maze::markAsPath(int Row, int Col) {
  Field[Row][Col] = '*';
}

/**
 * Purpose: This method marks a given location in the maze as visited
 *  (i.e. not part of the solution path).
 * 
 * Pre-conditions:
 * The Maze object must have been initialized.
 * The row and column coordinates must be within the bounds of the maze.
 * The location must be clear (not a wall).
 * 
 * Post-conditions:
 * The given location is marked as visited (not part of the solution path).
*/
void Maze::markAsVisited(int Row, int Col) {
  Field[Row][Col] = '+';
}

/**
 * Purpose: This method checks if a given location in the maze has been visited.
 * 
 * Pre-conditions: The Maze object must have been initialized.
 * The row and column coordinates must be within the bounds of the maze.
 * 
 * Post-conditions:
 * True is returned if the given location has been visited, false otherwise.
 * 
 * @return bool. True if the location has been visited, false otherwise
*/
bool Maze::isVisited(int Row, int Col) const {
  if(Field[Row][Col] == '+'){
    return true;
  }

  return false;
}


/**
 * Purpose: This method checks if a given location in the maze is part of the solution path.
 * 
 * Pre-conditions: The Maze object must have been initialized. 
 * The row and column coordinates must be within the bounds of the maze.
 * 
 * Post-conditions: True is returned if the given location is part of the solution path, 
 * false otherwise.
 * 
 * @return bool. True if location is part of the solution path,
 * false otherwise
*/
bool Maze::isPath(int Row, int Col) const{
  if(Field[Row][Col] == '*'){
    return true;
  }

  return false;
}