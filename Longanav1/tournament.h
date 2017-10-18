/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#pragma once
#include "gameRound.h"
#include "fileFunctions.h"

class tournament
{
public:
	// Default constructor
	tournament();

	// Default destructor
	~tournament();

	// This function displays the user options
	void loadUserOptions();

	// Creates a new tournament
	void newTournament();

	// Function to create players
	void createPlayers(bool a_isNewGame);

	// Loads in a previous tournament
	void loadFromFile();

	void playTournament(bool a_isNewGame);

	// print the tournament score
	void printScore();

	void setBooleans(string a_inGroupOne);

	// This creates a vector
	vector<dominoTile> createVector(string a_inLine);

	bool tournamentOver();

	bool getPassed(short a_inPlyrIndex, string m_playerPassed, short a_currIndex);

private:
	gameRound * newRound;
	gameBoard* m_loadGameBoard;
	// creates a new validation class
	validateInput* m_validateInputs; 
	fileFunctions* m_fileFunctions;
	// creates a new vector of players
	vector<player*> m_playerList;

	string m_playerName;

	// This will keep track of the tournament score
	int m_tournScore;
	// This is going to be the variable for the round number
	int m_roundNum;

	/*--------Variables that will be used when file is read in----------*/
	// this boolean will be true if we are loading up the
	// computer variables
	bool m_isComputer;
	// This is going to be the vector for the computerHand
	vector<dominoTile> m_comHand;
	// this will store the commputer score
	int m_computerScore;

	// This is going to be the vector for the playerHand
	vector<dominoTile> m_playerHand;
	// this will store the player score
	int m_playerScore;

	// this boolean will be true if and when we are loading up
	// the board from the file
	bool m_isBoard;
	// these will be the tiles stored into the layout
	vector<dominoTile> m_layoutTiles;

	// this boolean will be true if and when we are loading up
	// the board from the file
	bool m_isBoneYard;
	// these will be the domino tiles that will be used for the boneYard
	vector<dominoTile> m_boneyardTiles;

	// this boolean sets the player passed variable
	string m_playerPassed;

	// this variable sets the next player
	short m_nextPlayer;
	/*--------Variables that will be used when file is read in----------*/
};