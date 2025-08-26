#include "header.h"

// this prints the main game menu for the user to pick a choice.
void print_menu(void)
{

	printf("1. Display rules.\n");
	printf("2. Play the Game of Battleship.\n");
	printf("3. Exit.\n");

}

// this checks to see what the users choice is in regards to rules, playing the game, and exiting
int game_choice(void)
{
	int choice = 0;
	scanf(" %d", &choice);
	system("cls");
	return choice;

}

// this is the main function of the game and runs all of the processes to play the game.
void play_game(void)
{
	Direction dir = HORIZ;
	Cordinate start_pt = { -1, -1 };
	Cordinate attack_pt = { -1, -1 };
	FILE* infile = fopen("Game_Log.txt", "r"), * outfile = fopen("Game_Log.txt", "w");
	srand((unsigned int)time(NULL));
	int choice = 0, ply1_score = 0, ply2_score = 0, count = 0, turn = 0, check = 1, player_score = 0, bot_score = 0;
	char player_board[10][10] = { {'\0', '\0'}, {'\0'} }, bot_board[10][10] = { {'\0', '\0'}, {'\0'} }, bot_board2[10][10] = { {'\0', '\0'}, {'\0'} };
	int player_tally[8] = { NULL }, bot_tally[8] = { NULL }; // These are for keeping track of the total score of the player 0 - 4 will be for all five of the ships and the last two digets are for hits and misses.
	int player_win = 0, bot_win = 0, phit = 0, pmiss = 0, bhit = 0, bmiss = 0, track = 0;
	char hit = 'X', miss = 'm';

	printf("Player's Board\n");
	init_board(player_board, 10, 10);
	print_board(player_board, 10, 10);

	printf("Bots Board\n");
	init_board(bot_board, 10, 10);
	print_board(bot_board, 10, 10);
	init_board(bot_board2, 10, 10);
	printf("To place ships manually enter 1, to auto place enter 2\n");

	do
	{
		scanf("%d", &choice);
		if (choice == 1)
		{

			// this is for the main cruser.
			do
			{
				dir = get_dir_man();
				start_pt = get_start_pt(5, dir, 10, 10);
				check = check_ships_man(player_board, 10, 10, 'C', 5, dir, start_pt);
			} while (check != 1);
			system("pause");
			system("cls");
			place_ships_man(player_board, 10, 10, 'C', 5, dir, start_pt);
			print_board(player_board, 10, 10);

			// this is for the battleship
			do
			{
				dir = get_dir_man();
				start_pt = get_start_pt(4, dir, 10, 10);
				check = check_ships_man(player_board, 10, 10, 'B', 4, dir, start_pt);
			} while (check != 1);
			system("pause");
			system("cls");
			place_ships_man(player_board, 10, 10, 'B', 4, dir, start_pt);
			print_board(player_board, 10, 10);

			// this is for submarine
			do
			{
				dir = get_dir_man();
				start_pt = get_start_pt(3, dir, 10, 10);
				check = check_ships_man(player_board, 10, 10, 'S', 3, dir, start_pt);
			} while (check != 1);
			system("cls");
			place_ships_man(player_board, 10, 10, 'S', 3, dir, start_pt);
			print_board(player_board, 10, 10);

			// this places the carrier
			do
			{
				dir = get_dir_man();
				start_pt = get_start_pt(3, dir, 10, 10);
				check = check_ships_man(player_board, 10, 10, 'R', 3, dir, start_pt);
			} while (check != 1);
			system("cls");
			place_ships_man(player_board, 10, 10, 'R', 3, dir, start_pt);
			print_board(player_board, 10, 10);

			// this places the destroyer
			do
			{
				dir = get_dir_man();
				start_pt = get_start_pt(2, dir, 10, 10);
				check = check_ships_man(player_board, 10, 10, 'D', 2, dir, start_pt);
			} while (check != 1);
			system("cls");
			place_ships_man(player_board, 10, 10, 'D', 2, dir, start_pt);
			print_board(player_board, 10, 10);
			system("pause");
			system("cls");
		}
		else if (choice == 2)
		{
			// this is for rand cruiser check & placement
			do
			{
				dir = get_dir();
				start_pt = gen_start_pt(5, dir, 10, 10);
				check = check_ships(player_board, 10, 10, 'C', 5, dir, start_pt);
			} while (check != 1);
			place_ships(player_board, 10, 10, 'C', 5, dir, start_pt);
			// this is for rand battleship check & placement
			do
			{
				dir = get_dir();
				start_pt = gen_start_pt(4, dir, 10, 10);
				check = check_ships(player_board, 10, 10, 'B', 4, dir, start_pt);
			} while (check != 1);
			place_ships(player_board, 10, 10, 'B', 4, dir, start_pt);
			//this is for rand submarine check & placement
			do
			{
				dir = get_dir();
				start_pt = gen_start_pt(3, dir, 10, 10);\
				check = check_ships(player_board, 10, 10, 'S', 3, dir, start_pt);
			} while (check != 1);
			place_ships(player_board, 10, 10, 'S', 3, dir, start_pt);
			// this is for rand carrier check & placement
			do
			{
				dir = get_dir();
				start_pt = gen_start_pt(3, dir, 10, 10);
				check = check_ships(player_board, 10, 10, 'R', 3, dir, start_pt);
			} while (check != 1);
			place_ships(player_board, 10, 10, 'R', 3, dir, start_pt); // R is for carrier to mke it less confusing for names 
			//this is for rand destroyer check & placement
			do
			{
				dir = get_dir();
				start_pt = gen_start_pt(2, dir, 10, 10);
				check = check_ships(player_board, 10, 10, 'D', 2, dir, start_pt);

			} while (check != 1);
			place_ships(player_board, 10, 10, 'D', 2, dir, start_pt);

			system("pause");
			system("cls");
		}
		else
		{
			printf("Invalid choice selected please choose 1 for manual placement or 2 for auto placement.\n");
			choice = 0;
		}
	} while (choice < 1 || choice > 2);

	//
	// This goes through and prints out the bots board
	//

	// this is for rand cruiser check & placement
	
	do
	{
		dir = get_dir();
		start_pt = gen_start_pt(5, dir, 10, 10);
		check = check_ships(bot_board, 10, 10, 'C', 5, dir, start_pt);
	} while (check != 1);
	place_ships(bot_board, 10, 10, 'C', 5, dir, start_pt);
	// this is for rand battleship check & placement
	do
	{
		dir = get_dir();
		start_pt = gen_start_pt(4, dir, 10, 10);
		check = check_ships(bot_board, 10, 10, 'B', 4, dir, start_pt);
	} while (check != 1);
	place_ships(bot_board, 10, 10, 'B', 4, dir, start_pt);
	//this is for rand submarine check & placement
	do
	{
		dir = get_dir();
		start_pt = gen_start_pt(3, dir, 10, 10); \
		check = check_ships(bot_board, 10, 10, 'S', 3, dir, start_pt);
	} while (check != 1);
	place_ships(bot_board, 10, 10, 'S', 3, dir, start_pt);
	// this is for rand carrier check & placement
	do
	{
		dir = get_dir();
		start_pt = gen_start_pt(3, dir, 10, 10);
		check = check_ships(bot_board, 10, 10, 'R', 3, dir, start_pt);
	} while (check != 1);
	place_ships(bot_board, 10, 10, 'R', 3, dir, start_pt); // R is for carrier to mke it less confusing for names 
	//this is for rand destroyer check & placement
	do
	{
		dir = get_dir();
		start_pt = gen_start_pt(2, dir, 10, 10);
		check = check_ships(bot_board, 10, 10, 'D', 2, dir, start_pt);

	} while (check != 1);
	place_ships(bot_board, 10, 10, 'D', 2, dir, start_pt);
	// this shows the player ship locations and the bots blank board used to track hits or misses
	printf("Player Ship Locations\n");
	print_board(player_board, 10, 10);
	printf("Hit or miss board\n");
	print_board(bot_board2, 10, 10);
	// These can be used to help the tester test ship rand locations of bots along with progressing through faster for testing-----------------------------------------
	/*printf("Bot Ship Locations\n");
	print_board(bot_board, 10, 10);*/
	//The code above is used to cheat and finish the match quicker-----------------------------------------------------------------------------------------------------
	system("pause");
	system("cls");
	
	// this randomly picks a number to decide who goes first
	turn = rand() % 2;

	// this function runs through the entire game until either player sinks all five of the enemy's ships.
	do
	{
		if (turn == 1)
		{
			printf("hit or miss board\n");
			print_board(bot_board2, 10, 10);
			// this can be used to test and speed up the overall game --------------------------------------------------------------------------------------------------
			/*printf("Bot board\n");
			print_board(bot_board, 10, 10);*/
			//The code above is used to cheat and finish the match quicker ---------------------------------------------------------------------------------------------
			do
			{
				attack_pt = attack(10, 10);
				check = check_hit_or_miss(bot_board, attack_pt, 10, 10);
			} while (check != 1);
			system("cls");
			fprintf(outfile, "Players turn and progress report\n");
			hit_or_miss(bot_board, player_tally, attack_pt, 10, 10, outfile);
			update_bot_board(bot_board, bot_board2, attack_pt);
			printf("Bot board hit or miss\n");
			printf("Bot Board\n");
			print_board(bot_board2, 10, 10);

			//These here can be used to check the spaces of the bots ships to speed things up and to test the code.------------------------------------------------------
			/*printf("Bot cheat board\n");
			print_board(bot_board, 10, 10);*/
			//The code above is used to cheat and finish the match quicker-----------------------------------------------------------------------------------------------
			progress(player_tally, outfile, attack_pt);
			fprintf(outfile, "------------------------------------------------------------------------\n");
			system("pause");
			system("cls");
			turn = turn - 1;

		}
		else
		{
			do
			{
				attack_pt = attack_bot(10, 10);
				check = check_hit_or_miss_bot(player_board, attack_pt, 10, 10);
			} while (check != 1);
			system("cls");
			printf("Bot is attacking\n");
			fprintf(outfile, "Bots turn and progress report\n");
			hit_or_miss_bot(player_board, bot_tally, attack_pt, 10, 10, outfile);
			printf("Player's board\n");
			print_board(player_board, 10, 10);
			progress(bot_tally, outfile, attack_pt);
			fprintf(outfile, "------------------------------------------------------------------------\n");
			system("pause");
			system("cls");
			turn = turn + 1;
		}
		player_score = player_tally[5];
		bot_score = bot_tally[5];
		printf("Player Score: %d\n", player_score);
		printf("Bot Score: %d\n", bot_score);
		count++;
	} while ((player_score < 17) && (bot_score < 17));
	// this checks at the end to see who won the match and also prints the number of turns taken by both players total.
	printf("Total Rounds: %d\n", count);

	if (player_score == 17)
	{
		player_tally[7] = 1;
		printf("Player 1 wins the game\n");
	}
	else
	{
		bot_tally[7] = 1;
		printf("The bot has won the game\n");
	}
	// this is where the end of match stats are saved and logged to the game log text file
	fprintf(outfile, "Bots end of match stats\n");
	game_stats(outfile, bot_tally);
	fprintf(outfile, "------------------------------------------------------------------------\n");
	fprintf(outfile, "Player end of match stats\n");
	game_stats(outfile, player_tally);
	system("pause");
	system("cls");
	play_again(choice);
}

