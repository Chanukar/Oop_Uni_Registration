#ifndef POSTGRAD_H
#define POSTGRAD_H
#include "undergrad.h"

class Postgrad : public Undergrad {
    private:

    public:
        Postgrad();
        void personal_detail_prompt();
        bool sufficient_marks();
};

#endif
