#ifndef HANGMAN_H
#define HANGMAN_H
#include <string>
#include <set>
#include <vector>
#include <map>

class Hangman
{
public:
    Hangman();                            // Work on the view and model separately.
    int wrongGuesses();                   // Returns number of wrong guesses.
    //(makeGuesses (c:char));             // This is the letter being guessed.
    bool isGuessed(char c);               // Determines what letter has been entered to be guessed.
    bool isWon();                         // Returns whether you have won; disables everything until new phrase.
    bool isLost();                        // Returns whether you have lost; disables everything until new phrase.
    void newPhrase();                     // Intakes a new phrase from the infile.
    std::string phraseToString();         // Allows controller to ask the model about the phrase.
    std::string answerToString();         // Allows the controller to change the model's phrase(from - to char).
private:
    int _missesLeft;                      // How many misses the user has left.
    std::string _secretPhrase = "";       // The secret phrase.
    std::vector<std::string> _words;      // The phrases that can be guessed, intake from infile.
    std::set<char> _correctGuesses;       // Correct guesses made.
    std::set<char> _wrongGuesses;         // Incorrect guesses made.
    std::map<char, bool> _lettersInPhrase;// Contains all letters within the secret word.

};

#endif // HANGMAN_H
