/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include <stdlib.h>
#include <unistd.h>

char	*my_revstr(char *str)
{
	int count = 0;
	int count_rev = 0;
	char dest = 'a';

	while (str[count_rev] != '\0')
		count_rev ++;
	count_rev --;
	while (count_rev > count) {
		dest = str[count_rev];
		str[count_rev] = str[count];
		str[count] = dest;
		count ++;
		count_rev --;
	}
	return (str);
}

char *my_put_base(int nb, int b)
{
	int i = 0;
	char *base = "0123456789ABCDEF";
	int retur;
	char *result = malloc(sizeof(char) * 100);

	if (b == 16 && nb < 0)
		nb += 256;
	if (nb == 1)
		return ("1");
	if (nb == 0)
		return ("0");
	while (nb != 0) {
		retur = nb % b;
		nb = nb / b;
		result[i] = base[retur];
		i++;
	}
	result[i] = '\0';
	return (my_revstr(result));
}
