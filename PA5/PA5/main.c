#include "header.h"
// this is the main function which checks the players choice and launches the code based on players choice
int main(void)
{
	int count = 0,
		choice = 0; // initialization expression
	srand((unsigned int)time(NULL));

	do
	{
		print_menu();
		choice = game_choice();

		if (choice == 1)
		{
			print_game_rules();
			choice = 0;
		}
		else if (choice == 2)
		{
			play_game();
		}
		else if (choice == 3)
		{
			printf("Have a good one");
		}
	} while (choice < DISPLAY || choice > EXIT); // input validation

	printf("Thanks for playing");
	return 0;

	// process_choice(choice);


	// system("cls"); //windows system call for clearing the screen
	/*
	if (1 == option)
	{
		printf("display the rules \n");
		print_game_rules;

	}
	else if (2 == option)
	{
		printf("Playing the game! \n");

	}
	else
	{
		printf("Exiting!\n");

	}
	*/
	return 0;
}