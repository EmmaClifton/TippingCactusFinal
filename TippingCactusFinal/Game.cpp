#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <ctime>
#include <random> 
#include <thread>
#include <chrono>

using namespace std;


Game::Game(void) : playerLifes(2), cactusAlive(true), choice(-1)
{
	srand(time(NULL));
	int randomDecider = rand();
	if ((randomDecider % 2) == 1)
	{
		wetStreak = rand() % 2 + 1;
		dryStreak = 0;
	}
	else
	{
		wetStreak = 0;
		dryStreak = rand() % 2 + 1;
	}
	//cout << wetStreak << endl << dryStreak << endl;
}


Game::~Game(void)
{
}

void Game::Intro()
{
	cout << "******Tipping Cactus Game******" << endl << endl;
	cout << "Enter '1' to skip the instructions, or '2' to read them." << endl;
	bool notInteger;
	bool notChoice;
	int skip;
	cin >> skip;
	notInteger = cin.fail() ? true : false;
	if (!notInteger)
	{
		notChoice = ((skip != 1) && (skip != 2)) ? true : false;
	}
	while (notInteger || notChoice)
	{
		cin.clear();
		cin.ignore();
		cout << "Please try again " << endl;
		cin >> skip;
		notInteger = cin.fail() ? true : false;
		notChoice = ((skip != 1) && (skip != 2)) ? true : false;
	}
	if (skip == 1)
	{
	}
	else
	{
		Delay(2);
		cout << "You are plant-sitting your friend's beloved cactus for one week." << endl;
		Delay(4);
		cout << "Each day, you can choose to water the cactus or leave it dry." << endl;
		Delay(4);
		cout << "Watering the cactus too much or too little could cause the cactus to tip." << endl;
		Delay(4);
		cout << "If the cactus is tipping to the right, it is probably underwatered." << endl;
		Delay(4);
		cout << "If the cactus is tipping to the left, it is probably overwatered." << endl;
		Delay(4);
		cout << "You can push the cactus upright again to stop it from tipping." << endl;
		Delay(4);
		cout << "If the cactus is tipping too much, watering or not watering it won't save it." << endl;
		Delay(4);
		cout << "Only touching it will!" << endl;
		Delay(4);
		cout << "However, you are allergic to cactus prickles, so be careful!" << endl;
		Delay(4);
		cout << "Touching the cactus two times will cause a severe reaction." << endl;
		Delay(4);
		cout << "It's best to water the cactus evenly...maybe every other day?" << endl;
		Delay(4);
		cout << "However, this is a tempermental cactus, so don't expect consistency!" << endl;
		Delay(4);
		cout << "So when did your friend last water the cactus? " << endl;
		Delay(4);
		cout << "Good question..." << endl;
		cout << "\n";
	}


}

void Game::DisplayStatus()
{
	if (cactusAlive && playerAlive())
	{
		if ((wetStreak < 2) && (dryStreak < 2))
		{
			cout << "\n" << "Hmm, the cactus looks okay..." << "\n" << "\n";
			cout << "  |*|*|*|" << endl;
			cout << "  |*|*|*|" << endl;
			cout << "  |*|*|*|" << endl;
			cout << "===========" << endl;
			cout << " |       |" << endl;
			cout << " " << endl << " " << endl;
			Delay(1);
			PrintNormalOptions();

		}
		else {
			switch (dryStreak)
			{
			case 2:
				cout << "\n" << "Oh no, the cactus is tipping! But not too much, right?" << "\n" << "\n";
				cout << "      /*/*/*/" << endl;
				cout << "     /*/*/*/" << endl;
				cout << "    /*/*/*/" << endl;
				cout << " ===========" << endl;
				cout << "  |       |" << endl;
				cout << " " << endl << " " << endl;
				Delay(1);
				PrintExtraOptions();
				break;
			case 3:
				cout << "\n" << "Ack, the cactus is tipping a lot!" << "\n" << "\n";
				cout << "        /*/*/*/" << endl;
				cout << "      /*/*/*/" << endl;
				cout << "    /*/*/*/" << endl;
				cout << " ===========" << endl;
				cout << "  |       |" << endl;
				cout << " " << endl << " " << endl;
				Delay(1);
				PrintExtraOptions();
				/*if (choice != 3)
				{
				cactusAlive = false;
				}*/
				break;
			case 4:
				cout << "\n" << "Well, at least it's not tipping...hehe..ahem...hmm" << "\n" << "\n";
				cout << "   X     X" << endl;
				cout << "    -----" << endl;
				cout << " ===========" << endl;
				cout << "  |       |" << endl;
				cout << " " << endl << " " << endl;

			default:
				switch (wetStreak)
				{
				case 2:
					cout << "\n" << "Oh no, the cactus is tipping! But not too much, right?" << "\n" << "\n";
					cout << " \\*\\*\\*\\" << endl;
					cout << "  \\*\\*\\*\\" << endl;
					cout << "   \\*\\*\\*\\" << endl;
					cout << "  ===========" << endl;
					cout << "   |       |" << endl;
					cout << " " << endl << " " << endl;
					cout << " " << endl << " " << endl;
					Delay(1);
					PrintExtraOptions();
					break;
				case 3:
					cout << "\n" << "Ack, the cactus is tipping a lot!" << "\n" << "\n";
					cout << " \\*\\*\\*\\" << endl;
					cout << "   \\*\\*\\*\\" << endl;
					cout << "     \\*\\*\\*\\" << endl;
					cout << "    ===========" << endl;
					cout << "     |       |" << endl;
					cout << " " << endl << " " << endl;
					cout << " " << endl << " " << endl;
					Delay(1);
					PrintExtraOptions();
					/*if (choice != 3)
					{
					cactusAlive = false;
					}*/
					break;
				case 4:
					cout << "\n" << "Well, at least it's not tipping...hehe..ahem...hmm" << "\n" << "\n";
					cout << "   X     X" << endl;
					cout << "    -----" << endl;
					cout << " ===========" << endl;
					cout << "  |       |" << endl;
					cout << " " << endl << " " << endl;
					cout << " " << endl << " " << endl;

				default:
					cout << "there was an error." << endl;
				}

			}

		}

	}
	else {
		/*if (!playerAlive())
		{
		cout << "You have been incapacitated by a severe allergic reaction." << endl;
		}
		else
		{
		cout << "You killed the cactus." << endl;
		}*/
	}

}

