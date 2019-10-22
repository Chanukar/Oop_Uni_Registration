#ifndef POSTGRAD_H
#define POSTGRAD_H
#include "undergrad.h"      //includes the parent class

class Postgrad : public Undergrad {     //the class inherits the undergrad class
    private:

    public:
        Postgrad();     //default contructor
        void personal_detail_prompt();      //function to ask for personal details
        bool sufficient_marks();        //returns true if marks are sufficient
};

#endif
