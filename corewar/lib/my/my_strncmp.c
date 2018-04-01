/*
** EPITECH PROJECT, 2017
** strncmp
** File description:
** task 6
*/

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int c = 0;

	while (s1[c] != '\0' && s2[c] != '\0' && s1[c] == s2[c] && c < n) {
		c ++;
	}
	return (s1[c] - s2[c]);
}
