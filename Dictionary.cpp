#include "Dictionary.h"



Dictionary::Dictionary()
{
}

Dictionary::Dictionary(ifstream & infile)
{
	while (!infile.eof())
	{
		DictEntry new_word;

		string line;

		getline(infile, line);

		new_word.setWord(line);

		dictionary.push_front(new_word);

		items++;
	}
}

void Dictionary::sort()
{
	dictionary.sort();

	return;
}

void Dictionary::search(DictEntry search_entry)
{
	list<DictEntry>::iterator dict_iter;
	
	int iteration_counter = 0;


	dict_iter = dictionary.begin();

	while (dict_iter != dictionary.end())
	{
		if (search_entry.getWord() == dict_iter->getWord())
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

	return;
}

void Dictionary::reverse_search(DictEntry search_entry)
{
	list<DictEntry>::reverse_iterator rdict_iter;

	int iteration_counter = 0;

	rdict_iter = dictionary.rbegin();

	while (rdict_iter != dictionary.rend())
	{
		if (search_entry.getWord() == rdict_iter->getWord())
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

	return;
}

ofstream & Dictionary::write_to_file_reverse(ofstream & outfile)
{
	list<DictEntry>::reverse_iterator rdict_iter;

	rdict_iter = dictionary.rbegin();
	
	while (rdict_iter != dictionary.rend())
	{
		outfile << rdict_iter->getWord() << " ";

		rdict_iter++;
	}

	return outfile;
}

DictEntry Dictionary::operator[](int index)
{
	list<DictEntry>::iterator dict_iter;

	dict_iter = dictionary.begin();

	for (int i = 0; i < index; i++)
	{
		dict_iter++;
	}

	return *dict_iter;
}
