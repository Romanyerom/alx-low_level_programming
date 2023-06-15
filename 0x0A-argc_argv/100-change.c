#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * @argc: number of arguments passed to program
 * @argv: array of arguments passed to program
 *
 * Return: 0 on success, 1 on error
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    int cents = atoi(argv[1]);

    if (cents < 0) {
        printf("0\n");
        return 0;
    }

    int coins[] = {25, 10, 5, 2, 1};
    int num_coins = sizeof(coins) / sizeof(coins[0]);
    int count = 0;

    for (int i = 0; i < num_coins; i++) {
        while (cents >= coins[i]) {
            cents -= i];
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}

int main(int argc, char *argv[])
{
	int coins = 0, cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n
