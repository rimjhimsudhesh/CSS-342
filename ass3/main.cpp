/**
 * Main function to test the mazes and creatures
 * path
 * 
 * @author Rimjhim Sudhesh
*/

#include <iostream>
#include <cassert>

#include "creature.h"
#include "maze.h"


void test() {
    // Create a maze object with the maze data from "maze.txt" file
    Maze M("maze.txt");
    // Create a creature object with initial position (4, 4) in the maze
    Creature C(4, 4);
    // Output the solved path 
    cout << "Path: " << C.solve(M) << endl;
    // Output the creature's final position
    cout << C << endl;
    // Output the maze's final state
    cout << M << endl;

    // Assert that the creature's solved path is correct
    std::string result = C.solve(M);
    assert(result == "EEENNNEEEEEESEESSSEEENNNNN");   
}

void test1() {
    // Create a maze object with the maze data from "maze1.txt" file
    Maze M("maze1.txt");
    // Create a creature object with initial position (4, 4) in the maze
    Creature C(4, 4);
    // Output the solved path
    cout << "Path: " << C.solve(M) << endl;
    // Output the creature's final position
    cout << C << endl;
    // Output the maze's final state
    cout << M << endl;

    // Assert that the creature's solved path is correct
    std::string result = C.solve(M);
    assert(result == "EEENNNEEEEEESEESSSEEENNNNEEEEEEEEESSEENEEEEEEEESSSEEEEEEENNEEENEESSSEESSSSSEEEEEESSWWWWWWWWNNNWWSWWWSSWWWWWWWNNNWWWWWWWWSWWNNNWWWWWWWWWSSSSSWWWNNNWWNWWWWWWSSSWWWWWWSSSSEEEEEESSSWWWWWWSS");
}

void test2() {
    // Create a maze object with the maze data from "maze2.txt" file
    Maze M("maze2.txt");
    // Create a creature object with initial position (4, 4) in the maze
    Creature C(4, 4);
    // Output the solved path
    cout << "Path: " << C.solve(M) << endl;
    // Output the creature's final position
    cout << C << endl;
    // Output the maze's final state
    cout << M << endl;

    // Assert that the creature's solved path is correct
    std::string result = C.solve(M);
    assert(result == "EEENNNEEEEEESEESSSEEENNNNEEEEEEEEESSEENEEEEEEEESSSEEEEEEENNEEENEESSSEEEEEEEENNWWWWWWNNN"); 

}

void test3() {
    // Create a maze object with the maze data from "maze3.txt" file
    Maze M("maze3.txt");
    // Create a creature object with initial position (39, 4) in the maze
    Creature C(39, 4);
    // Output the solved path
    cout << "Path: " << C.solve(M) << endl;
    // Output the creature's final position
    cout << C << endl;
    // Output the maze's final state
    cout << M << endl;

    // Assert that the creature's solved path is correct
    std::string result = C.solve(M);
    assert(result == "NEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESSSSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSWWWWWWWWWWWWWWWWWWWWWWWWWWWSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSEEEEEEEEEEEEEEEEEEEEEEEEEEESSEEEEEEEEEEEEEEEEEEEEESSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESSSSSSSSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESSWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWSSSSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEESS");      

}


int main() {
    // testing all mazes and outputting done if successfully performed
    test();
    test1();
    test2();
    test3();
    cout << "Done!" << std::endl;
    return 0;
}