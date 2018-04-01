/*
** EPITECH PROJECT, 2017
** revstr
** File description:
** task 3
*/

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
