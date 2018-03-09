#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <list>
#include <fstream>
#include <string>
#include <iostream>
#include "DictEntry.h"

using namespace std;


class Dictionary
{
public:
	Dictionary();
	
	Dictionary(ifstream & infile);

	void sort();

	void search(DictEntry search_entry);

	void reverse_search(DictEntry search_entry);

	ofstream & write_to_file_reverse(ofstream & outfile);

	int size_of() { return items; }

	DictEntry operator[] (int index);

private:
	list<DictEntry> dictionary;
	
	int items = 0;
};

#endif // !DICTIONARY_H
