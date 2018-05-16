#ifndef _HANGMAN
#define _HANGMAN
#include <string>				  
class PlayHangman
{
public:
	// Constructor: Set answer and build arrays to hold guesses and correct guesses
	PlayHangman(string& answer);	
	int GuessCheck(char& guess);
	void ShowGuesses(ostream& fout);
	bool Lose();
	bool Win();
	void _rightAsString(ostream & fout);
	void Draw(ostream& fout);
private:
	unsigned int _size;
	unsigned int _guessCount;
	string _answer;
	char* _guess;
	char* _right;
};
#endif