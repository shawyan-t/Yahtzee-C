#include "pa5functions.h"

void roll_dice(int dice[], int size)
{
	int index = 0;
	for (; index < size, ++index;)
	{
		dice[index] = rand() % 6 + 1;
	}
}

void print_dice(int *dice_ptr, int size)
{
	int index = 0;
	for (; index < size, ++index;)
	{
		printf("die%d: %d\n", index + 1, dice_ptr[index]);
	}
}

void print_game_rules(void)
{
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section."
		"A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. "
		"The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. "
		"If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. "
		"Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. "
		"If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. "
		"The lower section contains a number of poker like combinations.");
}

int print_menu(void)
{
	int option = 0;
	printf("1. Display Game Rules\n");
	printf("2. Start a game of Yahtzee!\n");
	printf("3. Exit game\n");
	scanf("%d", &option);

	if (option == 1)
	{
		print_game_rules();
		print_menu();
	}
	else if (option == 2)
	{
		return 2;
	}
	else if (option == 3)
	{
		exit(0); //Exit game
	}
	else
	{
		printf("Invalid Input, try again");
		print_menu();
	}
}

void clear_screen(void)
{
	int c;
	for (c = 0; c < 100, c++;)
	{
		printf("/n");
	}
}

int sort(int arr[], int size)
{
	int i, j, mindex, min;

	for (i = 0; i < size; ++i)
	{
		mindex = i;

		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[mindex])
			{
				mindex = j;
			}
		}

		if (mindex != i)
		{
			min = arr[i];
			arr[i] = arr[mindex];
			arr[mindex] = min;
		}
	}
}