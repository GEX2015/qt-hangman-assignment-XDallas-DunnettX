//
//	Dallas Dunnett
//
//	Hangman.cpp
//
#include "hangman.h"
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QFile>
#include <QTextStream>
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

static const int ALLOWED_MISSES = 6; // Max misses.

Hangman::Hangman() // Constructor.
{
    srand(unsigned(time(0)));
    allocateWords();

}

Hangman::~Hangman() // Deconstructor.
{
}

void Hangman::allocateWords() // allocates words to the vector.
{

    std::ifstream infile;
    infile.open(":/new/prefix1/Hangman Images/Hangman_words.txt");

    if (infile.fail())
    {
        std::cout << "File failed to open." << std::endl;
        return;
    }
    std::string word;


    while (!infile.eof())
    {
        infile >> word;
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }
        _wordList.push_back(word);
    }

}

void Hangman::welcome() const // Initial welcome for the game.
{
    std::cout
        << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << "\n"
        << "xx                          xx" << "\n"
        << "xx         HangMan          xx" << "\n"
        << "xx                          xx" << "\n"
        << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
    std::cout << "\n Welcome to Hangman!" << std::endl;
    std::cout << "You are allowed 6 misses in your fight to guess the chosen phrase." << std::endl;
}

std::string Hangman::displayGallows()
{
    switch (_badGuesses.size())
    {
    case 0:
    {
        return "Border-image:url(:/new/prefix1/HangMan Images/hangman0.png)";
        break;
    }
    case 1:
    {

        return "Border-image:url(:/new/prefix1/HangMan Images/hangman1.png)";
        break;

    }
    case 2:
    {

        return "Border-image:url(:/new/prefix1/HangMan Images/hangman2.png)";
        break;

    }
    case 3:
    {

        return "Border-image:url(:/new/prefix1/HangMan Images/hangman3.png)";
        break;

    }
    case 4:
    {

        return "Border-image:url(:/new/prefix1/HangMan Images/hangman4.png)";
        break;
    }
    case 5:
    {

        return "Border-image:url(:/new/prefix1/HangMan Images/hangman5.png)";
        break;
    }
    case 6:
    {

        return "Border-image:url(:/new/prefix1/HangMan Images/hangman6.png)";
        break;
    }
    default:
    {
        return "Border-image:url(:/new/prefix1/HangMan Images/hangman6.png)";
        break;
    }
    }
} // Displays the gallows

std::string Hangman::workingPhrase() // deals with the characters in the secretphrase and the _'s
{
    std::stringstream ss;

    for (auto c : _secretPhrase)
    {
        auto itr = std::find(_goodGuesses.begin(), _goodGuesses.end(), c);
        if (itr == _goodGuesses.end())
        {
            ss << "_ ";
        }
        else
        {
            ss << c << " ";
        }
    }
    return ss.str();
}

void Hangman::drawScreen() // Draws the screen.
{

    std::cout << workingPhrase() << std::endl;
    std::cout << "Bad Guesses so far: ";
    for (auto c : _badGuesses)
    {
        std::cout << c << " ";
    }
    std::cout << "\n";
}

void Hangman::processGuess(char c) // Processes guess.
{
    // Already guessed
    if (find(_goodGuesses.begin(), _goodGuesses.end(), c) != _goodGuesses.end() ||
        find(_badGuesses.begin(), _badGuesses.end(), c) != _badGuesses.end())
    {
        return;
    }
    // Not found
    auto i = _secretPhrase.find(c);
    if (i == std::string::npos)
    {
        _badGuesses.insert(c);
    }
    else
    {
        _goodGuesses.insert(c);
    }
}

bool Hangman::isGameOver() const // checks for game over.
{
    return isWon() || isLost();
}

bool Hangman::isWon() const // checks if user has won.
{
    for (auto c : _secretPhrase)
    {
        if (std::find(_goodGuesses.begin(), _goodGuesses.end(), c) == _goodGuesses.end())
        {
            return false;
        }
    }
    return true;
}

bool Hangman::isLost() const // Checks if user has lost.
{
    return _badGuesses.size() == ALLOWED_MISSES;
}

void Hangman::play() // Plays the game.
{
    char c;
    initRound();
    do
    {
        drawScreen();
        std::cout << "Welcome, make a guess: ";
        std::cin >> c;
        processGuess(c);

    } while (!isGameOver());

    drawScreen();

    if (isWon())
    {
        std::cout << "Congratulations, you have won!" << std::endl;
        return;
    }
    else
    {
        std::cout << "You have lost, thanks for playing!" << std::endl;
        std::cout << "The word was: " << _secretPhrase;
        return;
    }
}

void Hangman::initRound() // Initializes the rounds;
{
    _goodGuesses.clear();
    _badGuesses.clear();
    _secretPhrase = _wordList[rand() % _wordList.size()];
}

int Hangman::wrongGuesses()
{
    return (_badGuesses.size() < 6) ? _badGuesses.size() : 6;
}

bool Hangman::isGuessed(char c) const
{
    if (std::find(_goodGuesses.begin(), _goodGuesses.end(), c) != _goodGuesses.end())
        return true;

    if (std::find(_badGuesses.begin(), _badGuesses.end(), c) != _badGuesses.end())
        return true;

    return false;
}

