#include "stdafx.h"
#include "human.h"

// this is the default constructor
human::human()
{
	//cout << "I'm creating a human\n";
	//humanHand = new playerHand;
}

human::human(string name)
{
	// cout << "I'm creating a human with a name: " << playerType << "\n";
	m_playerName = name;
}

human::~human()
{
}

bool human::playMove(gameBoard &a_inGameBoard)
{
	gameBoard thisGameBoard = a_inGameBoard;
	//cout << "I'm playing as: " << m_playerName << " and I'm in the 
	//human::playMove() function!\n";
	// display the hand of the user
	getHand();
	// display user options
	displayOptions1();
	executeOptions(thisGameBoard);
	while (m_exeSucc == false)
	{
		displayOptions1();
		executeOptions(thisGameBoard);
	}
	// returns true or false based
	// on if the move can be made succesfully
	return true;
}

void human::displayOptions1()
{
	cout << endl;

	int optionCount = 1;
	int userChoice;

	cout << "Please Select an Option: " << endl;
	cout << optionCount << " - Place a tile\n";
	optionCount++;
	cout << optionCount << " - Pass my turn\n";
	optionCount++;
	cout << optionCount << " - Get help\n";
	optionCount++;
	cout << optionCount << " - Exit Program (without saving)\n\n";
	// take in the userInput
	cout << "User Selection: ";
	cin >> userChoice;

	// validate the input
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		optionCount = 1;
		cout << "Please choose from one of the following options: " << endl;
		cout << optionCount << " - Place a tile\n";
		optionCount++;
		cout << optionCount << " - Pass my turn\n";
		optionCount++;
		cout << optionCount << " - Get help\n";
		optionCount++;
		cout << optionCount << " - Quit Program (without saving)\n\n";
		// take in the userInput
		cout << "User Selection: ";
		cin >> userChoice;
	}
	cout << endl;
	m_tempUserChoice = userChoice;
}

void human::executeOptions(gameBoard a_inGameBoard)
{
	gameBoard thisGameBoard = a_inGameBoard;
	switch (m_tempUserChoice)
	{
	case 1:
		// call function to allow the user to pick a tile
		// that will be placed on the board
		displayOptions2(thisGameBoard);
		// if the user selects 0 
		if (m_tempUserChoice == 0)
		{
			m_exeSucc = false;
			break;
		}
		m_tempUserChoice = m_tempUserChoice - 1;
		while (checkTileSelection(thisGameBoard, m_tempUserChoice) != true)
		{
			cout << "The tile you chose was invalid, please choose another tile\n";
			displayOptions2(thisGameBoard);
		}
		
		setUserOptions(m_tempUserChoice - 1);
		break;
	case 2:
		// if this function is called we need to check and
		// make sure that the user cannot actually make a move
		// checkPass()
	case 3:
		// This simply calls the help function from the player class
		// the help function will need the players hand in order to 
		// work
	case 4:
		exit(0);
	default:
		break;
	}
}

void human::displayTileOptions(int a_optionCount)
{
	// the user will also need to be able to see their hand
	cout << getName() << "'s Hand" << endl;
	m_currentHand.printHand();
	cout << setw(2) << a_optionCount;
	// this will display a number under each potential option
	for (a_optionCount = 2; a_optionCount < m_currentHand.getHandSize() + 1;
		a_optionCount++)
	{
		cout << setw(4) << a_optionCount;
	}
	cout << endl << endl;
	cout << "Press 0 to go back to the previous menu \n";
}

// displays the second set of options
void human::displayOptions2(gameBoard a_inGameBoard)
{
	gameBoard thisGameBoard = a_inGameBoard;
	int userChoice;
	int optionCount = 1;
	// want to print the board for the player
	// to see their options
	thisGameBoard.printToScreen();
	cout << endl;
	displayTileOptions(optionCount);
	// take in the userInput
	cout << "User Selection: ";
	cin >> userChoice;
	// check to make sure that the user has entered a valid number
	// while the user doesn't provide a valid input
	while (cin.fail() || (userChoice > m_currentHand.getHandSize()))
	{
		// clear the input
		cin.clear();
		cin.ignore();
		// print an error message
		cout << "Inccorect input - Please enter a value between 1 and "
			<< m_currentHand.getHandSize() << endl;
		thisGameBoard.printToScreen();
		cout << endl;
		displayTileOptions(optionCount);
		// take in the userInput
		cout << "User Selection: ";
		cin >> userChoice;
	}
	// once we get a valid input we will store it 
	// into a temporary variable
	m_tempUserChoice = userChoice;
}

playerHand* human::getHand()
{
	// cout << "Playing as: " << playerType << " and I am in the human::getHand()\n";
	return &m_currentHand;
}
