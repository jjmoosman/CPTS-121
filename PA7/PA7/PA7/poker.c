#include "header.h"

// this prints the main game menu for the user to pick a choice.
void print_menu(void)
{

	printf("1. Display rules.\n");
	printf("2. Play the Game of Poker.\n");
	printf("3. Exit.\n");

}

// this checks to see what the users choice is in regards to rules, playing the game, and exiting
int game_choice(void)
{
	int choice = 0;
	scanf(" %d", &choice);
	return choice;

}

// this is the main function of the game and runs all of the processes to play the game.
void play_game(void)
{
	int choice = 0, card_count = 1, hand = 5, player_score = 0, bot_score = 0, check1 = 0, check2 = 0, sorta = 0, sortb = 0, check = 0;
	Hand player, temp;
	Hand Bot_hand, temp2;
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	shuffle(deck);
	player = deal_cards(deck, face, suit, &card_count, hand);
	printf("Test Card\n");
	player = draw_cards(deck, face, suit, &card_count, hand, player);
	// use this to check player hand values to make sure the game is working properly
	/*player.Array[0].face = 2;
	player.Array[1].face = 3;
	player.Array[2].face = 4;
	player.Array[3].face = 5;
	player.Array[4].face = 6;*/
	player = Sort_cards(player);

	system("cls");
	printf("Players new hand:\n");
	printf("%s of %s \n", face[player.Array[0].face], suit[player.Array[0].suit]);
	printf("%s of %s \n", face[player.Array[1].face], suit[player.Array[1].suit]);
	printf("%s of %s \n", face[player.Array[2].face], suit[player.Array[2].suit]);
	printf("%s of %s \n", face[player.Array[3].face], suit[player.Array[3].suit]);
	printf("%s of %s \n", face[player.Array[4].face], suit[player.Array[4].suit]);

	player_score = match_check(player);
	printf("Players Score: %d\n", player_score);

	system("pause");
	system("cls");

	Bot_hand = deal_bot_cards(deck, face, suit, &card_count, hand);
	Bot_hand = Sort_cards(Bot_hand);
	
	//used to check and see if the bot is working properly
	/*Bot_hand.Array[0].suit = 2;
	Bot_hand.Array[1].suit = 2;
	Bot_hand.Array[2].suit = 2;
	Bot_hand.Array[3].suit = 2;
	Bot_hand.Array[4].suit = 3;
	printf("Bots sorted Hand\n");
	printf("%s of %s \n", face[Bot_hand.Array[0].face], suit[Bot_hand.Array[0].suit]);
	printf("%s of %s \n", face[Bot_hand.Array[1].face], suit[Bot_hand.Array[1].suit]);
	printf("%s of %s \n", face[Bot_hand.Array[2].face], suit[Bot_hand.Array[2].suit]);
	printf("%s of %s \n", face[Bot_hand.Array[3].face], suit[Bot_hand.Array[3].suit]);
	printf("%s of %s \n", face[Bot_hand.Array[4].face], suit[Bot_hand.Array[4].suit]);*/
	
	bot_score = bot_match_check(Bot_hand);
	// this function is for if the bot doesnt have a pair or better
	check = almost_flush(Bot_hand);
	if (bot_score < 3 || check == 1 || check == 5)
	{
		Bot_hand = bot_draw_cards(deck, face, suit, &card_count, hand, Bot_hand);
		Bot_hand = Sort_cards(Bot_hand);
		/*printf("\n\nBots new sorted Hand\n");
		printf("%s of %s \n", face[Bot_hand.Array[0].face], suit[Bot_hand.Array[0].suit]);
		printf("%s of %s \n", face[Bot_hand.Array[1].face], suit[Bot_hand.Array[1].suit]);
		printf("%s of %s \n", face[Bot_hand.Array[2].face], suit[Bot_hand.Array[2].suit]);
		printf("%s of %s \n", face[Bot_hand.Array[3].face], suit[Bot_hand.Array[3].suit]);
		printf("%s of %s \n", face[Bot_hand.Array[4].face], suit[Bot_hand.Array[4].suit]);*/
		bot_score = bot_match_check(Bot_hand);
	}
	// sorts the bots hand again
	Bot_hand = Sort_cards(Bot_hand);
	//printf("Test checkpoint\n");

	printf("Players score: %d\n", player_score);
	printf("Bots score: %d\n", bot_score);
	if (player_score < bot_score)
	{
		printf("The house won the round\n");
	}
	else if (player_score > bot_score)
	{
		printf("Player has won the round\n");
	}
	else
	{
		printf("The round is a draw\n");
	}
	
	play_again(choice);
}

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

