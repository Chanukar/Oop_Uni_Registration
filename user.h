#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
using namespace std;
//included libraries for our code
class User{
    private:

    protected:
        //attributes which can be inherited by a class
        string firstname;
        string lastname;
        double marks;    
        vector<string> faculties_vector;
        string facultychoise;
        string degreechoise;
        int facultynum;
        int degreenum;

    public:
        //attributes which can be accessed from any class
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
