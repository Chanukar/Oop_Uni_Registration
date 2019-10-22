#ifndef UNDERGRAD_H
#define UNDERGRAD_H
#include "user.h"       

class Undergrad : public User {
    private:

    protected:      //Marks can only be accessed by this class and those that inherit it
        double marks;

    public:    
        Undergrad();                     //contains the default contructor
        void personal_detail_prompt();   //contains the function that asks for information
        bool sufficient_marks();         //returns true if marks are above threshold
        double getmarks();               //returns the marks
};

#endif