// this function prints the games rules for the user
void print_game_rules(void)
{
	printf("The dealer deals each player five cards, placing them face down.\n"
	"Every player picks up their cards from the table and checks out their hand while not revealing it to other players.\n"
	"Again, starting with the player to the dealer’s left.\n"
	"Wh those who are still in the hand get to trade in one, two, or three cards from their hand for new (and hopefully better) cards.\n"
	"After everyone receives their new cards, another round of betting takes place, starting to the dealer's left.\n"
	"After the betting is completed, players show their hands. The best hand wins.\n");
}

/* shuffle cards in deck */
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

// this function sorts the deck of the player or the bot
Hand Sort_cards(Hand user)
{
	Hand temp;
	int sorta = 0, sortb = 0;
	for (sorta = 0; sorta <= 5 - 1; sorta++)
	{
		for (sortb = sorta + 1; sortb < 5; sortb++)
		{
			if (user.Array[sorta].face > user.Array[sortb].face)
			{
				temp.Array[sorta] = user.Array[sorta];
				user.Array[sorta] = user.Array[sortb];
				user.Array[sortb] = temp.Array[sorta];
			}
		}
	}
	return user;
}

/* deal cards in deck to the player */
Hand deal_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], int *count, int card_max_draw)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int deck = 0;
	int i = 0;
	Hand ary;

	/* deal each of the 52 cards */
	for (card= 1; card <= card_max_draw; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == *count)
				{
					ary.Array[i].face = column;
					ary.Array[i].suit = row;
					i++;
					printf("Card: %d is a %5s of %-8s%c", i, wFace[column], wSuit[row], '\n');
					
				}
			}
		}
		*count = *count + 1;
	}
	return ary;
}

/* deals bot cards*/
Hand deal_bot_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], int* count, int card_max_draw)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int deck = 0;
	int i = 0;
	Hand ary;

	/* deal each of the 52 cards */
	for (card = 1; card <= card_max_draw; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == *count)
				{
					ary.Array[i].face = column;
					ary.Array[i].suit = row;
					i++;
				}
			}
		}
		*count = *count + 1;
	}
	return ary;
}

// this function is used to check to see if the player wants to draw new cards and if they do it overwrites the selected cards to change them.
Hand draw_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], int* count, int card_max_draw, Hand player)
{
	int choice = 0, index = 0, reroll_i = 0, new_card = 0, row = 0, column = 0;
	for (index = 0; index < 1; index++)
	{
		do
		{
			printf("Would you like to draw some new cards? If so enter how many you would like to change. if not enter 0\n");
			scanf("%d", &choice);
		} while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 0));

		if (choice != 0)
		{
			for (reroll_i = 1; reroll_i <= choice; reroll_i++)
			{
				/* loop through rows of wDeck */
				for (row = 0; row <= 3; row++)
				{
					/* loop through columns of wDeck for current row */
					for (column = 0; column <= 12; column++)
					{
						if (wDeck[row][column] == *count)
						{
							printf("Enter the number of the card you would like to replace: ");
							scanf("%d", &new_card);
							new_card = new_card - 1;
							player.Array[new_card].face = column;
							player.Array[new_card].suit = row;
							printf("%5s of %-8s%c", wFace[column], wSuit[row], '\n');
						}
					}
				}
				*count = *count + 1;
			}while ((new_card != 4) && (new_card != 3) && (new_card != 2) && (new_card != 1) && (new_card != 0));
		}
	}

	return player;
}

