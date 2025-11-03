


//*************************************************************************************************************************
//
// WELCOME TO MY COMBATANT DOCUMENTOR PROGRAM!
// This program collects data about an enemy encountered in a video game, makes a nice summary of all the information 
// provided and calculated then stores it in a text file and offers a menu choice of the following 3 options:
// 1 to view the summary, 2 to view all given inputs, and 3 to end the program.
//
//*************************************************************************************************************************
//
//
// You will provide the following information:
// - Name of the game being played
// - Race of the enemy encountered
// - Classification of the enemy (BOSS, ELITE, MAJOR, MINOR)
// - Remaining health of the enemy when first encountered
// - 4 actions the enemy performs
// - The distance each action reached (in meters) (decimal values allowed)
//
// The program will then calculate:
// - The damage done to the enemy based on its remaining health
// - The average range of the enemy actions
// - A recommended safe distance to stay away from the enemy (double the average range)
//
// The program will then output all the collected and calculated data to a text file named "report.txt"
//
// Finally, the program will present a menu to the user with the following options:
// 1. View the summary of the enemy documentation in the console
// 2. Review the input choices made
// 3. Exit the program
//
// IF AN INVALID INPUT IS ENTERED AT ANY CRITICAL, THE PROGRAM WILL PROMPT THE USER TO RESTART THE PROGRAM AND ENTER A VALID INPUT AND RETURN 0, ENDING ITS RUN.
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

	string game;						// this variable stores the name of the game
	string enemyrace;					// this variable stores the name of the enemy
	string enemyclassification; 		// this variable stores the classification of the enemy	

	string action1;  					// this variable stores the first action of the enemy
	string action2;  					// this variable stores the second action of the enemy
	string action3;  					// this variable stores the third action of the enemy
	string action4;  					// this variable stores the fourth action of the enemy

	double range_1_m;             		// these variables store the ranges (in meters) of the enemy actions
	double range_2_m;					//
	double range_3_m;					//
	double range_4_m;					//

	double average_range_m;				// this variable stores the calculated average range of the enemy actions
	double recommended_safe_distance_m; // this variable stores the calculated recommended safe distance from the enemy

	int maximum_enemyhealth = 0;				// this variable stores the initial full health of the enemy
	int enemyremaininghealth = 0;		// this variable stores the remaining health of the enemy after being attack once
	int damagedone = 0;					// this variable stores the calculated damage done to the enemy
	int menu_choice;               		// this variable stores the menu choice input by the user

	bool flag = false;					// this variable is a killswitch for the enemyclassification portion of the program
	
	ofstream outdata;					// this variable is used for file output operations


	//*************************************************************************************************************************







	//******************************************************************************************************************
	// The section below contains the main code of the program
	//******************************************************************************************************************



	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl; 
	// this line creates space at the top of the console window for better formatting

	

	// this section welcomes the user to the program
	//
	cout << border_long << endl;
	cout << setfill(' ') << setw(50) << right << "WELCOME TO MY ENEMY ACTION DOCUMENTOR!" << endl;
	cout << border_long << endl;
	cout << " " << endl;



	// this section collects the game being played from the user
	//
	cout << "PLEASE PROVIDE THE NAME OF THE GAME YOU ARE PLAYING?: ";
	getline(cin, game);
	cout << "GAME PROVIDED: " << game << endl;
	cout << " " << endl;



	// this section collects the enemy race from the user
	//
	cout << "WHAT IS THE NAME OF THE RACE OF THE ENEMY YOU ENCOUNTERED?: ";
	getline(cin, enemyrace); 
	cout << "RACE PROVIDED: " << enemyrace << endl;
	cout << " " << endl;



	// this section collects the enemy classification from the user
	//
	cout << "WHAT IS THE CLASSIFICATION OF THE ENEMY?  |  OPTIONS ARE: BOSS, ELITE, MAJOR, MINOR  |  : (USE CAPITAL LETTERS ONLY) :";
	getline(cin, enemyclassification);
	cout << "CLASSIFICATION PROVIDED: " << enemyclassification << endl;
	cout << " " << endl;
	//
	// this section assigns full health to the enemy based on its classification
	//
	if (enemyclassification == "BOSS") maximum_enemyhealth = 100;
	else if (enemyclassification == "ELITE") maximum_enemyhealth = 75;
	else if (enemyclassification == "MAJOR") maximum_enemyhealth = 50;
	else if (enemyclassification == "MINOR") maximum_enemyhealth = 25;
	
	// this section provides a warning message based on the enemy classification
	//
	if (enemyclassification == "BOSS" || enemyclassification == "ELITE") cout << "THIS IS A LARGE THREAT! CONSIDER AVOIDING IT" << endl;
	else if (enemyclassification == "MAJOR" || enemyclassification == "MINOR") cout << "THIS ENEMY IS QUITE MANAGABLE AND NOT AS MUCH OF A THREAT" << endl;
	
	// this section validates the enemy classification input to ensure it is one of the 4 accepted options
	//
	if (enemyclassification != "BOSS" && enemyclassification != "ELITE" && enemyclassification != "MAJOR" && enemyclassification != "MINOR") {
		cout << "INVALID CLASSIFICATION. PLEASE RESTART THE PROGRAM." << endl;
		return 0; // Exit the program with an error code
	}

	cout << " " << endl;



	// this section collects the observed remaining health of the enemy from the user and calculates the damage done
	// it also validates the input to ensure only integer values within the correct range are accepted
	//
	cout << "THE KNOWN MAXIMUM HEALTH OF THIS ENEMY CLASSIFICATION IS: " << maximum_enemyhealth << endl;
	cout << "When you encountered this enemy, how much health did it have?:    |  WHOLE NUMBERS ONLY 0 TO " << maximum_enemyhealth << "  |" << endl;

	// this line collects the remaining health input and validates it to ensure it is an integer
	//
	if (!(cin >> enemyremaininghealth)) {
		cout << "INVALID INPUT. PLEASE RESTART THE PROGRAM AND ENTER A VALID INTEGER VALUE." << endl;
		return 0; // Exit the program with an error code
	}

	// this section validates the remaining health input based on the enemy classification
	//
	if (enemyclassification == "BOSS" && enemyremaininghealth >= 0 && enemyremaininghealth <= 100)
		flag = true;
	else if (enemyclassification == "ELITE" && enemyremaininghealth >= 0 && enemyremaininghealth <= 75)
		flag = true;
	else if (enemyclassification == "MAJOR" && enemyremaininghealth >= 0 && enemyremaininghealth <= 50) 
		flag = true;
	else if (enemyclassification == "MINOR" && enemyremaininghealth >= 0 && enemyremaininghealth <= 25)
		flag = true;
	//
	// this is the killswitch usage
	//
	if (!(flag)) {
		cout << "INVALID INPUT. PLEASE RESTART THE PROGRAM AND ENTER A VALID INTEGER VALUE." << endl;
		return 0; // Exit the program with an error code
	}
	flag = false;

	damagedone = maximum_enemyhealth - enemyremaininghealth;
	cout << "THE " << enemyrace << ' ' << enemyclassification << " IS MISSING: " << damagedone << " HEALTH" << endl;
	
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
	cout << "Please enter the observed distance of each action.\nIf the action did not reach any distance (ENTER: 0) \n=-=-=-=-=-=-=- DECIMAL VALUES ARE RECOMMENDED -=-=-=-=-=-=-=" << endl;
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
	recommended_safe_distance_m = average_range_m * 2;                        // this line calculates the recommended safe distance from the enemy












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
	outdata << setprecision(2) << fixed << right << setw(34) << average_range_m << " meters " << "  |  " << "Recommended safe distance: " << recommended_safe_distance_m << " meters" << endl;
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
	cout << " " << endl;
	cout << border_long << endl;
	cout << setw(39) << setfill(' ') << right << "MENU SELECTION" << endl;
	cout << border_long << endl;
	cout << " " << endl;
	cout << "PLEASE SELECT AN OPTION FROM THE MENU BELOW: " << endl;
	cout << "1. VIEW SUMMARY OF ENEMY DOCUMENTATION" << endl;
	cout << "2. REVIEW YOUR INPUT CHOICES" << endl;
	cout << "3. EXIT THE PROGRAM" << endl;
	cout << " " << endl;
	cout << "ENTER YOUR MENU CHOICE (1, 2, or 3): ";
	//
	// this section collects the menu choice from the user and validates the input
	//
	if (!(cin >> menu_choice && menu_choice >= 1 && menu_choice <= 3))
	{
		cout << "INVALID INPUT. PLEASE RESTART THE PROGRAM AND ENTER A VALID INTEGER VALUE." << endl;
		return 0; // Exit the program with an error code
	}
	//
	// this section processes the menu choice using a switch statement
	//
	switch (menu_choice)
	{
		case 1:
			cout << "YOU HAVE SELECTED TO VIEW THE SUMMARY." << endl;
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
			cout << right << setw(30) << setprecision(2) << fixed << average_range_m << " meters " << "  |  " << "Recommended safe distance: " << recommended_safe_distance_m << " meters" << endl;
			cout << " " << endl;
			cout << border_mega_long << endl;
			cout << right << setw(80) << "THANK YOU FOR THE INFORMATION PROVIDED!" << endl;
			cout << right << setw(88) << "it will be documented immediately for future players to use!" << endl;
			cout << border_mega_long << endl;
			cout << " " << endl;
			break;


		case 2:
			cout << "YOU HAVE SELECTED TO REVIEW YOUR INPUT CHOICES" << endl;
			cout << " " << endl;
			cout << "GAME PROVIDED: " << game << endl;
			cout << "RACE PROVIDED: " << enemyrace << endl;
			cout << "CLASSIFICATION PROVIDED: " << enemyclassification << endl;
			cout << "OBSERVED REMAINING HEALTH: " << enemyremaininghealth << endl;
			cout << "RANGE OF ACTION 1: " << range_1_m << " meters" << endl;
			cout << "RANGE OF ACTION 2: " << range_2_m << " meters" << endl;
			cout << "RANGE OF ACTION 3: " << range_3_m << " meters" << endl;
			cout << "RANGE OF ACTION 4: " << range_4_m << " meters" << endl;
			cout << " " << endl;
			break;


		case 3:
			cout << "YOU HAVE SELECTED TO EXIT THE PROGRAM. THANK YOU FOR USING THE ENEMY DOCUMENTOR!" << endl;
			break;


		default:
			cout << "INVALID MENU OPTION. PLEASE RESTART THE PROGRAM AND ENTER A VALID INTEGER VALUE." << endl;
			return 0; // Exit the program with an error code
	}
	cout << "THE PROGRAM WILL NOW END - HAVE A GOOD DAY" << endl;
	return 0;
}

