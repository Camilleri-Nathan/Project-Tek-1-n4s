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
	float	middle = info->middle;

	if (info->n_left >= info->n_right) {
		if (middle > 2500)
			write(1, "WHEELS_DIR:0.02\n", 16);
		else if (middle > 2000)
			write(1, "WHEELS_DIR:0.05\n", 16);
		else if (middle > 1500)
			write(1, "WHEELS_DIR:0.08\n", 16);
		else if (middle > 1000)
			write(1, "WHEELS_DIR:0.10\n", 16);
		else if (middle > 500)
			write(1, "WHEELS_DIR:0.15\n", 16);
		else if (middle > 350)
			write(1, "WHEELS_DIR:0.3\n", 15);
		else if (middle > 100)
			write(1, "WHEELS_DIR:0.4\n", 15);
	} else {
		if (middle > 2500)
			write(1, "WHEELS_DIR:-0.02\n", 17);
		else if (middle > 2000)
			write(1, "WHEELS_DIR:-0.05\n", 17);
		else if (middle > 1500)
			write(1, "WHEELS_DIR:-0.08\n", 17);
		else if (middle > 1000)
			write(1, "WHEELS_DIR:-0.10\n", 17);
		else if (middle > 500)
			write(1, "WHEELS_DIR:-0.15\n", 17);
		else if (middle > 350)
			write(1, "WHEELS_DIR:-0.3\n", 16);
		else if (middle > 100)
			write(1, "WHEELS_DIR:-0.4\n", 16);
	}
}

void	car_speed(float middle)
{
	if (middle >= 2000)
		write(1, "CAR_FORWARD:1\n", 14);
	else if (middle >= 1500)
		write(1, "CAR_FORWARD:0.75\n", 17);
	else if (middle >= 1000)
		write(1, "CAR_FORWARD:0.5\n", 16);
	else if (middle >= 600)
		write(1, "CAR_FORWARD:0.4\n", 16);
	else if (middle >= 400)
		write(1, "CAR_FORWARD:0.3\n", 16);
	else if (middle >= 200)
		write(1, "CAR_FORWARD:0.2\n", 16);
	else if (middle >=95)
		write(1, "CAR_FORWARD:0.05\n", 17);
	else if (middle < 95)
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
	info_t	info;

	init_info(&info);
	write(1, "GET_INFO_LIDAR\n", 15);
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
		ret = check_err_parcing(&stock);
		right_and_left_dir(&info);
		ret = check_err_parcing(&stock);
	}
	return (0);
}
