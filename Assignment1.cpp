


//*************************************************************************************************************************
//
// WELCOME TO MY COMBATANT DOCUMENTOR PROGRAM! (WEEK 7 - STRUCT VERSION)
// This program collects data about an enemy encountered in a video game, makes a nice summary of all the information 
// provided and calculated then stores it in a text file and offers a menu choice of the following 3 options:
// 1 to view the summary, 2 to view all given inputs, and 3 to end the program.
//
//*************************************************************************************************************************
//
// You will choose how many enemies u observed (Up to 10)
//
// You will provide the following information:
// - Name of the game being played
// - Race of the enemy encountered
// - Classification of the enemy (BOSS, ELITE, MAJOR, MINOR)
// - Remaining health of the enemy when first encountered
// - The Weakness of the enemy
// - The Nature of the enemy
// - The Maturity of the enemy
// - The Height of the enemy
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
#include <windows.h>

// GLOBAL NAMESPACE
using namespace std; // allows the user to use cout, cin, and endl without std::

// GLOBAL KILLSWITCH VARIABLES
bool flag = false;					// THIS ONE KILLS LOOPS
bool killswitch = false;			// THIS ONE KILLS THE PROGRAM
string end_or_continue;				// THIS ONE ASKS THE USER IF THEY WANT TO KILL SOMETHING


// GLOBAL STRUCT
struct Combatant
	{
		// THESE ARE THE MEMBERS OF COMBATANT
		string Game = "";						// this variable stores the name of the game
		string Race = "";					// this variable stores the name of the enemy
		string Classification = ""; 		// this variable stores the classification of the enemy	
		string Weakness = "";			// The Observed or known weakness of this combatant
		string Nature = "";
		string Maturity = "";

		int MaximumHealth = 0;
		int ObservedHealth = 0;		// this variable stores the observed health of the enemy
		int ActionCount = 0;
		int DamageDone = 0;

		double Height = 0.0;
		double AverageRange = 0.0;				// this variable stores the calculated average range of the enemy actions
		double Recommended_Safe_Distance = 0.0; // this variable stores the calculated recommended safe distance from the enemy

		string ActionNameValues[4] = { "None", "None", "None", "None" };			// THIS ARRAY WILL STORE THE ACTION NAMES BASED ON THE CLASSIFICATION
		double ActionRangeValues[4] = { 0.0 , 0.0 , 0.0 , 0.0 };		// THIS ARRAY WILL STORE THE ACTION RANGES BASED ON THE CLASSIFICATION

		
	};









// CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  
// CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  
// CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  // CHANGE COLOR  

void setcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}











// PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  
// PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  
// PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  // PRODUCE BANNER  

void banner(){
	const string border_long = "==============================================================";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl; 
	// this line creates space at the top of the console window for better formatting	
	// this section welcomes the user to the program
	//
	cout << border_long << endl;
	cout << setfill(' ') << setw(50) << right << "WELCOME TO MY ENEMY ACTION DOCUMENTOR!" << endl;
	cout << border_long << endl;
	cout << "\n\n" << endl;	
};











// GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  
// GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  
// GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  // GET GAME TYPE  

string get_gametype(){
	string para_gamename;
	// this section collects the game being played from the user
	//
	cout << "PLEASE PROVIDE THE NAME OF THE GAME YOU ARE PLAYING?: ";
	getline(cin, para_gamename);
	cout << "GAME PROVIDED: " << para_gamename << endl;
	cout << "\n\n" << endl;
	return para_gamename;
};








// GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  
// GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  
// GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  // GET ENEMY RACE  

string get_enemyrace(){
	string para_enemyrace;
	// this section collects the enemy race from the user
	//
	cout << "WHAT IS THE NAME OF THE RACE OF THE ENEMY YOU ENCOUNTERED?: ";
	getline(cin, para_enemyrace); 
	cout << "RACE PROVIDED: " << para_enemyrace << endl;
	cout << "\n\n" << endl;
	return para_enemyrace;
};










// GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  
// GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  
// GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  // GET CLASSIFICATION  

