// C++ hangman game

#include <iostream>
#include <string>

using namespace std;

#include "HangMan.h"
// Function to move the game below the answer so players cannot see it
void HideAnswer();

int main()
{
	string key; // answer word
	int sameGuessCount = 0; // incremeants if user keeps guessing the same chars
	char guess1; // current guess
	cout << "Please enter the word to be guessed: ";
	cin >> key;
	cout << endl;
	HideAnswer();
	PlayHangman player(key);

	player.Draw(cout);

	while (player.Lose() == false && player.Win() == false)
	{
		cout << "Enter the letter you want to guess: ";
		cin >> guess1;
		while (player.checkMultiple(guess1) == -1)
		{
			sameGuessCount++;
			 if(sameGuessCount == 3)
			 {
				 cout << "The letters you have already guessed are: \n";
				 player.ShowGuesses(cout);
				 cout << endl;
				 sameGuessCount = 0;
			 }
			cout << "You have already guess that letter! Please choose a new one: ";
			cin >> guess1;
		}
		cout << endl;
		cout << endl;
		if (player.GuessCheck(guess1) == false)
		{
			player.Draw(cout);
		}
		else if (player.GuessCheck(guess1) == true)
		{
			cout << "Correct Guess!\n";
		}
		cout << endl;
	}
	if (player.Lose() == true)
	{
		cout << "YOU ARE DEAD!" << endl;
		cout << "The answer was: " << key << endl;
		return 0;
	}
	cout << "YOU WIN!" << endl;
	cout << "The answer was: " << key << endl;
	cout << endl;
	cout << endl;
	return 0;
}

void HideAnswer()
{
	for (int i = 0; i < 100; i++)
	{
		cout << "\n";
	}
}
