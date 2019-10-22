#include "postgrad.h"

Postgrad::Postgrad() :
    //default contructor to create the object
    User(),
    //default constructor with faculties as well as the grades required for the degrees are hardcoded
    science_postgrad({"Master of Engineering", "Master of Computer Science", "Master of Science", "Master of Architecture"}),
    arts_postgrad({"Master of Sociology", "Master of music", "Master of Media", "Master of Arts"}),
    law_postgrad({"Master of Law", "Master of Criminology", "Master of International Relations", "Master of Litigation"}),
    professions_postgrad({"Master of Finance", "Master of Economics", "Master of Accounting", "Master of Business"}),
    medical_postgrad({"Master of Health", "Master of Medicine", "Master of Vetenary", "Master of Oral Health"}),
    degrees_postgrad({science_postgrad, arts_postgrad, law_postgrad, professions_postgrad, medical_postgrad}),
    marks_postgrad({6.0, 4.4, 5.5, 5.0, 6.5})
    {}

void Postgrad::personal_detail_prompt()
{
    //function to input details if they have the correct type
    string first_name, last_name;
    double GPA_score;
    bool is_valid_GPA = true;
    //firstname and lastname have to be entered
    std::cout << "Enter Your First Name: ";
    cin >> first_name;
    firstname = first_name;
    std::cout << "Enter Your Last Name: ";
    cin >> last_name;
    lastname = last_name;
    while(is_valid_GPA)
    {
	//gpa has to be of the correct type before accepted otherwise it loops
        cout << "Enter Your Valid Undergraduate GPA Score: ";
        cin >> GPA_score;
        marks = GPA_score;
        if (GPA_score<0 || GPA_score>7) {continue;}
        else {is_valid_GPA = false;}
    }
}

void Postgrad::degree_prompt()
{
    //function which asks postgrad degree is to be enrolled in and loops till a correct option is chosen
    int input;
    int i;
    bool is_input = true;

	while (is_input)
    {
        for (i=0; i<degrees_postgrad[facultynum-1].size(); i++)
        {
            if (i == 0) {cout << "\n"; }
            std::cout << i+1 << "." << degrees_postgrad[facultynum-1][i] << endl;
        }
        std::cout << "\nSelect The Degree Program That You Want To Enrol In: ";
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
    degreechoise = degrees_postgrad[facultynum-1][input-1];

}

bool Postgrad::sufficient_marks()
{
    //enrollment is only allowed if gpa is above a certain threshold
    bool is_sufficient = true;
    if (marks < this->marks_postgrad[facultynum-1])
    {
        cout << "\nYou Do Not Have Sufficient Marks To Enrol In This Degee Program" << endl;
        cout << "Thank You For Using The Registration Form." << endl;
        is_sufficient = false;
    }
    else
    {
        cout << "You Are Eligible To Enrol In This Degree. Please Wait For The University Offer" << endl;
    }
    return is_sufficient;
}
