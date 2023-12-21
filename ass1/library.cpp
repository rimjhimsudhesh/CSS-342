/**
// @author Rimjhim Sudhesh
// 
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library
// 
// Library class that performs actions like:
// findBook, isInLibrary, addBook, removeBook,
// listAllBooks, and operator overloading for "<<"
// 
// 
*/


#include "library.h"
#include <iostream>

//const int Library::MAX = 100;

// constructor with default name
Library::Library(const string &Name) {
    libraryName = Name;
    numOfBooks = 0;
}

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

/**
 * @brief Searches the library for a book with the given name
 * 
 * @param name. The name of the book to search for
 * 
 * @pre The library object has been initialized with valid data. The name 
 * parameter is a valid string
 * 
 * @post Returns the index of the first book with the given name, if found.
 * Returns -1 if no book with the given name is found
 * 
 * @return The index of the first book thats found with this name
*/
int Library::findBook(const string& name) const{
    for(int i = 0; i < numOfBooks; i++){
        if(libraryArray[i] == name){
            return i;
        }
    }
    return -1;
}


// true if book found in library
/**
 * @brief Checks if a book is in the library 
 * 
 * @param BookName. The name of the book to check
 * 
 * @pre The library object has been initialized with valid data. The 
 * BookName parameter is a valid string
 * 
 * @post Library object is unchanged
 * 
 * @return true if book is found. false if not.
*/
bool Library::isInLibrary(const string &BookName) const {
    for(int i = 0; i < numOfBooks; i++){
        if(libraryArray[i] == BookName){
            return true;
        }
    }
    return false;

}

// add a new book
// return true if successful, false if
// book already in library
/**
 * @brief adds a book to the library
 * 
 * @param BookName. The name of the book to add to library
 * 
 * @pre The library object has been initialized with valid data. The BookName
 * parameter is a valid string
 * 
 * @return true if successfully added, false if not added (book was already
 * in library)
 * 
 * @post If the book is already in the library, 
 * the function returns false.
 * If the book is not already in the library, 
 * it adds the book to the libraryArray and increments 
 * the numOfBooks counter.
 * The function returns true to indicate that the book
 *  was successfully added to the library.
*/
bool Library::addBook(const string &BookName) {
    if(isInLibrary(BookName)){
        return false;
    }
    libraryArray[numOfBooks] = BookName;
    numOfBooks++;
    return true;
}

// remove a book
// return true if successfully removed
// false if book not in library
/**
 * @brief removes a book from the library
 * 
 * @param BookName. The name of the book that needs to be removed
 * 
 * @pre The library object has been initialized with valid data. The BookName
 * parameter is a valid string
 * 
 * @return true if book was sucessfully removed, false if book could 
 * not be found in library
 * 
 * example:
 * 
 * string& BookName: "gone girl"
 * 
 * ["The oddyssey", "TKAM", "gone girl", "it ends with us"]
 * ["The oddyssey", "TKAM", "it ends with us"]
 * 
 * number of books is removed
*/
bool Library::removeBook(const string &BookName) {
    int bookIndex = findBook(BookName);
    if(bookIndex == -1){
        return false;
    }
    libraryArray[bookIndex] = libraryArray[numOfBooks - 1];
    numOfBooks--;
    return true;
}

// list all books
/**
 * @brief prints the name of all books in the library to the console
 * 
 * @pre the library object has been initialized with valid data
 * 
 * @post function prints the name of each book in the library on a seperate
 * line in the console output. The order of the books printed should be 
 * the order in which they were added to the library. The function does not modify
 * the state of the "library" object
*/
void Library::listAllBooks() const {
    for(int i = 0; i < numOfBooks; i++){
        std::cout << libraryArray[i] << std::endl;
    }
}

/**
 * @brief This function is an overloaded stream insertion 
 * operator that is used to output the details of a "Library"
 * to an output stream
 * 
 * @pre Lib is a valid "Library" object. The output stream "Out" 
 * is valid and open 
 * 
 * @post The Library object's name, number of books, and list of books 
 * are written to the output stream "Out". The output stream
 * "Out" is returned
*/
ostream &operator<<(ostream &Out, const Library &Lib) {
    Out << "Library Name:" << Lib.libraryName << endl;
    Out << "Number of Books:" << Lib.numOfBooks << endl;
    Out << "Books:" << endl;
    for(int i = 0; i < Lib.numOfBooks; i++){
        Out << Lib.libraryArray[i] << endl;
    }

    return Out;
}