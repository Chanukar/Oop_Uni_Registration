#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
using namespace std;

class User{
    private:

    protected:

        string firstname;
        string lastname;
        double marks;    
        vector<string> faculties_vector;
        string facultychoise;
        string degreechoise;
        int facultynum;
        int degreenum;

    public:
        User();
        virtual void personal_detail_prompt() = 0;
        void facultyprompt();
        virtual void degree_prompt() = 0;
        virtual bool sufficient_marks() = 0;
        string getfirstname();
        string getlastname();
        string getfaculty();
        string getdegree();
        double getmarks();
};

#endif