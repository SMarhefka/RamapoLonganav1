#pragma once
#include "player.h"

#include <iomanip>

// human is the derived class
// this means that this class will inherits all 
// the functions from player.cpp
class human : public player
{
public:
	// the default constructor of derived class is called
	human();

	// creates a constructor for human class with the arguement
	// of a player name
	human(string inName);

	// default destructor
	~human();

	// this is the overridden function from the player class
	void playMove(gameBoard &a_inGameBoard);

	// this function is specific to the human class
	void displayOptions1();

	void displayTileOptions(int a_optionCount);

	void executeOptions(gameBoard &a_inGameBoard);

	void displayOptions2(gameBoard &a_inGameBoard);

	void displayOptions3();

	// this is a getter function
	playerHand* getHand();

private:
	int m_tempUserChoice;
	bool m_exeSucc;
};

