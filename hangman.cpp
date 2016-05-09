#include "hangman.h"
#include <QMainWindow>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>



static const int ALLOWED_MISSES = 6;

Hangman::Hangman()
{
    std::ifstream infile;
    infile.open("Hangman.txt");
    std::string word;
    srand(unsigned(time(0)));
    _missesLeft = ALLOWED_MISSES;

    while(!infile.eof())
    {
        infile >> word;
                word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
                for (int i = 0; i < word.length(); i++)
                {
                    word[i] = tolower(word[i]);
                }
                _words.push_back(word);
    }
    if (infile.fail())
    {
        std::cout << "File failed to open." << std::endl;
        return;
    }

    _lettersInPhrase.clear();

    for (char c : _secretPhrase) // Inserts word into the map.
    {
        _lettersInPhrase.insert(std::pair<char, bool>(c, bool(c == ' ')));
    }
}

bool Hangman::isGuessed(char c)
{

}

bool Hangman::isWon()
{

}

bool Hangman::isLost()
{
    if(_missesLeft == 0)
    {
        return true;
    }
    else
        return false;
}

void Hangman::newPhrase()
{
    std::string newWord;
    newWord = _words[rand() % _words.size()];
    _secretPhrase = newWord;
}

std::string Hangman::phraseToString()
{
    //std::stringstream ss;
    //for(int i = 0; i < _secretPhrase.size();++i)
    //{
    //    if(i != 0)
    //    {
    //        ss << "- ";
    //    }
    //    ss << _secretPhrase[i];
    //}
    //std::string s = ss.str();
}

std::string Hangman::answerToString()
{
    return _secretPhrase;
}

