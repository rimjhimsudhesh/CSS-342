/**
 * header file for Polynomial.cpp
 * includes operator overloading, comparasion,
 * and equality checks
*/
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>

using namespace std;

class Polynomial {

private:
    std::vector<double> coeffs;  // coefficients of the polynomial
    
    
public:
    // constructor that takes a vector of coefficients
    Polynomial(const std::vector<double>& c);    
    
    // addition operator
    Polynomial operator+(const Polynomial& other) const;
    
    // subtraction operator
    Polynomial operator-(const Polynomial& other) const;
    
    // multiplication operator
    Polynomial operator*(const Polynomial& other) const;

    // adding to operator
    Polynomial operator+=(const Polynomial& other) ;

    // subtracting from operator
    Polynomial operator-=(const Polynomial& other) ;
    
    // multiplying to operator
    Polynomial operator*=(const Polynomial& other) ;

    // greater than comparasion
    bool operator>(const Polynomial& other) const;

    // less than comparasion
    bool operator<(const Polynomial& other) const;

    // greater than or equal to comparasion
    bool operator>=(const Polynomial& other) const;
    
    // less than or equal to comparasion
    bool operator<=(const Polynomial& other) const;
    
    // check equality
    bool operator==(const Polynomial& other) const;

    // check if not equal
    bool operator!=(const Polynomial& other) const;
   
    // print function
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& other);

    // in operation
    friend std::istream& operator>>(std::istream& in, const Polynomial& other);
   
};

#endif