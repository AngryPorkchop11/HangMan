#include <iostream>
#include <string>
#include <iomanip>

#include "HangMan.h"

PlayHangman::PlayHangman(string& answer) // Constructor
{
	_size = answer.length();
	_guessCount = 0;
	_answer = answer;
	// Create dynamic array for wrong and right
	_wrong = new char[_endGame];
	for (int i = 0; i < _endGame + 1; i++)
	{
		_wrong[i] = '0';
	}

	_right = new char[_size];
	for (int i = 0; i < _size + 1; i++)
	{
		_right[i] = '_';
	}
}

bool PlayHangman::GuessCheck(char& guess) //Adds guess as a correct letter or a wrong guessed letter // T=GuessRight F=GuessWrong
{
	bool guessFound = false;
	if (Lose() == false)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_answer[i] == guess)
			{
				_right[i] = guess;
				guessFound = true;
			}
		}
		if (guessFound == false)
		{
			for (int i = 0; i < _endGame; i++)
			{
				if (_wrong[i] == '0' && checkMultiple(guess) == 1)
				{
					_wrong[i] = guess;
					_guessCount++;
				}
			}
		}
	}
	return guessFound;
}

int PlayHangman::checkMultiple(char guess) // Checks if player has already guessed a char
{
	for (int i = 0; i < _size; i++)
		if (_right[i] == guess)
			return -1;
	for (int i = 0; i < _endGame; i++)
		if (_wrong[i] == guess)
			return -1;
	return 1;
}

void PlayHangman::ShowGuesses(ostream& fout)
{
	for (int i = 0; i < _size; i++)
	{
		if (_right[i] != '_')
			fout << " " << _right[i];
	}
	for (int i = 0; i < _endGame; i++)
	{
		if (_wrong[i] != '0')
		fout << " " << _wrong[i];
	}
}

bool PlayHangman::Lose()
{
	if (_guessCount == 6)
		return true;
	return false;
}

bool PlayHangman::Win()
{
	for (int i = 0; i < _size; i++)
	{
		if (_right[i] != _answer[i])
			return false;
	}
	return true;
}

void PlayHangman::_rightAsString(ostream& fout)
{
	for (int i = 0; i < _size; i++)
	{
		fout << _right[i];
	}
}

void PlayHangman::Draw(ostream& fout)
{
	if (_guessCount == 0)
	{
		fout << "===========+=\n";
		fout << "           | \n";
		_rightAsString(fout);

	}
	else if (_guessCount == 1)
	{
		fout << "===========+=\n";
		fout << "           | \n";
		fout << "           O \n";
		_rightAsString(fout);
	}
	else if (_guessCount == 2)
	{
		fout << "===========+=\n";
		fout << "           | \n";
		fout << "           O \n";
		fout << "           /\n";
		_rightAsString(fout);
	}
	else if (_guessCount == 3)
	{
		fout << "===========+=\n";
		fout << "           | \n";
		fout << "           O \n";
		fout << "           /-\n";
		_rightAsString(fout);
	}
	else if (_guessCount == 4)
	{
		fout << "===========+=\n";
		fout << "           | \n";
		fout << "           O \n";
		fout << "          -/-\n";
		_rightAsString(fout);
	}
	else if (_guessCount == 5)
	{
		fout << "===========+=\n";
		fout << "           | \n";
		fout << "           O \n";
		fout << "          -/-\n";
		fout << "           \\\n";
		_rightAsString(fout);
	}
	else if (_guessCount == 6)
	{
		fout << "===========+=\n";
		fout << "           | \n";
		fout << "           O \n";
		fout << "          -/-\n";
		fout << "          /\\ \n";
		_rightAsString(fout);
	}
}
