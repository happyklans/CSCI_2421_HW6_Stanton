/* 
Benjamin Stanton
CSCI 2421
3/7/18

Description: declarations for the DictEntry class
*/


#ifndef DICTENTRY_
#define DICTENTRY_

#include <string>

typedef std::string wordType;
class DictEntry
{
private:
    wordType word;

    wordType definition;
    
public:
    wordType getWord(){return word;}

    void setWord(wordType _word){word = _word;}

    wordType getDef(){return definition;}

    void setDef(wordType _def){definition = _def;}

    bool operator < (const DictEntry &entry) const {return (word < entry.word);}

};

#endif
