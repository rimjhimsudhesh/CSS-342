/**
 * Represents a polynomial with real coefficients. The coefficients are stored in a vector,
 * where each element corresponds to a term in the polynomial. For example, the polynomial
 * 3x^2 + 2x + 1 would be represented by the vector [1, 2, 3].
 * 
 * @author Rimjhim Sudhesh
*/

#include "polynomial.h"

/**
 * Purpose
 * Create a new polynomial object with the given coefficients.

Parameters
c: A vector of doubles representing the coefficients of the polynomial.
Pre-conditions
other is a valid Polynomial object.

Post-conditions
A new Polynomial object is created with the coefficients specified in c.
*/
Polynomial::Polynomial(const std::vector<double>& c){
    coeffs = c;
}

/**
 * Overloaded operator for output stream.

Purpose
Overload the << operator for easy printing of polynomials.

Parameters
out: A reference to the output stream object.
p: A constant reference to the Polynomial object to be printed.

Pre-conditions
other is a valid Polynomial object.

Post-conditions
The polynomial p is printed to the output stream out.
*/

std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
  for(int i = static_cast<int>(p.coeffs.size() - 1) ; i > 0; i--){
    out << p.coeffs[i] << "x^" << i << " + ";
    }

    out << p.coeffs[0];
    return out;
}

/**
 * Overloaded operator for input stream.

Purpose
Overload the >> operator for easy input of polynomials.

Parameters
in: A reference to the input stream object.
p: A reference to the Polynomial object to store the input.

Pre-conditions
other is a valid Polynomial object.

Post-conditions
The input stream in is read and a new Polynomial object is created and stored in p.
*/

std::istream& operator>>(std::istream& in, Polynomial& p) {
    std::vector<double> coeffs;
    double coeff;
    char c;

    while (in >> coeff) {
        coeffs.push_back(coeff);
        if (in.peek() == '\n' || in.peek() == EOF) {
            break;
        }
        in >> c;
    }

    p = Polynomial(coeffs);
    return in;
}

/**
 * Overloaded operator for addition of two polynomials.

Purpose
Add two polynomials and return the result.

Parameters
other: A constant reference to the Polynomial object to be added.
Pre-conditions
None.

Post-conditions
A new Polynomial object is created that is the sum of the two polynomials.
*/

Polynomial Polynomial::operator+(const Polynomial &other) const {
    int max_degree = std::max(coeffs.size(), other.coeffs.size());
    std::vector<double> result_coeffs(max_degree);

    int i = coeffs.size() - 1;
    int j = other.coeffs.size() - 1;
    int k = max_degree - 1;

    while(k >= 0) {
        double coefficient = 0;
        if(i >= 0){
            coefficient += coeffs[i];
        } 
        if(j >= 0)  {
            coefficient += other.coeffs[j];
        }

        result_coeffs[k] = coefficient;

        i--;
        j--;
        k--;
    }

    Polynomial result(result_coeffs);
    return result;
}

/**
 * Overloaded operator for subtraction of two polynomials.
 * Purpose: Subtract one polynomial from another and return the result.
 * Parameters other: A constant reference to the Polynomial object to be subtracted.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions: A new Polynomial object is created that is the difference of the two polynomials.
*/
Polynomial Polynomial::operator-(const Polynomial &other) const{
    int max_degree = std::max(coeffs.size(), other.coeffs.size());
    std::vector<double> result_coeffs(max_degree);

    int i = coeffs.size() - 1;
    int j = other.coeffs.size() - 1;
    int k = max_degree - 1;

    while(k >= 0) {
        double coefficient = 0;
        if(i >= 0){
            coefficient = coeffs[i];
        } 
        if(j >= 0)  {
            coefficient -= other.coeffs[j];
        }

        result_coeffs[k] = coefficient;

        i--;
        j--;
        k--;
    }

    Polynomial result(result_coeffs);
    return result;
}

/**
 * Overloaded operator for multiplication of two polynomials.
 * Purpose: Multiply two polynomials and return the result.
 * Parameters other: A constant reference to the Polynomial object to be multiplied.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions
 * A new Polynomial object is created that is the product of the two polynomials.
*/

