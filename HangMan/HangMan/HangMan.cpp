//
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "HangMan.h"

PlayHangman::PlayHangman(string& answer)
{
	_size = answer.length();
	_guessCount = 0;
	_answer = answer;
	// Create dynamic array for guesses
	_guess = new char[_size + 1];
	for(int i = 0; i < _size+1; i++)
	{
		_guess[i] = '0'; 
	}
	_right = new char[_size+1];
	for (int i = 0; i < _size+1; i++)
	{
		_right[i] = '_';
	}
}

int PlayHangman::GuessCheck(char& guess) //Adds guess as a correct letter or a wrong guessed letter
{
	if (Lose() == false)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_answer[i] == guess)
			{
				_right[i] == guess;
				_guessCount++;
				return 1;
			}
			if (_guess[i] == '0')
			{
				_guess[i] = guess;
				_guessCount++;
				return -1;
			}
		}
	}
}

void PlayHangman::ShowGuesses(ostream& fout)
{
	for (int i = 0; i < _size; i++)
	{
		fout << " " << _guess[i];
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

void PlayHangman::_rightAsString(ostream & fout)
{
	for (int i = 0; i < _size; i++)
	{
		fout << _right[i] << " ";
	}
}

void PlayHangman::Draw(ostream & fout)
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
		fout << "           \\n";
		_rightAsString(fout);
	}
	else if (_guessCount == 6)
		{
		fout << "===========+=\n";
		fout << "           | \n";
		fout << "           O \n";
		fout << "          -/-\n";
		fout << "          /\ \n";
		_rightAsString(fout);
		}
}