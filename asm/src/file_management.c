/*
** EPITECH PROJECT, 2017
** Project Corewar ASM
** File description:
** File management
*/

#include "../include/main.h"

void create_file(asm_t *cor, header_t *header)
{
	int fd = open(cor->filepath_dot_cor, O_CREAT | O_WRONLY, 0664);
	union psize psize;
	char tmp;

	psize.value = cor->size;
	tmp = psize.str[3];
	psize.str[3] = psize.str[0];
	psize.str[0] = tmp;
	tmp = psize.str[2];
	psize.str[2] = psize.str[1];
	psize.str[1] = tmp;
	header->prog_size = psize.value;
	write(fd, header, sizeof(header_t));
	close(fd);
}

void get_name_file(asm_t *cor, char *filepath)
{
	char **path = my_str_to_word_array(filepath, '/');
	char **dot;
	int i = 0;

	for (; path[i]; i++);
	cor->filepath = path[i - 1];
	cor->nbr_labels = 0;
	dot = my_str_to_word_array(path[i - 1], '.');
	cor->filepath_dot_cor = my_strcat(dot[0], ".cor");
}
