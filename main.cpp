#include <iostream>
#include <vector>
#include "postgrad.h"
using namespace std;

int prompt(string[], int&);

int main()
{
    vector<Undergrad> *undergrad_register = new vector<Undergrad>;
    vector<Postgrad> *postgrad_register = new vector<Postgrad>;
    string option[3] = {"Undergraduate Registration", "Postgraduate Registration", "Quit"};
    int option_size = 3;
    bool sufficient_marks = true;
    bool is_registration_active = true;
    int input_number;

    while(is_registration_active)
    {
        std::cout << "\nWelcome to The University Registration and Login System" << endl;
        input_number = prompt(option, option_size);

        if (input_number == 1)
        {
            undergrad_register->push_back(Undergrad());
            system("clear");
            undergrad_register->back().personal_detail_prompt();
            system("clear");
            undergrad_register->back().facultyprompt();
            system("clear");
            undergrad_register->back().undergradprompt();
            system("clear");
            sufficient_marks = undergrad_register->back().sufficient_marks();
            system("clear");
            if(!sufficient_marks)
            {
                undergrad_register->pop_back();
            }

        }
        else if(input_number ==2)
        {
            postgrad_register->push_back(Postgrad());
            system("clear");
            postgrad_register->back().personal_detail_prompt();
            system("clear");
            postgrad_register->back().facultyprompt();
            system("clear");
            postgrad_register->back().undergradprompt();
            system("clear");
            sufficient_marks = postgrad_register->back().sufficient_marks();
            system("clear");
            if(!sufficient_marks)
            {
                postgrad_register->pop_back();
            }

        }
        else if(input_number == 3)
        {
            std::cout << "The Program Has Been Successfully Terminated" << endl;
            is_registration_active = false;
            delete undergrad_register;
            delete postgrad_register;
        }
    }
    return 0;
}

int prompt(string array[], int& size)
{
    int input;
    int i;
    bool is_input = true;

	while (is_input)
    {
        for (i=0; i<size; i++)
        {
            if (i == 0) {cout << "\n"; }
            std::cout << i+1 << "." << array[i] << endl;
        }
        std::cout << "\nSelect One of The Following Option: ";
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
    return input;
}