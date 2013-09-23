//
// ECE3090 Program 1 - Complex Number Class decaration
// Jonathan Tuck
//

// Class declaration for Complex number class
// ECE3090 Lab 1
#include <iostream>
#include <string>
class Complex {
public:
  // Define your constructors here
  // Constructors
  Complex();
  Complex(double,double);
  Complex(const std::string&);
  // Define the other required member functions here
  // Member Functions
  void set_realPart(double);
  void set_imgPart(double);
  double get_realPart();
  double get_imgPart();
  void Print();
  // Define your operator overloads here if using member function overloads
  Complex operator+(Complex c);
  Complex operator-(Complex d);
  // Define your Data Members here
  // Data Members
  double realPart;
  double imgPart;
 private:
 
};

// Define your operator overloads here if using non-member function
// operator overloads.

Complex operator*(Complex c5, Complex c6);
Complex operator/(Complex c7, Complex c8);




