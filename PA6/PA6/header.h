#ifndef HEADER_H
#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>

#define DISPLAY 1
#define PLAY 2
#define EXIT 3

// This function is used for the direction placement of the ship
typedef enum direction
{
	HORIZ, VERT

}Direction;

typedef enum direction2
{
	NORTH, SOUTH, EAST, WEST

}Direction2;
// this is for setting up the row and colum of the ship
typedef struct cordinate
{
	int row;
	int colum;

}Cordinate;
// this is for getting the attack point for the player or the ai.
typedef struct attack
{
	int row;
	int colum;

}Attack;
 
//typedef struct attack_bot
//{
//	int row;
//	int colum;
//
//}Attack_bot;
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

// this function will create the board for the player
void init_board(char board[][10], int num_rows, int num_cols);


// this prints the board
void print_board(char board[][10], int num_rows, int num_cols);

//this function is used to place all ships on the board for the player this includes the direction it will be facing.
char place_ship(char battle_board[][11], int ship, int size);

// this gets the random direction for the ship and uses vertical and horizontal for the directions
Direction get_dir(void);

// this function is the manual selection for the ship direction using north south east and west
Direction get_dir_man(void);
// this function generates a start point and uses the random direction function
Cordinate gen_start_pt(int ship_length, Direction dir, int num_rows, int num_colums);

// this function is getting the user input to get a starting point 
Cordinate get_start_pt(int ship_length, Direction2 dir, int num_rows, int num_colums);

// this function is getting the user input for an attack point and checking to make sure its in bounds 
Cordinate attack(int num_rows, int num_colums);

// this function is getting two random numbers for the bots hit location
Cordinate attack_bot(int num_rows, int num_colums);

// This function checks to make sure the randomly generated ships are not going out of bounds or overlaping with other ships
int check_ships(char board[][10], int num_rows, int num_colums, char symbol, int length, Direction dir, Cordinate start_pt);

// after the ships have been checked this function prints the ships onto the board for the player or the bot
void place_ships(char board[][10], int num_rows, int num_colums, char symbol, int length, Direction dir, Cordinate start_pt);

// this function checks the manual placement of ships to make sure they are not overlaping or going out of bounds
int check_ships_man(char board[][10], int num_rows, int num_colums, char symbol, int length, Direction2 dir, Cordinate start_pt);

// after the checking of the ships this function places the manual ships onto the board 
void place_ships_man(char board[][10], int num_rows, int num_colums, char symbol, int length, Direction2 dir, Cordinate start_pt);

// this function checks to see if the input of either the player or the bot has already been used
int check_hit_or_miss(char board[][10], Cordinate attack_pt, int num_rows, int num_colums);

// this function is used to check to see if any ship is hit or if the player missed based on their attack point
void hit_or_miss(char board[][10], int targets[], Cordinate attack_pt, int num_rows, int num_colums);

// this function also checks to see if the bot hit or miss the players ships and has different text based on what happens
void hit_or_miss_bot(char board[][10], int targets[], Cordinate attack_pt, int num_rows, int num_colums);

// this function updates the main blank board that the player sees for their hits or misses
void update_bot_board(char board[][10], char board2[][10], Cordinate attack_pt);

// this function is used to track the progress of both the player and the bot and then prints to the log file for each turn
void progress(int list[], FILE* outfile, Cordinate attack_pt);

// this is for when the game finally comes to an end and this prints both the players and the bots stats to the game log text file
void game_stats(FILE* outfile, int list[]);


#endif HEADER_H