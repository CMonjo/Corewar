/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include "tools.h"
	#include "op.h"

	#define READ_SIZE 1

	typedef struct list_s
	{
		char *name;
		struct list_s *next;
	} list_t;

	typedef struct asm_s {
		char *filepath;
		char *filepath_dot_cor;
		int line;
		int start;
		int size;
		int nbr_labels;
		list_t *labels;
	} asm_t;

	union data {
		int magic;
		char tank[4];
	};

	union psize {
		int value;
		char str[4];
	};

	int main();
	void create_file();
	void get_name_file();
	void file_modification();
	int get_label_index();
	char *clean_parameters();
	void file_edit();
	void get_magic_number();
	void get_prog_name();
	void get_comment_text();
	void error_cote();
	void error_header();
	void error_instructions();
	void check_parameters();
	int parameters_verification();
	int parameters_register();
	void check_direct_prog_size();
	void line_read();
	void register_error();
	int header_file();
	void check_prog_size();
	char *remove_empty_tab();
	void check_comment_line();
	void error_display();
	void error_specified_header();
#endif
