// Alexander Muyshondt
// 8/4/2017
// PR4_adm1.cpp
// CS2308
// Created by Alexander Muyshondt on 8/1/17.
// Copyright © 2017 Alexander Muyshondt. All rights reserved.
//
// C++ program that manages and applies a linked list. Program:
// Assume that a set of characters in stored in a linked list –
// one character per list node. This list is referred to as a list of chars.

/**************************NOTES****************************
* CHAPTER                                                  *
* CHAPTER                                                  *
* CHAPTER                                                  *
* INCLUDE .TXT FILES WHEN TURNING IN TO TRACS              *
* INCLUDE .JPEG FILES WHEN TURNING IN TO TRACS             *
* To access .txt files from Finder                         *
* Library-->Developer-->XCode-->DerivedData-->PR4_adm1-->  *
* Build-->Products-->Debug                                 *
*                                                          *
***********************************************************/

//Have to use a .h file for class definitions and .cpp file for the C++ implementation.
#include "Header.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//fu
void List::AppendNode(char app)
{
    ptrNode linkedList = new node;
    linkedList->next = nullptr;
    linkedList->letter = app;
    
    //if statement to search for end of list and then append
    if (ptrHead != nullptr)
    {
        nodePtr = ptrHead;
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }
        
        nodePtr -> next = linkedList;
    }
    
    else
    {
        ptrHead = linkedList;
    }
}

void List::DeleteNode(char del)
{
    ptrNode toDelete = nullptr;
    ptrTemp = ptrHead;
    nodePtr = ptrHead;
    
    while(nodePtr != nullptr && nodePtr->letter != del)
    {
        ptrTemp = nodePtr;
        nodePtr = nodePtr->next;
    }
    
    if(nodePtr == nullptr)
    {
        cout << del << " is not in the list" << endl;
        delete toDelete;
    }
    
    else
    {
        toDelete = nodePtr;
        nodePtr = nodePtr->next;
        ptrTemp->next = nodePtr;
        
        if (toDelete == ptrHead)
        {
            ptrHead = ptrHead->next;
            ptrTemp = nullptr;
        }
        delete toDelete;
        cout << "The letter " << del << "was deleted" << endl;
    }
}

void List::DisplayList()
{
    nodePtr = ptrHead;
    while (nodePtr != nullptr)
    {
        cout << nodePtr->letter;
        nodePtr = nodePtr->next;
    }
}

//This Function will check
bool List::isPalindrome()
{
    ptrNode alpha;
    
    alpha = ptrHead;
    ptrTemp = ptrHead;
    nodePtr = ptrHead;
    
    // If the list is empty, the function returns true.
    // If the list is a singleton, the function returns true.
    if (ptrHead == nullptr)
    {
        return true;
    }
    
    //Next the function identifies the first and the last elements of the list.
    while (nodePtr->next != nullptr)
    {
        nodePtr = nodePtr->next;
    }
    
    while (alpha !=  nullptr &&  alpha->next != nullptr)
    {
        // If the two characters stored in the two ends differ from each other,
        // the function returns false.
        if (nodePtr->letter != alpha->letter)
        {
            return false;
        }
        // Otherwise the function removes the first and last elements from the
        // list and continues with the same procedure on the remaining list items.
        else
        {
            ptrTemp = alpha;
            while(ptrTemp->next != nodePtr && ptrTemp->next != nullptr)
                ptrTemp = ptrTemp->next;
            ptrTemp->next = nullptr;
            nodePtr = ptrTemp;
        }
        alpha = alpha->next;
    }
    return true;
}

int main ()
{
    List Test;
    string input;
    string fileName ="input.txt";
    fstream inputFile;
    inputFile.open(fileName.c_str(), fstream::in);
    getline(inputFile,input);
    
    for (long i = 0; i < input.size(); i++)
    {
        Test.AppendNode(input[i]);
    }
    
    Test.DisplayList();
    
    if(Test.isPalindrome())
        cout << "It is a palindrome.\n";
    else
        cout << "It is not a palindrome.\n";
    
    return 0;
}
