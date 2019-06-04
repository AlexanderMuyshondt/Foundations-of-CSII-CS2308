//  Header.h
//  PR4_adm1
//  Alexander Muyshondt
//  CS2308
//
//  Created by Alexander Muyshondt on 8/2/17.
//  Copyright © 2017 Alexander Muyshondt. All rights reserved.

// Specification file for the Header class
#ifndef Header_h
#define Header_h

class List
{
    
    public:
    //Declare Struct for list
    struct node
    {
        char letter;        // The data in this node
        node *next;         //pointer to point to the next node
    };
    
    typedef struct node *ptrNode;
    ptrNode ptrHead;
    ptrNode nodePtr;
    ptrNode ptrTemp;

    // Constructor
    List()
    {
        ptrHead = nullptr;
        nodePtr = nullptr;
        ptrTemp = nullptr;
    }
    
    
    //Linked List Operations
    bool isPalindrome();
    void AppendNode(char app);
    void DeleteNode(char del);
    void DisplayList();
    
};

#endif /* Header_h */

