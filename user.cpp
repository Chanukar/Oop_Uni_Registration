#include "user.h"

User::User():
    firstname("Default Initialised"),
    lastname("Default Initialised"),
    faculties_vector({"Faculty of Science", "Faculty of Arts", "Law School", "Faculty of the Professions", "Medical School"}),
    marks_undergrad_vector({94.0, 50.0, 85.0, 70.0, 96.0}),
    marks_postgrad_vector({6.0, 4.4, 5.5, 5.0, 6.5}),
    science_faculty_undergrads({"Bachelor of Engineering", "Bachelor of Computer Science", "Bachelor of Science", "Bachelor of Architecture"}),
    arts_faculty_undergrads({"Bachelor of Sociology", "Bachelor of music", "Bachelor of Media", "Bachelor of Arts"}),
    law_school_undergrads({"Bachelor of Law", "Bachelor of Criminology", "Bachelor of International Relations", "Bachelor of Litigation"}),
    professions_faculty_undergrads({"Bachelor of Finance", "Bachelor of Economics", "Bachelor of Accounting", "Bachelor of Business"}),
    medical_school_undergrads({"Bachelor of Health", "Bachelor of Medicine", "Bachelor of Vetenary", "Bachelor of Oral Health"}),
    science_faculty_postgrads({"Master of Engineering", "Master of Computer Science", "Master of Science", "Master of Architecture"}),
    arts_faculty_postgrads({"Master of Sociology", "Master of music", "Master of Media", "Master of Arts"}),
    law_school_postgrads({"Master of Law", "Master of Criminology", "Master of International Relations", "Master of Litigation"}),
    professions_faculty_postgrads({"Master of Finance", "Master of Economics", "Master of Accounting", "Master of Business"}),
    medical_school_postgrads({"Master of Health", "Master of Medicine", "Master of Vetenary", "Master of Oral Health"}),
    undergrad_degrees({science_faculty_undergrads, arts_faculty_undergrads, law_school_undergrads, professions_faculty_undergrads, medical_school_undergrads}),
    postgrad_degrees({science_faculty_postgrads, arts_faculty_postgrads, law_school_postgrads, professions_faculty_postgrads, medical_school_postgrads}),
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

void User::undergradprompt()
{
    int input;
    int i;
    bool is_input = true;

	while (is_input)
    {
        for (i=0; i<undergrad_degrees[facultynum-1].size(); i++)
        {
            if (i == 0) {cout << "\n"; }
            std::cout << i+1 << "." << undergrad_degrees[facultynum-1][i] << endl;
        }
        std::cout << "\nSelect The Undergraduate Degree That You Want To Enrol In: ";
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
    degreechoise = undergrad_degrees[facultynum-1][input-1];

}
void User::postgradprompt()
{
    int input;
    int i;
    bool is_input = true;

	while (is_input)
    {
        for (i=0; i<postgrad_degrees[facultynum-1].size(); i++)
        {
            if (i == 0) {cout << "\n"; }
            std::cout << i+1 << "." << postgrad_degrees[facultynum-1][i] << endl;
        }
        std::cout << "\nSelect The Postgraduate Degree That You Want To Enrol In: ";
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
    degreechoise = undergrad_degrees[facultynum-1][input-1];

}

void User::setfirstname(string& name)
{
    firstname = name;
}

void User::setlastname(string& name)
{
    lastname = name;
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
