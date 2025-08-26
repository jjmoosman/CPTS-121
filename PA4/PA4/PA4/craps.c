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
	int die1 = 0, die2 = 0, sum = 0, choice = 0, wager = 0, balance = 0,
		points = 0, adjust = 0;
	choice = 0;

	balance = get_bank_balance();
	do
	{
		wager = get_wager_amount();

		wager = check_wager_amount(wager, balance);


		die1 = roll_die();
		die2 = roll_die();

		sum = calculate_sum_dice(die1, die2);
		printf("Sum of dice %d\n", sum);
		points = is_win_loss_or_point(sum);
		if (points == 1)
		{
			balance = adjust_bank_balance(balance, wager, points);
		}
		else if (points == -1)
		{
			is_point_loss_or_neither(sum, points);
			balance = adjust_bank_balance(balance, wager, points);
		}
		else if (points == 0)
		{
			balance = adjust_bank_balance(balance, wager, points);
		}
		choice = get_choice(choice, balance);

	} while (balance != 0 && choice != 2);
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
	printf("A Player rolls two dice. Each die has six face.\n");
	printf("these faces contain 1, 2, 3, 4, 5, & 6 spots. he sum of the spots on the two upward faces is calculated\n");
	printf("If the sum is 7 or 11 on the first throw, the player wins. if the sum is 2, 3, or 12 on the first throw(called craps), the player loses\n");
	printf("if the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the players ""point"" \n");
	printf("To win, you must continue rolling the dice until you make your point, the player looses by rolling a 7 before making the point\n");

}

// this gets a user created balance for the game to make wagers on winning or loosing a round.
double get_bank_balance(void)
{
	double balance = 0.0;
	printf("Please enter your starting balance: ");
	scanf("%lf", &balance);
	printf("Current Balance: %.2lf\n", balance);
	return balance;
}

// this function gets an input from the user for a wager then sends it to check wager after entering an ammount.
double get_wager_amount(void)
{
	double wager = 0;
	printf("Please enter your wager ammount:  ");
	scanf("%lf", &wager);

	return wager;
}

// this function checks the overall wager amount to see if it is greater than the balance and if so it will have the user re-enter a wager until they enter a value smaller or equal to the balance
int check_wager_amount(double wager, double balance)
{
	if (wager >= balance)
	{
		while (wager > balance) 
		{
			printf("Wager is to high, Exceeds balance\n");
			wager = get_wager_amount();

		}
		return wager;
	}
	else
	{
		printf("Wager is within balance\n");
		return wager;
	}
	
}


/*
calling sran(seated random)
sets the starting point random to something different every time
should only call srand() once period do not call again
*/

// this function rolls the dice 
int roll_die(void)
{
	return rand() % 6 + 1;

}

// this takes the dice values rolled and sums them up and returns them to the function
int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum = 0;

	sum = die1_value + die2_value;

	return sum;
}

// this function checks to see if the player wins, loses, or gets a point in which it then sends down to check if the player wins the point or loses
int is_win_loss_or_point(int sum_dice)
{
	int point = 0, dicepoint = 0;
	if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		printf("Player rolled a %d and the house wins!\n", sum_dice);
		point = 0;
		return point;
	}
	else if (sum_dice == 7 || sum_dice == 11)
	{
		printf("Player Wins with a roll of %d\n", sum_dice);
		point = 1;
		return point;
	}
	else
	{
		printf("Player's Point: %d\n", sum_dice);

		dicepoint = sum_dice;
		point = -1;
		return is_point_loss_or_neither(sum_dice, dicepoint);
	}

}

// this function runs when the player returns point where they roll 
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	int die1 = 0, die2 = 0;
	do
	{
		sum_dice = 0;
		printf("Rolling dice\n");
		die1 = roll_die();
		die2 = roll_die();
		sum_dice = die1 + die2;
		printf("Rolled %d\n", sum_dice);

	} while (sum_dice != 7 && sum_dice != point_value);

	if (sum_dice == 7)
	{
		printf("House Wins the point\n");
		point_value = 0;
		return point_value;
	}
	else if(sum_dice == point_value)
	{
		printf("Player has won the point!\n");
		point_value = 1;
		return point_value;

	}
	else
	{
		printf("Something went wrong");
		point_value = -1;
		return point_value;
	}


}

// this function checks to see weather the player has won or lost the round of craps
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	double new_balance = 0.0;
	if (add_or_subtract == 1)
	{
		printf("Congrats you won!\n");
		new_balance = bank_balance + wager_amount;
		printf("New Balance: %.2lf\n", new_balance);
		return new_balance;
	}
	else if (add_or_subtract == 0)
	{
		printf("Better luck next time.\n");
		new_balance = bank_balance - wager_amount;
		printf("New Balance: %.2lf\n", new_balance);
		return new_balance;
	}

}

// this checks to see if the user wants to continue playing after the first round or if they wish to exit the game
int get_choice(int choice, int balance)
{
	if (balance != 0)
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
	else
	{
		return 2;
	}
}

// this function was supposed to add in some chatter and conversation into the game to keep it lively 
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{

	do
	{


	} while (current_bank_balance != 0);

}


