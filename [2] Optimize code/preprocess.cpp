#include <iostream>
#include <set>
#include <string.h>

using namespace std;

void preprocess(string&);


set<string> SKIP_WORDS = {"~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "{", "}", "+", "-", "=", ".", ",", " "};

int main()
{
	string str = "tắp.";
	cout <<"\nBefore processing: " << str;
	cout << "\nThe length of string before preprocess: " << str.length();
	preprocess(str);
	cout << "\nAfter processing: " << str;
	cout << "\nThe length of string after preprocess: " << str.length();
	return 0;
}

void preprocess(string& str)
{
	int n = str.length()-1;
	int i = n;
	string temp;
	while(i >= 1){		
		temp = str[i-1] + "";
		if(SKIP_WORDS.find(temp) == SKIP_WORDS.end())
			break;
		--i;
	}
	str.erase(i, n-i);
}

