//
//  Extra.cpp
//  PR6_adm1
//
//  Created by Alexander Muyshondt on 8/11/17.
//  Copyright © 2017 Alexander Muyshondt. All rights reserved.

#include "Extra.h"

// Default constructor
ExtraCredit::ExtraCredit() = default;

// Default destructor
ExtraCredit::~ExtraCredit() = default;

// Setter function for i
void ExtraCredit::seti(int i)
{
    this->i=i;
}

// Setter function for j
void ExtraCredit::setj(int j)
{
    this->j=j;
}

// Getter function for i
int ExtraCredit::geti()
{
    return i;
}

// Getter function for j
int ExtraCredit::getj()
{
    return j;
}

// 𝑠(𝑖) – returns the successor of 𝑖
int ExtraCredit::s(int i)
{
    return ++i;  // implemented as ++𝑖
}

// 𝑝(𝑖) – returns the predecessor of 𝑖.
int ExtraCredit::p(int i)
{
    return --i;  // implemented as --𝑖
}

// This recursive function returns 𝑖 + 𝑗
int ExtraCredit::padd(int i,int j)
{
    if(j == 0)
    {
        return i;
    }
    else if(j > 0)
    {
        return padd(s(i),p(j));
    }
    else
        return 0;
}

// This recursive function returns 𝑖 × 𝑗
int ExtraCredit::pmul(int i,int j)
{
    if(j == 1)
    {
        return i;
    }
    else if(j > 1)
    {
        return padd(i, pmul(i, p(j)));
    }
    else
        return 0;
}

// This recursive function returns 𝑖^𝑗
int ExtraCredit::ppwr(int i,int j)
{
    if(j==1)
    {
        return i;
    }
    else if (j>1)
    {
        return pmul(i, ppwr(i, p(j)));
    }
    else
        return 0;
}