bool Game::UpdateStatus()
{
	switch (choice)
	{
	case 1:
		//you chose to water the cactus.
		if ((wetStreak < 3) && (dryStreak < 3))
		{
			cout << "watering the cactus..." << endl;
			wetStreak++;
			dryStreak = 0;
		}
		else
		{
			cactusAlive = false;
			cout << "The cactus was tipping too much. Watering couldn't save it." << endl;
		}
		break;
	case 2:
		//you chose to leave the cactus dry.
		if ((wetStreak < 3) && (dryStreak < 3))
		{
			cout << "not watering the cactus..." << endl;
			dryStreak++;
			wetStreak = 0;
		}
		else
		{
			cactusAlive = false;
			cout << "The cactus was tipping too much. Not watering it couldn't save it." << endl;
		}
		break;
	case 3:
		//you chose to save the cactus from tipping.
		cout << "saving the cactus from tipping..." << endl;
		cout << "Ouch, those prickles sure hurt!" << endl;
		playerLifes--;
		if (dryStreak > 2)
		{
			dryStreak--;
			break;
		}
		else
		{
			wetStreak--;
			break;
		}
		if (playerLifes < 2)
			cout << "Uh-oh, I think you're having an allergic reaction...";
	default:
		//there was an error.
		cout << "error";
	}
	srand(time(NULL));
	if (rand() % 2 == 0)
	{
		if ((rand() % 2) == 0)
		{
			wetStreak = rand() % 3 + 1;
			dryStreak = 0;
		}
		else
		{
			dryStreak = rand() % 3 + 1;
			wetStreak = 0;
		}
	}
	return (cactusAlive && playerAlive());


}

void Game::PrintNormalOptions()
{
	cout << "What would you like to do?" << endl;
	cout << " 1) water the cactus" << endl;
	cout << " 2) leave the cactus dry" << endl;
	cout << "Enter the number that corresponds to your choice." << endl;
	bool notInteger;
	bool notChoice;
	cin >> choice;
	notInteger = cin.fail() ? true : false;
	if (!notInteger)
	{
		notChoice = ((choice != 1) && (choice != 2)) ? true : false;
	}
	while (notInteger || notChoice)
	{
		cin.clear();
		cin.ignore();
		cout << "Please try again " << endl;
		cin >> choice;
		notInteger = cin.fail() ? true : false;
		notChoice = ((choice != 1) && (choice != 2)) ? true : false;
	}

}

void Game::EnterPrompt()
{
	cout << "\n";
	cout << "Press 'ENTER' to continue." << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	cin.clear();
	cin.ignore();
}
void Game::PrintExtraOptions()
{
	cout << "What would you like to do?" << endl;
	cout << " 1) water the cactus" << endl;
	cout << " 2) leave the cactus dry" << endl;
	cout << " 3) stop the cactus from tipping!" << endl;
	cout << "Enter the number that corresponds to your choice." << endl;
	bool notInteger;
	bool notChoice;
	cin >> choice;
	notInteger = cin.fail() ? true : false;
	if (!notInteger)
	{
		notChoice = ((choice != 1) && (choice != 2) && (choice != 3)) ? true : false;
	}
	while (notInteger || notChoice)
	{
		cin.clear();
		cin.ignore();
		cout << "Please try again " << endl;
		cin >> choice;
		notInteger = cin.fail() ? true : false;
		notChoice = ((choice != 1) && (choice != 2) && (choice != 3)) ? true : false;
	}
}

bool Game::playerAlive()
{
	return playerLifes > 0;
}

void Game::Delay(int x)
{
	std::this_thread::sleep_for(std::chrono::seconds(x));
}