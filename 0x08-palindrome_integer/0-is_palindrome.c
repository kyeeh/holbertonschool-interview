#include "palindrome.h"

/**
 * is_palindrome - checks if a long numbers is a palindrome
 * @n: long integer to analyze
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(unsigned long n)
{
	int pal = 1;
	int arr[18];
	int i = 0, j;

	while ((n / 10) > 0)
	{
		arr[i] = n % 10;
		n = n / 10;
		i += 1;
	}
	arr[i] = n;
	for (j = 0; j <= i; j++, i--)
	{
		if (arr[j] != arr[i])
			return (0);
	}
	return (pal);
}
