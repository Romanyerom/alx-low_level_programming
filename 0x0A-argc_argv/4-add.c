#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 for success, 1 for error
 */
int main(int argc, char *argv[])
{
	int i, j, sum = 0;

	if (argc == 1) /* No numbers passed */
	{
		printf("0\n");
		return (0);
	}

	/* Loop through each argument */
	for (i = 1; i < argc; i++)
	{
		/* Check each character in the argument */
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			/* If the character is not a digit */
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		/* Convert the argument to an int and add it to the sum */
		sum += atoi(argv[i]);
	}

	/* Print the sum */
	printf("%d\n", sum);

	return (0);
}
