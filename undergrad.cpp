#include "undergrad.h"

Undergrad::Undergrad() : User(), marks(0.0) {}

void Undergrad::personal_detail_prompt()
{
    string first_name, last_name;
    double ATAR_score;
    bool is_valid_ATAR = true;
	
    std::cout << "Enter Your First Name: ";
    cin >> first_name;
    this->setfirstname(first_name);
    std::cout << "Enter Your Last Name: ";
    cin >> last_name;
    this->setlastname(last_name);
    while(is_valid_ATAR)
    {
        cout << "Enter Your The Valid ATAR Score: ";
        cin >> ATAR_score;
        this->marks = ATAR_score;
        if (ATAR_score<0 || ATAR_score>100) {continue;}
        else {is_valid_ATAR = false;}
    }
}

bool Undergrad::sufficient_marks()
{
    bool is_sufficient = true;
    if (marks < marks_undergrad_vector[facultynum-1])
    {
        cout << "\nYou Do Not Have Sufficient Marks To Enrol In This Degee Program" << endl;
        cout << "Thank You For Using The Registration Form." << endl;
        is_sufficient = false;
    }
    else
    {
        cout << "You Are Eligible To Enrol In This Degree Degree. Please Wait For The University Offer" << endl;
    }
    return is_sufficient;
}