// this function prints the games rules for the user
void print_game_rules(void)
{
	printf("The object of Battleship is to try and sink all of the bots's ships before they sink all of your ships.\n");
	printf("All of the bots ships are somewhere on its board. \n");
	printf("You try and hit them by calling out the coordinates of one of the squares on the board. \n");
	printf("The bot also tries to hit your ships by calling out coordinates. Neither you nor the bot can see the other's board so you must try to guess where they are. \n");
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("Each player places the 5 ships somewhere on their board. The ships can only be placed vertically or horizontally.\n");
	printf("Diagonal placement is not allowed. No part of a ship may hang off the edge of the board. \n");
	printf("Ships may not overlap each other. No ships may be placed on another ship. \n");
	printf("The 5 ships are:  Carrier (occupies 5 spaces), Battleship (4), Cruiser (3), Submarine (3), and Destroyer (2). \n");
	printf("------------------------------------------------------------------------------------------------------------- \n");
	printf("The player and the bot take turns guessing by calling out the coordinates. if you hit any of the bots ships you will be told which ones you are hitting \n");
	printf("If you dont manage to hit anything the bot will let you know that you missed. \n");
	printf("When all of the squares that one your ships occupies have been hit, the ship will be sunk. \n");
	printf("When this happens you will be notified on which ship has sank. This also applies to the bots ships and you will know which ones you have sunk.\n");
	printf("As soon as all of the players ships or the bots ships have been sunk, the game ends. \n");

}

