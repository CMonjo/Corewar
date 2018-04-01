/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** Count and return the number of character found in the string
*/

int my_strlen(char *str)
{
	int var = 0;

	for (var = 0; str[var] != '\0'; var++);
	return (var);
}
