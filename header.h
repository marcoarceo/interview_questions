/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: Five-Card Poker                                                    
* Date: December 6th, 2017                                                                         
* Description: C Interview Questions w/ Bonus
*******************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

char my_str_n_cat(char *destination, const char *source, int number);
int binary_search(int arr[], int target, int size);
void bubble_sort(char *bubble_array[], int string_count);
int isPalindrome(char *word1, int length);
void removeSpaces(char *word, char *word1);
int sum_primes(int number);
int isPrime(int number);
void max_occurences(char *string, Occurrences occ_struct[], int *integer, char *character);
void max_consecutive_integer(int **data, int row, int column, int *max, int *count);
