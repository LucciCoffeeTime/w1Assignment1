

#include <iostream> // This is the library required for cout and cin

int main() {

	using namespace std;			// allows the user to use cout, cin, and endl without std::


	//*************************************************************************************************************************
	// This section declares all the variables used in this program
	//*************************************************************************************************************************

	
	
	string game;				// this variable stores the name of the game
	string enemyrace;			// this variable stores the name of the enemy
	string enemyclassification;  // this variable stores the classification of the enemy	
	string action1;  			// this variable stores the first action of the enemy
	string action2;  			// this variable stores the second action of the enemy
	string action3;  			// this variable stores the third action of the enemy
	string action4;  			// this variable stores the fourth action of the enemy
	string action5;  			// this variable stores the fifth action of the enemy
	string action6;  			// this variable stores the sixth action of the enemy
	string action7;  			// this variable stores the seventh action of the enemy



	int enemyhealth = 10;			// this variable stores the initial full health of the enemy
	int enemyremaininghealth = 0;	// this variable stores the remaining health of the enemy after being attack once
	int damagedone = 0;			// this variable stores the calculated damage done to the enemy
	//*************************************************************************************************************************




	//******************************************************************************************************************
	// The section below contains the main code of the program
	//******************************************************************************************************************




	// this section instructs the user to input the required information and avoid using spaces
	cout << "Welcome to my enemy action documentor. - DO NOT USE SPACES - when answering any question" << endl;
	cout << " " << endl;


	// this section collects the game being played from the user
	cout << "What game are you playing?: ";
	cin >> game; 
	cout << " " << endl;


	// this section collects the enemy race from the user
	cout << "What is the race of the encountered enemy?: ";
	cin >> enemyrace; 
	cout << " " << endl;


	// this section collects the enemy classification from the user
	cout << "What is the classification of this enemy: BOSS, ELITE, MAJOR, MINOR?: ";
	cin >> enemyclassification;
	cout << " " << endl;


	// this section informs the user of the full health of the enemy
	cout << "The full health of this race is typically 10. ";
	cout << " " << endl;


	// this section collects the observed remaining health of the enemy from the user and calculates the damage done
	cout << "When you initially encounter this enemy, how much health did it have remaining? - (enter an amount between 1-10): ";
	cin >> enemyremaininghealth;
	damagedone = enemyhealth - enemyremaininghealth;
	cout << " " << endl;


	// this section collects 7 actions of the enemy from the user
	cout << "Please enter 7 - ACTIONS - you have seen the enemy perform." << endl;
	cin >> action1; 
	cin >> action2; 
	cin >> action3; 
	cin >> action4; 
	cin >> action5; 
	cin >> action6; 
	cin >> action7; 
	cout << " " << endl;
	cout << " " << endl;  // double spacing for readability


	// this section outputs all the collected information back to the user and thanks them for their input
	cout << "Thank you for the information." << endl;
	cout << " " << endl;
	cout << "You are playing: " << game << endl;
	cout << "You are fighting against a: " << enemyrace << endl; 
	cout << "It's classification is: " << enemyclassification << endl;
	cout << "The damage done to the enemy was observed to be: " << damagedone << endl;
	cout << "This enemy has the following actions: ";
	cout << action1 << ", " << action2 << ", " << action3 << ", " << action4 << ", " << action5 << ", " << action6 << ", " << action7 << endl;	
	cout << " " << endl;
	cout << "WOW, WHAT A FOE!" << endl;
	cout << "This information will be documented immediately!" << endl;  // this is a pseudo-confirmation message
	cout << "Goodbye!" << endl;
	
	//******************************************************************************************************************

	return 0;
}

