/*
** EPITECH PROJECT, 2017
** epitech,project 2017
** File description:
** epitech,project corewar 2017
*/

#include "my.h"

void my_elseq(champion_t *champ, corewar_t *structure, char *binary, int n1)
{
	int n2 = 0;
	int S = 0;
	int n3 = structure->map[champ->pc + 6];
	int save = 0;

	if (n1 == 0 && n2 == 0) {
		n1 = structure->map[champ->pc + 2];
		if ((binary[2] == '1' && binary[3] == '1') ||
		(binary[2] == '1' && binary[3] == '0'))
			n2 = two_bytes_to_int(structure->map[champ->pc + 3],
			structure->map[champ->pc + 4]);
		else
			n2 = structure->map[champ->pc + 3];
		champ->pc += binary[2] == '0' && binary[3] == '1' ? 4 : 5;
		S = structure->map[(save + n1)] + n2;
		champ->registre[n3] = structure->map[save + S];
		champ->pc = champ->pc % MEM_SIZE;
		champ->carry = S;
	}
}

int if_else_ldi2(char *binary, int n2, champion_t *champ, corewar_t *structure)
{
	if ((binary[2] == '1' && binary[3] == '1')||
	(binary[2] == '1' && binary[3] == '0')) {
		n2 = two_bytes_to_int(structure->map[champ->pc + 4],
		structure->map[champ->pc + 5]);
		champ->pc += 6;
	}
	else {
		n2 = structure->map[champ->pc + 4];
		champ->pc += 5;
	}
	return (n2);
}

void func_lldi(champion_t *champ, corewar_t *structure)
{
	int n1 = 0;
	int n3 = structure->map[champ->pc + 6];
	int S = 0;
	char *binary = my_put_base(structure->map[champ->pc + 1], 2);
	int save = champ->pc;

	my_strlen(binary) == 7 ? binary = my_strcat("0", binary) : 0;
	for (int n2 = 0; binary[0] == '1' && binary[1] == '1'; n2 = 1) {
		n1 = two_bytes_to_int(structure->map[champ->pc + 2],
		structure->map[champ->pc + 3]);
		n2 = if_else_ldi2(binary, n2, champ, structure);
		S = structure->map[(save + n1)] + n2;
		champ->registre[n3] = structure->map[save + S];
		champ->pc = champ->pc % MEM_SIZE;
		champ->carry = S;
	}
	my_elseq(champ, structure, binary, n1);
}
