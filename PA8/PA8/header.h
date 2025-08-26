#ifndef HEADER_H
#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>
#include <string.h>

#define DISPLAY 1
#define PLAY 2
#define EXIT 3

// this is used in the maximum_occurences function futher down in the project
typedef struct occurrences
{
    int num_occurrences;
    double frequency;
} Occurrences;


// this prints the main game menu for the user to pick a choice.
void print_menu(void);

// this checks to see what the users choice is in regards to rules, playing the game, and exiting
int game_choice(void);

// this is the main function of the game and runs all of the processes to play the game.
void play_game(void);

// this function prints the games rules for the user
void print_game_rules(void);

// function should copy a string into another string
char* my_str_n_cat(char* destination, const char* src);

//this function finds the index of an item in a sorted array using binary searching
int binary_search(int array[], int target);

// this function sorts the array of strings based on the ascii value of the first letter for alphebetical and can be removed to sort strictly based on their ASCII values.
void bubble_sort(char* list[], int max);

// Supposed to determin if a string is a palindrome
int is_palindrome(char* string[], int length);

// function that checks for primes using recursion to find all of the primes up to a number
int sum_primes(unsigned int n);

// checks to see if the number is a prime number
int is_prime(int num);

// this is supposed to determine the frequency of each character found inside of a string
void maximum_occurences(char* string, Occurrences oc[], int* max, char* max_char);

#endif HEADER_H