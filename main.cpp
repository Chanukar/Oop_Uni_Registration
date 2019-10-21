#include <iostream>
#include <vector>
#include "postgrad.h"
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <regex>
using namespace std;

int prompt(string[], int&);
string check_crazy(string);

int main()
{
    vector<Undergrad> *undergrad_register = new vector<Undergrad>;		//vector in which we store the students
    vector<Postgrad> *postgrad_register = new vector<Postgrad>;
	int option_size = 4;
    string option[4] = {"Undergraduate Registration", "Postgraduate Registration", "Admin", "Quit"};
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
            usleep(3000000);
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
            postgrad_register->back().postgradprompt();
            system("clear");
            sufficient_marks = postgrad_register->back().sufficient_marks();
            usleep(3000000);
            system("clear");
            if(!sufficient_marks)
            {
                postgrad_register->pop_back();
            }

        }
	else if(input_number == 3)
        {
            string username;
            string password;
            bool is_authenticated = false;
            int admin_input;
            int admin_option_size = 2;
            string admin_options[2] = {"Undergraduates Details", "Postgraduate Details"};
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

            admin_input = prompt(admin_options, admin_option_size);
            if(admin_input == 1)
            {
                for (int i=0; i<undergrad_register->size(); i++)
                {
                    cout << undergrad_register->at(i).getfirstname() << "\t" << undergrad_register->at(i).getlastname() << "\t" << undergrad_register->at(i).getmarks() << "\t" << undergrad_register->at(i).getfaculty() << "\t" << undergrad_register->at(i).getdegree() << "\t" << endl;
                }
            }
            else if(admin_input == 2)
            {
                for (int i=0; i<postgrad_register->size(); i++)
                {
                    cout << postgrad_register->at(i).getfirstname() << "\t" << postgrad_register->at(i).getlastname() << "\t" << postgrad_register->at(i).getmarks() << "\t" << postgrad_register->at(i).getfaculty() << "\t" << postgrad_register->at(i).getdegree() << "\t" << endl;
                }
            }
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

int prompt(string array[], int& size)
{
    string input;
    int i;
    bool is_input = true;
    double input1;
	while (is_input)
    {
        std::string::size_type sz;
        for (i=0; i<size; i++)
        {
            if (i == 0) {cout << "\n"; }
            std::cout << i+1 << "." << array[i] << endl;
        }
        std::cout << "\nSelect One of The above Option: ";
        cin >> input;
        system("clear");
        input = check_crazy(input);
        input1 = stoi(input, &sz);
        if((input1 < 1 || input1 > i))
        {
            continue;
        }
        else
        {
            is_input = false;
        }
    }
    return input1;
}

string check_crazy(string a)
{
	string go;
	int length = a.length();
	if((length>0)&&(length <= 5))
	{
		if(regex_match(a, regex("[+-]?[0-9]+")))
		{
			go = a;
		}
		else
		{
			go = "0";
		}
	}
	else
	{
		go = "0";
	}

	return go;
}
