#ifndef UNDERGRAD_H
#define UNDERGRAD_H
#include "user.h"

class Undergrad : public User {
    private:

    protected:
        double marks;

    public:
        Undergrad();
        void personal_detail_prompt();
        bool sufficient_marks();
};

#endif