// this checks to see if the user wants to continue playing after the first round or if they wish to exit the game
int play_again(int choice)
{
	printf("Would you Like to play again? 1: Yes, 2 No:  ");

	do
	{
		scanf("%d", &choice);

		if (choice == 2)
		{
			printf("Thanks for playing!");
			exit(0x1);
		}
		else if (choice == 1)
		{
			system("cls");
			play_game();
		}
	} while (choice != 1 && choice != 2);
}

// this sets the values of the board to ~ on the board
void init_board(char board[][10], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

// this prints the players board for the game of battleship
void print_board(char board[][10], int num_rows, int num_cols)
{
	/*
	*   0 1 2 3
	* 0 ~ ~ b
	* 1 ~ ~ b
	*/

	int row_index = 0, col_index = 0;

	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (; row_index < num_rows; ++row_index)
	{
		printf("%d", row_index);
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("%2c", board[row_index][col_index]);
		}

		putchar('\n');
	}
}


// randomly get a direction for the ships direction
Direction get_dir(void)
{

	return(Direction)(rand() % 2);

}

// this function gets the players manual input for direction for the ship placement.
Direction2 get_dir_man(void)
{
	int direct = 0;

	printf("Please enter a direction 1 is North, 2 is South, 3 is East, 4 is west\n");
	scanf("%d", &direct);
	direct = direct - 1;
	if (direct > -1 && direct < 4)
	{
		return(Direction2)(direct);
	}
	else
	{
		printf("the number you entered is out of range\n");
		get_dir_man();
	}

}

