/*
** EPITECH PROJECT, 2017
** c
** File description:
** c
*/

#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
		i++;
		if (s1[i + 1] == '\0' && s2[i + 1] == '\0')
			return (0);
	}
	return (1);
}
