#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() function

using namespace std;

int main() {

	string weapon[3] = { "Rock", "Paper", "Scissors" }; // Declare and define this array to allow for reuse when informing the user of the choices behind the outcome
	int outcomes[3][3] = {
		{0, -1, 1}, /* When user selects Rock, it will be matched against the machine's choice: Rock = Draw, Paper = Loss, Scissor = Win*/
		{1, 0, -1}, /* When user selects Paper, it will be matched against the machine's choice: Rock = Win, Paper = Draw, Scissor = Loss*/
		{-1, 1, 0}  /* When user selects Scissor, it will be matched against the machine's choice: Rock = Loss, Paper = Win, Scissor = Draw*/
	};


	int round_num;                                 // This will be used count the number of rounds so far
	int machine_win_count = 0;                     // This will count how many wins the computer has in the rounds, initialised with 0
	int user_win_count = 0;                        // This will count the number of wins the user has, intialised with 0

	// Ask the user to enter their weapon of choice using the assigned numbers
	cout << "Select the weapon of your choice using the numbers as follows: " << "\n";
	

	// Create a loop that will continue going until you have played 3 rounds with the machine to determine the winner

	for (round_num = 1; round_num <= 3; round_num++) {

		srand(time(0));
		int machine_input = (rand() % 3);                       // Randomly generate a number within the range (0-2) used to select a weapon
		int user_input;


		// The do-while loop will ensure the user enters a number within the stated range (1 to 3)
		do {
			cout << "1 - Rock \n" << "2 - Paper \n" << "3 - Scissors \n\n";
			cin >> user_input;

			if (user_input < 1 || user_input > 3) {
				cout << "\n" << "Please select one of the numbers listed: " << "\n";
			}
		} while (user_input < 1 || user_input > 3);

		cout << "\n";

		user_input -= 1;             // This allows the user's input to be adjusted to the array index [0] to [2]
		switch (user_input) {
		case 0:
			cout << "You have selected " << weapon[user_input];
			break;
		case 1:
			cout << "You have selected " << weapon[user_input];
			break;
		case 2:
			cout << "You have selected " << weapon[user_input];
			break;
		}

		cout << "\n";

		// What did the machine choose?
		switch (machine_input) {
		case 0:
			cout << "The machine has selected " << weapon[machine_input];
			break;
		case 1:
			cout << "The machine has selected " << weapon[machine_input];
			break;
		case 2:
			cout << "The machine has selected " << weapon[machine_input];
			break;
		}

		cout << "\n\n";

		int result = outcomes[user_input][machine_input];
		if (result == 1) {
			cout << "You won round " << round_num;
			user_win_count++;
		}
		else if (result == -1) {
			cout << "You lost round " << round_num;
			machine_win_count++;
		}
		else {
			cout << "Draw for round " << round_num;
		}

		if (round_num < 3) {
			cout << "\n\n";
			cout << "Please select again for round " << round_num + 1;
			cout << "\n";
		}
	}
	cout << "\n\n";

	if (user_win_count > machine_win_count) {
		cout << "YOU WIN. WELL PLAYED!";
	}
	else if (machine_win_count < user_win_count) {
		cout << "YOU LOST :( \nWELL TRIED";
	}
	else {
		cout << "THE GAME HAS ENDED IN A DRAW";
	}

	cout << "\n";

	return 0; 

}