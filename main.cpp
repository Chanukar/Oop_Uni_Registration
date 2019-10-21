#include <iostream>
#include <vector>
#include "postgrad.h"
#include "undergrad.h"
using namespace std;

extern int prompt(vector<string>&);
extern bool Register_user(User&);
extern void admin(int (*promptptr)(vector<string>&), vector<Undergrad>*&, vector<Postgrad>*&);

int main()
{
    int input_number;
    bool is_registration_active = true;
    vector<string>menu_options = {"Undergraduate Registration", "Postgraduate Registration", "Admin", "Quit"};
    vector<Undergrad> *undergrad_register = new vector<Undergrad>;
    vector<Postgrad> *postgrad_register = new vector<Postgrad>;
    
    while(is_registration_active)
    {
        std::cout << "\nWelcome to The University Registration and Login System" << endl;
        input_number = prompt(menu_options);

        if (input_number == 1)
        {
            undergrad_register->push_back(Undergrad());
            if(!Register_user(undergrad_register->back()))
            {
                undergrad_register->pop_back();
            }

        }
        else if(input_number ==2)
        {
            postgrad_register->push_back(Postgrad());
            if(!Register_user(postgrad_register->back()))
            {
                postgrad_register->pop_back();
            }

        }
        else if(input_number == 3)
        {
            admin(prompt, undergrad_register, postgrad_register);
        }
        else if(input_number == 4)
        {
            
            std::cout << "The Program Has Been Successfully Terminated" << endl;
            is_registration_active = false;
        }
    }
    delete undergrad_register;
    delete postgrad_register;
    return 0; 
}

