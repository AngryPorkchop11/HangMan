#pragma once
#include <string>

using namespace std;
class PlayHangman
{
public:
	//Constructor: Set answer and build arrays to hold wrong guesses and correct guesses
	PlayHangman(string& answer);
	bool GuessCheck(char& guess); // Checks if the guessed char is in the answer word
	int checkMultiple(char guess); // Checks if player has already guessed a char
	void ShowGuesses(ostream& fout); // Shows all the letters guessed
	bool Lose(); // Checks if player lost
	bool Win(); // Checks if player won
	void _rightAsString(ostream& fout); // Writes the correct guessed letter as a string
	void Draw(ostream& fout); // Draws hangman on how many wrong guesses

private:
	const int _endGame = 6; // 6 wrong guesses with draw hangman all the way - ending the game
	unsigned int _size; // Size of the array based on the answer word
	unsigned int _guessCount; // Number of incorrect guesses
	string _answer; // Answer word
	char* _wrong; // char array of wrong guesses
	char* _right; // char array of right guesses
};
