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
#include "Dictionary.h"

using namespace std;

int main()
{	
	ifstream infile ("dictionary.txt");

	ifstream search_file("findwords.txt");

	ofstream outfile("revsorted.txt");

	int iteration_counter = 0;

	Dictionary dictionary(infile);

	Dictionary search_words(search_file);	

	dictionary.sort();
	
	for (int i = 0; i < search_words.size_of(); i++)
	{
		dictionary.search(search_words[i]);

		dictionary.reverse_search(search_words[i]);
	}

	dictionary.write_to_file_reverse(outfile);

	return 0;
}
