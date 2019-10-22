#include <iostream>
#include <vector>
#include "user.h"
using namespace std;

bool Register_user(User& student)
{
    bool sufficient_marks = true;
    
    student.personal_detail_prompt();
    student.facultyprompt();
    student.degree_prompt();
    sufficient_marks = student.sufficient_marks();

    if(!sufficient_marks)
    {
        sufficient_marks = false;
        return sufficient_marks;
    }
    return sufficient_marks;
}