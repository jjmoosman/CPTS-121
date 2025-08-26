#ifndef HEADER_H
#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>

#define DISPLAY 1
#define PLAY 2
#define EXIT 3

// this struct is used to store the card face and suit values
typedef struct card
{
	int face;
	int suit;

}Card;
// this struct is an array that stores a face and suit value from the card struct
typedef struct hand
{
	Card Array[5];

}Hand;

// this function shuffles the entire deck of cards
void shuffle(int wDeck[][13]);

// this prints the main game menu for the user to pick a choice.
void print_menu(void);

// this checks to see what the users choice is in regards to rules, playing the game, and exiting
int game_choice(void);

// this is the main function of the game and runs all of the processes to play the game.
void play_game(void);

// this function prints the games rules for the user
void print_game_rules(void);

// this checks to see if the user wants to continue playing after the first round or if they wish to exit the game
int play_again(int choice);

/* deal cards in deck to the player */
Hand deal_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], int* count, int card_max_draw);

/* deals bot cards*/
Hand deal_bot_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], int* count, int card_max_draw);

// this function sorts the deck of the player or the bot
Hand Sort_cards(Hand user);

// this function is used to check to see if the player wants to draw new cards and if they do it overwrites the selected cards to change them.
Hand draw_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], int* count, int card_max_draw, Hand player);

// this function is used to check to see if the player wants to draw new cards and if they do it overwrites the selected cards to change them.
Hand bot_draw(const int wDeck[][13], const char* wFace[], const char* wSuit[], int* count, int card_max_draw, Hand bot);

// this function is used so the bot can draw new cards if does not have a pair or better
Hand bot_draw_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], int* count, int card_max_draw, Hand bot);

// this function looks to see what the player has and returns a score value based on what it matches 
int match_check(Hand player);

// this function looks to see what the bot has and returns a score value based on what it matches
int bot_match_check(Hand player);

// this checks to see if the bot almost has a flush and will use this to choose a card based on whats not matching
int almost_flush(Hand bot);

// this goes through the pairs and picks the best cards to replace based on the pairs
int pairs_replace(Hand bot);

// this function checks to see if the user or the bot has one or two pairs
int pairs(Hand user);

// this function checks the user and the bots hands to see if they have either a three of a kind or a full house
int three_of_or_full_house(Hand user);

// this function is used to check and see which cards the bot needs to replace if it has a three of a kind or none if it has a full house
int bot_check_three_of_or_full_house(Hand user);

// this function checks to see if the player or the bot has a four of a kind
int four_of_kind(Hand user);

// this function checks to see if the player or the bot has a flush
int flush(Hand user);

// this function checks to see if the player or the bot has a straight
int straight(Hand user);


#endif HEADER_H