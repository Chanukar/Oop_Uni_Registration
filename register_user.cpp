#include <iostream>
#include <vector>
#include "user.h"
using namespace std;

bool Register_user(User& student)
{
    //function which asks for personal details and choices by calling functions
    bool sufficient_marks = true;
    
    student.personal_detail_prompt();
    student.facultyprompt();
    student.degree_prompt();
    sufficient_marks = student.sufficient_marks();
    //checks if marks are sufficient by comparing to the sufficient marks and returns false if not
    if(!sufficient_marks)
    {
        sufficient_marks = false;
        return sufficient_marks;
    }
    return sufficient_marks;
}
