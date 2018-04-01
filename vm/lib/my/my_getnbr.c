/*
** EPITECH PROJECT, 2017
** part 1
** File description:
** bootstrap
*/

int my_getnbr(char *str)
{
	long num = 0;
	int i = 0;

	for (; str[i] != '\0' && str[i] != '\n'; i++) {
		if (str[i] > 47 && str[i] < 58) {
			num = num * 10;
			num = num + str[i] - 48;
		} else
			return (-1);
		if (num > 2147483647)
			return (-1);
	}
	if (i == 0)
		return (-1);
	return ((int)num);
}
