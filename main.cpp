#include <iostream>
#include <vector>
#include "postgrad.h"
#include "undergrad.h"
#include <stdlib.h>
#include <unistd.h>
using namespace std;
//all libraries required are included along with the right .h files
extern int prompt(vector<string>&);
extern bool Register_user(User&);
extern void admin(int (*promptptr)(vector<string>&), vector<Undergrad>*&, vector<Postgrad>*&);
//functions from other classes are called
int main()
{
    //vectors for storing student details and choices are created and vector with the hardcoded choices is declared
    int input_number;
    bool is_registration_active = true;
    vector<string>menu_options = {"Undergraduate Registration", "Postgraduate Registration", "Admin", "Quit"};
    vector<Undergrad> *undergrad_register = new vector<Undergrad>;
    vector<Postgrad> *postgrad_register = new vector<Postgrad>;
    while(is_registration_active)
    {
        //the appropriate functions for each available input choice are called
        std::cout << "\nWelcome to The University Registration and Login System" << endl;
        input_number = prompt(menu_options);

        if (input_number == 1)
        {
            undergrad_register->push_back(Undergrad());
            if(!Register_user(undergrad_register->back()))
            {
                //all the student details and choices are stored in the vector at first and then removed later if required
                undergrad_register->pop_back();
                //the students which do not have sufficient marks are removed from the vector with the popback function
                system("clear");
            }

        }
        else if(input_number ==2)
        {
            postgrad_register->push_back(Postgrad());
            if(!Register_user(postgrad_register->back()))
            {
                //all the student details and choices are stored in the vector at first and then removed later if required
                postgrad_register->pop_back();
                //the students which do not have sufficient marks are removed from the vector with the popback function
                system("clear");
            }

        }
        else if(input_number == 3)
        {
            admin(prompt, undergrad_register, postgrad_register);
            //admin is allowed to access the undergrad and postgrad vectors and their contents
        }
        else if(input_number == 4)
        {
            //the function is terminated
            std::cout << "The Program Has Been Successfully Terminated" << endl;
            is_registration_active = false;
        }
    }
    //the vectors are deleted
    delete undergrad_register;
    delete postgrad_register;
    return 0;
}