Polynomial Polynomial::operator*(const Polynomial& other) const {
    int size1 = coeffs.size() - 1;
    int size2 = other.coeffs.size() - 1;

    std::vector<double> result_coeffs(size1 + size2 + 1);

    for(int i = 0; i <= size1; i++){
        for(int j = 0; j <= size2; j++){
            result_coeffs[i+j] += coeffs[i] * other.coeffs[j];
        }
    }

    Polynomial result(result_coeffs);
    return result;
}

/**
 * Overloaded operator for in-place multiplication of two polynomials.
 * Purpose: Multiply this polynomial by another and store the result in this polynomial.
 * Parameters other: A constant reference to the Polynomial object to be multiplied.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions: This Polynomial object is modified to be the product of itself and the other polynomial.
*/
Polynomial Polynomial::operator*=(const Polynomial &other) {
    *this = *this * other;

    return *this;
}

/**
 * Overloaded operator for in-place addition of two polynomials.
 * Purpose: Add another polynomial to this polynomial and store the result in this polynomial.
 * Parameters other: A constant reference to the Polynomial object to be added.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions: This Polynomial object is modified to be the sum of itself and the other polynomial.
*/
Polynomial Polynomial::operator+=(const Polynomial &other) {
    *this = *this + other;

    return *this;
}

/**
 * This function overloads the -= operator for the Polynomial class.
 * It subtracts another polynomial (other) from the current polynomial (*this) and assigns the result to the current polynomial.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions: The current polynomial is modified to contain the result of the subtraction operation.
*/

Polynomial Polynomial::operator-=(const Polynomial &other) {
    *this = *this - other;

    return *this;
}

/**
 * This function overloads the == operator for the Polynomial class.
 * It compares the current polynomial (*this) with another polynomial (other) to check if they are equal.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions: Returns a boolean value indicating whether the two polynomials are equal or not.
*/
bool Polynomial::operator==(const Polynomial& other) const {
    if(coeffs.size() != other.coeffs.size()){
        return false;
    }

    
    for(int i = 0; i < coeffs.size(); i++){
        if(coeffs[i] != other.coeffs[i]){
                return false;
        }  

    }

    return true;
}

/**
 * This function overloads the != operator for the Polynomial class.
 * It compares the current polynomial (*this) with another polynomial (other) to check if they are not equal.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions: Returns a boolean value indicating whether the two polynomials are not equal or not.
*/
bool Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);
}

/**
 * This function overloads the > operator for the Polynomial class.
 * It compares the degree of the current polynomial (*this) with the degree of another polynomial (other) to check if the current polynomial has a greater degree.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions: Returns a boolean value indicating whether the degree of the current polynomial is greater than the degree of other.
*/
bool Polynomial::operator>(const Polynomial& other) const{
    int deg1 = coeffs.size() - 1;
    int deg2 = other.coeffs.size() - 1;
    
    if(deg1 > deg2){
        return true;
    }

    else{
        return false;
    }
}

/**
 * This function overloads the < operator for the Polynomial class.
 * It compares the degree of the current polynomial (*this) with the degree of another polynomial (other) to check if the current polynomial has a smaller degree.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions: Returns a boolean value indicating whether the degree of the current polynomial is less than the degree of other.
*/
bool Polynomial::operator<(const Polynomial& other) const{
    int deg1 = coeffs.size() - 1;
    int deg2 = other.coeffs.size() - 1;
    
    if(deg1 < deg2){
        return true;
    }

    else{
        return false;
    }
}   

/**
 * This function overloads the <= operator for the Polynomial class.
 * It compares the current polynomial (*this) with another polynomial (other) to check if the current polynomial has a smaller or equal degree.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions: Returns a boolean value indicating whether the degree of the current polynomial is less than or equal to the degree of other.
*/
bool Polynomial::operator<=(const Polynomial& other) const{
    if(*this < other){
        return true; 
    }

    else if(*this == other){
        return true;
    }

    return false;
}
/**
 * This function overloads the >= operator for the Polynomial class.
 * It compares the current polynomial (*this) with another polynomial (other) to check if the current polynomial has a greater or equal degree.
 * Pre-conditions: other is a valid Polynomial object.
 * Post-conditions: Returns a boolean value indicating whether the degree of the current polynomial is greater than or equal to the degree of other.
*/
bool Polynomial::operator>=(const Polynomial& other) const{
    if(*this > other){
        return true;
    }

    else if(*this == other){
        return true;
    }

    return false;
}