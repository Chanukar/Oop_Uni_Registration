#include <iostream>
#include <vector>
using namespace std;

int prompt(vector<string>& vec)
{
    int input;
    int i;
    bool is_input = true;

	while (is_input)
    {
        for (i=0; i<vec.size(); i++)
        {
            if (i == 0) {cout << "\n"; }
            std::cout << i+1 << "." << vec[i] << endl;
        }
        std::cout << "\nSelect One of The Following Option: ";
        cin >> input;
        if (input < 1 || input > i)
        {
            continue;
        }
        else
        {
            is_input = false;
        }
    }
    return input;
}