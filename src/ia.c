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

void 	right_and_left_dir(info_t *info)
{
	if (((info->n_left - info->n_right) < 50) || ((info->left - info->right) < 50))
		write(1, "WHEELS_DIR:0.3\n", 15);
	else if(((info->n_left - info->n_right) < -50) || ((info->left - info->right) < -50))
		write(1, "WHEELS_DIR:-0.3\n", 16);
	else
		write(1, "WHEELS_DIR:0\n", 13);
}

void	car_speed(float middle)
{
	fprintf(stderr, "\nstock = %f\n\n", middle);
	if (middle >= 10000)
		write(1, "CAR_FORWARD:1\n", 14);
	else if (middle >= 5000)
		write(1, "CAR_FORWARD:0.7\n", 16);
	else if (middle >= 1000)
		write(1, "CAR_FORWARD:0.4\n", 16);
	else if (middle >= 500)
		write(1, "CAR_FORWARD:0.3\n", 16);
	else
		write(1, "CAR_FORWARD:0,15\n", 17);
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
	info_t	info;

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
	if (info.middle < 95)
                        write(1, "CAR_FORWARD:0\n", 14);
	ret = check_err_parcing(&stock);
	right_and_left_dir(&info);
	ret = check_err_parcing(&stock);
	sleep(2);
	return (0);
}

