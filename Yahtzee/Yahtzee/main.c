#include "pa5functions.h"

int main(void)
{
	int die[5] = { 0 }, *saved_combos[1000] = { 0 }, tempDie[5] = { 0 }, size = sizeof(saved_combos),
		totalRounds = 0, gameRounds = 0, option = 0, n = 0, check = 0, upperScore = 0, score = 0, position = -1, screen = 0;

	int b1 = saved_combos[0], b2 = saved_combos[1], b3 = saved_combos[2], b4 = saved_combos[3], b5 = saved_combos[4], b6 = saved_combos[5],
		b7 = saved_combos[6], b8 = saved_combos[7], b9 = saved_combos[8], b10 = saved_combos[9], b11 = saved_combos[10],
		b12 = saved_combos[11], b13 = saved_combos[12];

	roll_dice(die, 5);
	print_dice(die, 5);

	srand((unsigned int)time(NULL));

	option = print_menu();

	while (screen < 100) //Clear Screen
	{
		printf("/n");
		screen = screen + 1;
	}

	while (gameRounds != 14)
	{
		if (option == 2) //game
		{
			printf("Press any key to roll the dice\n");
			getch();

			roll_dice(die, 5); //Roll and add to rounds
			print_dice(die, 5);
			sort(die, 5);
			totalRounds = totalRounds + 1;

			while (totalRounds < 3)
			{
				printf("You have %d rolls remaining. If you would like to roll, press 0. If you would like to choose a combination, press 1.\n");
				scanf("%d", &option);
				if (option == 0)
				{
					roll_dice(die, 5);
					print_dice(die, 5);
					sort(die, 5);
					totalRounds = totalRounds + 1;
				}
				else if (option == 1)
				{
					option = 0;
					while (option == 0 || option == b1 || option == b2 || option == b3 || option == b4 || option == b5 || option == b6
						|| option == b7 || option == b8 || option == b9 || option == b10 || option == b11 || option == b12 || option == b13)
					{
						printf("Please enter a number based off the combination options:"
							"1. Sum of 1's        7. Three-of-a-kind"

							"2. Sum of 2's        8. Four-of-a-kind"

							"3. Sum of 3's        9. Full house"

							"4. Sum of 4's        10. Small straight"

							"5. Sum of 5's        11. Large straight"

							"6. Sum of 6's        12. Yahtzee"

							" 13. Chance");
						scanf("%d", option);

						if (option == 1) //Sum of 1s
						{
							saved_combos[position + 1] = 1;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								check = die[n];
								if (check == 1)
								{
									upperScore = upperScore + 1;
									score = score + 1;
								}
							}
						}
						else if (option == 2) // Sum of 2s
						{
							saved_combos[position + 1] = 2;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								check = die[n];
								if (check == 2)
								{
									upperScore = upperScore + 1;
									score = score + 1;
								}
							}
						}
						else if (option == 3) //Sum of 3s
						{
							saved_combos[position + 1] = 3;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								check = die[n];
								if (check == 3)
								{
									upperScore = upperScore + 1;
									score = score + 1;
								}
							}
						}
						else if (option == 4) //Sum of 4s
						{
							saved_combos[position + 1] = 4;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								check = die[n];
								if (check == 4)
								{
									upperScore = upperScore + 1;
									score = score + 1;
								}
							}
						}
						else if (option == 5) //Sum of 5s
						{
							saved_combos[position + 1] = 5;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								check = die[n];
								if (check == 5)
								{
									upperScore = upperScore + 1;
									score = score + 1;
								}
							}
						}
						else if (option == 6) //Sum of 6s
						{
							saved_combos[position + 1] = 6;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								check = die[n];
								if (check == 6)
								{
									upperScore = upperScore + 1;
									score = score + 1;
								}
							}
						}
						else if (option == 7) //Three of a Kind
						{
							saved_combos[position + 1] = 7;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								if (die[n] == die[n + 1] && die[n] == die[n + 2])
								{
									score = die[n] + die[n + 1] + die[n + 2];
								}
							}
						}
						else if (option == 8) //Four of a Kind
						{
							saved_combos[position + 1] = 8;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								if (die[n] == die[n + 1] && (die[n] == die[n + 2]) && (die[n] == die[n + 3]))
								{
									score = die[n] + die[n + 1] + die[n + 2] + die[n + 3];
								}
							}
						}
						else if (option == 9) //Full House
						{
							saved_combos[position + 1] = 9;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								if (die[n] == die[n + 1] && die[n] == die[n + 2])
								{
									if (die[n + 3] == die[n + 4])
									{
										score = score + 25;
									}
								}
							}
						}
						else if (option == 10) //Small Straight
						{
							saved_combos[position + 1] = 10;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								if (die[n] == die[n + 1] - 1 && (die[n] == die[n + 2] - 2) &&
									die[n] == die[n + 3] - 3)
								{
									score = score + 30;
								}
							}
						}
						else if (option == 11) //Large Straight
						{
							saved_combos[position + 1] = 11;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								if (die[n] == die[n + 1] - 1 && (die[n] == die[n + 2] - 2) &&
									die[n] == die[n + 3] - 3 && die[n] == die[n + 4] - 4)
								{
									score = score + 40;
								}
							}
						}
						else if (option == 12) //YAHTZEE
						{
							saved_combos[position + 1] = 12;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								if (die[n] == die[n + 1] && (die[n] == die[n + 2]) &&
									die[n] == die[n + 3] && die[n] == die[n + 4])
								{
									score = score + 50;
								}
							}
						}
						else if (option == 13) //Chance
						{
							saved_combos[position + 1] = 13;
							position = position + 1;
							for (n = 0, n < 5; n++;)
							{
								check = die[n];
								score = score + check;
							}
						}
						else
						{
							printf("Invalid input, please try again\n");
						}

						if (totalRounds == 3)
						{
							option = 0;
							while (option == 0 || option == b1 || option == b2 || option == b3 || option == b4 || option == b5 || option == b6
								|| option == b7 || option == b8 || option == b9 || option == b10 || option == b11 || option == b12 || option == b13)
							{
								printf("Please enter a number based off the combination options:"
									"1. Sum of 1's        7. Three-of-a-kind"

									"2. Sum of 2's        8. Four-of-a-kind"

									"3. Sum of 3's        9. Full house"

									"4. Sum of 4's        10. Small straight"

									"5. Sum of 5's        11. Large straight"

									"6. Sum of 6's        12. Yahtzee"

									" 13. Chance");
								scanf("%d", option);

								if (option == 1) //Sum of 1s
								{
									saved_combos[position + 1] = 1;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										check = die[n];
										if (check == 1)
										{
											upperScore = upperScore + 1;
											score = score + 1;
										}
									}
								}
								else if (option == 2) // Sum of 2s
								{
									saved_combos[position + 1] = 2;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										check = die[n];
										if (check == 2)
										{
											upperScore = upperScore + 1;
											score = score + 1;
										}
									}
								}
								else if (option == 3) //Sum of 3s
								{
									saved_combos[position + 1] = 3;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										check = die[n];
										if (check == 3)
										{
											upperScore = upperScore + 1;
											score = score + 1;
										}
									}
								}
								else if (option == 4) //Sum of 4s
								{
									saved_combos[position + 1] = 4;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										check = die[n];
										if (check == 4)
										{
											upperScore = upperScore + 1;
											score = score + 1;
										}
									}
								}
								else if (option == 5) //Sum of 5s
								{
									saved_combos[position + 1] = 5;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										check = die[n];
										if (check == 5)
										{
											upperScore = upperScore + 1;
											score = score + 1;
										}
									}
								}
								else if (option == 6) //Sum of 6s
								{
									saved_combos[position + 1] = 6;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										check = die[n];
										if (check == 6)
										{
											upperScore = upperScore + 1;
											score = score + 1;
										}
									}
								}
								else if (option == 7) //Three of a Kind
								{
									saved_combos[position + 1] = 7;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										if (die[n] == die[n + 1] && die[n] == die[n + 2])
										{
											score = die[n] + die[n + 1] + die[n + 2];
										}
									}
								}
								else if (option == 8) //Four of a Kind
								{
									saved_combos[position + 1] = 8;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										if (die[n] == die[n + 1] && (die[n] == die[n + 2]) && (die[n] == die[n + 3]))
										{
											score = die[n] + die[n + 1] + die[n + 2] + die[n + 3];
										}
									}
								}
								else if (option == 9) //Full House
								{
									saved_combos[position + 1] = 9;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										if (die[n] == die[n + 1] && die[n] == die[n + 2])
										{
											if (die[n + 3] == die[n + 4])
											{
												score = score + 25;
											}
										}
									}
								}
								else if (option == 10) //Small Straight
								{
									saved_combos[position + 1] = 10;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										if (die[n] == die[n + 1] - 1 && (die[n] == die[n + 2] - 2) &&
											die[n] == die[n + 3] - 3)
										{
											score = score + 30;
										}
									}
								}
								else if (option == 11) //Large Straight
								{
									saved_combos[position + 1] = 11;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										if (die[n] == die[n + 1] - 1 && (die[n] == die[n + 2] - 2) &&
											die[n] == die[n + 3] - 3 && die[n] == die[n + 4] - 4)
										{
											score = score + 40;
										}
									}
								}
								else if (option == 12) //YAHTZEE
								{
									saved_combos[position + 1] = 12;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										if (die[n] == die[n + 1] && (die[n] == die[n + 2]) &&
											die[n] == die[n + 3] && die[n] == die[n + 4])
										{
											score = score + 50;
										}
									}
								}
								else if (option == 13) //Chance
								{
									saved_combos[position + 1] = 13;
									position = position + 1;
									for (n = 0, n < 5; n++;)
									{
										check = die[n];
										score = score + check;
									}
								}
								if (upperScore >= 63)
								{
									score = score + 35;
									printf("Your Score:%d", score);
								}
							}
						}
					}
				}
			}
		}
	}
}