string get_classification(){
	string para_enemyclassification;

		// THIS SECTION COLLECTS THE ENEMY CLASSIFICATION FROM THE USER AND ENSURES IT IS CORRECT USING A LOOP
		// IT ALSO SETS THE ACTION COUNT

		string end_or_continue1;

		enum EnemyClassifications { BOSS, ELITE, MAJOR, MINOR } EnemyClassificationchoice;


		do
		{
			flag = true;
			cout << "WHAT IS THE CLASSIFICATION OF THE ENEMY?  |  OPTIONS ARE: BOSS, ELITE, MAJOR, MINOR  |  : (USE CAPITAL LETTERS ONLY) :";
			getline(cin, para_enemyclassification);
			cout << "\n\n" << endl;
			
			if (para_enemyclassification == "BOSS") {
				EnemyClassificationchoice = BOSS;
			}
			else if (para_enemyclassification == "ELITE") {
				EnemyClassificationchoice = ELITE;
			}
			else if (para_enemyclassification == "MAJOR") {
				EnemyClassificationchoice = MAJOR;
			}
			else if (para_enemyclassification == "MINOR") {
				EnemyClassificationchoice = MINOR;
			};

			if (EnemyClassificationchoice == BOSS) {
				cout << "YOU HAVE SELECTED THE BOSS CLASSIFICATION. ";
			}
			else if (EnemyClassificationchoice == ELITE) {
				cout << "YOU HAVE SELECTED THE ELITE CLASSIFICATION. ";
			}
			else if (EnemyClassificationchoice == MAJOR) {
				cout << "YOU HAVE SELECTED THE MAJOR CLASSIFICATION. ";
			}
			else if (EnemyClassificationchoice == MINOR) {
				cout << "YOU HAVE SELECTED THE MINOR CLASSIFICATION. ";
			};
			// this section provides a warning message based on the enemy classification
			//
			if (para_enemyclassification == "BOSS" || para_enemyclassification == "ELITE") cout << "THIS IS A LARGE THREAT! CONSIDER AVOIDING IT" << endl;
			else if (para_enemyclassification == "MAJOR" || para_enemyclassification == "MINOR") cout << "THIS ENEMY IS QUITE MANAGABLE AND NOT AS MUCH OF A THREAT" << endl;
			
			// this section validates the enemy classification input to ensure it is one of the 4 accepted options
			//
			if (para_enemyclassification != "BOSS" && para_enemyclassification != "ELITE" && para_enemyclassification != "MAJOR" && para_enemyclassification != "MINOR") {
				cout << "The INPUT received does not match the requirements. \n If you would like to retry, enter any input, otherwise, type exactly \"EXIT\" to end the program." << endl;
				getline(cin, end_or_continue1);
				if (end_or_continue1 == "EXIT")
					{
					killswitch = true;
					break;
					}
				flag = false;
			}
		}
		while (!flag);
		flag = false;
		cout << "\n\n" << endl;
		return para_enemyclassification;
};









// GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  
// GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  
// GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  // GET DAMAGEDONE  

int observedhealth(string para_classification2, int &enemyremaininghealth, int &health_storage_review){
	
	const int health_boss = 100;		// These variables will be used to state the known maximum health of a combatant based on its classification
	const int health_elite = 75;		//
	const int health_major = 50;		//
	const int health_minor = 25;		//
	const int health_zero = 0;	

	int maximum_enemyhealth = 0;		// this variable stores the initial full health of the enemy
	int damagedone = 0;					// this variable stores the calculated damage done to the enemy


	if (para_classification2 == "BOSS") {
		maximum_enemyhealth = health_boss;
		health_storage_review = health_boss;
	}
	else if (para_classification2 == "ELITE") {
		maximum_enemyhealth = health_elite;
		health_storage_review = health_elite;
	}
	else if (para_classification2 == "MAJOR") {
		maximum_enemyhealth = health_major;
		health_storage_review = health_major;
	}
	else if (para_classification2 == "MINOR") {
		maximum_enemyhealth = health_minor;
		health_storage_review = health_minor;
	}

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
			if (para_classification2 == "BOSS" && enemyremaininghealth >= health_zero && enemyremaininghealth <= health_boss){
				flag = true;
			}
			else if (para_classification2 == "ELITE" && enemyremaininghealth >= health_zero && enemyremaininghealth <= health_elite){
				flag = true;
			}
			else if (para_classification2 == "MAJOR" && enemyremaininghealth >= health_zero && enemyremaininghealth <= health_major){
				flag = true;
			}
			else if (para_classification2 == "MINOR" && enemyremaininghealth >= health_zero && enemyremaininghealth <= health_minor){
				flag = true;
			}
			}
		
		if(!flag)
		{
			cout << "\n\n" << endl;
			cout << "The INPUT received does not match the requirements. \n If you would like to retry, enter any input, otherwise, type exactly \"EXIT\" to end the program." << endl;
			cin >> end_or_continue;
			if (end_or_continue == "EXIT"){
				killswitch = true;
				break;
			}
		}

		cin.clear();				// THIS ALLOWS CIN TO TAKE INPUT AGAIN, REVERTING ITS FAILED STATE.
		cin.ignore(1000, '\n');
	}
	while (!flag);					// END OF THE LOOP
	flag = false;					// RESETS THE LOOP KILL SWITCH
	damagedone = maximum_enemyhealth - enemyremaininghealth;
	return damagedone;
};











