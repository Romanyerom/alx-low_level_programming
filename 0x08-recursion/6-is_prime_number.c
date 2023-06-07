#include "main.h"

/**
 * is_prime_number - checks whether a number is prime or not
 * @n: number to check
 * is_divisible - Checks if n is divisible by divisor.
 * @n: The number to be checked for divisibility.
 * @divisor: The divisor to check against.
 *
 * Return: 1 if n is divisible by divisor, 0 otherwise.
 *
 * Return: 1 if n is prime, 0 otherwise
 */

int is_divisible(int n, int divisor)
{
	if (divisor == 1)
	{
		return (0);  /* Not a prime number */
	}

	if (n % divisor == 0)
	{
		return (1);  /* Divisible, not a prime number */
	}

	return (is_divisible(n, divisor - 1));
}
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);  /* Not a prime number */
	}

	return (!is_divisible(n, n - 1));
}
