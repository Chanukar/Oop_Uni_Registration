#ifndef POSTGRAD_H
#define POSTGRAD_H
#include "undergrad.h"
//includes the parent class

class Postgrad : public User {
    //the class inherits the undergrad class
    private:

    protected:
        //protected attributes are inherited by child classes
        //vectors which are to contain the degrees and marks are declared
        vector<string> science_postgrad;
        vector<string> arts_postgrad;
        vector<string> law_postgrad;
        vector<string> professions_postgrad;
        vector<string> medical_postgrad;
        vector<vector<string>> degrees_postgrad;
        vector<double> marks_postgrad;

    public:
        //default contructor and functions declared
        Postgrad();
        void personal_detail_prompt() override;
        void degree_prompt() override;
        bool sufficient_marks() override;

};

#endif
