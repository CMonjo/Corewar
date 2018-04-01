/*
** EPITECH PROJECT, 2017
** Project Corewar ASM
** File description:
** Header fill file
*/

#include "main.h"

void get_magic_number(header_t *header)
{
	union data data;
	char tmp;

	data.magic = COREWAR_EXEC_MAGIC;
	tmp = data.tank[3];
	data.tank[3] = data.tank[0];
	data.tank[0] = tmp;
	tmp = data.tank[2];
	data.tank[2] = data.tank[1];
	data.tank[1] = tmp;
	header->magic = data.magic;
}

void get_prog_name(asm_t *cor, header_t *header, char *line)
{
	int i = 0;
	int j = 0;
	int cote = 0;

	while (line[i] != '\0') {
		if (line[i] == '"')
			cote++;
		if (j == 0 && line[i] == '"')
			j = i;
		i++;
	}
	error_cote(cor, cote);
	i = j + 1;
	j = 0;
	while (line[i] != '"' && i != PROG_NAME_LENGTH) {
		header->prog_name[j] = line[i];
		j++;
		i++;
	}
	header->prog_name[j] = '\0';
}

void get_comment_text(asm_t *cor, header_t *header, char *line)
{
	int i = 0;
	int j = 0;
	int cote = 0;

	while (line[i] != '\0') {
		if (line[i] == '"')
			cote++;
		if (j == 0 && line[i] == '"')
			j = i;
		i++;
	}
	error_cote(cor, cote);
	i = j + 1;
	j = 0;
	while (line[i] != '"' && i != COMMENT_LENGTH) {
		header->comment[j] = line[i];
		j++;
		i++;
	}
	header->comment[j] = '\0';
}

void check_empty_content(asm_t *cor, char **line, int value)
{
	int i = 0;

	for (i = 0; line[i] != NULL; i++);
	if (i == 1)
		error_specified_header(cor, value);
}

int header_file(asm_t *cor, header_t *header, char **line, char *gnl)
{
	static int name = 0;
	static int comment = 0;
	int tmp = 0;

	if (my_strcmp(line[0], ".name") == 0) {
		check_empty_content(cor, line, 1);
		name++;
		get_prog_name(cor, header, gnl);
		error_header(cor, name, 0);
		tmp++;
	}
	if (my_strcmp(line[0], ".comment") == 0) {
		check_empty_content(cor, line, 2);
		comment++;
		get_comment_text(cor, header, gnl);
		error_header(cor, 0, comment);
		tmp++;
	}
	if (tmp != 0)
		return (1);
	return (0);
}
