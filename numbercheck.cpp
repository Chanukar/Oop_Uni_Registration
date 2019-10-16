#include <iostream>
#include <string>
#include <regex>
using namespace std;
bool check_crazy(string);
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
		if(wasInteger(a))
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

bool wasInteger(const std::string num) {
    return regex_match(num, regex("[+-]?[0-9]+"));
}
