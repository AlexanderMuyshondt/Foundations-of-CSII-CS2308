//
//  main.cpp
//  PR6_adm1
//
//  Created by Alexander Muyshondt on 8/11/17.
//  Copyright © 2017 Alexander Muyshondt. All rights reserved.
/*
 SUBMISSION REQUIREMENTS
 1. This is an extra credit assignment.
 2. The assignment counts for 5% extra credit on your class grade
 3. Please carefully follow the instructions of assignments P1-P5. In addition:
 a. You have to use a .h file for class definitions and at least one .cpp file for the C++ implementation.
 b. Please submit enough screenshots showing compiling and execution under Linux.
*/

#include <iostream>
#include "Extra.h"

using namespace std;

int main()
{
    // Test the class with a main function that sets an integer variable, 𝑚, to 2 and
    // an integer variable, 𝑛, to 3.
    int m = 2;
    int n = 3;
    
    ExtraCredit calcPeano;
    
    calcPeano.seti(m);
    calcPeano.setj(n);
    
    cout << "m = " << m << " and n = " << n << endl;
    
    // Next, the program calculates and outputs 𝑚𝑛 using the Peano-Arithmetic class via
    // the method that corresponds to 𝑝𝑝𝑤𝑟(𝑚, 𝑛).
    cout << "Next, the program calculates and outputs 𝑚 𝑛 using the Peano-Arithmetic class via ";
    cout << "the method that corresponds to 𝑝𝑝𝑤𝑟(𝑚, 𝑛).\n";
    cout<<"m^n = " << calcPeano.ppwr(m, n) << endl;
    
    return 0;
}