// gets the starting point for the ship
Cordinate gen_start_pt(int ship_length, Direction dir, int num_rows, int num_colums)
{
	Cordinate start_pt = { -1, -1 };

	if (dir == VERT)
	{
		start_pt.row = rand() % num_rows;
		start_pt.colum = rand() % (num_colums - ship_length + 1);
	}
	else
	{
		start_pt.row = rand() % (num_rows - ship_length + 1);
		start_pt.colum = rand() % num_colums;
	}

	return start_pt;
}
//
// This function gets a manual starting direction
//
Cordinate get_start_pt(int ship_length, Direction2 dir, int num_rows, int num_colums)
{
	int x = 0, y = 0;
	printf("Please enter the x cordinate and the y cordinate to place the ship in the bounds of 0 - 9\n");
	scanf("%d", &x);
	scanf("%d", &y);

	Cordinate start_pt = { -1, -1 };
	if ((x < 0 || x > 9) && (y < 0 || y > 9))
	{
		printf("The Value you entered is out of range\n");
		system("pause");
		system("cls");
		get_start_pt(ship_length, dir, num_rows, num_colums);
	}
	else if (dir == NORTH)
	{
		start_pt.row = y;
		start_pt.colum = x;
		return start_pt;
	}
	else if (dir == SOUTH)
	{
		start_pt.row = y;
		start_pt.colum = x;
		return start_pt;
	}
	else if (dir == EAST)
	{
		start_pt.row = y;
		start_pt.colum = x;
		return start_pt;
	}
	else if (dir == WEST)
	{
		start_pt.row = y;
		start_pt.colum = x;
		return start_pt;
	}




}

