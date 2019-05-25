//  LLQ.cpp
//  PR5_adm1_test
//  CS2308
//
//  Created by Alexander Muyshondt on 8/8/17.
//  Copyright © 2017 Alexander Muyshondt. All rights reserved.

//P.739

// Implementation file for the LLQ class.
#include "LLQ.h"        // Needed for the LLQ class
#include <iostream>     // Needed for cout
#include <cstdlib>      // Needed for the exit function
#include <string>

using namespace std;

/*************************** Constructor ***************************/
LLQ::LLQ()
{
    cout << "This program uses a list based queue class to check if an input string is of the form ";
    cout << "a^nb^na^n, meaning n times the character ‘a’ followed by n times the charater 'b’, ";
    cout << "followed by n times the character ‘a’.\n\n";
    
    // Initialize member variables
    input.clear();
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

/**************************** Destructor ****************************/
LLQ::~LLQ()
{
    clear();
}

/*************************** verifyString ***************************/
// Verifies the string input by the user follows the given criteria
 bool LLQ::verifyString() const
 {
    // cstr now contains a c-string copy of input
    char *cstr = new char [input.length()+1];
    strcpy(cstr, input.c_str());
 
    // If the string does not start with an ‘a’ then the string is invalid
    if(cstr[0] != 'a')
    {
        cout << "Invalid string. String must begin with the 'a' character. Please try again.\n\n";
        delete[] cstr;          // Free allocated memory
        return false;
    }
 
    // Scan the string from left to right until reaching the NULL terminator, '\0'.
    // If you reach any character that is different than ‘a’ or ‘b’ then the string is invalid.
    for(int i = 0; cstr[i] != '\0'; i++)
    {
        if(cstr[i] != 'a' && cstr[i] != 'b')
        {
            cout << "Invalid string. The following characters must consist of only 'a' and 'b'. ";
            cout << "Please try again.\n\n";
            delete[] cstr;      // Free allocated memory
            return false;
        }
    }
 
     delete[] cstr;             // Free allocated memory
     return true;
 }

/**************************** insert [enqueue] ****************************/
// insert function that gets a character value and inserts it at the “end” of the queue.
// For every occurrence of the character ‘a’ insert the character ‘b’ to the queue.
void LLQ::insert(char l)
{
     QueueNode *newNode = nullptr;
     
     // Create a new node and store char there. 
     newNode = new QueueNode;
     newNode->letter = l;
     newNode->next = nullptr;
    
     // Adjust front and rear as necessary. 
     if (is_empty())
     {
     front = newNode;
     rear = newNode; 
     }
     else
     {
        rear->next = newNode;
        rear = newNode;
     }

     // Update numItems.
     numItems++;
}

/**************************** remove [dequeue] ****************************/
// remove function that gets the value of the “first” queue element and stores it in a
// character variable.
// Once the first ‘b’ character in the string is reached: for each ‘b’ in the string remove a
// ‘b’ from the queue and insert an ‘a’ to the queue. Once the first ‘a’ character  is reached
// in the string, remove an ‘a’ character from the queue for every ‘a’ character encountered.
// If procedure cannot be followed the string is considered invalid.
void LLQ::remove(char l)
{
    QueueNode *del = nullptr;
    QueueNode *temp = front;
    QueueNode *curr = front;
     
     while(curr!= nullptr && curr->letter !=l)
     {
         temp = curr;
         curr = curr->next;
     }
     if(curr == nullptr)
     {
         delete del;
     }
     else
     {
         del = curr;
         curr = curr->next;
         temp->next = curr;
         if(del == front)
         {
             front = front->next;
             temp = nullptr;
         }
    delete del;
     }

     // Update numItems.
    numItems--;
}

/****************************** is_full ******************************/
// Boolean function that returns true if the queue is “full” (otherwise it returns
// false). This function should be called before inserting items to the queue.
bool LLQ::is_full() const
{
    bool status;
    
    if (numItems < 0)
        status = true;
    else
        status = false;
    
    return status;
}

/****************************** is_empty ******************************/
// Boolean function that returns true if the queue is “empty” (otherwise it
// returns false). This function should be called before removing items from the queue
bool LLQ::is_empty() const
{
    bool status;

    if (numItems > 0)
        status = false;
    else
        status = true;
    
    return status;
}

/****************************** displayQueue ******************************/
void LLQ::displayQueue() const
{
    QueueNode *temp = nullptr;
    temp = front;
    
    if(is_empty())
    {
        cout << "The queue is empty.\n";
    }
    else
    {
        cout << "Queue contains: ";
        while(temp != nullptr)
        {
            cout << temp->letter << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

/****************************** clear ******************************/
void LLQ::clear()
{
    char l = '\0';      // Dummy variable for dequeue
    
    while(!is_empty())
    {
        remove(l);
    }
}

/****************************** goOn ******************************/
bool LLQ::goOn()
{
    char choice;
    bool status;
    
    do
    {
        cout << "Would you like to try again?";
        cout << "Enter Y or N: ";
        cin  >> choice;
        if(choice == 'Y' || choice == 'y')
        {
            cout << "Restarting...\n";
            return status = true;
        }
        else
        {
            if(choice == 'N' || choice == 'n')
                cout << "\n";
            else
                cout << "\nInvalid choice. Please select an option from the menu below.\n";
        }
    }while(choice != 'N' && choice != 'n');
    
    return status = false;
}
