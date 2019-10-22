#ifndef UNDERGRAD_H
#define UNDERGRAD_H
#include "user.h"

class Undergrad : public User {
    //the user class public attributes are inherited
    private:

    protected:
        //these vectors are declared and can only be accessed by this class and those that inherit it
        vector<string> science_undergrad;
        vector<string> arts_undergrad;
        vector<string> law_undergrad;
        vector<string> professions_undergrad;
        vector<string> medical_undergrad;
        vector<vector<string>> degrees_undergrad;
        vector<double> marks_undergrad;

    public:
        //contains the default contructor
        Undergrad();
        //contains the function that asks for information
        void personal_detail_prompt() override;
        //asks which degree is to be selected
        void degree_prompt() override;
        //returns true if marks are above threshold
        bool sufficient_marks() override;

};

#endif
