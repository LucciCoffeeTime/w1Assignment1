


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
// 
// THE PROGRAM WILL ASK THE USER TO CONFIRM IF THE INPUTS ARE CORRECT OR IF THEY WANT TO RESTART
// - The user will be able to Restart, continue, or exit.
//
// You will provide the following information:
// - 1-4 actions the enemy performs
// - The distance each action reached (in meters) (decimal values allowed)
//
// THE PROGRAM WILL MAKE THE FOLLOWING CALCULATIONS:
// - The damage done to the enemy based on its remaining health
// - The average range of the enemy actions
// - A recommended safe distance to stay away from the enemy (double the average range)
//
// THE PROGRAM WILL OUTPUT A SUMMARY TO A FILE NAMED "REPORT.TXT"
//
// AT THE END THE PROGRAM WILL OFFER A MENU SELECTION OF THE 3 FOLLOWING CHOICES:
// - 1. View the summary of the enemy documentation in the console
// - 2. Review the input choices made
// - 3. Exit the program
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
                           

	string game;						// this variable stores the name of the game
	string enemyrace;					// this variable stores the name of the enemy
	string enemyclassification; 		// this variable stores the classification of the enemy	

	string action1;  					// this variable stores the first action of the enemy
	string action2;  					// this variable stores the second action of the enemy
	string action3;  					// this variable stores the third action of the enemy
	string action4;  


	string end_or_continue;				// THESE VARIABLES CONTROL THE CHOICE TO END THE PROGRAM MID LOOP OR RESTART THE PROGRAM
	string loop_termination_confirmer_1;//
	

	double range_1_m;             		// these variables store the ranges (in meters) of the enemy actions
	double range_2_m;					//
	double range_3_m;					//
	double range_4_m;					//

	double range_value_holder;			// THIS VARIABLE WILL BE USED TO TRANSFER RANGES WHILE USING A LOOP.
	double average_range_m;				// this variable stores the calculated average range of the enemy actions
	double recommended_safe_distance_m; // this variable stores the calculated recommended safe distance from the enemy


	int maximum_enemyhealth = 0;		// this variable stores the initial full health of the enemy
	int enemyremaininghealth = 0;		// this variable stores the remaining health of the enemy after being attack once
	int damagedone = 0;					// this variable stores the calculated damage done to the enemy
	int menu_choice;               		// this variable stores the menu choice input by the user
	int action_count = 0;				// THIS VARIABLE STORES THE ACTION COUNT OF THE ENEMY BASED ON THE CLASSIFICATION

	int i_reset_to_one = 1;
	int health_storage_review;			// THIS STORES THE MAX HEALTH OF THE ENEMY BASED ON THE CLASSIFICATION. IT WILL BE USED DURING THE REVIEW

	bool flag = false;					// this variable is a killswitch for the enemyclassification portion of the program


	ofstream outdata;					// this variable is used for file output operations


	// CONSTANT VARIABLES				// THESE ARE INSIDE OF MAIN UNTIL WE START USING OTHER FUNCTIONS
	const int health_boss = 100;		// These variables will be used to state the known maximum health of a combatant based on its classification
	const int health_elite = 75;		//
	const int health_major = 50;		//
	const int health_minor = 25;		//
	const int health_zero = 0;			// This variable is mainly used for stating and/or conditions in if-statements involving health min- and maximums

	const int action_count_boss = 4;	// These variables will be used to control loop instances and calculate range averages.
	const int action_count_elite = 3;	//
	const int action_count_major = 2;	//
	const int action_count_minor = 1;	//

	const double safe_distance_multiplier = 2.0;	// This variable is used to calculate the safe distance, which is 2 times the average of ranges

	const string border_mega_long_thin = "------------------------------------------------------------------------------------------------------------------";
	const string border_mega_long = "==================================================================================================================";
	const string border_long = "==============================================================";
	const string border_short = "=============================";     

	//*************************************************************************************************************************





















	//******************************************************************************************************************
	// The section below contains the main code of the program
	//******************************************************************************************************************







	do
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl; 
		// this line creates space at the top of the console window for better formatting

		

		// this section welcomes the user to the program
		//
		cout << border_long << endl;
		cout << setfill(' ') << setw(50) << right << "WELCOME TO MY ENEMY ACTION DOCUMENTOR!" << endl;
		cout << border_long << endl;
		cout << "\n\n" << endl;



		// this section collects the game being played from the user
		//
		cout << "PLEASE PROVIDE THE NAME OF THE GAME YOU ARE PLAYING?: ";
		getline(cin, game);
		cout << "GAME PROVIDED: " << game << endl;
		cout << "\n\n" << endl;



		// this section collects the enemy race from the user
		//
		cout << "WHAT IS THE NAME OF THE RACE OF THE ENEMY YOU ENCOUNTERED?: ";
		getline(cin, enemyrace); 
		cout << "RACE PROVIDED: " << enemyrace << endl;
		cout << "\n\n" << endl;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		// THIS SECTION COLLECTS THE ENEMY CLASSIFICATION FROM THE USER AND ENSURES IT IS CORRECT USING A LOOP
		// IT ALSO SETS THE ACTION COUNT
		do
		{
			flag = true;
			cout << "WHAT IS THE CLASSIFICATION OF THE ENEMY?  |  OPTIONS ARE: BOSS, ELITE, MAJOR, MINOR  |  : (USE CAPITAL LETTERS ONLY) :";
			getline(cin, enemyclassification);
			cout << "CLASSIFICATION PROVIDED: " << enemyclassification << endl;
			cout << "\n\n" << endl;
			//
			// this section assigns full health to the enemy based on its classification
			//
			if (enemyclassification == "BOSS") {
				maximum_enemyhealth = health_boss;
				action_count = action_count_boss;
				health_storage_review = health_boss;
			}
			else if (enemyclassification == "ELITE") {
				maximum_enemyhealth = health_elite;
				action_count = action_count_elite;
				health_storage_review = health_elite;
			}
			else if (enemyclassification == "MAJOR") {
				maximum_enemyhealth = health_major;
				action_count = action_count_major;
				health_storage_review = health_major;
			}
			else if (enemyclassification == "MINOR") {
				maximum_enemyhealth = health_minor;
				action_count = action_count_minor;
				health_storage_review = health_minor;
			}
			
			// this section provides a warning message based on the enemy classification
			//
			if (enemyclassification == "BOSS" || enemyclassification == "ELITE") cout << "THIS IS A LARGE THREAT! CONSIDER AVOIDING IT" << endl;
			else if (enemyclassification == "MAJOR" || enemyclassification == "MINOR") cout << "THIS ENEMY IS QUITE MANAGABLE AND NOT AS MUCH OF A THREAT" << endl;
			
			// this section validates the enemy classification input to ensure it is one of the 4 accepted options
			//
			if (enemyclassification != "BOSS" && enemyclassification != "ELITE" && enemyclassification != "MAJOR" && enemyclassification != "MINOR") {
				cout << "The INPUT received does not match the requirements. \n If you would like to retry, enter any input, otherwise, type exactly \"EXIT\" to end the program." << endl;
				getline(cin, end_or_continue);
				if (end_or_continue == "EXIT")
					return 0;
				flag = false;
			}
		}
		while (!flag);
		flag = false;
		cout << "\n\n" << endl;
		


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		do
		{
			
			// this section collects the observed remaining health of the enemy from the user and calculates the damage done
			// it also validates the input to ensure only integer values within the correct range are accepted
			//
			cout << "THE KNOWN MAXIMUM HEALTH OF THIS ENEMY CLASSIFICATION IS: " << maximum_enemyhealth << endl;
			cout << "When you encountered this enemy, how much health did it have?:    |  WHOLE NUMBERS ONLY FROM  0 TO " << maximum_enemyhealth << "  |" << endl;
			
			if (cin >> enemyremaininghealth)
				{
				// this section validates the remaining health input based on the enemy classification
				//
				if (enemyclassification == "BOSS" && enemyremaininghealth >= health_zero && enemyremaininghealth <= health_boss){
					flag = true;
				}
				else if (enemyclassification == "ELITE" && enemyremaininghealth >= health_zero && enemyremaininghealth <= health_elite){
					flag = true;
				}
				else if (enemyclassification == "MAJOR" && enemyremaininghealth >= health_zero && enemyremaininghealth <= health_major){
					flag = true;
				}
				else if (enemyclassification == "MINOR" && enemyremaininghealth >= health_zero && enemyremaininghealth <= health_minor){
					flag = true;
				}
				}
			
			if(!flag)
			{
				cout << "\n\n" << endl;
				cout << "The INPUT received does not match the requirements. \n If you would like to retry, enter any input, otherwise, type exactly \"EXIT\" to end the program." << endl;
				cin >> end_or_continue;
				if (end_or_continue == "EXIT")
					return 0;
			}

			cin.clear();				// THIS ALLOWS CIN TO TAKE INPUT AGAIN, REVERTING ITS FAILED STATE.
			cin.ignore(1000, '\n');
		}
		while (!flag);					// END OF THE LOOP

		flag = false;					// RESETS THE KILL SWITCH

		damagedone = maximum_enemyhealth - enemyremaininghealth;
		cout << "THE " << enemyrace << ' ' << enemyclassification << " IS MISSING: " << damagedone << " HEALTH" << endl;
		cout << "\n\n" << endl;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		// THIS IS A REVIEW PORTION THAT WILL EITHER ALLOW THE USER TO RESTART OR CONTINUE THE PROGRAM WITHOUT EXITING
		//
		cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
		cout << "PLEASE REVIEW THE FOLLOWING INFORMATION AND DECIDE IF YOU WISH TO PROCEED." << endl;
		cout << "GAME PROVIDED: " << game << endl;
		cout << "RACE PROVIDED: " << enemyrace << endl;
		cout << "CLASSIFICATION PROVIDED: " << enemyclassification << endl;
		cout << "MAXIMUM HEALTH OF THE " << enemyclassification << ": " << health_storage_review << endl;
		cout << "OBSERVED REMAINING HEALTH: " << enemyremaininghealth << endl;
		cout << "\n";
		
		for (;;)
		{
			cout << "Would you like to restart, continue or exit?" << "\n" << "INPUT: - RESTART or CONTINUE or EXIT - in capitals" << endl;
			cin >> loop_termination_confirmer_1;

			if (loop_termination_confirmer_1 == "CONTINUE")
				{
				flag = true;
				break;
				}

			else if (loop_termination_confirmer_1 == "RESTART")
				break;

			else if (loop_termination_confirmer_1 == "EXIT") return 0;
			else cout << "ERROR - PLEASE PROVIDE A CORRECT INPUT" << "\n\n" << endl;

		}

		cin.ignore(1000, '\n');
	}
	while (!flag);
	flag = false;
	cout << "\n\n\n\n" << endl;
	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	// THIS SECTION WILL RUN A FOR LOOP A FIXED NUMBER OF TIMES AND COLLECT ACTIONS THE ENEMY PERFORMS
	//
	cout << "Please enter the Actions that you have seen the enemy perform. \n" << endl;
	for (int i = 1; i <= action_count; i++)
	{
		cout << "ACTION: " << i << endl;
		if (i == 1) getline(cin, action1); 
		else if (i == 2) getline(cin, action2); 
		else if (i == 3) getline(cin, action3); 
		else if (i == 4) getline(cin, action4); 

		
	}
	cout << "\n\n" << endl;
	cout << "\n\n" << endl;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	// THIS SECTION COLLECTS THE RANGES OF EACH ACTION
	//
	cout << border_short << border_short << endl;
	cout << "Please enter the observed distance of each action.\n";
    cout << "If the action did not reach any distance, enter 0.\n";
    cout << "Decimal values are recommended.\n";
	cout << border_short << border_short << endl;
	cout << "\n\n" << endl;
	for (int i = 1; i <= action_count; i++) {
        while (true) {
            if (i == 1) cout << "Range of Action 1 (" << action1 << "): ";
            else if (i == 2) cout << "Range of Action 2 (" << action2 << "): ";
            else if (i == 3) cout << "Range of Action 3 (" << action3 << "): ";
            else if (i == 4) cout << "Range of Action 4 (" << action4 << "): ";

            if (cin >> range_value_holder) { // VALIDATES INPUTS
                if (i == 1) range_1_m = range_value_holder;
                else if (i == 2) range_2_m = range_value_holder;
                else if (i == 3) range_3_m = range_value_holder;
                else if (i == 4) range_4_m = range_value_holder;
				
                break; // exit the while loop
            } 

			else {
				cin.clear();			// fixes the failstate
				cin.ignore(1000, '\n'); 
                cout << "INVALID INPUT! Please enter a decimal value.\n";
				cout << "If you would like to retry, enter any input, otherwise, type exactly \"EXIT\" to end the program." << endl;
				cin >> end_or_continue;
				if (end_or_continue == "EXIT")
					return 0;
                cin.clear();
                cin.ignore(1000, '\n'); 
            }
        }
    }

	cout << "\n\n" << endl;
	cout << "\n\n" << endl;

	// THIS SECTION CALCULATES THE AVERAGE
	//
	if (action_count == action_count_boss)
		average_range_m = (range_1_m + range_2_m + range_3_m + range_4_m) / action_count;  // this line calculates the average range of the enemy actions	
	else if (action_count == action_count_elite)
		average_range_m = (range_1_m + range_2_m + range_3_m) / action_count; 
	else if (action_count == action_count_major)
		average_range_m = (range_1_m + range_2_m) / action_count; 
	else if (action_count == action_count_minor)
		average_range_m = range_1_m; 
	recommended_safe_distance_m = average_range_m * safe_distance_multiplier;        // this line calculates the recommended safe distance from the enemy



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



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



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	/////////////////////////////////////////////////////////////////////////////////////

	// MENU SELECTION - SWITCH VERSION
	
	/////////////////////////////////////////////////////////////////////////////////////
	//

	while (true)
		{
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
			if (!(cin >> menu_choice)){
				cout << "INVALID INPUT. PLEASE ENTER A VALID INTEGER VALUE." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}

			cin.ignore(1000, '\n');
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

					cout << "Type anything in the terminal to continue: " << endl;
					cin >> end_or_continue;

					break;


				case 2:
					cout << "YOU HAVE SELECTED TO REVIEW YOUR INPUT CHOICES" << endl;
					cout << " " << endl;
					cout << "GAME PROVIDED: " << game << endl;
					cout << "RACE PROVIDED: " << enemyrace << endl;
					cout << "CLASSIFICATION PROVIDED: " << enemyclassification << endl;
					cout << "OBSERVED REMAINING HEALTH: " << enemyremaininghealth << endl;
					cout << "OBSERVED ACTION 1: " << action1 << endl;
					cout << "OBSERVED ACTION 2: " << action2 << endl;
					cout << "OBSERVED ACTION 3: " << action3 << endl;
					cout << "OBSERVED ACTION 4: " << action4 << endl;
					cout << "RANGE OF ACTION 1: " << range_1_m << " meters" << endl;
					cout << "RANGE OF ACTION 2: " << range_2_m << " meters" << endl;
					cout << "RANGE OF ACTION 3: " << range_3_m << " meters" << endl;
					cout << "RANGE OF ACTION 4: " << range_4_m << " meters" << endl;
					cout << " " << endl;

					cout << "Type anything in the terminal to continue: " << endl;
					cin >> end_or_continue;

					break;


				case 3:
					cout << "YOU HAVE SELECTED TO EXIT THE PROGRAM. THANK YOU FOR USING THE ENEMY DOCUMENTOR!" << endl;
					return 0;


				default:
					cout << "INVALID MENU OPTION. PLEASE INPUT EITHER CHOICES 1, 2, 3." << endl;		
			}
			
		}
	return 0;
}

