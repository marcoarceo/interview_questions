/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: Five-Card Poker                                                    
* Date: December 6th, 2017                                                                         
* Description: C Interview Questions w/ Bonus
*******************************************************************************************/

#include "header.h"

char my_str_n_cat(char *destination, const char *source, int number)
{ // This was copied from my Lab 9 Task 2 Solution

	int s_size = strlen(source), d_size = strlen(destination);

	for (int index = 0; destination[index] != NULL && index < number; index++)
	{
		destination[index + d_size] = source[index];
	}
	return destination;
}

int binary_search(int arr[], int target, int size)
{ // Followed the instruction that were given, pretty much gives the answer
	int left = 1, right = size - 1;
	bool found = false;

	for (int n = 0; found == false && left <= right; n++)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == target)
		{
			return mid;
			found = true;
		}
		else if (arr[mid] > target)
		{
			right = mid - 1;
		}
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
	}
	return 0;
}

void bubble_sort(char *bubble_array[], int string_count)
{ // I wrote this code on my exam 2 and copied O'fallon from class

	char *temp = NULL;

	for (int i = 0; i < (string_count - 1); i++)
	{
		for (int j = 0; j < (string_count - i - 1); j++)
		{
			if (strcmp(bubble_array[j], bubble_array[j + 1]) > 0) // Only change added
			{
				temp = bubble_array[j + 1];
				bubble_array[j + 1] = bubble_array[j];
				bubble_array[j] = temp;
			}
		}
	}
	for (int n = 0; n < string_count; n++)
	{
		printf("%s\n", bubble_array[n]);
	}
}

int isPalindrome(char *word1, int length)
{ // Ask for help on this one!
	// Doesnt account for spaces and produces wrong result
	// Got it to work with some insight from Ryan Manny

	int index = strlen(word1) - (length + 1);

	if (word1[length] != word1[index]) // Base Condition
	{
		return 0;
	}
	if (length == index) // If equal, then its a palindrome
	{
		return 1;
	}
	isPalindrome(word1, length + 1);
}

void removeSpaces(char *word, char *word1)
{ // Code courtesy of geeksforgeeks.org
	// Needed this to fix isPalindrome

	int count = 0;

	// Traverse the given string. If current character
	// is not space, then place it at index 'count++'
	for (int i = 0; word[i]; i++)
	{
		if (word[i] != ' ')
		{
			word1[count++] = word[i]; // here count is incremented
		}
	}
	word1[count] = '\0';
}

int sum_primes(int number)
{ // Followed what we did in lab before
	int sum = 0;

	if (number <= 1) // Base condition
	{
		return 0;
	}
	if (isPrime(number) == 1) // If prime, Sum becomes the number
	{
		sum = number;
	}
	return sum + sum_primes(number - 1);
}

int isPrime(int number)
{ // Code from Stack Overflow Title: "How to test easily if it is prime-number?"
	//I figured out why it works but im crunched on time so i wont change it.

	if (number <= 1)
	{
		return 0;
	}
	if (number % 2 == 0 && number > 2)
	{
		return 0;
	}
	for (int i = 3; i < number / 2; i += 2)
	{
		if (number % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void max_occurences(char *string, Occurrences occ_struct[], int *integer, char *character)
{ // Used a couple components from Stack Overflow and some of O'Fallons in class advice

	int counter = 0, index = 0;

	for (int i = 0, count = 0; i < 128; i++)
	{ // Initialize the array of structs

		occ_struct[i].num_occurrences = 0;
		occ_struct[i].frequency = 0;

		for (int i = 0; i < strlen(string); i++, counter++)
		{ 
			index = string[i];
			occ_struct[index].num_occurrences++;
		}

		// Get the frequency of the letter
		occ_struct[i].frequency = occ_struct[i].num_occurrences / counter;

		if (occ_struct[i].num_occurrences > *integer)
		{ // Gathers the most used character and the amount of times it was used

			*integer = occ_struct[i].num_occurrences;
			*character = (char)i;
		}
	}
	printf("Sentence: %s\n", string);
	printf("Character: %c\n", *character);
	printf("Occurrences: %d\n\n", *integer);
}

void max_consecutive_integer(int **data, int row, int column, int *max, int *count)
{ // Got help from a couple of TA's to make this one work, mainly got helped in the 
  // portion of the code that is in main since they hinted at using malloc

	int number = 0, max_number = 0, tracker = 0;

	 number = max; // Initial number that goes through the loop

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (data[i][j] == number)
			{
				tracker++; // Increment the amount of times it is located
			}
			else
			{
				if (max_number < tracker)
				{
					max_number = tracker;
					*max = number; // This will eventually be the final number that gets displayed
				}
				tracker = 1;
				number = data[i][j]; // Changes the number to a new one
			}
		}
	}
	*count = max_number; // The amount of times the number was spotted
	printf("\n\nThe maximum consecutive sequence same number is: %d\n", *max);
	printf("The length of the sequence is: %d\n", *count);
}