// this function is used so the bot can draw new cards if does not have a pair or better
Hand bot_draw_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], int* count, int card_max_draw, Hand bot)
{
	int choice = 0, index = 0, reroll_i = 0, new_card = 0, row = 0, column = 0, check = 0, check2 = 0, check3, random = 0;
	for (index = 0; index < 1; index++)
	{
		do
		{
			check = pairs(bot);
			check2 = almost_flush(bot);
			check3 = bot_check_three_of_or_full_house(bot);
			if (check == 2)
			{
				choice = 1;
			}
			else if (check == 1)
			{
				choice = 3;
			}
			else if (check == 0)
			{
				choice = 3;
			}
			else if (check2 == 1 || check2 == 5)
			{
				choice = 1;
			}
			else if (check3 == 2)
			{
				choice = 0;
			}
			else if (check3 == 1  || check3 == 4 || check3 == 5)
			{
				choice = 2;
			}
			else
			{
				random = 1;
				choice = 3;
			}
		} while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 0));

		if (choice != 0)
		{
			for (reroll_i = 1; reroll_i <= choice; reroll_i++)
			{
				/* loop through rows of wDeck */
				for (row = 0; row <= 3; row++)
				{
					/* loop through columns of wDeck for current row */
					for (column = 0; column <= 12; column++)
					{
						if (wDeck[row][column] == *count)
						{
							check = pairs_replace(bot);
							check3 = bot_check_three_of_or_full_house(bot);
							check2 = almost_flush(bot); 
							if (check == 5 || check2 == 5 || check3 == 5)
							{
								new_card = 5;
							}
							else if (check == 4 || check3 == 5)
							{
								new_card = 4;
							}
							else if (check == 3 || check3 == 3)
							{
								new_card = 3;
							}
							else if (check == 2)
							{
								new_card = 2;
							}
							else if (check == 1 || check3 == 1)
							{
								new_card = 1;
							}
							else if (check3 == 6)
							{
								new_card = 3;
							}
							else if (random = 1)
							{
								//printf("using the random select\n");
								new_card = rand() % 5;
								new_card++;
							}
							else
							{
								//printf("Something went wrong");
								new_card = rand() % 5;
								new_card++;
							}
							//printf("Card being replaced: %d", new_card);
							new_card = new_card - 1;
							bot.Array[new_card].face = column;
							bot.Array[new_card].suit = row;
							//printf("%5s of %-8s%c", wFace[column], wSuit[row], '\n');
							bot = Sort_cards(bot);
						}
					}
				}
				*count = *count + 1;
			}while ((new_card != 4) && (new_card != 3) && (new_card != 2) && (new_card != 1) && (new_card != 0));
		}
	}
	return bot;
}

// this function looks to see what the player has and returns a score value based on what it matches 
int match_check(Hand player)
{
	int check1 = 0, player_score = 0;

	check1 = straight(player);
	if (check1 == 1)
	{
		// four of a kind, full house, flush, straight, three of a kind, two pair, pair
		printf("Player has a straight!\n");
		player_score = 4;
		return player_score;
	}
	check1 = flush(player);
	if (check1 == 1 && (player_score == 0))
	{
		printf("Player has a flush!\n");
		player_score = 5;
		return player_score;
	}
	check1 = four_of_kind(player);
	if (check1 == 1 && (player_score == 0))
	{
		printf("Player has a four of a kind!\n");
		player_score = 7;
		return player_score;
	}
	check1 = three_of_or_full_house(player);
	if (check1 == 2 && (player_score == 0))
	{
		printf("Player has a full house!\n");
		player_score = 6;
		return player_score;
	}
	if (check1 == 1 && (player_score == 0))
	{
		printf("Player has a three of a kind!\n");
		player_score = 3;
		return player_score;
	}
	check1 = pairs(player);
	if (check1 == 2 && (player_score == 0))
	{
		printf("Player has two pairs!\n");
		player_score = 2;
		return player_score;
	}
	if (check1 == 1 && (player_score == 0))
	{
		printf("Player has a pair!\n");
		player_score = 1;
		return player_score;
	}
	if (player_score == 0)
	{
		printf("Players didnt have a good hand\n");
		return 0;
	}


}

