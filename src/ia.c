/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** ia.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_info.h"
#include "commands.h"


void	car_speed(float middle)
{
	fprintf(stderr, "stock = %f\n", middle);
	if (middle >= 2000)
		write(1, "CAR_FORWARD:1\n", 14);
	else if (middle >= 1500)
		write(1, "CAR_FORWARD:0.8\n", 16);
	else if (middle >= 1000)
		write(1, "CAR_FORWARD:0.5\n", 16);
	else if (middle >= 500)
		write(1, "CAR_FORWARD:0.3\n", 16);
	else if (middle < 500)
		write(1, "CAR_FORWARD:0.15\n", 17);
	else
		write(1, "CAR_FORWARD:0\n", 14);
}

void	init_info(info_t *info)
{
	info->n_left = 0;
	info->left = 0;
	info->n_right = 0;
	info->right = 0;
	info->middle = 0;
}

int	ia(int *end, char **stock)
{
	int	ret = 0;
	info_t info;

	init_info(&info);
	get_info_lidar();
	ret = check_err_parcing(&stock);
	parcing_captor(&info, stock);
	if (ret == 84) {
		*end = 1;
		return (0);
	}
	if (ret == 1) {
		*end = 1;
		return (0);
	}
	car_speed(info.middle);
	ret = check_err_parcing(&stock);
	return (0);
}

/*void 	right_and_left_cdir()
{
       	if (n_left > n_right)
		wheels_dir(0.2);
	else if (n_left < n_right)
		wheels_dir(-0.2);
	else if (left <= 50)
}*/
