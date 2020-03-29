#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in;
	in.open("test.txt", ios::out);
	
	string first_character;
	in >> first_character;
	cout << first_character;
	
	while(in)
	{
		in >> character;
		
	}
	in.close();
	return 0;
}
