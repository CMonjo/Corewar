/*
** EPITECH PROJECT, 2017
** strlen
** File description:
** worklib
*/

int	my_strlen(char const *str)
{
	int compteur = 0;

	while (str[compteur] != '\0')
		compteur = compteur + 1;
	return (compteur);
}
