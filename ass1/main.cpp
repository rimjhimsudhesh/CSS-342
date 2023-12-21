/**
 * @brief This class represents a library with functionality to add, remove and list books.
*/

#include "library.h"

#include <cassert>
#include <iostream>


using namespace std;

/**
 * @brief A function to test the Library class functionality.
*/
void test1() {
  Library Libs("UWB");
  Libs.addBook("Don Quixote");
  Libs.addBook("In Search of Lost Time");
  Libs.addBook("Ulysses");
  Libs.addBook("The Odyssey");
  Libs.listAllBooks();
  // should generate already in library message and return true
  // Checks if book is already in the library, should return true
  bool Result = Libs.isInLibrary("The Odyssey");
  assert(Result);

  // cannot add book twice, result should be false
  Result = Libs.addBook("The Odyssey");
  assert(!Result);

  // test remove, result should be true
  Result = Libs.removeBook("The Odyssey");
  assert(Result);

  // not in library, result should be false
  Result = Libs.isInLibrary("The Odyssey");
  assert(!Result);

  // cannot remove twice, result should be false
  Result = Libs.removeBook("The Odyssey");
  assert(!Result);
}

/**
* @brief A function to run all test cases.
*/
void testAll() {
  test1();
  cout << "Successfully completed all tests." << endl;
}

/**
* @brief The main function to run the program.
*/
int main() {
  testAll();
  return 0;
}