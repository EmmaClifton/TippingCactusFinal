//the header file for the game class 
#pragma once
class Game
{

private:
	//these variables keep track of how many days in a row the cactus been watered or left dry 
	int wetStreak;
	int dryStreak;
	//the player has two lives
	int playerLifes;
	//this variable keeps track of the player's choices throughout the game 
	int choice;


	bool cactusAlive;
	void PrintNormalOptions();
	void PrintExtraOptions();


public:
	Game(void);
	~Game(void);
	bool playerAlive();
	//displays instructions for the game
	void Intro();
	void DisplayStatus();
	bool UpdateStatus();
	void Delay(int x);
};