// this is the random generation function for placing ships
void place_ships(char board[][10], int num_rows, int num_colums, char symbol, int length, Direction dir, Cordinate start_pt)
{
	int count = 0;

	if (dir == VERT)
	{
		for (count = 0; count < length; ++count)
		{
			board[start_pt.row + count][start_pt.colum] = symbol;
		}
	}
	else
	{
		for (count = 0; count < length; ++count)
		{
			board[start_pt.row][start_pt.colum + count] = symbol;
		}
	}

}

// this function checks to make sure the random generated ships are not overlaping or going out of bounds
int check_ships(char board[][10], int num_rows, int num_colums, char symbol, int length, Direction dir, Cordinate start_pt)
{
	int count = 0;

	if (dir == VERT)
	{
		for (count = 0; count < length; ++count)
		{
			if (board[start_pt.row][start_pt.colum] != '~')
			{
				return 0;
			}
			else if (board[start_pt.row + count][start_pt.colum] != '~')
			{
				return 0;
			}
			else if (start_pt.row < -1 + length || start_pt.row > 10)
			{
				return 0;
			}
			else
			{
				board[start_pt.row + count][start_pt.colum];
			}
		}
		return 1;
	}
	else
	{
		for (count = 0; count < length; ++count)
		{
			if (board[start_pt.row][start_pt.colum] != '~')
			{
				return 0;
			}
			else if (board[start_pt.row][start_pt.colum + count] != '~')
			{
				return 0;
			}
			else if (start_pt.colum > 10 - length)
			{
				return 0;
			}
			else
			{
				board[start_pt.row][start_pt.colum + count];
			}
		}
		return 1;
	}

}

// this funtcion is used for manual placement of ships
void place_ships_man(char board[][10], int num_rows, int num_colums, char symbol, int length, Direction2 dir, Cordinate start_pt)
{
	int count = 0;

	if (dir == NORTH)
	{

		for (count = 0; count < length; ++count)
		{
			board[start_pt.row - count][start_pt.colum] = symbol;
		}
	}
	else if (dir == SOUTH)
	{
		for (count = 0; count < length; ++count)
		{
			board[start_pt.row + count][start_pt.colum] = symbol;
		}
	}
	else if (dir == EAST)
	{
		for (count = 0; count < length; ++count)
		{
			board[start_pt.row][start_pt.colum + count] = symbol;
		}
	}
	else if (dir == WEST)
	{
		for (count = 0; count < length; ++count)
		{
			board[start_pt.row][start_pt.colum - count] = symbol;
		}
	}

}

// this function checks to make sure ships are not going out of bounds
int check_ships_man(char board[][10], int num_rows, int num_colums, char symbol, int length, Direction2 dir, Cordinate start_pt)
{
	int count = 0;

	if (dir == NORTH)
	{

		for (count = 0; count < length; ++count)
		{
			//board[start_pt.row - count][start_pt.colum];
			if (board[start_pt.row][start_pt.colum] != '~')
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else if (board[start_pt.row - count][start_pt.colum] != '~')
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else if (start_pt.row < -1 + length || start_pt.row > 10)
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else 
			{
				board[start_pt.row - count][start_pt.colum];
			}

		}
		return 1;
	}
	else if (dir == SOUTH)
	{
		for (count = 0; count < length + 1; ++count)
		{
			if (board[start_pt.row][start_pt.colum] != '~')
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else if (board[start_pt.row + count][start_pt.colum] != '~')
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else if (start_pt.row < 0 || start_pt.row > 10 - length)
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else
			{
				board[start_pt.row + count][start_pt.colum];
			}
		}
		return 1;
	}
	else if (dir == EAST)
	{
		for (count = 0; count < length; ++count)
		{
			if (board[start_pt.row][start_pt.colum] != '~' )
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else if (board[start_pt.row][start_pt.colum + count] != '~')
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else if (start_pt.colum > 10 - length)
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else
			{
				board[start_pt.row][start_pt.colum + count];
			}
		}
		return 1;
	}
	else if (dir == WEST)
	{
		for (count = 0; count < length; ++count)
		{
			if (board[start_pt.row][start_pt.colum] != '~')
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship");
				count == length;
				return 0;
			}
			else if (board[start_pt.row][start_pt.colum - count] != '~')
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else if (start_pt.colum < 0 + length)
			{
				printf("The ship has either gone out of bounds or is overlaping with another ship\n");
				count == length;
				return 0;
			}
			else
			{
				board[start_pt.row][start_pt.colum - count];
			}

		}
		return 1;
	}

}

