/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

int four_bytes_to_int(int n1, int n2, int n3, int n4)
{
	int result = (n4 * 1) + (n3 * 256) + (n2 * 256 * 256) +
	(n1 * 256 * 256 * 256);

	return (result);
}