// this function looks to see what the bot has and returns a score value based on what it matches
int bot_match_check(Hand bot)
{
	int check1 = 0, bot_score = 0;

	
	check1 = straight(bot);
	if (check1 == 1)
	{
		bot_score = 4;
		return bot_score;
	}
	check1 = flush(bot);
	if (check1 == 1 && (bot_score == 0))
	{
		bot_score = 5;
		return bot_score;
	}
	check1 = four_of_kind(bot);
	if (check1 == 1 && (bot_score == 0))
	{
		bot_score = 7;
		return bot_score;
	}
	check1 = three_of_or_full_house(bot);
	if (check1 == 2 && (bot_score == 0))
	{
		bot_score = 6;
		return bot_score;
	}
	if (check1 == 1 && (bot_score == 0))
	{
		bot_score = 3;
		return bot_score;
	}
	check1 = pairs(bot);
	if (check1 == 2 && (bot_score == 0))
	{
		bot_score = 2;
		return bot_score;
	}
	if (check1 == 1 && (bot_score == 0))
	{
		bot_score = 1;
		return bot_score;
	}
	
	return 0;
	


}

// this checks to see if the bot almost has a flush and will use this to choose a card based on whats not matching
int almost_flush(Hand bot)
{
	if (bot.Array[0].suit == bot.Array[1].suit && bot.Array[1].suit == bot.Array[2].suit && bot.Array[2].suit == bot.Array[3].suit)
	{
		return 5;
	}
	if (bot.Array[1].suit == bot.Array[2].suit && bot.Array[2].suit == bot.Array[3].suit && bot.Array[3].suit == bot.Array[4].suit)
	{
		return 1;
	}
	return 0;
}

// this goes through the pairs and picks the best cards to replace based on the pairs the bot already has
int pairs_replace(Hand bot)
{
	int random_draw = 0;
	if (bot.Array[0].face == bot.Array[1].face)
	{
		if (bot.Array[2].face == bot.Array[3].face)
		{
			//printf("Bot is replacing 5th card\n");
			return 5;
		}
		else if (bot.Array[3].face == bot.Array[4].face)
		{
			//printf("Bot is replacing 3rd card\n");
			return 3;
		}
		else
		{
			random_draw = rand() % 3;
			random_draw++;
			if (random_draw == 1)
			{
				random_draw = 3;
				//printf("random draw for pair: %d\n", random_draw);
				return random_draw;
			}
			else if(random_draw == 2)
			{
				random_draw = 4;
				//printf("random draw for pair: %d\n", random_draw);
				return random_draw;
			}
			else if(random_draw == 3)
			{
				random_draw = 5;
				//printf("random draw for pair: %d\n", random_draw);
				return random_draw;
			}

		}
	}
	if (bot.Array[1].face == bot.Array[2].face)
	{
		if (bot.Array[3].face == bot.Array[4].face)
		{
			//printf("Bot is replacing 1rst card\n");
			return 1;
		}
		else
		{
			//printf("Bot is replacing 4th card\n");
			return 4;
		}
	}

	if (bot.Array[2].face == bot.Array[3].face)
	{
		random_draw = rand() % 2;
		random_draw++;
		return random_draw;
	}

	if (bot.Array[3].face == bot.Array[4].face)
	{
		random_draw = rand() % 3;
		random_draw++;
		return random_draw;
	}
}

