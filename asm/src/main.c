/*
** EPITECH PROJECT, 2017
** Project Corewar ASM
** File description:
** Main file
*/

#include "main.h"

int print_h(char const *filepath)
{
	int fd = 0;
	int rd = 0;
	char *buffer;

	fd = open(filepath, O_RDONLY);
	buffer = (char*)malloc(sizeof(char *) * 1200 + 1);
	rd = read(fd, buffer, 1200);
	if (rd <= 0)
		return (84);
	write(1, buffer, rd);
	free(buffer);
	return (0);
}

int main(int ac, char **av)
{
	asm_t *cor = malloc(sizeof(asm_t));
	header_t *header = malloc(sizeof(header_t));
	int fd = 0;

	if (av[1] != NULL && my_strlen(av[1]) == 2 && av[1][0]
	== '-' && av[1][1] == 'h') {
		print_h(".legend");
		return (0);
	}
	if (ac < 2) {
		my_putstr("Usage: ./asm file_name[.s] ....\n");
		return (1);
	}
	for (int i = 1; i < ac; i++) {
		get_name_file(cor, av[i]);
		line_read(cor, header, av[i]);
		create_file(cor, header, fd);
	}
	return (0);
}
