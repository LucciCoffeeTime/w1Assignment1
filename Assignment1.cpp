


//*************************************************************************************************************************
//
// WELCOME TO MY COMBATANT DOCUMENTOR PROGRAM!
// This program collects data about an enemy encountered in a video game, makes a nice summary of all the information 
// provided and calculated then stores it in a text file and displays it in the console for the user to see.
//
//*************************************************************************************************************************
//
//
// You will provide the following information:
// - Name of the game being played
// - Race of the enemy encountered
// - Classification of the enemy (BOSS, ELITE, MAJOR, MINOR)
// - Remaining health of the enemy when first encountered (full health is 10)
// - 4 actions the enemy performs
// - The distance each action reached (in meters) (decimal values allowed)
//
// The program will then calculate:
// - The damage done to the enemy based on its remaining health
// - The average range of the enemy actions
// - A recommended safe distance to stay away from the enemy (double the average range)
//
// The program will finally output all the collected and calculated data to a text file named "report.txt" and display
// it in the console for the user to review.
//
//
//*************************************************************************************************************************




#include <iostream> // This is the library required for cout and cin
#include <iomanip>  // This lets me use setprecision
#include <string>   // This lets me use string variables
#include <fstream>  // This lets me use file input and output




int main() {

	using namespace std;			// allows the user to use cout, cin, and endl without std::


	//*************************************************************************************************************************
	// This section declares all the variables used in this program
	//*************************************************************************************************************************


	string border_mega_long_thin = "------------------------------------------------------------------------------------------------------------------"; // these variables store border designs for output formatting
	string border_mega_long = "=================================================================================================================="; // these variables store border designs for output formatting
	string border_long = "=============================================================="; // these variables store border designs for output formatting
	string border_short = "=============================";                                // these variables store border designs for output formatting

	string game;				// this variable stores the name of the game
	string enemyrace;			// this variable stores the name of the enemy
	string enemyclassification;  // this variable stores the classification of the enemy	

	string action1;  			// this variable stores the first action of the enemy
	string action2;  			// this variable stores the second action of the enemy
	string action3;  			// this variable stores the third action of the enemy
	string action4;  			// this variable stores the fourth action of the enemy

	double range_1_m;             // these variables store the ranges (in meters) of the enemy actions
	double range_2_m;				//
	double range_3_m;				//
	double range_4_m;				//

	double average_range_m;		// this variable stores the calculated average range of the enemy actions

	int enemyhealth = 10;			// this variable stores the initial full health of the enemy
	int enemyremaininghealth = 0;	// this variable stores the remaining health of the enemy after being attack once
	int damagedone = 0;			// this variable stores the calculated damage done to the enemy

	ifstream indata;			// this variable is used for file input operations
	ofstream outdata;			// this variable is used for file output operations


	//*************************************************************************************************************************







	//******************************************************************************************************************
	// The section below contains the main code of the program
	//******************************************************************************************************************





	

	// this section welcomes the user to the program
	//
	cout << border_long << endl;
	cout << setfill(' ') << setw(50) << "WELCOME TO MY ENEMY ACTION DOCUMENTOR!" << endl;
	cout << border_long << endl;
	cout << " " << endl;



	// this section collects the game being played from the user
	//
	cout << "What game are you playing?: ";
	getline(cin, game);
	cout << "GAME PROVIDED: " << game << endl;
	cout << " " << endl;



	// this section collects the enemy race from the user
	//
	cout << "What is the race of the encountered enemy?: ";
	getline(cin, enemyrace); 
	cout << "RACE PROVIDED: " << enemyrace << endl;
	cout << " " << endl;



	// this section collects the enemy classification from the user
	//
	cout << "What is the classification of this enemy: BOSS, ELITE, MAJOR, MINOR?: ";
	getline(cin, enemyclassification);
	cout << "CLASSIFICATION PROVIDED: " << enemyclassification << endl;
	cout << " " << endl;



	// this section informs the user of the full health of the enemy
	// 
	cout << "The full health of this race is typically 10. " << endl;



	// this section collects the observed remaining health of the enemy from the user and calculates the damage done
	// it also validates the input to ensure only integer values between 1-10 are accepted
	//
	cout << "When you initially encounter this enemy, how much health did it have remaining? - (enter an amount between 1-10): ";
	if (cin >> enemyremaininghealth) {
		cout << "REMAINING HEALTH PROVIDED: " << enemyremaininghealth << endl;
	}
	else {
		cout << "INVALID INPUT. PLEASE RESTART THE PROGRAM AND ENTER A NUMBER BETWEEN 1-10." << endl;
		return 0; // Exit the program with an error code
	}

	damagedone = enemyhealth - enemyremaininghealth;
	cout << " " << endl;











	// this section collects 4 actions of the enemy, how far they reached, and calculates the average distance of the actions.
	// it also validates the input to ensure only decimal values are accepted
	//
	cin.ignore(1000, '\n');  // this line clears the input buffer before collecting string inputs again (taught in chapter 3)
	cout << "Please enter 4 - Actions - you have seen the enemy perform." << endl;
	getline(cin, action1); 
	getline(cin, action2); 
	getline(cin, action3); 
	getline(cin, action4); 
	cout << " " << endl;
	cout << " " << endl;
	cout << border_short << border_short << endl;
	cout << "Please enter the observed distance of each action.\nIf the action did not reach any distance (ENTER: 0) \n=-=-=-=-=-=-=- DECIMAL VALUES ARE ALLOWED -=-=-=-=-=-=-=" << endl;
	cout << border_short << border_short << endl;
	cout << " " << endl;
	cout << "Range of Action 1: " << action1 << endl;
	if (cin >> range_1_m) {
	}
	else {
		cout << "INVALID INPUT. PLEASE RESTART THE PROGRAM AND ENTER A DECIMAL VALUE." << endl;
		return 0; // Exit the program with an error code
	}
	cout << "Range of Action 2: " << action2 << endl;
	if (cin >> range_2_m) {
	}
	else {
		cout << "INVALID INPUT. PLEASE RESTART THE PROGRAM AND ENTER A DECIMAL VALUE." << endl;
		return 0; // Exit the program with an error code
	}
	cout << "Range of Action 3: " << action3 << endl;
	if (cin >> range_3_m) {
	}
	else {
		cout << "INVALID INPUT. PLEASE RESTART THE PROGRAM AND ENTER A DECIMAL VALUE." << endl;
		return 0; // Exit the program with an error code
	}
	cout << "Range of Action 4: " << action4 << endl;
	if (cin >> range_4_m) {
	}
	else {
		cout << "INVALID INPUT. PLEASE RESTART THE PROGRAM AND ENTER A DECIMAL VALUE." << endl;
		return 0; // Exit the program with an error code
	}
	average_range_m = (range_1_m + range_2_m + range_3_m + range_4_m) / 4.0;  // this line calculates the average range of the enemy actions	













	// this section outputs all collected and calculated data to a text file
	// it will provide a nice summary of all the information gathered from the user and upload it to "report.txt"
	//
	outdata.open("report.txt");  // this line opens the file for input operations

	outdata << "\n\n" << endl;
	outdata << border_mega_long << endl;
	outdata << setw(76) << "SUMMARY OF THE ENEMY DOCUMENTATION: " << endl;
	outdata << border_mega_long << endl;
	outdata << endl << endl;
	outdata << left << setw(30) << "NAME OF GAME" << setw(30) << "ENEMY RACE" << setw(30) << "ENEMY CLASSIFICATION" << setw(30) << "HEALTH MISSING" << endl;
	outdata << border_mega_long_thin << endl;
	outdata << left << setw(30) << game << setw(30) << enemyrace << setw(30) << enemyclassification << setw(30) << damagedone << endl;
	outdata << endl << endl;
	outdata << left << setw(30) << "ACTION 1 + Distance" << setw(30) << "ACTION 2 + Distance" << setw(30) << "ACTION 3 + Distance" << setw(30) << "ACTION 4 + Distance" << endl;
	outdata << border_mega_long_thin << endl;
	outdata << left << setw(30) << action1 << setw(30) << action2 << setw(30) << action3 << setw(30) << action4 << endl;
	outdata << left << setprecision(2) << fixed << setw(30) << range_1_m << setw(30) << range_2_m << setw(30) << range_3_m << setw(30) << range_4_m << endl;
	outdata << endl;
	outdata << right << setw(75) << "AVERAGE RANGE OF ACTIONS (IN METERS)" << endl;
	outdata << setprecision(2) << fixed << right << setw(34) << average_range_m << " meters " << "  |  " << "Recomended safe distance: " << average_range_m * 2 << " meters" << endl;
	outdata << " " << endl;
	outdata << border_mega_long << endl;
	outdata << right << setw(80) << "THANK YOU FOR USING THE INFORMATION PROVIDED!" << endl;
	outdata << right << setw(88) << "it will be documented immediately for future players to use!" << endl;
	outdata << border_mega_long << endl;
	outdata << " " << endl;

	outdata.close();  // this line closes the file after input operations are complete







	/////////////////////////////////////////////////////////////////////////////////////

	// MENU SELECTION - SWITCH VERSION

	/////////////////////////////////////////////////////////////////////////////////////
	//
	





	// this section outputs all collected and calculated data to the console
	// it will provide a nice summary of all the information gathered from the user and display it in the temrinal window
	//
	cout << "\n\n" << endl;
	cout << border_mega_long << endl;
	cout << setw(76) << "SUMMARY OF THE ENEMY DOCUMENTATION: " << endl;
	cout << border_mega_long << endl;
	cout << endl << endl;
	cout << left << setw(30) << "NAME OF GAME" << setw(30) << "ENEMY RACE" << setw(30) << "ENEMY CLASSIFICATION" << setw(30) << "HEALTH MISSING" << endl;
	cout << border_mega_long_thin << endl;
	cout << left << setw(30) << game << setw(30) << enemyrace << setw(30) << enemyclassification << setw(30) << damagedone << endl;
	cout << endl << endl;
	cout << left << setw(30) << "ACTION 1 + Distance" << setw(30) << "ACTION 2 + Distance" << setw(30) << "ACTION 3 + Distance" << setw(30) << "ACTION 4 + Distance" << endl;
	cout << border_mega_long_thin << endl;
	cout << left << setw(30) << action1 << setw(30) << action2 << setw(30) << action3 << setw(30) << action4 << endl;
	cout << left << setw(30) << setprecision(2) << fixed << range_1_m << setw(30) << range_2_m << setw(30) << range_3_m << setw(30) << range_4_m << endl;
	cout << endl;
	cout << right << setw(74) << "AVERAGE RANGE OF ACTIONS (IN METERS)" << endl;
	cout << right << setw(30) << setprecision(2) << fixed << average_range_m << " meters " << "  |  " << "Recomended safe distance: " << average_range_m * 2 << " meters" << endl;
	cout << " " << endl;
	cout << border_mega_long << endl;
	cout << right << setw(80) << "THANK YOU FOR THE INFORMATION PROVIDED!" << endl;
	cout << right << setw(88) << "it will be documented immediately for future players to use!" << endl;
	cout << border_mega_long << endl;
	cout << " " << endl;
	return 0;
}

