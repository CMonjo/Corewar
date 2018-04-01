/*
** EPITECH PROJECT, 2017
** Project Corewar ASM
** File description:
** Main file
*/

#include "../include/main.h"

void check_comment_line(char *gnl)
{
	int i = 0;

	while (gnl[i] != '\0') {
		if (gnl[i] == '#') {
			gnl[i] = '\0';
			return;
		}
		i++;
	}
}

char *replace_tab_to_space(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '\t')
			str[i] = ' ';
	return (str);
}

char *remove_empty_tab(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			return (str);
	free(str);
	return (NULL);
}

int get_label_index(char **line)
{
	int i = 0;
	int index = 0;

	while (line[0][i] != '\0') {
		if (line[0][i] == ':')
			index = 1;
		i++;
	}
	for (; line[index] && line[index][0] == 0; index++);
	return (index);
}

char *clean_parameters(char *line)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(line) + 1));
	int i = my_strlen(line) - 1;
	int j = i;

	for (; line[j] == ' ' || line[j] == '\t'; i--, j--);
	for (j = 0; i != 0; i--, j++) {
		if (line[i] == ' ')
			break;
		tmp[j] = line[i];
		tmp[j + 1] = '\0';
	}
	tmp = my_revstr(tmp);
	free(line);
	return (tmp);
}
