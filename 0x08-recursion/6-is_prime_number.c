#include "main.h"

/**
 * is_prime_number - checks whether a number is prime or not
 * @n: number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */

int is_prime_number(int n)
{
	/* Base cases */
	if (n <= 1)
	{
		return (0);
		/* Not a prime number */
	}
	else if (n <= 3)
	{
		return (1);
		/* 2 and 3 are prime numbers */
	}

	/* Check if n is divisible by numbers from 2 to sqrt(n) */
	int i;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return (0);
			/* Not a prime number */
		}
	}

	return (1);  /* Prime number */
}
