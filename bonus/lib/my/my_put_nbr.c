/*
** EPITECH PROJECT, 2017
** put_nbr
** File description:
** task 1
*/

#include <unistd.h>

void	my_putchar(char c);

int	my_put_nbr(int nb)
{
	int a;
	int b;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	b = nb % 10;
	a = nb / 10;
	if (a != 0)
		my_put_nbr(a);
	my_putchar(b + '0');
	return (0);
}
