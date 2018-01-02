/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: Five-Card Poker                                                    
* Date: December 6th, 2017                                                                         
* Description: C Interview Questions w/ Bonus
*******************************************************************************************/

#include "header.h"

int main(void)
{
	// All code used in the functions are hardcoded except for the bonus
	// I used the example numbers from PA8 to run the bonus

	srand((unsigned)time(NULL));

	char destination[] = "Hello ";
	char source[] = "Ryan Manny";
	char *string = "bells belong bellow";
	char word[] = "do geese see god";
	char word1[] = "\0";
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char *bubble_array[10] = {"banana", "cherry", "apple", "orange", "drupe", "eggplant", "strawberry", "kiwi", "plum", "melon"};
	int number = 0, target = 0, option = 0, first = 0, length = 0;

	int **data, row = 4, column = 5, max = 0, count = 0;

	Occurrences occ_struct[128];
	int integer = 0;
	char character = '\0';

	do
	{
		number = rand() % 100;
		target = rand() % 10 + 1;
		do
		{
			printf("WELCOME TO PA8!\n\n");
			printf("All code is hardcoded, to change it go to Main.\n\n");
			printf("1.) my_str_n_cat()\n");
			printf("2.) binary_search()\n");
			printf("3.) bubble_sort()\n");
			printf("4.) isPalindrome()\n");
			printf("5.) sum_primes()\n");
			printf("6.) maximum_occurences()\n");
			printf("7.) max_consecutive_integers()\n");
			printf("8.) quit the program\n\n");
			printf("Please choose an option: ");
			scanf("%d", &option);
			printf("\n");
		} while (option > 8 || option < 1);

		switch (option)
		{
		case 1:
			printf("String 1: %s\n", destination);
			printf("String 2: %s\n", source);
			my_str_n_cat(destination, source, 11);
			printf("Concated: %s\n\n", destination);
			system("pause");
			system("cls");
			break;
		case 2:
			printf("arr[%d] = %d\n\n", binary_search(arr, target, 10), target);
			system("pause");
			system("cls");
			break;
		case 3:
			bubble_sort(bubble_array, 10);
			printf("\n");
			system("pause");
			system("cls");
			break;
		case 4:
			printf("%s\n\n", word);
			removeSpaces(word, word1);
			if (isPalindrome(word1, length) == 0)
			{
				printf("Not A Palindrome!\n\n");
			}
			if (isPalindrome(word1, length) == 1)
			{
				printf("Palindrome!\n\n", word);
			}
			system("pause");
			system("cls");
			break;
		case 5:
			printf("The sum of primes of %d is %d\n\n", number, sum_primes(number));
			system("pause");
			system("cls");
			break;
		case 6:
			max_occurences(string, occ_struct, &integer, &character);
			system("pause");
			system("cls");
			break;
		case 7:
			// TA helped me better understand how to use malloc
			data = malloc(row * sizeof(int)); // Initial memory allocation
			for (int i = 0; i < row; i++)
			{
				data[i] = malloc(column * sizeof(int)); // Allocate the memory
				printf("Row %d: ", i + 1);
				for (int j = 0; j < column; j++)
				{
					scanf("%d", &data[i][j]); // Places the users number into the data array
				}
			}
			max = (int)data[0][0]; // Set max to the value of data[0][0]
			max_consecutive_integer(data, row, column, &max, &count);
			system("pause");
			system("cls");
			break;
		case 8:
			printf("I really need an A in this class Ryan, hopefully you liked it!\n\n");
			break;
		}
	} while (option != 8);
}