/*
** EPITECH PROJECT, 2017
** Project Corewar ASM
** File description:
** Main file
*/

#include "../include/main.h"

void check_instruction(asm_t *cor, int instruction, char *gnl)
{
	char **line;
	int i = 0;

	gnl = replace_tab(gnl);
	line = my_str_to_word_array(gnl, ',');
	line[0] = clean_parameters(line[0]);
	for (i = 0; line[i] != NULL; i++)
		line[i] = remove_empty_tab(line[i]);
	for (i = 0; line[i] != NULL; i++) {
		remove_space(line[i]);
		remove_tab(line[i]);
	}
	if (i < op_tab[instruction].nbr_args)
		error_instructions(cor, -1);
	else if (i > op_tab[instruction].nbr_args)
		error_instructions(cor, 1);
	check_parameters(cor, line, instruction, i);
}

void content_file(asm_t *cor, char **line, char *gnl)
{
	int i = 0;
	int index = get_label_index(line);

	if (line[1]) {
		while (i < 16) {
			if (my_strcmp(line[index], op_tab[i].name) == 0) {
				check_instruction(cor, i, gnl);
				break;
			}
			i++;
		}
	}
}

void line_parsing(asm_t *cor, header_t *header, char *gnl)
{
	char **line;
	int fill_head = 0;
	static int tmp = 0;

	gnl = replace_tab(gnl);
	line = my_str_to_word_array(gnl, ' ');
	for (int i = 0; line[i] != NULL; i++)
		remove_space(line[i]);
	fill_head = header_file(cor, header, line, gnl);
	if (fill_head == 0) {
		content_file(cor, line, gnl);
		if (tmp == 0) {
			cor->start = cor->line;
			tmp++;
		}
	}
	for (int i = 0; line[i] != NULL; i++)
		free(line[i]);
	free(line);
}

void line_read(asm_t *cor, header_t *header, char *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char *gnl;

	if (fd < 0)
		return;
	gnl = my_read(fd);
	cor->line = 1;
	cor->size = 0;
	get_magic_number(header);
	while (gnl) {
		check_comment_line(gnl);
		if (gnl[0] != '#' && gnl[0] != '\n' && gnl[0] != '\0')
			line_parsing(cor, header, gnl);
		free(gnl);
		gnl = my_read(fd);
		cor->line++;
	}
	close(fd);
}
