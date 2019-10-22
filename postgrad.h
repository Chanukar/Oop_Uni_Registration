#ifndef POSTGRAD_H
#define POSTGRAD_H
#include "undergrad.h"

class Postgrad : public User {
    private:

    protected:
        vector<string> science_postgrad;
        vector<string> arts_postgrad;
        vector<string> law_postgrad;
        vector<string> professions_postgrad;
        vector<string> medical_postgrad;
        vector<vector<string>> degrees_postgrad;
        vector<double> marks_postgrad;

    public:
        Postgrad();
        void personal_detail_prompt() override;
        void degree_prompt() override;
        bool sufficient_marks() override;

};

#endif