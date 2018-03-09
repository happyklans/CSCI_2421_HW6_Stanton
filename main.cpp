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

	list<DictEntry>::reverse_iterator rdict_iter;

	list<DictEntry>::iterator search_iter;
	
	ifstream infile ("dictionary.txt");

	ifstream search_file("findwords.txt");

	ofstream outfile("revsorted.txt");

	int iteration_counter = 0;



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

	search_iter = search_words.begin();

	while (search_iter != search_words.end())
	{
		dict_iter = dictionary.begin();

		while (dict_iter != dictionary.end())
		{
			if (search_iter->getWord() == dict_iter->getWord())
			{
				cout << "found " << dict_iter->getWord() << " in the dictionary. It took " << iteration_counter
					<< " iterations from the front to find" << endl;

				break;

			}
			else
			{
				iteration_counter++;
				
				dict_iter++;
			}
		}

		iteration_counter = 0;

		rdict_iter = dictionary.rbegin();

		while (rdict_iter != dictionary.rend())
		{
			if (search_iter->getWord() == rdict_iter->getWord())
			{
				cout << "found " << rdict_iter->getWord() << " in the dictionary. It took " << iteration_counter
					<< " iterations from the back to find" << endl;

				break;

			}
			else
			{
				iteration_counter++;

				rdict_iter++;
			}
		}

		search_iter++;

		iteration_counter = 0;

	}
	
	rdict_iter = dictionary.rbegin();

	while (rdict_iter != dictionary.rend())
	{
		outfile << rdict_iter->getWord() << endl;

		rdict_iter++;
	}


	return 0;
}
