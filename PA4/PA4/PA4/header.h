#ifndef HEADER_H
#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>

#define DISPLAY 1
#define PLAY 2
#define EXIT 3
// this prints the main game menu for the user to pick a choice.
void print_menu(void);

// this checks to see what the users choice is in regards to rules, playing the game, and exiting
int game_choice(void);


//void process_choice(int choice);

// this is the main function of the game and runs all of the processes to play the game.
void play_game(void);


//int play_again(int choice);

// this function prints the games rules for the user
void print_game_rules(void);

// this gets a user created balance for the game to make wagers on winning or loosing a round.
double get_bank_balance(void);

// this function gets an input from the user for a wager then sends it to check wager after entering an ammount.
double get_wager_amount(void);

// this function checks the overall wager amount to see if it is greater than the balance and if so it will have the user re-enter a wager until they enter a value smaller or equal to the balance
int check_wager_amount(double wager, double balance);

// this function rolls the dice 
int roll_die(void);

// this takes the dice values rolled and sums them up and returns them to the function
int calculate_sum_dice(int die1_value, int die2_value);

// this function checks to see if the player wins, loses, or gets a point in which it then sends down to check if the player wins the point or loses
int is_win_loss_or_point(int sum_dice);

// this function runs when the player returns point where they roll 
int is_point_loss_or_neither(int sum_dice, int point_value);

// this function checks to see weather the player has won or lost the round of craps
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);

// this checks to see if the user wants to continue playing after the first round or if they wish to exit the game
int get_choice(int choice);

// this function was supposed to add in some chatter and conversation into the game to keep it lively 
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);







#endif HEADER_H