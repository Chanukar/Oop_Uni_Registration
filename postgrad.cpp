#include "postgrad.h"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

Postgrad::Postgrad() : Undergrad()
{

}

void Postgrad::personal_detail_prompt()
{
    string first_name, last_name;
    string GPA_score;
    double GPA_score1;
    bool is_valid_GPA = true;

    std::cout << "Enter Your First Name: ";
    cin >> first_name;
    this->setfirstname(first_name);
    std::cout << "Enter Your Last Name: ";
    cin >> last_name;
    this->setlastname(last_name);
    while(is_valid_GPA)
    {
        std::string::size_type sz;
        cout << "Enter Your Valid Undergraduate GPA Score: ";
        cin >> GPA_score;
        if(regex_match(GPA_score, regex("[+-]?[0-9]+")))
        {
            GPA_score1 = stod(GPA_score, &sz);
            if (GPA_score1<0 || GPA_score1>7)
            {
                this->marks = GPA_score1;
                continue;
            }
            else
            {
                is_valid_GPA = false;
            }
        }
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
