/*
** EPITECH PROJECT, 2017
** match
** File description:
** bonus
*/

#include "my.h"
#include "time.h"

char *my_reverse_str(char *str)
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

char *my_change_base(int nb, int b)
{
	char *base = "0123456789ABCDEF";
	int retur;
	int i = 0;
	int stock = nb;
	char *result = malloc(sizeof(char) * 100);

	if (nb == 0)
		return ("00");
	if (nb < 10) {
		result[0] = '0';
		i++;
	} for (; nb != 0; i++) {
		retur = nb % b;
		nb = nb / b;
		result[i] = base[retur];
		result[i + 1] = '\0';
	}
	if (stock < 10)
		return (result);
	return (my_reverse_str(result));
}

char *i_to_a(int nbr)
{
	char *str;
	int i = 0;

	if (nbr == 0) {
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	for (int tmp = nbr; tmp > 0; tmp /= 10, i++);
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i --;
	for (int tp = nbr; tp > 0; tp /= 10, i--)
		str[i] = tp % 10 + 48;
	return (str);
}
