/**
 * A class that represents a Creature in a Maze. The Creature can move
 * north, south, east, or west within the Maze and keep track of its
 * current position and path taken to reach that position.
*/

#include "creature.h"
#include <iostream>  // NOLINT(llvmlibc-restrict-system-libc-headers)
#include <sstream> //NOLINT

/**
 * Purpose: used to output the row and column coordinates of a Creature object
 * 
 * Pre conditions: an output stream object (std::ostream) must be provided 
 * A valid creature object must be provided as a parameter
 * 
 * Post conditions: the row and column coordinates of the Creature object 
 * will be printed to the provided output stream 
 * 
 * @param out. the output stream object to print the coordinates to
 * @param Creature the Creature object to retrieve the coordinates from
 * @return the provided object after the coordinates have been printed
 * 
*/
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {  //NOLINT
  std::cout << "C (" << Creature.Row << "," << Creature.Col << ")";
  return Out;
}

/**
 * Purpose: creates a new Creature object with the given row and column coordinates 
 * and initializes an empty path stack
 * 
 * Pre-condition: Row and Col must be valid integer values
 * 
 * Post condition: Row and Col must be valid integer values
 * 
 * @param Row the row coordinate of the Creature object
 * @param Col the col coordinate of the Creture object
 * 
*/
Creature::Creature(int Row, int Col) : Row(Row), Col(Col)  {
  Path.push("");
}

/**
 * Purpose: checks if Creature object is at the Exit
 * 
 * Pre-condition: A valid Maze object must be provided as a parameter
 * 
 * Post Condition: Returns true if the creature is at the exit of the maze,
 * false otherwise
 * 
 * @param Maze the Maze object to check the exit location against
 * @return true if Creature is at exit, false if not
*/
bool Creature::atExit(const Maze &Maze) const {
  return (this->Row == Maze.getExitRow() && this->Col == Maze.getExitColumn());
}

/**
 * Purpose: solves the given Maze using the DFS algorithm. Path starts 
 * from the starting point of the Creature object and ends at the exit point of 
 * the Maze object
 * 
 * Pre-condition: A valid Maze object must be provided as a parameter
 * 
 * Post-condition: Returns a string of the Path the creature went
 * 
 * @param Maze the Maze object for the Creature to make it's way through
 * @return string of the path the creature went 
*/
string Creature::solve(Maze &Maze) {
  // loop until solution is found or no more moves are possible
  while(true){  
    // if at exit point, push an empty string to makr the end of the path
    if(atExit(Maze)){
      Path.push("");
    }

    // try moving north 
    if(goNorth(Maze, *this)){
      goNorth(Maze);
      continue;
    }

    // try moving west
    if(goWest(Maze, *this)){
      goWest(Maze);
      continue;
    }

    // try moving south
    if(goSouth(Maze,*this)){
      goSouth(Maze);
      continue;
    }

    // try moving East
    if(goEast(Maze, *this)){
      goEast(Maze);
      continue;
    }

    // no more moves possible, end loop
    break;
  }

  // reverse the order of the elements in the stack to get correct path
  std::stack<std::string> tempStack;
    std::stringstream ss;
    while (!Path.empty()) {
        tempStack.push(Path.top());
        Path.pop();
    }
    while (!tempStack.empty()) {
        std::string element = tempStack.top();
        ss << element;
        Path.push(element);
        tempStack.pop();
    }

    // return the solution path as a string 
    return ss.str();


}

/**
 * Purpose: attempts to move the Creature object north in the 
 * provided Maze object
 * 
 * Pre-conditions: A valid Maze object must be provided as a parameter
 * A valid Creature object must be provided as a parameter
 * 
 * Post-conditions: If the cell north of the Creature object in the
 * provided Maze is clear and unvisited
 *  The creature object will move north one cell and its path will 
 *  be updated
 *    If the creature object reaches the exit cell, the function will return true
 *    If the creature object is unable to move north, the function returns false
 *    If the creature object backtracks, the previous cell in the path is popped
 *    from the stack
 * 
 * @param Maze the Maze object to move within 
 * @param myCreature the creature object to move
 * @return true if the creature object moves north successfully, false otherwise
*/
bool Creature::goNorth(Maze &Maze, Creature& myCreature) {
  Row = myCreature.Row;
  Col = myCreature.Col;
  success = false;
  if(Maze.isClear(Row - 1, Col) && (!(Maze.isVisited(Row - 1, Col)))){
    Row--; 
    Path.push("N");
    Maze.markAsPath(Row, Col);
    if(atExit(Maze)){
      return true; 
    }

    else{
      success = goNorth(Maze, myCreature);
      if(!success){
        success = goWest(Maze, myCreature);
        if(!success){
          success = goEast(Maze, myCreature);
          if(!success){
            Maze.markAsVisited(Row, Col);
            // backtrack south??????
            myCreature.Row++;
            Path.pop();
          }
        }
      }
    }
  }
  else{
    success = false;
  }
  return success;

}

/**
 * Purpose: implement the string goNorth() method
 * 
 * Pre-condittion: valid Maze object
 * 
 * Post-conditon: returns empty string
 * 
 * @param Maze the Maze object to move within
*/
string Creature::goNorth(Maze &Maze) {
  cout << goNorth(Maze, *this);
  return "";
}

