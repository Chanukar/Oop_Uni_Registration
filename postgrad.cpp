#include "postgrad.h"
#include <stdlib.h>
#include <unistd.h>

Postgrad::Postgrad() :
    //default contructor to create the object
    User(),
    //default constructor with degrees as well as the grades required for the degrees are hardcoded
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
    int GPA_score;
    string tempscore;
    std::string::size_type sz;
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
        cin >> tempscore;
        system("clear");
        for(int j=0; j<tempscore.size(); j++)
        {
            if( !(tempscore[j] >= '0' && tempscore[j] <= '9')){
                tempscore = "0";
                break;
            }
        }
        GPA_score = stoi(tempscore, &sz);
        marks = GPA_score;
        if (GPA_score<=0 || GPA_score>7) {continue;}
        else {is_valid_GPA = false;}
    }
}

void Postgrad::degree_prompt()
{
    //function which asks postgrad degree is to be enrolled in and loops till a correct option is chosen
    string input;
    int i;
    bool is_input = true;
    int inputnum;
    std::string::size_type sz;
	while (is_input)
    {
        for (i=0; i<degrees_postgrad[facultynum-1].size(); i++)
        {
            if (i == 0) {cout << "\n"; }
            std::cout << i+1 << "." << degrees_postgrad[facultynum-1][i] << endl;
        }
        std::cout << "\nSelect The Degree Program That You Want To Enrol In: ";
        cin >> input;
        for(int j=0; j<(input.length()-1); j++)
        {
            if(input.substr(j,j+1) != "1" || input.substr(j,j+1) != "2" || input.substr(j,j+1) != "3" || input.substr(j,j+1) != "4" || input.substr(j,j+1) != "5" || input.substr(j,j+1) != "6" || input.substr(j,j+1) != "7" || input.substr(j,j+1) != "8" ||  input.substr(j,j+1) != "9")
            {
                input = "0";
            }
        }
        inputnum = stoi(input, &sz);
        if (inputnum < 1 || inputnum > i)
        {
            continue;
        }
        else
        {
            is_input = false;
        }
    }
    degreechoise = degrees_postgrad[facultynum-1][inputnum-1];

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
