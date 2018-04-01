/*
** EPITECH PROJECT, 2017
** Header file
** File description:
** Library tools
*/

#ifndef _TOOLS_H_
	#define _TOOLS_H_

	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>

	void my_putchar(char c);
	void remove_space(char *str);
	void remove_tab(char *str);
	char *replace_tab(char *str);
	int my_put_nbr(int nb);
	int my_putstr(char const *str);
	int my_strlen(char const *str);
	int my_getnbr(char const *str);
	char *my_strcat(char *str1, char *str2);
	char **my_str_to_word_array(char *str, char separator);
	char *my_read(int fd);
	int my_strcmp(char const *s1, char const *s2);
	char *my_revstr(char *str);
	int my_str_isnum(char const *str);
#endif
