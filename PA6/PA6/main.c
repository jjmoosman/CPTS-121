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
			printf("Have a good one\n");
		}
		else if (choice != 1 || choice != 2 || choice != 3)
		{
			printf("Invalid choice please try again\n");
			choice = 0;
		}
	} while (choice < DISPLAY || choice > EXIT); // input validation

	printf("Now Exiting");
	return 0;
}