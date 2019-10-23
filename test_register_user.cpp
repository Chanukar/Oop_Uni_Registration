#include <iostream>
#include <vector>
#include "postgrad.h"
#include "undergrad.h"
using namespace std;

extern bool Register_user(User&);

int main()
{
    vector<Undergrad> *undergrad_register = new vector<Undergrad>;
    vector<Postgrad> *postgrad_register = new vector<Postgrad>;
    cout << "1.UG" <<endl;
    cout << "2.PG" <<endl;
    int input;
    cin >> input;
    if(input == 1)
    {
        undergrad_register->push_back(Undergrad());
            if(!Register_user(undergrad_register->back()))
            {
                undergrad_register->pop_back();
            }
    }
    else if(input ==2)
    {
        postgrad_register->push_back(Postgrad());
            if(!Register_user(postgrad_register->back()))
            {
                postgrad_register->pop_back();
            }
    }
    else
    {
        cout << "Invalid input"<< endl;
    }
}