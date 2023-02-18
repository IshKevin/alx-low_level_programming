#include <stdio.h>

/**
 * main - entry point
 * Return: always 0 (success)
 */
int main(void)
{
	char lcase = 'a';
	char ucase = 'A';

	while (lcase <= 'z') 
	{
		putchar(lcase); 
		lcase++;  
	}
	while (ucase <= 'Z')
	{
		putchar(ucase); 
		ucase++; 
	}
	putchar('\n');
	return (0);
}
