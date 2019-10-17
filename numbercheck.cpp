#include <iostream>
#include <string>
#include <regex>
#include "util.h"

using namespace std;
bool wasInteger(string);

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