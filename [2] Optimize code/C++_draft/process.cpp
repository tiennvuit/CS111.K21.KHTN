#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>


using namespace std;

void preprocess(string&);
map<string, int> load_test(const char[]);
vector<string> load_dict(const char[]);
void display_dict(vector<string>&);
void display_test(map<string, int>&);
void toupper(string&);

set<string> SKIP_WORDS = {"~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "{", "}", "+", "-", "=", ".", ",", " "};

int main(int argc, char *argv[])
{
	const char test_path[] = "test.txt";
	const char dict_path[] = "syllables.txt";
	
	
	vector<string> dict = load_dict(dict_path);
	map<string, int> test = load_test(test_path);

	display_test(test);
	
	
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

map<string, int> load_test(const char path[])
{
	/*Open file*/
	ifstream in;
	in.open(path, ios::out);
	map<string, int> content;
	string word;
	while(in)
	{
		string temp;
		in >> temp;
		word = temp;
		// Preprocess word
		// preprocess(character);
		if(word != "")
		{
			if (content.find(word) == content.end())
			{
				toupper(word);
				content[word] = 1;
			}
			else
			{
				content[word]++;
			}
		}
	}
	in.close();
	return content;
}

vector<string> load_dict(const char path[]){
	/*Open file*/
	ifstream in;
	in.open(path, ios::out);
	vector<string> dict;
	string character;
	while(in)
	{
		in >> character;
		dict.push_back(character);
	}
	in.close(); // close file
	return dict;
}

void display_dict(vector<string>& dict){
	vector<string>::iterator it;
	int id = 1;
	for(it = dict.begin(); it != dict.end(); ++it)
	{
		cout << left << setw(6) << id;
		cout << *it << endl;
		++id;
	}
}


void display_test(map<string, int>& test){
	map<string, int>::iterator imap;
	for(imap = test.begin(); imap != test.end(); ++imap)
	{
		cout << imap->first << ": " << imap->second << endl;
	}
}

void toupper(string&str)
{
	std::for_each(str.begin(), str.end(), [](char & c){
		c = ::toupper(c);
	});
}
