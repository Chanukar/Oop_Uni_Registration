#include <iostream>
#include <string>
#include <regex>
#include "util.h"
//includes the libraries that are required for checking if the input is of the correct type
using namespace std;
bool wasInteger(string);
//if integer then accepted
int main()
{
	string abc;
	cout<<"enter something"<<endl;
	cin>>abc;
	cout<<check_crazy(abc)<<endl;
	return 0;
}

bool check_crazy(string a)
{
//checks if the string is correct or not
	bool go = false;
	int length = a.length();
	if((length>0)&&(length <= 5))
	{
		if(regex_match(a, regex("[+-]?[0-9]+")))
		{
			go = true;
		}
		else
		{
			go = false;
		}
	}
	else
	{
		go = false;
	}

	return go;
}