// this function checks to see if the user or the bot has one or two pairs
int pairs(Hand user)
{
	if (user.Array[0].face == user.Array[1].face)
	{
		if (user.Array[2].face == user.Array[3].face || user.Array[3].face == user.Array[4].face)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	if (user.Array[1].face == user.Array[2].face)
	{
		if (user.Array[3].face == user.Array[4].face)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}

	if (user.Array[2].face == user.Array[3].face)
	{
			return 1;
	}

	if (user.Array[3].face == user.Array[4].face)
	{
		return 1;
	}

	return 0;
}

// this function checks the user and the bots hands to see if they have either a three of a kind or a full house
int three_of_or_full_house(Hand user)
{
	if (user.Array[0].face == user.Array[1].face && user.Array[1].face == user.Array[2].face)
	{
		if (user.Array[3].face == user.Array[4].face)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	if (user.Array[1].face == user.Array[2].face && user.Array[2].face == user.Array[3].face)
	{
		return 1;
	}

	if (user.Array[2].face == user.Array[3].face && user.Array[3].face == user.Array[4].face)
	{
		if (user.Array[0].face == user.Array[1].face)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}

	return 0;
}

// this function is used to check and see which cards the bot needs to replace if it has a three of a kind or none if it has a full house
int bot_check_three_of_or_full_house(Hand user)
{
	int check = 0;
	if (user.Array[0].face == user.Array[1].face && user.Array[1].face == user.Array[2].face)
	{
		if (user.Array[3].face == user.Array[4].face)
		{
			check = 2;
			return check;
		}
		else
		{
			check = (rand() % 2);
			check++;
			if (check == 1)
			{
				check = 4;
				return check;
			}
			else if (check == 2)
			{
				check = 5;
				return check;
			}
		}
	}
	if (user.Array[1].face == user.Array[2].face && user.Array[2].face == user.Array[3].face)
	{
		check = rand() % 2;
		check++;
		if (check == 1)
		{
			return check;
		}
		else if(check == 2)
		{
			check = 5;
			return check;
		}
	}

	if (user.Array[2].face == user.Array[3].face && user.Array[3].face == user.Array[4].face)
	{
		if (user.Array[0].face == user.Array[1].face)
		{
			check = 2;
			return check;
		}
		else
		{
			check = rand() % 2;
			check++;
			if (check == 1)
			{
				return check;
			}
			else if (check == 2)
			{
				check = 6;
				return check;
			}
		}
	}

	return 0;
}

// this function checks to see if there are four matching cards in a hand
int four_of_kind(Hand user)
{
	if (user.Array[0].face == user.Array[1].face && user.Array[1].face == user.Array[2].face && user.Array[2].face == user.Array[3].face)
	{
		return 1;
	}
	if (user.Array[1].face == user.Array[2].face && user.Array[2].face == user.Array[3].face && user.Array[3].face == user.Array[4].face)
	{
		return 1;
	}
	return 0;
}

// this checks to see if the user or the bot has a flush
int flush(Hand user)
{
	int x = 0, suit = 0;
	suit = user.Array[0].suit;
	for (x = 1; x <= 4; x++)
	{
		if (suit != user.Array[x].suit)
		{
			return 0;
		}
	}
	return 1;
}

// this function checks to see if the user or the bot has a straight
int straight(Hand user)
{
	if (user.Array[0].face == 1 && user.Array[1].face == 10 && user.Array[2].face == 11 && user.Array[3].face == 12 && user.Array[4].face == 13)
	{
		return 1;
	}

	/* other straight */
	if (user.Array[0].face != user.Array[1].face - 1)
	{
		return 0;
	}
	if (user.Array[1].face != user.Array[2].face - 1)
	{
		return 0;
	}
	if (user.Array[2].face != user.Array[3].face - 1)
	{
		return 0;
	}
	if (user.Array[3].face != user.Array[4].face - 1)
	{
		return 0;
	}

	return 1;
}



