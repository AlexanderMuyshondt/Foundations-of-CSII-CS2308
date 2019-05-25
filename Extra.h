//  Extra.h
//  PR6_adm1
//
//  Created by Alexander Muyshondt on 8/11/17.
//  Copyright © 2017 Alexander Muyshondt. All rights reserved.
//

#ifndef Extra_h
#define Extra_h
#pragma once

class ExtraCredit
{
// The class should have at least two private integer members (e.g., 𝑖𝑛𝑡 𝑖; 𝑖𝑛𝑡 𝑗;)
    private:
        int i;
        int j;
    public:
// At the minimum, the class should have a constructor and a destructor
        ExtraCredit();
        ~ExtraCredit();
// At the minimum, the class should include all the above operations ((1) to (5)) as public methods.
        int s(int);
        int p(int);
        int padd(int,int);
        int pmul(int,int);
        int ppwr(int,int);
// A getter and a setter for its two private members (listed above).
        void seti(int);
        void setj(int);
        int geti();
        int getj();
    
};

#endif /* Extra_h */
