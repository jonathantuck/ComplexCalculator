//
// ECE3090 Program 1 - Complex Number Calculator
// Jonathan Tuck
//

#include <iostream>
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "complex.h"
#include "string-parse.h"

using namespace std;

int main()
{
  // Add any variables you might need here
  Complex cOld;
  while(true)
    {
      string st = GetStringFromKeyboard(); // Get the  next input line
      // The types StringArray_t and CharArray_t are defined in string-parse.h
      // They are fixed length arrays of 3 elements.
      // The StringParse function returns an integer indicating how many
      // of the three are actually used.
      StringArray_t operands; // array of operands
      CharArray_t   delims;   // array of delimiters
      int count = StringParse(st, "+-*/", operands, delims);
      if (count == 0) break; // All done
      Complex c1, c2, cNew;
      const std::string& A = operands[0];
      const std::string& B = operands[1];
      char op = delims[0];
      
      if (count == 2)
	{
      c1 = Complex(A);
      c2 = Complex(B);
      if (A.length() == 0) // entry with one delimiter followed by one complex number (values of components don't matter)
	{
	  c1 = cOld;
	  c2 = c2;
	}
      switch(op)
	{
	case '*':
	  cNew = c1 * c2;
	  break;
	case '/':
	  if ( (c2.realPart == 0 && c2.imgPart == 0) || (c1.realPart == NAN) || (c2.realPart == NAN) )
	    {
	      cNew = Complex(NAN,NAN);
	    }
	  else
	    {
	      cNew = c1/c2;
	    }
	  break;
	case '+':
	  cNew = c1+c2;
	  break;
	case '-':
	  cNew = c1-c2;
	  break;
	default:
	  cout << "= NaN" << endl;
	  cNew = Complex();
	  break;
	} //end switch

	} //end (count == 2) loop

      if (count == 1) // 1 entered operand
	{
	  cNew = Complex(A);
	}

      cNew.Print();
      cOld = cNew;    
      
    }
  return 0;  // Successful completion of main()
}


