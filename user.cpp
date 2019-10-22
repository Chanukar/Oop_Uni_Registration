#include "user.h"

User::User() :
    firstname("None"),
    lastname("None"),
    marks(0.0),
    faculties_vector({"Faculty of Science", "Faculty of Arts", "Law School", "Faculty of the Professions", "Medical School"}),
    facultychoise("None"), 
    degreechoise("None"),
    facultynum(0),
    degreenum(0)
    {}


void User::facultyprompt()
{
    int input;
    int i;
    bool is_input = true;

	while (is_input)
    {
        for (i=0; i<faculties_vector.size(); i++)
        {
            if (i == 0) {cout << "\n"; }
            std::cout << i+1 << "." << faculties_vector[i] << endl;
        }
        std::cout << "\nSelect The Faculty That You Want To Enrol In: ";
        cin >> input;
        if (input < 1 || input > i)
        {
            continue;
        }
        else
        {
            is_input = false;
        }
    }
    facultychoise = faculties_vector[input-1];
    facultynum = input;
}


string User::getfirstname()
{
    return firstname;
}


string User::getlastname()
{
    return lastname;
}

string User::getfaculty()
{
    return facultychoise;
}

string User::getdegree()
{
    return degreechoise;
}

double User::getmarks()
{
    return marks;
}
