//  LLQ.h
//  PR5_adm1_test
//  CS2308
//
//  Created by Alexander Muyshondt on 8/8/17.
//  Copyright © 2017 Alexander Muyshondt. All rights reserved.

//P.738

// Specification file for the LLQ class.
#ifndef LLQ_h
#define LLQ_h
#include <string>
#include <iostream>

using namespace std;

class LLQ
{
    private:
    string input;           // Variable
    
    struct QueueNode        // Structure for the queue nodes
    {
        
    char letter;            // Value in a node
    QueueNode *next;        // Pointer to the next node
        
    };
    
    QueueNode *front;       // The front of the queue
    QueueNode *rear;        // The rear of the queue
    int numItems;           // Number of items in the queue
    
    public:
    LLQ();                  // Constructor
    
    ~LLQ();                 // Destructor
    
    // STRING OPERATIONS
    void inputString()      // At least one inline setter for private members.
    {
        cout << "Use the following criteria to enter a test string:\n";
        cout << "1) String must begin with the 'a' character.\n";
        cout << "2) The following characters may consist of only 'a' and 'b'.\n";
        cout << "Enter your string: ";
        getline(cin, input);
    }
    
    string getString() const // At least one inline getter for private members.
    {
        return input;
    }
    
    bool verifyString() const;
    
    // QUEUE OPERATIONS
    void insert(char);
    void remove(char);
    bool is_full() const;
    bool is_empty() const;
    void displayQueue() const;
    bool goOn();
    void clear();
    
};


#endif /* LLQ_h */
