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
	float	length = info->n_left - info->n_right;
	
	fprintf(stderr, "\nlength = %f\n\n", length);	
        if (info->n_left >= info->n_right)
		write(1, "WHEELS_DIR:0.15\n", 16);
	else if(info->n_left < info->n_right)
		write(1, "WHEELS_DIR:-0.15\n", 17);
}

void	car_speed(float middle)
{
	if (middle >= 150)
		write(1, "CAR_FORWARD:0.4\n", 16);
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
	else if (ret == 1) {
		*end = 1;
		return (0);
	} else {
		car_speed(info.middle);
		if (info.middle < 150)
			write(1, "CAR_FORWARD:0\n", 14);
		ret = check_err_parcing(&stock);
		right_and_left_dir(&info);
		ret = check_err_parcing(&stock);
	}
	return (0);
}
