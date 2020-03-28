#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

map<string, int> load_test(const char[]);
vector<string> load_dict(const char[]);

int main(int argc, char *argv[])
{
	const char test_path[] = "test.txt";
	const char dict_path[] = "syllables.txt";
	
	
	vector<string> dict = load_dict(dict_path);
	map<string, int> test = load_test(test_path);
	
	
	return 0;
}

map<string, int> load_test(const char path[])
{
	ofstream myfile("filename.txt");
	string myText;
	while(getline(myfile, myText)) {
		// Output the text from the file
		cout << myText;
	}
	
	map<string, int> content;

	myfile.close();
	return content;
}

vector<string> load_dict(const char path[]){
	vector<string> dict;
	return dict;
}
