#ifndef UNDERGRAD_H
#define UNDERGRAD_H
#include "user.h"

class Undergrad : public User {
    private:

    protected:
        vector<string> science_undergrad;
        vector<string> arts_undergrad;
        vector<string> law_undergrad;
        vector<string> professions_undergrad;
        vector<string> medical_undergrad;
        vector<vector<string>> degrees_undergrad;
        vector<double> marks_undergrad;

    public:
        Undergrad();
        void personal_detail_prompt() override;
        void degree_prompt() override;
        bool sufficient_marks() override;

};

#endif