/**
 * Purpose: attempts to move the Creature object west in the 
 * provided Maze object
 * 
 * Pre-conditions: A valid Maze object must be provided as a parameter
 * A valid Creature object must be provided as a parameter
 * 
 * Post-conditions: If the cell west of the Creature object in the
 * provided Maze is clear and unvisited
 *  The creature object will move west one cell and its path will 
 *  be updated
 *    If the creature object reaches the exit cell, the function will return true
 *    If the creature object is unable to move west, the function returns false
 *    If the creature object backtracks, the previous cell in the path is popped
 *    from the stack
 * 
 * @param Maze the Maze object to move within 
 * @param myCreature the creature object to move
 * @return true if the creature object moves west successfully, false otherwise
*/
bool Creature::goWest(Maze &Maze, Creature& myCreature) {
  Row = myCreature.Row;
  Col = myCreature.Col;
  if(Maze.isClear(Row, Col - 1) && (!(Maze.isVisited(Row, Col - 1)))){
    Col--;
    Path.push("W");
    Maze.markAsPath(Row, Col);
    if(atExit(Maze)){
      return true; 
    }

    else{
      success = goWest(Maze, myCreature);
      if(!success){
        success = goNorth(Maze, myCreature);
        if(!success){
          success = goSouth(Maze, myCreature);
          if(!success){
            Maze.markAsVisited(Row, Col);
            // backtrack south??????
            myCreature.Col++;
            Path.pop();
          }
        }
      }
    }
  }
  else{
    success = false;
    //
  }
  //cout << goWest(Maze);
  return success;
} 

/**
 * Purpose: implement the string goWest() method
 * 
 * Pre-condittion: valid Maze object
 * 
 * Post-conditon: returns empty string
 * 
 * @param Maze the Maze object to move within
*/
string Creature::goWest(Maze &Maze) {
  cout << goWest(Maze, *this);
  return "";
}

/**
 * Purpose: attempts to move the Creature object east in the 
 * provided Maze object
 * 
 * Pre-conditions: A valid Maze object must be provided as a parameter
 * A valid Creature object must be provided as a parameter
 * 
 * Post-conditions: If the cell east of the Creature object in the
 * provided Maze is clear and unvisited
 *  The creature object will move east one cell and its path will 
 *  be updated
 *    If the creature object reaches the exit cell, the function will return true
 *    If the creature object is unable to move east, the function returns false
 *    If the creature object backtracks, the previous cell in the path is popped
 *    from the stack
 * 
 * @param Maze the Maze object to move within 
 * @param myCreature the creature object to move
 * @return true if the creature object moves east successfully, false otherwise
*/
bool Creature::goEast(Maze &Maze, Creature& myCreature) {
  Row = myCreature.Row;
  Col = myCreature.Col;
  if(Maze.isClear(Row, Col + 1) && (!(Maze.isVisited(Row, Col + 1)))){
    Col++;
    Path.push("E");
    Maze.markAsPath(Row, Col);
    if(atExit(Maze)){
      return true; 
    }

    else{
      success = goEast(Maze, myCreature);
      if(!success){
        success = goNorth(Maze, myCreature);
        if(!success){
          success = goSouth(Maze, myCreature);
          if(!success){
            Maze.markAsVisited(Row, Col);
            // backtrack south??????
            myCreature.Col--;
            Path.pop();
          }
        }
      }

    

    }


    
  }
  else{
    success = false;
    //Path.pop();
  }

  return success;
} 

/**
 * Purpose: implement the string goEast() method
 * 
 * Pre-condittion: valid Maze object
 * 
 * Post-conditon: returns empty string
 * 
 * @param Maze the Maze object to move within
*/
string Creature::goEast(Maze &Maze) {
  cout << goEast(Maze, *this);
  return "";
}

/**
 * Purpose: attempts to move the Creature object south in the 
 * provided Maze object
 * 
 * Pre-conditions: A valid Maze object must be provided as a parameter
 * A valid Creature object must be provided as a parameter
 * 
 * Post-conditions: If the cell south of the Creature object in the
 * provided Maze is clear and unvisited
 *  The creature object will move south one cell and its path will 
 *  be updated
 *    If the creature object reaches the exit cell, the function will return true
 *    If the creature object is unable to move south, the function returns false
 *    If the creature object backtracks, the previous cell in the path is popped
 *    from the stack
 * 
 * @param Maze the Maze object to move within 
 * @param myCreature the creature object to move
 * @return true if the creature object moves south successfully, false otherwise
*/
bool Creature::goSouth(Maze &Maze, Creature& myCreature) {
  Row = myCreature.Row;
  Col = myCreature.Col;
  if(Maze.isClear(Row + 1, Col) && (!(Maze.isVisited(Row + 1, Col)))){
    Row++;
    Path.push("S");
    Maze.markAsPath(Row, Col);
    if(atExit(Maze)){
      return true; 
    }

    else{
      success = goSouth(Maze, myCreature);
      if(!success){
        success = goWest(Maze, myCreature);
        if(!success){
          success = goEast(Maze, myCreature);
          if(!success){
            Maze.markAsVisited(Row, Col);
            // backtrack south??????
            myCreature.Row--;
            Path.pop();
          }
        }
      }
    }
  }
  else{
    success = false;
    //
  }
  //cout << goSouth(Maze);
  return success;
} 

/**
 * Purpose: implement the string goSouth() method
 * 
 * Pre-condittion: valid Maze object
 * 
 * Post-conditon: returns empty string
 * 
 * @param Maze the Maze object to move within
*/
string Creature::goSouth(Maze &Maze) {
  cout << goEast(Maze, *this);
  return "";
}
