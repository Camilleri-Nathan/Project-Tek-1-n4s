/*
** EPITECH PROJECT, 2017
** commands_info_time_and_cycle.c
** File description:
** Need4Stek
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

void	get_info_simtime(void)
{
	write(1, "GET_INFO_SIMTIME\n", 17);
}

int	cycle_wait(int nb_cycle)
{
	write(1, "CYCLE_WAIT:", 11);
	my_put_nbr(nb_cycle);
	write(1, "\n", 1);
	return (SUCCES);
}
