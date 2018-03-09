/* 
Benjamin Stanton
CSCI 2421
3/7/18

Description: main program, contains the ui, instantiates the objects and 
calls the member functions
*/

#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include "DictEntry.h"

using namespace std;

int main()
{
	list<DictEntry> dictionary;

	list<DictEntry> search_words;
	
	list<DictEntry>::iterator dict_iter;
	
	ifstream infile ("dictionary.txt");

	ifstream search_file("findwords.txt");

	ofstream outfile("revsorted.txt");

	while (!infile.eof())
	{
		DictEntry new_word;

		string line;

		getline(infile, line);

		new_word.setWord(line);

		dictionary.push_front(new_word);
	}

	while (!search_file.eof())
	{
		DictEntry new_word;

		string line;

		getline(search_file, line);

		new_word.setWord(line);

		search_words.push_front(new_word);
	}

	dictionary.sort();
	
	dict_iter = dictionary.begin();

	while (dict_iter != dictionary.end())
	{
		
	}
	
	return 0;
}
