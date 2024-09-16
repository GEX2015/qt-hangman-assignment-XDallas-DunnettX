#ifndef HANGMAN_H
#define HANGMAN_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include <QString>

class Hangman
{
public:
public:
    Hangman(); // Constructor
    ~Hangman(); // Deconstructor.

    void welcome() const; // Welcome to game.

    std::string displayGallows(); // Displays hangman.

    std::string workingPhrase();

    void allocateWords();

    void drawScreen();

    void processGuess(char c);

    bool isGameOver() const;

    void play();

    void initRound();

    int wrongGuesses();

    bool isGuessed(char c) const;

private:

    bool isWon() const;
    bool isLost() const;

private:
    std::vector<std::string> _wordList;
    std::set<char> _goodGuesses;
    std::set<char> _badGuesses;
    std::string _secretPhrase;
    std::map<std::set<char>, QString> _imageFor;

};

#endif // HANGMAN_H