// this function gets the player's attack and checks to see if its in bounds
Cordinate attack(int num_rows, int num_colums)
{
	char hit = 'X', miss = 'm';
	int x = 0, y = 0, check = 1;
	Cordinate attack_pt = { -1, -1 };
	
	do
	{
		printf("Please enter an x and y cordinate for us to fire on\n");
		scanf("%d", &x);
		scanf("%d", &y);
		if ((x < 0 || x > 9) || (y < 0 || y > 9))
		{
			printf("Those cordinates are out of range sir\n");
			system("pause");
			system("cls");
			check = 0;
		}
		else
		{
			attack_pt.row = y;
			attack_pt.colum = x;
			check = 1;
		}
	} while (check != 1);

	return attack_pt;
}

// this function is for the bots attack points and checks to make sure its within the bounds of the board.
Cordinate attack_bot(int num_rows, int num_colums)
{
	char hit = 'X', miss = 'm';
	int x = 0, y = 0, check = 1;
	Cordinate attack_pt = { -1, -1 };
	do
	{
		x = rand() % 10;
		y = rand() % 10;
		if ((x < 0 || x > 9) && (y < 0 || y > 9))
		{
			check = 0;
		}
		else
		{
			attack_pt.row = y;
			attack_pt.colum = x;
			check = 1;
		}
	} while (check != 1);

	return attack_pt;
}

