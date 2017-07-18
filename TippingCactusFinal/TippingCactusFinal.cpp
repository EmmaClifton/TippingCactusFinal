// TippingCactusFinal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"
using namespace std;

//the code for creating a game instance and running the game
int main()
{
	bool keepPlaying = true;
	while (keepPlaying)
	{
		bool stillWinning = true;
		Game YourGame = Game();
		YourGame.Intro();
		//the game has up to seven levels, so the code goes through at most seven iterations
		for (int i = 0; i < 7; i++)
		{
			if (stillWinning)
			{
				//a time delay of two seconds
				YourGame.Delay(2);
				cout << "\n" << "***DAY " << i + 1 << "***" << endl;
				YourGame.DisplayStatus();
				stillWinning = YourGame.UpdateStatus();

			}
			else
				break;
		}
		YourGame.Delay(2);
		if (stillWinning)
		{
			cout << "\n" << "\n";
			cout << "*";
			YourGame.Delay(1);
			cout << "*";
			YourGame.Delay(1);
			cout << "*";
			YourGame.Delay(1);
			cout << "YOU ";
			YourGame.Delay(1);
			cout << "WON!";
			YourGame.Delay(1);
			cout << "*";
			YourGame.Delay(1);
			cout << "*";
			YourGame.Delay(1);
			cout << "*" << endl;
			YourGame.Delay(1);
			cout << "You made it through the week without killing the cactus!" << endl;
			YourGame.Delay(2);
			cout << "\n";
			cout << "    \\|/" << endl;
			cout << "  |*|*|*|" << endl;
			cout << "  |*|*|*|" << endl;
			cout << "  |*|*|*|" << endl;
			cout << "===========" << endl;
			cout << " |       |" << endl;
			cout << " " << endl << " " << endl;
		}

		else
		{
			cout << "\n" << "\n";
			cout << "*";
			YourGame.Delay(1);
			cout << "*";
			YourGame.Delay(1);
			cout << "*";
			YourGame.Delay(1);
			cout << "YOU ";
			YourGame.Delay(1);
			cout << "LOST";
			YourGame.Delay(1);
			cout << "*";
			YourGame.Delay(1);
			cout << "*";
			YourGame.Delay(1);
			cout << "*" << endl;
			YourGame.Delay(1);
			if (!YourGame.playerAlive())
			{
				cout << "You were taken to the hospital to be treated for a severe allergic reaction." << endl;
			}
			else
			{
				cout << "Unfortunately, you killed the cactus." << endl << endl;
			}
		}
		//code to make sure user input is valid, and if not, prompt user for more input until the input is valid  
		cout << "Press '1' to keep playing, or '0' to quit." << endl;
		int choice;
		cin >> choice;
		bool notInteger;
		bool notChoice;
		notInteger = cin.fail() ? true : false;
		if (!notInteger)
		{
			notChoice = ((choice != 1) && (choice != 0)) ? true : false;
		}
		while (notInteger || notChoice)
		{
			cin.clear();
			cin.ignore();
			cout << "Please try again " << endl;
			cin >> choice;
			notInteger = cin.fail() ? true : false;
			notChoice = ((choice != 1) && (choice != 0)) ? true : false;
		}
		keepPlaying = (choice == 1) ? true : false;

	}


	return 0;
}




