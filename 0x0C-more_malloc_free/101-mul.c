main.h


#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*functions for 101-mul.c */

/**
 * error_exit - prints error with _putchar
 *              and exits with 98
 *
 * Return: Error 98 and exit(98)
*/

int error_exit(void)
{
	char *err;
	int i;

	err = "Error";
	for (i = 0; err[i] != '\0'; i++)
		_putchar(err[i]);
	_putchar('\n');
	exit(98);
}

/**
 * check_number - checks if string has only
 *                numbers
 *
 * @str: string to check
 *
 * Return: 0 is true 1 if false
*/

int check_number(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

/**
 * _length - get the length of strings
 *
 * @str: string to get length of
 *
 * Return: length of string
*/

int _length(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

#endif /* MAIN_H_ */



Task 0

#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 * @b: size of memory to be allocated
 * Return: pointer to the allocated memory (SUCCESS)
 * 98 if insufficient memory was available (FAILURE)
 */

void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);
	if (p == NULL)
		exit(98);

	return (p);
}


Task 1

#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 *
 * @s1: first string
 * @s2: second string
 * @n: the number of bytes to include of @s2
 *
 * Return: newly allocated space in memory;
 * NULL if the function fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ar;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int m;
	unsigned int p;
	unsigned int k = 0;
	unsigned int len;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (j > n)
		j = n;

	len = i + j;

	ar = malloc(sizeof(char) * (len + 1));
	if (ar == NULL)
		return (NULL);

	for (p = 0; p < i; p++)
		ar[k++] = s1[p];
	for (m = 0; m < j; m++)
		ar[k++] = s2[m];

	ar[k] = '\0';
	return (ar);
}


Taks 2


#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc, and initializes to 0
 * @nmemb: number of elements of the array
 * @size: size of each element of the array
 * Return: pointer to the allocated memory (SUCCESS) or
 * NULL if @nmemb or @size is 0 (FAILURE) or
 * NULL if insufficient memory was available (FAILURE)
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return ('\0');

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return ('\0');

	for (i = 0; i < nmemb * size; i++)
		ptr[i] = 0;

	return ((void *)ptr);
}



Task 3


#include <stdlib.h>

/**
 * array_range - creates an array of integers, ordered from @min to @max
 * @min: first and minimum value of the array to be created
 * @max: last and maximum value of the array to be created
 * Return: pointer to the newly created array (SUCCESS) or
 * NULL if @min > @max (FAILURE) or
 * NULL if insufficient memory was available (FAILURE)
 */

int *array_range(int min, int max)
{
	int i, n;
	int *ptr;

	if (min > max)
		return ('\0');

	n = (max - min) + 1;
	ptr = malloc(sizeof(int) * n);

	if (ptr == NULL)
		return ('\0');

	for (i = 0; i < n; i++)
		ptr[i] = min + i;

	return (ptr);
}



Task 4


#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free functions
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size, in bytes, of the allocated space for @ptr
 * @new_size: new size, in bytes of the new memory block
 * Return: pointer to new allocated memory
 * NULL, if @ptr is NULL (FAILURE) or
 * NULL, if @new_size == 0 && @ptr != NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);

		if (new_ptr == NULL)
			return ('\0');

		return (new_ptr);
	}

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return ('\0');
	}

	new_ptr = malloc(new_size);

	if (!new_ptr)
		return ('\0');

	for (i = 0; i < old_size; i++)
		*((char *)new_ptr + i) = *((char *)ptr + i);

	free(ptr);
	return ((void *)new_ptr);
}



Task 5 (I HOPE THIS WORKS FOR YOU)


#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _memset - fills memory with a constant byte
 *
 * @s: input pointer that represents memory block
 *     to fill
 * @b: characters to fill/set
 * @n: number of bytes to be filled
 *
 * Return: pointer to the filled memory area
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}

/**
 * _calloc - function that allocates memory
 *           for an array using memset
 *
 * @nmemb: size of array
 * @size: size of each element
 *
 * Return: pointer to new allocated memory
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	_memset(ptr, 0, nmemb * size);

	return (ptr);
}


/**
 * multiply - initialize array with 0 byte
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: nothing
*/

void multiply(char *s1, char *s2)
{
	int i, l1, l2, total_l, f_digit, s_digit, res = 0, tmp;
	char *ptr;
	void *temp;

	l1 = _length(s1);
	l2 = _length(s2);
	tmp = l2;
	total_l = l1 + l2;
	ptr = _calloc(sizeof(int), total_l);

	/* store our pointer address to free later */
	temp = ptr;

	for (l1--; l1 >= 0; l1--)
	{
		f_digit = s1[l1] - '0';
		res = 0;
		l2 = tmp;
		for (l2--; l2 >= 0; l2--)
		{
			s_digit = s2[l2] - '0';
			res += ptr[l2 + l1 + 1] + (f_digit * s_digit);
			ptr[l1 + l2 + 1] = res % 10;
			res /= 10;
		}
		if (res)
			ptr[l1 + l2 + 1] = res % 10;
	}

	while (*ptr == 0)
	{
		ptr++;
		total_l--;
	}

	for (i = 0; i < total_l; i++)
		printf("%i", ptr[i]);
	printf("\n");
	printf("\n");
	free(temp);
}


/**
 * main - Entry point
 *
 * Description: a program that multiplies
 *            two positive numbers
 *
 * @argc: number of arguments
 * @argv: arguments array
 *
 * Return: 0 on success 98 on faliure
*/

int main(int argc, char *argv[])
{
	char *n1 = argv[1];
	char *n2 = argv[2];

	if (argc != 3 || check_number(n1) || check_number(n2))
		error_exit();

	if (*n1 == '0' || *n2 == '0')
	{
		_putchar('0');
		_putchar('\n');
	}
	else
		multiply(n1, n2);
	return (0);
}