// this function checks to make sure that the player didnt enter a grid point already entered on the map if they have this will cause the function to loop and make them enter another cordinate.
int check_hit_or_miss(char board[][10],  Cordinate attack_pt, int num_rows, int num_colums)
{
	if ((board[attack_pt.row][attack_pt.colum] == 'X') || (board[attack_pt.row][attack_pt.colum] == 'm'))
	{
		printf("This position has already been fired apon please enter another cordinate on the grid.\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

// this function checks to make sure the bot didnt already call the grid point already and if it did it causes the bot to enter another random point on the grid.
int check_hit_or_miss_bot(char board[][10], Cordinate attack_pt, int num_rows, int num_colums)
{
	if ((board[attack_pt.row][attack_pt.colum] == 'X') || (board[attack_pt.row][attack_pt.colum] == 'm'))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// this function is used to check and see if the player hit a ship and track which one is hit and or to mark the misses of the player.
void hit_or_miss(char board[][10], int targets[], Cordinate attack_pt, int num_rows, int num_colums, FILE* outfile)
{
	if (board[attack_pt.row][attack_pt.colum] == 'C')
	{
		printf("Critical hit on the enemy cruiser\n");
		fprintf(outfile, "Critical hit on the enemy cruiser\n");
		board[attack_pt.row][attack_pt.colum] = 'X';
		++targets[0];
		++targets[5];
	}
	else if (board[attack_pt.row][attack_pt.colum] == 'B')
	{
		printf("Critical hit on the enemy battleship\n");
		fprintf(outfile, "Critical hit on the enemy battleship\n");
		board[attack_pt.row][attack_pt.colum] = 'X';
		++targets[1];
		++targets[5];
	}
	else if (board[attack_pt.row][attack_pt.colum] == 'S')
	{
		printf("Critical hit on the enemy submarine\n");
		fprintf(outfile, "Critical hit on the enemy submarine\n");
		board[attack_pt.row][attack_pt.colum] = 'X';
		++targets[2];
		++targets[5];
	}
	else if (board[attack_pt.row][attack_pt.colum] == 'R')
	{
		printf("Critical hit on the enemy carrier\n");
		fprintf(outfile, "Critical hit on the enemy carrier\n");
		board[attack_pt.row][attack_pt.colum] = 'X';
		++targets[3];
		++targets[5];
	}
	else if (board[attack_pt.row][attack_pt.colum] == 'D')
	{
		printf("Critical hit on the enemy destroyer\n");
		fprintf(outfile, "Critical hit on the enemy destroyer\n");
		board[attack_pt.row][attack_pt.colum] = 'X';
		++targets[4];
		++targets[5];
	}
	else
	{
		printf("We were unable to hit any of the ships\n");
		fprintf(outfile, "unable to hit any of the ships\n");
		board[attack_pt.row][attack_pt.colum] = 'm';
		++targets[6];
	}
}

// this function is for the bots hit or miss of the players ships.
void hit_or_miss_bot(char board[][10], int targets[], Cordinate attack_pt, int num_rows, int num_colums, FILE* outfile)
{
	if (board[attack_pt.row][attack_pt.colum] == 'C')
	{
		printf("Critical hit on the player's cruiser\n");
		fprintf(outfile, "Critical hit on the player's cruiser\n");
		board[attack_pt.row][attack_pt.colum] = 'X';
		++targets[0];
		++targets[5];
	}
	else if (board[attack_pt.row][attack_pt.colum] == 'B')
	{
		printf("Critical hit on the player's battleship\n");
		fprintf(outfile, "Critical hit on the player's battleship\n");
		board[attack_pt.row][attack_pt.colum] = 'X';
		++targets[1];
		++targets[5];
	}
	else if (board[attack_pt.row][attack_pt.colum] == 'S')
	{
		printf("Critical hit on the player's submarine\n");
		fprintf(outfile, "Critical hit on the player's submarine\n");
		board[attack_pt.row][attack_pt.colum] = 'X';
		++targets[2];
		++targets[5];
	}
	else if (board[attack_pt.row][attack_pt.colum] == 'R')
	{
		printf("Critical hit on the player's carrier\n");
		fprintf(outfile, "Critical hit on the player's carrier\n");
		board[attack_pt.row][attack_pt.colum] = 'X';
		++targets[3];
		++targets[5];
	}
	else if (board[attack_pt.row][attack_pt.colum] == 'D')
	{
		printf("Critical hit on the player's destroyer\n");
		fprintf(outfile, "Critical hit on the player's destroyer\n");
		board[attack_pt.row][attack_pt.colum] = 'X';
		++targets[4];
		++targets[5];
	}
	else
	{
		printf("The bot was unable to hit any of the ships\n");
		fprintf(outfile, "The bot was unable to hit any of the ships\n");
		board[attack_pt.row][attack_pt.colum] = 'm';
		++targets[6];
	}
}

//this function is used to update the hit or miss board that the player uses to guess locations on the grid to hit a target.
void update_bot_board(char board[][10], char board2[][10], Cordinate attack_pt)
{
	if(board[attack_pt.row][attack_pt.colum] == 'X')
	{
		board2[attack_pt.row][attack_pt.colum] = 'X';
	}
	else
	{
		board2[attack_pt.row][attack_pt.colum] = 'm';
	}
}

// this displays the progress of the game for each player displaying hits and misses along with what ships they have hit or sunk so far.
// this also checks to see if the player or bot has sunken the ship and if so it lets the user know as well as logging the event in the game_log.txt file
void progress(int list[], FILE* outfile, Cordinate attack_pt)
{

	printf("End of turn report\n");
	// this checks to see if the player or bot has sunken the cruiser
	if (list[0] < 5)
	{
		printf("Cruiser hits %d\n", list[0]);
	}
	else if(list[0] == 5)
	{
		printf("Cruser has been sunk\n");
		fprintf(outfile ,"Cruser has been sunk\n");
		list[0] = 6;
	}
	else
	{
		printf("Cruser has been sunk\n");
	}
	// this checks to see if the player or bot has sunken the battleship
	if (list[1] < 4)
	{
		printf("Battleship hits %d\n", list[1]);
	}
	else if (list[1] == 4)
	{
		printf("Battleship has been sunk\n");
		fprintf(outfile, "Battleship has been sunk\n");
		list[1] = 6;
	}
	else
	{
		printf("Battleship has been sunk\n");
	}
	// this checks to see if the player or bot has sunken the Submarine
	if (list[2] < 3)
	{
		printf("Submarine hits %d\n", list[2]);
	}
	else if (list[2] == 3)
	{
		printf("Submarine has been sunk\n");
		fprintf(outfile, "Submarine has been sunk\n");
		list[2] = 6;
	}
	else
	{
		printf("Submarine has been sunk\n");
	}
	// this checks to see if the player or bot has sunken the carrier
	if (list[3] < 3)
	{
		printf("Carrier hits %d\n", list[3]);
	}
	else if (list[3] == 3)
	{
		printf("Carrier has been sunk\n");
		fprintf(outfile, "Carrier has been sunk\n");
		list[3] = 6;
	}
	else
	{
		printf("Carrier has been sunk\n");
	}
	// this checks to see if the player or bot has sunken the destroyer
	if (list[4] < 2)
	{
		printf("Destroyer hits %d\n", list[4]);
	}
	else if (list[4] == 2)
	{
		printf("Destroyer has been sunk\n");
		fprintf(outfile, "Destroyer has been sunk\n");
		list[4] = 6;
		
	}
	else
	{
		printf("Destroyer has been sunk\n");
	}
	fprintf(outfile, "Attack x and y point: (%d, %d)\n", attack_pt.row, attack_pt.colum);
	printf("Hits %d\n", list[5]);
	printf("Misses %d\n", list[6]);
}

// this final function prints out both the player and bot stats after the game has ended.

void game_stats(FILE* outfile, int list[])
{
	double hit_miss_ratio = 0.0;
	int count = 0;
	fprintf(outfile, "End of game report\n");
	// this checks to see if the player or bot has sunken the cruiser
	if (list[0] < 5)
	{
		fprintf(outfile, "Cruiser hits %d\n", list[0]);
	}
	else
	{
		fprintf(outfile, "Destroyed the Cruser\n");
	}
	// this checks to see if the player or bot has sunken the battleship
	if (list[1] < 4)
	{
		fprintf(outfile, "Battleship hits %d\n", list[1]);
	}
	else
	{
		fprintf(outfile, "Destroyed the Battleship\n");
	}
	// this checks to see if the player or bot has sunken the carrier
	if (list[2] < 3)
	{
		fprintf(outfile, "Carrier hits %d\n", list[2]);
	}
	else
	{
		fprintf(outfile, "Destroyed the Carrier\n");
	}
	// this checks to see if the player or bot has sunken the submarine
	if (list[3] < 3)
	{
		fprintf(outfile, "Submarine hits %d\n", list[3]);
	}
	else
	{
		fprintf(outfile, "Destroyed the Submarine\n");
	}
	// this checks to see if the player or bot has sunken the destroyer
	if (list[4] < 2)
	{
		fprintf(outfile, "Destroyer hits %d\n", list[4]);
	}
	else
	{
		fprintf(outfile, "Destroyed the Destroyer\n");
	}
	// this prints the overall hits and misses
	fprintf(outfile, "Hits %d\n", list[5]);
	fprintf(outfile, "Misses %d\n", list[6]);
	// this checks the overall accuracy of the player and the bot at the end of the match
	if (list[5] == 0)
	{
		fprintf(outfile, "Missed everything with a total of %d, misses\n", list[6]);
	}
	else if (list[6] == 0)
	{
		fprintf(outfile, "GODLIKE all %d shots hit their mark destroying the enemy 100% Accuracy!\n", list[5]);
	}
	else
	{
		hit_miss_ratio = ((double)list[5] / (double)list[6]);
		hit_miss_ratio = hit_miss_ratio * 100;
		fprintf(outfile, "Hit/Miss ratio: %.2lf\n", hit_miss_ratio);
	}

	if (list[7] == 1)
	{
		fprintf(outfile, "Winner of the match\n");
	}
	else
	{
		fprintf(outfile, "Looser of the match\n");
	}
}