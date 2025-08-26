#include "header.h"

// this prints the main game menu for the user to pick a choice.
void print_menu(void)
{

	printf("1. Display information on PA8.\n");
	printf("2. Launch PA8\n");
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
	int choice = 0, list_max = 9, target_value = 4, pali_length = 8, value = 0, primes = NULL, target_index = 0;
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	char destination[] = { "\0" };
	char* list[] = { "zebra", "charlie", "delta", "foxtrot", "ALPHA", "geronimo", "canteen", "alpha", "quicksilver", "beta" };
	char pali[] = { "race car" };
	char string_cpy[20];
	int max = 0;
	char char_max = '\0';
	Occurrences occ[128];

	printf("Test\n");
	my_str_n_cat(string_cpy, "randomness");	
	printf("Test2\n");
	target_index = binary_search(array, target_value);
	printf("Target Index: %d\n", target_index);
	printf("Bubble sorting\n");
	bubble_sort(list, list_max);
	printf("Test_pali\n");
	value = is_palindrome(pali, pali_length);
	printf("is palindrome: %d\n", value);
	printf("Test 4\n");
	printf("is prime: %d\n", sum_primes(primes));
	printf("max_occurences\n");
	maximum_occurences("Test sentince thing for the thing", occ, &max, &char_max);
	printf("Finish!!!\n");
	return 0;
}

// this function prints the discription of the PA for the user
void print_game_rules(void)
{
	printf(" This program will be testing several functions that you will be able to choose from and will be things like\n string functions, binary searching, and several other programs\n");
}

// function should copy a string into another string
char* my_str_n_cat(char* destination, const char* src)
{
	char* temp = destination;
	while (*src)
	{
		*destination = *src;
		destination++;
		src++;
	}
	*destination++ = '\0';
	return temp;
}

//this function finds the index of an item in a sorted array using binary searching
int binary_search(int array[], int target) // Return the target index
{
	int size = 10;
	int left = 1, right = 8, found = 0, mid = (left + right) / 2;
	while (left <= right)
	{
		if (array[mid] < target)
		{
			left = mid + 1;
		}
		else if (array[mid] == target)
		{
			return mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

// this function sorts the array of strings based on the ascii value of the first letter for alphebetical and can be removed to sort strictly based on their ASCII values.
void bubble_sort(char* list[], int max) // doesnt need to return anything after running
{
	int U = 0, C = 0;
	char *temp = { '\0' };
	for (U = 0; U < max; U++)
	{
		for (C = U + 1; C < max + 1; C++)
		{
			if (list[C][0] < list[U][0])
			{
				temp = list[C];
				list[C] = list[U];
				list[U] = temp;
			}
		}
	}
	/*printf("Made it through\n");
	printf("%s\n", list[0]);
	printf("%s\n", list[1]);
	printf("%s\n", list[2]);
	printf("%s\n", list[3]);
	printf("%s\n", list[4]);
	printf("%s\n", list[5]);
	printf("%s\n", list[6]);
	printf("%s\n", list[7]);
	printf("%s\n", list[8]);
	printf("%s\n", list[9]);*/
}

// Supposed to determin if a string is a palindrome
int is_palindrome(char*string[], int length) // should return weather it is a palendrome or not with 1 being yes and 0 being no
{
	int char_num = 0, counter = 7, start = 0;
	int right = 0;
	length--;
	while (string[length] == ' ')
	{
		length--;
	}

	////
	while (counter > length)
	{
		if (string[counter] != ' ')
		{
			char_num += 1;
		}
		counter--;
	}

	////
	while (char_num > 0)
	{
		if (string[right] != ' ')
		{
			char_num--;
		}
		right++;
	}

	////
	while (string[right] == ' ')
	{
		right++;
	}
	////
	if (right >= length)
	{
		return 1;
	}
	if (string[right] != string[length])
	{
		return 0;
	}
	else
	{
		return is_palindrome(string, length);
	}

}

// function that checks for primes using recursion to find all of the primes up to a number
int sum_primes(unsigned int n)
{
	int sum = 0;
	if (n < 2)
	{
		return 0;
	}
	if (is_prime(n))
	{
		sum = n;
	}
	else
	{
		sum = 0;
	}

	return sum + sum_primes(n - 1);

}

// checks to see if the number is a prime number
int is_prime(int num)
{
	if (num <= 1)
	{
		return 0;
	}
	if (num % 2 == 0 && num > 2)
	{
		return 0;
	}
	for (int index = 3; index < num / 2; index += 2)
	{
		if (num % index == 0)
		{
			return 0;
		}
	}
	return 1;
}

// this is supposed to determine the frequency of each character found inside of a string
void maximum_occurences(char *string, Occurrences oc[], int *max, char *max_char)
{
	int count = 0, i = 0;

	for (i = 0; i < 128; i++)
	{
		oc[i].num_occurrences = 0;
		oc[i].frequency = 0.0;
	}

	for (int i = 0; i < strlen(string); i++)
	{
		int char_index = (int)string[i];
		oc[char_index].num_occurrences += 1;
		count++;
	}
	for (int i = 0; i < 128; i++)
	{
		oc[i].frequency = (double)oc[i].num_occurrences / count;
	}
	*max = 0;
	*max_char = '\0';
	for (int i = 48; i < 128; i++)
	{
		if (oc[i].num_occurrences > *max)
		{
			*max = oc[i].num_occurrences;
			*max_char = (char)i;
		}
	}
	printf("Max char: %c, num occurrences: %d\n", *max_char, *max);
}
