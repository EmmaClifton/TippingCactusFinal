#pragma once
class Game
{

private:
	int wetStreak;
	int dryStreak;
	int playerLifes;
	int choice;


	bool cactusAlive;
	void PrintNormalOptions();
	void PrintExtraOptions();


public:
	Game(void);
	~Game(void);
	bool playerAlive();
	void Intro();
	void DisplayStatus();
	bool UpdateStatus();
	void EnterPrompt();
	void Delay(int x);
};


