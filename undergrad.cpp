#include "undergrad.h"

Undergrad::Undergrad() :
    User(),
    science_undergrad({"Bachelor of Engineering", "Bachelor of Computer Science", "Bachelor of Science", "Bachelor of Architecture"}),
    arts_undergrad({"Bachelor of Sociology", "Bachelor of music", "Bachelor of Media", "Bachelor of Arts"}),
    law_undergrad({"Bachelor of Law", "Bachelor of Criminology", "Bachelor of International Relations", "Bachelor of Litigation"}),
    professions_undergrad({"Bachelor of Finance", "Bachelor of Economics", "Bachelor of Accounting", "Bachelor of Business"}),
    medical_undergrad({"Bachelor of Health", "Bachelor of Medicine", "Bachelor of Vetenary", "Bachelor of Oral Health"}),
    degrees_undergrad({science_undergrad, arts_undergrad, law_undergrad, professions_undergrad, medical_undergrad}),
    marks_undergrad({94.0, 50.0, 85.0, 70.0, 96.0})
    {}


void Undergrad::personal_detail_prompt()
{
    //function that initializes variables and assigns the personal details that are input to them
    string first_name, last_name;
    string tempscore;
    int ATAR_score;
    std::string::size_type sz;
    bool is_valid_ATAR = true;
    std::cout << "Enter Your First Name: ";
    cin >> first_name;
    firstname = first_name;
    std::cout << "Enter Your Last Name: ";
    cin >> last_name;
    lastname = last_name;
    while(is_valid_ATAR)
    {
        cout << "Enter Your Valid ATAR Score: ";
        cin >> tempscore;
        for(int j=0; j<tempscore.size(); j++)
        {
            if( !(tempscore[j] >= '0' && tempscore[j] <= '9')){
                tempscore = "0";
                break;
            }
        }
        ATAR_score = stoi(tempscore, &sz);
        cout << "SCORE AFTer coNVERT is = "<< ATAR_score <<endl;
        marks = ATAR_score;
        if (ATAR_score<=0 || ATAR_score>=100) {continue;}
        else {is_valid_ATAR = false;}
    }
}

void Undergrad::degree_prompt()
{
    //function that asks which degree is to be chosen and rejects the inputs which don't match the options
    string input;
    int i;
    bool is_input = true;
    int inputnum;
    std::string::size_type sz;
	while (is_input)
    {
        for (i=0; i<degrees_undergrad[facultynum-1].size(); i++)
        {
            if (i == 0) {cout << "\n"; }
            std::cout << i+1 << "." << degrees_undergrad[facultynum-1][i] << endl;
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
    degreechoise = degrees_undergrad[facultynum-1][inputnum-1];

}

bool Undergrad::sufficient_marks()
{
    //function that rejects marks below threshold
    bool is_sufficient = true;
    if (marks < marks_undergrad[facultynum-1])
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
