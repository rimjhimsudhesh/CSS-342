Goals: Understanding operator overloading, for reference and help take a look at RationalLinks to an external site. class operator overloading. 

Polynomials are expressions that consist of a sum of terms, each of which is a variable raised to a power multiplied by a coefficient. In C++, they can be represented as a class that stores the coefficients of the polynomial as an array,

For example the following Polynomial expression 
   can be presented as the following array [1,5,0,4]

Or 
 would be presented as [5,1,0]

For these numbers operators such as addition, subtraction, multiplication, etc can be overloaded to work with polynomials. For example addition between the above two polynomials will be 
 which in terms of array it can be represented as [1,10,1,4]

 

Example use cases:

 

Polynomial p1({1, 2, 3});   // x^2 + 2x + 3
Polynomial p2({4, 5, 6});   // 4x^2 + 5x + 6

Polynomial p3 = p1 + p2;

Polynomial p4 = p1 * p2;    // (x^2 + 2x + 3) * (4x^2 + 5x + 6)
cout << p3;            // output: 4x^4 + 13x^3 + 28x^2 + 27x + 18
