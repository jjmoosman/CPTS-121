#include "header.h"

// this prints the main game menu for the user to pick a choice.
void print_menu(void)
{

	printf("1. Display rules.\n");
	printf("2. Play the Game.\n");
	printf("3. Exit.\n");

}

// this checks to see what the users choice is in regards to rules, playing the game, and exiting
int game_choice(void)
{
	int choice = 0;
	scanf("%d", &choice);
	return choice;

}
/*
void process_choice(int choice)
{
	switch (choice)
	{
	case DISPLAY: printf("Rules\n"), print_game_rules();
		break;
	case PLAY:printf("Playing the game\n"), play_game();
		break;
	case EXIT: printf("Exiting\n");
		break;
	}
}
*/

// this is the main function of the game and runs all of the processes to play the game.
void play_game(void)
{
	int clear_die = 0, choice = 0, sum = 0,
		points = 0, adjust = 0, player1 = 0, player2 = 0, index = 0, input = NULL;
	int roll_dice[5], table[7] = {0};
	choice = 0;

	choice = 0;
	do
	{
		printf("Player One hit any key to continue\n");
		scanf(input);
		get_dice_roll(roll_dice, table);

		
		get_choice(choice);
	} while (choice != 2);
}

// this function checks to see if the user wants to continue the game or exit after playing the first round.
//int play_again(int choice)
//{
//	printf("Would you like to play another round? 1: Yes, 2: No\n");
//	scanf("&d", &choice);
//	return choice;
//}

// this function prints the games rules for the user
void print_game_rules(void)
{
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. \n");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. \n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. \n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. \n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. \n");
	printf("The lower section contains a number of poker like combinations. See the table provided below: \n");
	printf("	Name						Combination									score \n");
	printf("Three-of-a-kind			Three dice with the same face			Sum of all face values on the 5 dice	 \n");
	printf("Four-of-a-kind			Four dice with the same face			Sum of all face values on the five dice \n");
	printf("Full house				one pair and a three-of-a-kind							25 \n");
	printf("Small straight				A sequence of four dice								30 \n");
	printf("Large straight				A sequence of five dice								40 \n");
	printf("Yahtzee(five-of-a-kind)	Five dice with the same face							50 \n");
	printf("Chance				May be used for any sequence of dice;		Sum of all face values on the 5 dice \n");
}







int roll_die(void)
{
	int count = 0;
	do
	{
		rand() % 6 + 1;
		count++;

	} while (count != 5);

}

// this takes the dice values rolled and sums them up and returns them to the function
int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum = 0;

	sum = die1_value + die2_value;

	return sum;
}



// this checks to see if the user wants to continue playing after the first round or if they wish to exit the game
int get_choice(int choice)
{
	
	printf("Would you Like to play again? 1: Yes, 2: No :  ");

	do
	{
		scanf("%d", &choice);

		if (choice == 2)
		{
			return choice;
		}
		else if (choice == 1)
		{
			choice = 0;
			return choice;
		}
	} while (choice != 1 && choice != 2);
}

// this function was supposed to add in some chatter and conversation into the game to keep it lively 
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{

	do
	{


	} while (current_bank_balance != 0);

}


