/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** copy a string into another
*/

#include <stdlib.h>
#include <stdio.h>

int str_len_cpy(char *str)
{
	int result = 0;

	for (; str[result] != '\0'; result++);
	return (result);
}

char *my_strcpy(char *src)
{
	int i = 0;
	char *dest = malloc(sizeof(char) * str_len_cpy(src) + 1);

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
