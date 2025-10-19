

#include <iostream> // This is the library required for cout and cin

int main() {

	using namespace std;			// allows the user to use cout, cin, and endl without std::

	string game;						// this variable stores the name of the game
	string enemyrace;					// this variable stores the name of the enemy
	string enemyclassification;  		// this variable stores the classification of the enemy	
	string attack1;  					// this variable stores the first action of the enemy
	string attack2;  					// this variable stores the second action of the enemy
	string attack3;  					// this variable stores the third action of the enemy
	string attack4;  					// this variable stores the fourth action of the enemy
	string attack5;  					// this variable stores the fifth action of the enemy
	string attack6;  					// this variable stores the sixth action of the enemy
	string attack7;  					// this variable stores the seventh action of the enemy

	// this section instructs the user to input the required information and avoid using spaces
	cout << "Welcome to my enemy action documentor. DO NOT USE SPACES - when answering any question" << endl;
	cout << " " << endl;

	// this section collects the game being played from the user
	cout << "What game are you playing?: ";
	cin >> game; 
	cout << " " << endl;

	// this section collects the enemy race from the user
	cout << "What enemy are you facing?: ";
	cin >> enemyrace; 
	cout << " " << endl;

	// this section collects the enemy classification from the user
	cout << "What is the classification of this enemy: BOSS, ELITE, MAJOR, MINOR?: ";
	cin >> enemyclassification;
	cout << " " << endl;

	// this section collects 7 actions of the enemy from the user
	cout << "Please enter 7 - ACTIONS - the enemy has been seen doing." << endl;
	cin >> attack1; 
	cin >> attack2; 
	cin >> attack3; 
	cin >> attack4; 
	cin >> attack5; 
	cin >> attack6; 
	cin >> attack7; 
	cout << " " << endl;
	cout << " " << endl;  // double spacing for readability

	// this section outputs all the collected information back to the user
	cout << "Thank you for the information." << endl;
	cout << " " << endl;
	cout << "You are playing: " << game << endl;
	cout << "You are fighting against a: " << enemyrace << endl; 
	cout << "It's classification is: " << enemyclassification << endl;
	cout << "This enemy has the following actions: " << endl;
	cout << attack1 << ", " << attack2 << ", " << attack3 << ", " << attack4 << ", " << attack5 << ", " << attack6 << ", " << attack7 << endl;	
	cout << " " << endl;
	cout << "This information will be documented!" << endl;  // this is a pseudo-confirmation message

	return 0;
}

