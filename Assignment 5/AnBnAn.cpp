//  Alexander Muyshondt
//  AnBnAn.cpp
//  PR5_adm1
//  CS2308
//
//  Created by Alexander Muyshondt on 8/7/17.
//  Assignment due by 8/12/2017
//  Copyright © 2017 Alexander Muyshondt. All rights reserved.
//
//  ASSIGNMENT: Write a main program that uses the list based queue class (defined below) to check if an
//  input string is of the form 𝑎𝑛𝑏𝑛𝑎𝑛, meaning 𝑛 times the character ‘a’ followed by 𝑛 times the charater
//  ‘b,’ followed by 𝑛 times the character ‘a’.
//  ********************REQUIREMENTS********************
//  1) Must use a .h file for class definitions and two .cpp file for the C++ implementation.
//  2) You have to generate the list from scratch and check for overflow
//  3) Extra points, for example,extensive testing, checking for exceptions, and usable user interface.
//  4) Submit enough screenshots showing compiling and execution under Linux.

#include <iostream>
#include <string>
#include <cstdlib>
#include "LLQ.h"

using namespace std;

int main()
{
    LLQ list;   // Create LLQ object called list
    int countA = 0;
    int countB =0;
    int j = 0;
    
    do
    {
        list.inputString();
        cout << "Verifying string: " << list.getString() << endl << endl;
    }while(!list.verifyString());
    
    cout << "String meets the required criteria. You have entered a valid test string.\n";
    cout << "Program will now determine if the string is of the form a^nb^na^n.\n";
    
    // Place string in local variable
    string cstr = list.getString();
    
    // cstr now contains a c-string copy of input
    char *input = new char[cstr.length()+1];
    strcpy(input, cstr.c_str());
    
    //static cast prevents loss of integer precision due to implicit conversion
    int size = (static_cast<int>(cstr.length()) + 1);
    
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] == 'a')
        {
            // Condition checks if character 'a' is encountered after a 'b' character with
            // a counter variable
            if(i > countA)
            {
                j = i;
                break;
            }
            else
            {
                if(list.is_full())
                {
                    cout << "Not enough memory.\n";
                    exit(0);
                }
                list.insert('b');
                // Increment 'a' counter
                countA++;
            }
        }
        else if(input[i] == 'b')
        {
            countB++;
            if(list.is_empty())
                break;
            if(countB > countA)
            {
                cout << "\nString is not of the form a^nb^na^n.\n\n";
                if(list.goOn())
                {
                    main();
                }
                else
                {
                    cout << "***************************************************************\n";
                    cout << "*                                                             *\n";
                    cout << "*                      PROGRAM TERMINATED                     *\n";
                    cout << "*                                                             *\n";
                    cout << "***************************************************************\n";
                    exit(0);
                }
            }
            list.remove('b');
            if(list.is_full())
            {
                cout << "Not enough memory.\n";
                exit(0);
            }
            list.insert('a');
        }
    }
    
    if(j > 0)
    {
        for(; j < size; j++)
        {
            if(input[j] == 'a')
            {
                if(list.is_empty() && input[j] != '\0')
                {
                    cout << "\nString is not of the form a^nb^na^n.\n\n";
                    if(list.goOn())
                    {
                        main();
                    }
                    else
                    {
                        cout << "***************************************************************\n";
                        cout << "*                                                             *\n";
                        cout << "*                      PROGRAM TERMINATED                     *\n";
                        cout << "*                                                             *\n";
                        cout << "***************************************************************\n";
                        exit(0);
                    }
                }
                list.remove('a');
            }
            else if(input[j] == 'b')
            {
                cout << "\nString is not of the form a^nb^na^n.\n\n";
                if(list.goOn())
                {
                    main();
                }
                else
                {
                    cout << "***************************************************************\n";
                    cout << "*                                                             *\n";
                    cout << "*                      PROGRAM TERMINATED                     *\n";
                    cout << "*                                                             *\n";
                    cout << "***************************************************************\n";
                    exit(0);
                }
            }
        }
    }
    
    // The string is valid if upon reaching the NULL character the queue is empty
    // and no overflow or underflow has accrued.
    if(list.is_empty())
    {
        cout << "\nString is of the form a^nb^na^n.\n\n";
        exit(0);
    }
    else
    {
        cout << "\nString is not of the form a^nb^na^n.\n\n";
        if(list.goOn())
        {
            main();
        }
        else
        {
            cout << "***************************************************************\n";
            cout << "*                                                             *\n";
            cout << "*                      PROGRAM TERMINATED                     *\n";
            cout << "*                                                             *\n";
            cout << "***************************************************************\n";
            exit(0);
        }
    }
    
    return 0;
}

