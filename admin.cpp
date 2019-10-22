#include <iostream>
#include <vector>
#include "undergrad.h"
#include "Postgrad.h"
using namespace std;

extern int prompt(vector<string>&);

void admin(int (*promptptr)(vector<string>&), vector<Undergrad>*&undergrad_register, vector<Postgrad>*&postgrad_register)
{
    string username;
    string password;
    bool is_authenticated = false;

    cout << "Admin Login" << endl;
        while(!is_authenticated)
        {
            cout << "\nEnter UserName: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
            if(username == "admin" && password == "admin") {is_authenticated = true; }
            else {continue; }
        }
    cout << "\nLogin Successful!" << endl;

    vector<string>admin_menu = {"Undergraduates Details", "Postgraduate Details", "Sort Undergraduates", "Sort Postgraduates"};
    int admin_menu_input;
    admin_menu_input = promptptr(admin_menu);
            if(admin_menu_input == 1)
            {
                for (int i=0; i<undergrad_register->size(); i++)
                {
                    cout << undergrad_register->at(i).getfirstname() << "\t" << undergrad_register->at(i).getlastname() << "\t" << undergrad_register->at(i).getmarks() << "\t" << undergrad_register->at(i).getfaculty() << "\t" << undergrad_register->at(i).getdegree() << endl;
                }
            }
            else if(admin_menu_input == 2)
            {
                for (int i=0; i<postgrad_register->size(); i++)
                {
                    cout << postgrad_register->at(i).getfirstname() << "\t" << postgrad_register->at(i).getlastname() << "\t" << postgrad_register->at(i).getmarks() << "\t" << postgrad_register->at(i).getfaculty() << "\t" << postgrad_register->at(i).getdegree() << endl;
                }
            }
            else if(admin_menu_input == 3)
            {

            }
}