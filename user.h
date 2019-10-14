#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
using namespace std;

class User{
    private:
        string firstname;
        string lastname;
    protected:
        vector<string> faculties_vector;
        vector<double> marks_undergrad_vector;
        vector<double> marks_postgrad_vector;
        vector<string> science_faculty_undergrads;
        vector<string> arts_faculty_undergrads;
        vector<string> law_school_undergrads;
        vector<string> professions_faculty_undergrads;
        vector<string> medical_school_undergrads;
        vector<string> science_faculty_postgrads;
        vector<string> arts_faculty_postgrads;
        vector<string> law_school_postgrads;
        vector<string> professions_faculty_postgrads;
        vector<string> medical_school_postgrads;
        vector<vector<string> > undergrad_degrees;
        vector<vector<string> > postgrad_degrees;
        string facultychoise;
        string degreechoise;
        int facultynum;
        int degreenum;
    public:
        User();
        void facultyprompt();
        void undergradprompt();
        void postgradprompt();
        void setfirstname(string& name);
        void setlastname(string& name);
};



/* class Staff{
    private:
        string username;
        string password;
    public:
        Staff();
        Staff();
};

class Admin{
    private:

    public:
        Admin();
        Admin();
};
 */
#endif