string get_weakness(){

	string EnemyWeakness;
	cout << "What is the weakness of this enemy?: " << endl;
	cout << "Weakness: ";
	getline(cin, EnemyWeakness);
	cout << endl;
	return EnemyWeakness;
}

string get_Nature(){

	string EnemyNature;
	cout << "What is the Nature of this enemy?" << endl;
	cout << "(Example: Aggressive, Passive, Cautious..)" << endl;
	cout << "Nature: ";
	getline(cin, EnemyNature);
	cout << endl;
	return EnemyNature;

}

string get_Maturity(){

	string EnemyMaturity;
	cout << "What is the Maturity of this enemy?" << endl;
	cout << "(Example: Child, Adult, Elder, Ancient)" << endl;
	cout << "Maturity: ";
	getline(cin, EnemyMaturity);
	cout << endl;
	return EnemyMaturity;
}

double get_Height(){
	
	double EnemyHeight;
	while (true)
	{
		cout << "What is the Height (in feet) of this enemy? (Provide either an integer or decimal value)" << endl;
		cout << "Height: ";
		

		if (cin >> EnemyHeight) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Wrong Input. Please Provide a proper Heigh in numeric terms (integer or decimal values)" << endl;
		};
	}
	cout << endl;
	return EnemyHeight;
}


// GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT
// GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT
// GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT  // GET ACTION COUNT
int get_actioncount(string para_enemyclassification){

	
	const int action_count_boss = 4;
	const int action_count_elite = 3;	
	const int action_count_major = 2;	
	const int action_count_minor = 1;

	int action_count;
	if (para_enemyclassification == "BOSS") {
		action_count = action_count_boss;
	}
	else if (para_enemyclassification == "ELITE") {
		action_count = action_count_elite;
	}
	else if (para_enemyclassification == "MAJOR") {
		action_count = action_count_major;
	}
	else if (para_enemyclassification == "MINOR") {
		action_count = action_count_minor;
	}

	return action_count;
}










// GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  
// GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  
// GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  // GET ACTIONS  

void get_actions(int action_count, string (&ActionNameValues)[4]){

	string value_dump;
	string confirm_actions;

	while (true){

		// THIS SECTION WILL RUN A FOR LOOP A FIXED NUMBER OF TIMES AND COLLECT ACTIONS THE ENEMY PERFORMS
		//
		cout << "Please enter the Actions that you have seen the enemy perform. \n" << endl;
		for (int i = 0; i < action_count; i++)
		{
			cout << "ACTION: " << i + 1 << endl;
			getline(cin, value_dump); 
			ActionNameValues[i] = value_dump;
		}
		cout << "\n\n" << endl;
		cout << "\n\n" << endl;
		cout << "You have entered the following actions: " << endl;
		for (int i = 0; i < action_count; i++)
		{
			cout << "ACTION " << i + 1 << ": " << ActionNameValues[i] << endl;
		}
		cout << "Are you happy with your actions? [ Y  or  N ]" << endl;
		cout << "Y = continue    |     N = redo" << endl;
		getline(cin, confirm_actions);

		if (confirm_actions == "Y") break;
	}
	
};









// GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  
// GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  
// GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  // GET RANGES  

