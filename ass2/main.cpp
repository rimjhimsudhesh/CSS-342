/**
 * tests all operators and methods from polynomial.h
*/

#include "polynomial.h"

#include <cassert>
#include <iostream>

using namespace std;

int main() {
  
  // Testing default constructor
  Polynomial p2({4, 1, 3});
  assert(p2 == Polynomial({4, 1, 3})); 
  cout << p2 << std::endl; 

  // Testing >> operator
  //std::cin >> p2;
  //assert(p2 == Polynomial({1, 2, 3, 4}));

  // Testing operator== and operator!=
  Polynomial p3({1, 2, 3});
  Polynomial p4({1, 2, 3});
  Polynomial p5({2, 3, 4});
  assert(p3 == p4);
  assert(p3 != p5);

  // Testing operator>, operator<, operator>=, operator<=
  Polynomial p6({1, 2, 3});
  Polynomial p7({2, 3, 4, 5});
  assert(p6 < p7);
  assert(p7 > p6);
  assert(p6 <= p7);
  assert(p7 >= p6);

  // Testing operator*, operator+, operator-, operator+=, operator-=, operator*=
  Polynomial p8({1, 2, 3});
  Polynomial p9({4, 5});
  Polynomial p10 = p8 * p9;
  assert(p10 == Polynomial({4, 13, 22, 15}));
  
  Polynomial p11 = p8 + p9;
  assert(p11 == Polynomial({1, 6, 8}));

  Polynomial p12 = p8 - p9;
  assert(p12 == Polynomial({1, -2, -2}));
  
  p8 += p9;
  assert(p8 == Polynomial({1, 6, 8}));
  
  p8 -= p9;
  assert(p8 == Polynomial({1, 2, 3}));
  
  p8 *= p9;
  assert(p8 == Polynomial({4, 13, 22, 15}));

  cout << "Passed all tests!" << endl;

  return 0; 

 
}


