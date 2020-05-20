/*

Jonathan Greco
Professor Viviano
Programming III
17 November 2018

Program: Baseball Player.

This program is designed to store information about a baseball player
through an Linked List. It then calculates the total
points earned by each player and list the players by their total points in
descending order of the player whom scored the most points.

*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

// Global constant.
const int NUM_PLAYERS = 12,	 // Number of players on team.
CHARS = 21;		 // Number of characters for player's name.

// Structure.
struct Player
{
	char firstName[CHARS],	// To hold a player's name.
		lastName[CHARS];	// To hold a player's last name.
	int number,				// To hold a player's number.
		points;			    // To hold points scored by a player.
};

// Function Prototypes.
void getPlayerInfo(Player&);
Player getName();
void showInfo(Player);
int getTotalPoints(Player[], int);
void showHighest(Player[], int);

int main()
{
	// Define the variables.
	Player info[NUM_PLAYERS];	// Array of structures.
	int total,				    // To hold the team's average.
		high;					// To hold the score of the highest player.
	int index = 0;				// Loop counter.
	char again;					// To hold Y or N.


	do
	{
		// Display a message.
		// Display a message.
		cout << "----------------------------------------------------------------------" << endl;
		cout << "\t\tWelcome to Soccer Scores!" << endl;
		cout << "----------------------------------------------------------------------" << endl << endl;

		cout << "This program will record the information of the twelve players on" << endl;
		cout << "your team. It will then calculate the total points accumulated by" << endl;
		cout << "team and display the player with the most points scored." << endl << endl;

		// Step through the array and populate each instance
		// with player info from user.
		for (index = 0; index < NUM_PLAYERS; index++)
		{
			cout << "----------------------------------------" << endl;
			cout << "\t\tPlayer #" << (index + 1) << endl;
			cout << "----------------------------------------" << endl;
			getPlayerInfo(info[index]);
			cout << endl;
		}

		// Display team information.
		cout << "------------------------------------------------------------" << endl;
		cout << "NAME" << setw(25) << "NUMBER" << setw(30) << "POINTS SCORED" << endl;
		cout << "------------------------------------------------------------" << endl;
		for (index = 0; index < NUM_PLAYERS; index++)
		{
			showInfo(info[index]);
		}
		cout << endl;
		cout << "------------------------------------------------------------" << endl;

		// Get the total points scored by team.
		total = getTotalPoints(info, NUM_PLAYERS);
		cout << "\t\t\tTOTAL POINTS: " << total << endl;
		cout << "----------------------------------------------------------------------" << endl;

		// Display the highest scoring player.
		showHighest(info, NUM_PLAYERS);

		// Does this user want to run the program again?
		cout << "Would you like to run the program again? (Y/N) ";
		cin >> again;
		cout << endl;

		// Validate the input.
		while (toupper(again) != 'Y' && toupper(again) != 'N')
		{
			cout << "Please enter Y or N: ";
			cin >> again;
		}

	} while (toupper(again) == 'Y');

	// Display a goodbye message.
	cout << endl;
	cout << "Thanks for using Soccer Scores!" << endl << endl;

	return 0;
}

//***********************************************************************************
// Definition of getPlayerInfo function. This function uses a structure array		*
// reference variable as its parameter. It asks the user for information to store in*
// the array structure. It also calls to the getName function to get a player's		*
// full name.																		*
//***********************************************************************************

void getPlayerInfo(Player &p)
{
	// Call to the getName function and get a valid player 
	// name from user.
	p = getName();

	// Get the player's number and validate it.
	cout << p.firstName << " " << p.lastName << "'s number: ";
	cin >> p.number;
	while (p.number < 0)
	{
		cout << endl;
		cout << "ERROR: Player cannot have a negative number! Please enter" << endl;
		cout << "a valid player number for " << p.firstName << " " << p.lastName << ": ";
		cin >> p.number;
		cout << endl;
	}

	// Get the player's score and validate it.
	cout << "Points scored by " << p.firstName << " " << p.lastName << " : ";
	cin >> p.points;
	while (p.points < 0)
	{
		cout << endl;
		cout << "ERROR: Player score less than 0 points! Please enter" << endl;
		cout << "a valid score for " << p.firstName << " " << p.lastName << ": ";
		cin >> p.points;
	}
}

//***********************************************************************************
// Definition of getName function. This function uses a local variable, tempName,	*
// which is a Player structure. The user enters the first and last name of the		*
// the player, which is then validated. tempName is then returned from this function*
// to the getPlayerInfo function.													*
//***********************************************************************************

Player getName()
{
	// Define the variables.
	Player tempName;			// Temporary structure variable.
	int index;					// Loop counter.
	bool first = true,			// First name flag.
		last = true;			// Last name flag.

   // Get the player's first name.
	cout << "Player's first name: ";
	cin >> tempName.firstName;

	// Determine length of string.
	int firstLen = strlen(tempName.firstName);

	// Validate the name.
	for (int index = 0; index < firstLen; index++)
	{
		if (islower(tempName.firstName[0]))
		{
			tempName.firstName[0] = toupper(tempName.firstName[0]);
		}

		if (isdigit(tempName.firstName[index]))
		{
			first = false;
		}
	}

	// If the name is not valid, display an error message
	// and get the player's name again.
	while (!first)
	{
		cout << endl;
		cout << "Error: Name cannot contain a numeric digit!" << endl;
		cout << "Please enter the player's name again: ";
		cin >> tempName.firstName;

		for (index = 0; index < firstLen; index++)
		{
			if (isdigit(tempName.firstName[index]))
			{
				first = false;
			}
			else
				first = true;
		}
	}

	// Get the player's last name.
	cout << "Player's last name: ";
	cin >> tempName.lastName;

	// Determine length of string.
	int lastLen = strlen(tempName.lastName);

	// Validate the name.
	for (int index = 0; index < lastLen; index++)
	{
		if (islower(tempName.lastName[0]))
		{
			tempName.lastName[0] = toupper(tempName.lastName[0]);
		}

		if (isdigit(tempName.lastName[index]))
		{
			last = false;
		}
	}

	// If the name is not valid, display an error message
	// and get the player's name again.
	while (!last)
	{
		cout << endl;
		cout << "Error: Name cannot contain a numeric digit!" << endl;
		cout << "Please enter the player's name again: ";
		cin >> tempName.lastName;

		for (index = 0; index < lastLen; index++)
		{
			if (isdigit(tempName.lastName[index]))
			{
				last = false;
			}
			else
				last = true;
		}
	}

	// Return the temporary variable.
	return tempName;
}

//***********************************************************************************
// Definition of showInfo function. This function accepts an argument from the info	*
// info Player structure type. The contents of the structure in the array is then	*
// displayed.																		*
//***********************************************************************************

void showInfo(Player p)
{
	// Display each instance of players.
	cout << setw(0) << p.firstName << " " << p.lastName;
	cout << setw(26) << p.number;
	cout << setw(15) << p.points << setw(5) << endl;
}

//***********************************************************************************
// Definition of getTotalPoints function. This function accepts an array of			*
// structures and its size as arguments. It then runs an accumulator on the points	*
// member of each structure in the total variable, which is then returned.			*
//***********************************************************************************

int getTotalPoints(Player info[], int NUM_PLAYERS)
{
	// Define the variables.

	int total = 0,	// Accumulator.
		index = 0;	// Loop counter.

	// Step through the array and get the total points scored.
	for (index = 0; index < NUM_PLAYERS; index++)
	{
		total += info[index].points;
	}

	return total;
}

//***********************************************************************************
// Definition of showHighest function. This function accepts an array of structures	*
// and its size as arguments. It then steps through the array to determine the		*
// highest int value of the point member of each structure. It then displays the	*
// corresponding player whom scored the most points.								*
//***********************************************************************************

void showHighest(Player info[], int NUM_PLAYERS)
{
	// Define the variables.
	int index = 0;				// Loop counter.
	int highest = 0;			// To hold the element of the highest score member.
	int high = info[0].points;	// To hold the highest points scored.

	// Step through the array to determine the highest points
	// scored.
	for (index = 0; index < NUM_PLAYERS; index++)
	{
		if (info[index].points > high)
		{
			high = info[index].points;
			highest = index;
		}
	}

	// Display the player whom scored the most points.
	cout << "The player who scored the most points is: " << info[highest].firstName
		<< " " << info[highest].lastName << endl << endl;;
}
