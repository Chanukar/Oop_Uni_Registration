#include "user.h"

User::User() :
    //faculties are hardcoded in a vector in this default constructor
    firstname("None"),
    lastname("None"),
    marks(0.0),
    faculties_vector({"Faculty of Science", "Faculty of Arts", "Law School", "Faculty of the Professions", "Medical School"}),
    facultychoise("None"),
    degreechoise("None"),
    facultynum(0),
    degreenum(0)
    {}


void User::facultyprompt()
{
    //function with a loop and bool which asks which faculty is to be chosen
    string input;
    int inputnum;
    std::string::size_type sz;
    int i;
    bool is_input = true;

	while (is_input)
    {
        for (i=0; i<faculties_vector.size(); i++)
        {
            if (i == 0) {cout << "\n"; }
            std::cout << i+1 << "." << faculties_vector[i] << endl;
        }
        std::cout << "\nSelect The Faculty That You Want To Enrol In: ";
        cin >> input;
        system("clear");
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
    facultychoise = faculties_vector[inputnum-1];
    facultynum = inputnum;
}

//functions below either change the values of the variables or return them
string User::getfirstname()
{
    return firstname;
}


string User::getlastname()
{
    return lastname;
}

string User::getfaculty()
{
    return facultychoise;
}

string User::getdegree()
{
    return degreechoise;
}

double User::getmarks()
{
    return marks;
}