double get_ranges(string para_enemyclassification, string (&ActionNameValues)[4], double (&ActionRangeValues)[4], int action_count){ 

	double Value_dump = 0.0;
	double Total_range = 0.0;
	const string border_short = "=============================";   
	double average_range_m = 0.0;

	// THIS SECTION COLLECTS THE RANGES OF EACH ACTION
	//
	cout << border_short << border_short << endl;
	cout << "Please enter the observed distance of each action.\n";
    cout << "If the action did not reach any distance, enter 0.\n";
    cout << "Decimal values are recommended.\n";
	cout << border_short << border_short << endl;
	cout << "\n\n" << endl;
	for (int i = 0; i < action_count; i++) {
		if (flag) break;
        while (true) {
            cout << "ENTER THE RANGE OF ACTION " << i + 1 << " ( " << ActionNameValues[i] << " ) IN METERS: ";

            if (cin >> Value_dump) { // VALIDATES INPUTS
                ActionRangeValues[i] = Value_dump;
				
                break; // exit the while loop
            } 

			else {
				cin.clear();			// fixes the failstate
				cin.ignore(1000, '\n'); 
                cout << "INVALID INPUT! Please enter a decimal value.\n";
				cout << "If you would like to retry, enter any input, otherwise, type exactly \"EXIT\" to end the program." << endl;
				cin >> end_or_continue;
				if (end_or_continue == "EXIT"){
					killswitch = true;
					flag = true;
					break;
				}
                cin.clear();
                cin.ignore(1000, '\n'); 
            }
        }
    }

	cout << "\n\n" << endl;
	cout << "\n\n" << endl;

	// THIS SECTION CALCULATES THE AVERAGE
	//
	for (int i = 0; i < action_count; i++) {
		Total_range += ActionRangeValues[i];
	}
	average_range_m = Total_range / action_count;
	return average_range_m;

};









// OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  
// OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  
// OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  // OUTPUT REPORTFILE  

void reportfile(Combatant Enemy[10], int CombatantCount){
	

	ofstream outdata;	
	

	const string border_mega_long_thin = "------------------------------------------------------------------------------------------------------------------";
	const string border_mega_long = "==================================================================================================================";
	// this section outputs all collected and calculated data to a text file
	// it will provide a nice summary of all the information gathered from the user and upload it to "report.txt"
	//
	outdata.open("report.txt");  // this line opens the file for input operations

	for (int J = 0; J < CombatantCount; J++)
	{
		outdata << "\n\n" << endl;
		outdata << border_mega_long << endl;
		outdata << setw(76) << "SUMMARY OF THE ENEMY #" << J + 1 << endl;
		outdata << border_mega_long << endl;
		outdata << endl << endl;
		outdata << left << setw(30) << "GAME" << setw(30) << "RACE" << setw(30) << "CLASSIFICATION" << setw(30) << "HEALTH MISSING" << endl;
		outdata << border_mega_long_thin << endl;
		outdata << left << setw(30) << Enemy[J].Game << setw(30) << Enemy[J].Race << setw(30) << Enemy[J].Classification << setw(30) << Enemy[J].DamageDone << endl;
		outdata << endl << endl;
		outdata << left << setw(30) << "WEAKNESS" << setw(30) << "NATURE" << setw(30) << "MATURITY" << setw(30) << "HEIGHT" << endl;
		outdata << border_mega_long_thin << endl;
		outdata << left << setw(30) << Enemy[J].Weakness << setw(30) << Enemy[J].Nature << setw(30) << Enemy[J].Maturity << setw(30) << Enemy[J].Height << endl;
		outdata << endl << endl;
		outdata << left << setw(30) << "ACTION 1 + Distance" << setw(30) << "ACTION 2 + Distance" << setw(30) << "ACTION 3 + Distance" << setw(30) << "ACTION 4 + Distance" << endl;
		outdata << border_mega_long_thin << endl;
		outdata << left << setw(30) << Enemy[J].ActionNameValues[0] << setw(30) << Enemy[J].ActionNameValues[1] << setw(30) << Enemy[J].ActionNameValues[2] << setw(30) << Enemy[J].ActionNameValues[3] << endl;
		outdata << left << setprecision(2) << fixed << setw(30) << Enemy[J].ActionRangeValues[0] << setw(30) << Enemy[J].ActionRangeValues[1] << setw(30) << Enemy[J].ActionRangeValues[2] << setw(30) << Enemy[J].ActionRangeValues[3] << endl;
		outdata << endl;
		outdata << right << setw(75) << "AVERAGE RANGE OF ACTIONS (IN METERS)" << endl;
		outdata << setprecision(2) << fixed << right << setw(34) << Enemy[J].AverageRange << " meters " << "  |  " << "Recommended safe distance: " << Enemy[J].Recommended_Safe_Distance << " meters" << endl;
		outdata << " " << endl;
	}

	outdata << border_mega_long << endl;
	outdata << right << setw(80) << "THANK YOU FOR USING THE INFORMATION PROVIDED!" << endl;
	outdata << right << setw(88) << "it will be documented immediately for future players to use!" << endl;
	outdata << border_mega_long << endl;
	outdata << " " << endl;

	outdata.close();  // this line closes the file after input operations are complete
};









// MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  
// MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  
// MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  // MENU - SELECTION  

void openmenu(Combatant Enemy[10], int CombatantCount){

	int menu_choice;



	enum MenuOptions { VIEW_SUMMARY = 1, REVIEW_INPUTS = 2, EXIT_PROGRAM = 3 } MenuOptionchoice;
	
	/////////////////////////////////////////////////////////////////////////////////////

	// MENU SELECTION - SWITCH VERSION
	
	/////////////////////////////////////////////////////////////////////////////////////
	

	const string border_mega_long_thin = "------------------------------------------------------------------------------------------------------------------";
	const string border_mega_long = "==================================================================================================================";
	const string border_long = "==============================================================";

	while (true)
		{


			if (flag) break;

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
			MenuOptionchoice = static_cast<MenuOptions>(menu_choice);
			cin.ignore(1000, '\n');
			// this section processes the menu choice using a switch statement
			//
			switch (MenuOptionchoice)
			{
				case VIEW_SUMMARY:
					cout << "YOU HAVE SELECTED TO VIEW THE SUMMARY." << endl;
					//
					// this section outputs all collected and calculated data to the console
					// it will provide a nice summary of all the information gathered from the user and display it in the temrinal window
					//
					for (int J = 0; J < CombatantCount; J++)
					{
						cout << "\n\n" << endl;
						cout << border_mega_long << endl;
						cout << setw(76) << "SUMMARY OF THE ENEMY #" << J + 1 << endl;
						cout << border_mega_long << endl;
						cout << endl << endl;
						cout << left << setw(30) << "GAME" << setw(30) << "RACE" << setw(30) << "CLASSIFICATION" << setw(30) << "HEALTH MISSING" << endl;
						cout << border_mega_long_thin << endl;
						cout << left << setw(30) << Enemy[J].Game << setw(30) << Enemy[J].Race << setw(30) << Enemy[J].Classification << setw(30) << Enemy[J].DamageDone << endl;
						cout << endl << endl;
						cout << left << setw(30) << "WEAKNESS" << setw(30) << "NATURE" << setw(30) << "MATURITY" << setw(30) << "HEIGHT" << endl;
						cout << border_mega_long_thin << endl;
						cout << left << setw(30) << Enemy[J].Weakness << setw(30) << Enemy[J].Nature << setw(30) << Enemy[J].Maturity << setw(30) << Enemy[J].Height << endl;
						cout << endl << endl;
						cout << left << setw(30) << "ACTION 1 + Distance" << setw(30) << "ACTION 2 + Distance" << setw(30) << "ACTION 3 + Distance" << setw(30) << "ACTION 4 + Distance" << endl;
						cout << border_mega_long_thin << endl;
						cout << left << setw(30) << Enemy[J].ActionNameValues[0] << setw(30) << Enemy[J].ActionNameValues[1] << setw(30) << Enemy[J].ActionNameValues[2] << setw(30) << Enemy[J].ActionNameValues[3] << endl;
						cout << left << setprecision(2) << fixed << setw(30) << Enemy[J].ActionRangeValues[0] << setw(30) << Enemy[J].ActionRangeValues[1] << setw(30) << Enemy[J].ActionRangeValues[2] << setw(30) << Enemy[J].ActionRangeValues[3] << endl;
						cout << endl;
						cout << right << setw(75) << "AVERAGE RANGE OF ACTIONS (IN METERS)" << endl;
						cout << setprecision(2) << fixed << right << setw(34) << Enemy[J].AverageRange << " meters " << "  |  " << "Recommended safe distance: " << Enemy[J].Recommended_Safe_Distance << " meters" << endl;
						cout << " " << endl;
					};

					cout << border_mega_long << endl;
					cout << right << setw(80) << "THANK YOU FOR USING THE INFORMATION PROVIDED!" << endl;
					cout << right << setw(88) << "it will be documented immediately for future players to use!" << endl;
					cout << border_mega_long << endl;
					cout << " " << endl;

					cout << "Type anything in the terminal to continue: " << endl;
					cin >> end_or_continue;

					break;


				case REVIEW_INPUTS:
					cout << "YOU HAVE SELECTED TO REVIEW YOUR INPUT CHOICES" << endl;

					for (int J = 0; J < CombatantCount; J++)
					{	
						cout << "ENEMY #" << J+1 << endl;
						cout << " " << endl;
						cout << "GAME PROVIDED: " << Enemy[J].Game << endl;
						cout << "RACE PROVIDED: " << Enemy[J].Race << endl;
						cout << "CLASSIFICATION PROVIDED: " << Enemy[J].Classification << endl;
						cout << "OBSERVED REMAINING HEALTH: " << Enemy[J].ObservedHealth << endl;
						cout << "OBSERVED ACTION 1: " << Enemy[J].ActionNameValues[0] << endl;
						cout << "OBSERVED ACTION 2: " << Enemy[J].ActionNameValues[1] << endl;
						cout << "OBSERVED ACTION 3: " << Enemy[J].ActionNameValues[2] << endl;
						cout << "OBSERVED ACTION 4: " << Enemy[J].ActionNameValues[3] << endl;
						cout << "RANGE OF ACTION 1: " << Enemy[J].ActionRangeValues[0] << " meters" << endl;
						cout << "RANGE OF ACTION 2: " << Enemy[J].ActionRangeValues[1] << " meters" << endl;
						cout << "RANGE OF ACTION 3: " << Enemy[J].ActionRangeValues[2] << " meters" << endl;
						cout << "RANGE OF ACTION 4: " << Enemy[J].ActionRangeValues[3] << " meters" << endl;
						cout << " " << endl;
					}
					cout << "Type anything in the terminal to continue: " << endl;
					cin >> end_or_continue;

					break;


				case EXIT_PROGRAM:
					cout << "YOU HAVE SELECTED TO EXIT THE PROGRAM. THANK YOU FOR USING THE ENEMY DOCUMENTOR!" << endl;
					
					flag = true;
					break;


				default:
					cout << "INVALID MENU OPTION. PLEASE INPUT EITHER CHOICES 1, 2, 3." << endl;		
			}
			
		}
}









