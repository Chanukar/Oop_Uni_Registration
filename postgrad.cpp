#include "postgrad.h"

Postgrad::Postgrad() : Undergrad() {}

void Postgrad::personal_detail_prompt()
{
    string first_name, last_name;
    double GPA_score;
    bool is_valid_GPA = true;

    std::cout << "Enter Your First Name: ";
    cin >> first_name;
    this->setfirstname(first_name);
    std::cout << "Enter Your Last Name: ";
    cin >> last_name;
    this->setlastname(last_name);
    while(is_valid_GPA)
    {
        cout << "Enter Your Valid Undergraduate GPA Score: ";
        cin >> GPA_score;
        this->marks = GPA_score;
        if (GPA_score<0 || GPA_score>7) {continue;}
        else {is_valid_GPA = false;}
    }
}

bool Postgrad::sufficient_marks()
{
    bool is_sufficient = true;
    if (marks < marks_postgrad_vector[facultynum-1])
    {
        cout << "\nYou Do Not Have Sufficient Marks To Enrol In This Degee Program." << endl;
        cout << "Thank You For Using The Registration Form." << endl;
        is_sufficient = false;
    }
    else
    {
        cout << "You Are Eligible To Enrol In This Degree. Please Wait For The University Offer." << endl;
    }
    return is_sufficient;
}
