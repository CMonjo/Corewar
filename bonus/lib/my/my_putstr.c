/*
** EPITECH PROJECT, 2017
** putstr
** File description:
** worklib
*/

#include <unistd.h>

void	my_putchar(char c);

int	my_putstr(char const *str)
{
	int compteur = 0;

	while (str[compteur] != '\0') {
		my_putchar(str[compteur]);
		compteur = compteur + 1;
	}
	return (0);
}