int main() {

	int CombatantCount = 0;

	while (true){

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "THIS PROGRAM GIVES YOU THE CHOICE TO DETERMINE THE AMOUNT OF ENEMIES YOU WISH TO DOCUMENT (1 REQUIRED | UP TO 10)." << endl;
		cout << "CHOOSE AN INTEGER AMOUNT. (THE LARGER THE NUMBER, THE LONGER THE PROGRAM TAKES TO FINISH) " << endl;

		if (cin >> CombatantCount && CombatantCount > 0 && CombatantCount <= 10)
			break;
		else{
			cout << "Choose a proper amount" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

	};



	//*************************************************************************************************************************
	// This section declares all the variables used in the main function
	//*************************************************************************************************************************

	string loop_termination_confirmer_1;	// THIS VARIABLE WILL BE USED TO CONFIRM IF THE USER WANTS TO RESTART THE INPUT PROCESS


	int maximum_enemyhealth = 0;		// this variable stores the initial full health of the enemy
	int enemyremaininghealth = 0;		// this variable stores the remaining health of the enemy after being attack once
	int damagedone = 0;					// this variable stores the calculated damage done to the enemy
	int action_count = 0;				// THIS VARIABLE STORES THE ACTION COUNT OF THE ENEMY BASED ON THE CLASSIFICATION


	int health_storage_review;			// THIS STORES THE MAX HEALTH OF THE ENEMY BASED ON THE CLASSIFICATION. IT WILL BE USED DURING THE REVIEW

	const double safe_distance_multiplier = 2.0; // THIS CONSTANT MULTIPLIER WILL BE USED TO CALCULATE THE RECOMMENDED SAFE DISTANCE

	Combatant Enemy[10];				// THIS IS MY ENEMY ARRAY THAT HOLDS 10 COMBATANT OBJECTS/INSTANCES.
	//*************************************************************************************************************************





	//******************************************************************************************************************
	// The section below contains the main code of the program
	//******************************************************************************************************************






	for (int J = 0; J < CombatantCount; J++)
	{
		cin.clear();
		cin.ignore(1000, '\n');

		do
		{


			setcolor(12);			// changes color to red


			// THIS FUNCTION PRODUCES THE WELCOME BANNER
			banner();


			setcolor(10);			// chances color to green


			// THIS FUNCTION ASKS THE USER TO PROVIDE THE NAME OF THE GAME
			Enemy[J].Game = get_gametype();
			

			setcolor(9);			// changes color to blue


			// THIS FUNCTION ASKS THE USER TO PROVIDE THE ENEMY RACE
			Enemy[J].Race = get_enemyrace();
			

			setcolor(5);			// changes color to magenta


			// THIS FUNCTION ASKS THE USER TO PROVIDE THE ENEMY CLASSIFICATION
			Enemy[J].Classification = get_classification();	
			if (killswitch == true) return 0;

			setcolor(3);			// changes color to cyan


			// THIS FUNCTION ASKS THE USER TO PROVIDE THE REMAINING HEALTH OF THE ENEMY
			Enemy[J].DamageDone = observedhealth(Enemy[J].Classification, Enemy[J].ObservedHealth, Enemy[J].MaximumHealth);
			if (killswitch == true) return 0;


			setcolor(13);			// changes color to light magenta
			cout << endl;
			Enemy[J].Weakness = get_weakness();

			setcolor(5);

			Enemy[J].Nature = get_Nature();
			
			setcolor(3);

			Enemy[J].Maturity = get_Maturity();

			setcolor(9);

			Enemy[J].Height = get_Height();

			setcolor(10);

			// THIS SECTION ASKS THE USER TO CONFIRM IF THE INPUTS ARE CORRECT OR IF THEY WANT TO RESTART
			cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "PLEASE REVIEW THE FOLLOWING INFORMATION AND DECIDE IF YOU WISH TO PROCEED." << endl;
			cout << "GAME PROVIDED: " << Enemy[J].Game << endl;
			cout << "RACE PROVIDED: " << Enemy[J].Race << endl;
			cout << "CLASSIFICATION PROVIDED: " << Enemy[J].Classification << endl;
			cout << "MAXIMUM HEALTH OF THE " << Enemy[J].Classification << ": " << Enemy[J].MaximumHealth << endl;
			cout << "WEAKNESS PROVIDED: " << Enemy[J].Weakness << endl;
			cout << "NATURE PROVIDED: " << Enemy[J].Nature << endl;
			cout << "MATURITY PROVIDED: " << Enemy[J].Maturity << endl;
			cout << "HEIGHT PROVIDED: " << Enemy[J].Height << " ft." << endl;
			cout << "OBSERVED REMAINING HEALTH: " << Enemy[J].ObservedHealth << endl;
			cout << "\n";
			
			for (;;)
			{
				cout << "Would you like to restart, continue or exit?" << "\n" << "INPUT: - RESTART or CONTINUE or EXIT - in capitals" << endl;
				cin >> loop_termination_confirmer_1;

				cin.clear();
				cin.ignore(1000, '\n');

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
		
		
		// THIS FUNCTION DETERMINES THE ACTION COUNT BASED ON THE ENEMY CLASSIFICATION
		Enemy[J].ActionCount = get_actioncount(Enemy[J].Classification);	

		
		// THIS FUNCTION ASKS THE USER TO PROVIDE ACTIONS OBSERVED BASED ON THE CLASSIFICATION
		get_actions(Enemy[J].ActionCount, Enemy[J].ActionNameValues);


		setcolor(3);			// changes color to cyan


		// THIS FUNCTION ASKS THE USER TO PROVIDE RANGES FOR THE ACTIONS
		Enemy[J].AverageRange = get_ranges(Enemy[J].Classification, Enemy[J].ActionNameValues, Enemy[J].ActionRangeValues, Enemy[J].ActionCount);
		if (killswitch == true) return 0;
		Enemy[J].Recommended_Safe_Distance = Enemy[J].AverageRange * safe_distance_multiplier;   // THIS CALCULATES THE RECOMMENDED SAFE DISTANCE

	};

	// THIS FUNCTION OUTPUTS THE REPORT FILE
	reportfile(Enemy, CombatantCount);
	

	setcolor(10);			// changes color to green


	// THIS FUNCTION OPENS THE MENU SELECTION
	openmenu(Enemy, CombatantCount);


	return 0;
}