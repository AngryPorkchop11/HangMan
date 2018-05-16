//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <assert.h>

using namespace std;

#include "HangMan.h"

int main()
{
	string key;
	char guess1;
	cout << "Please enter the word to be guessed: ";
	cin >> key;
	PlayHangman player(key);
	
	player.Draw(cout);

	while (player.Lose() == false || player.Win() == true)
	{
		cout << "Enter the letter you want to guess: ";
		cin >> guess1;
		if (player.GuessCheck(guess1) == -1)
		{
			player.Draw(cout);
		}
		cout << endl;
	}
	if (player.Lose() == true)
	{
		cout << "YOU ARE DEAD!" << endl;
		return 0;
	}
	cout << "YOU WIN!" << endl;
	return 0;
}