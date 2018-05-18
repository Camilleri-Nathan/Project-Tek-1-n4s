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

void	init_info(info_t *info)
{
	info->n_left = 0;
	info->left = 0;
	info->n_right = 0;
	info->right = 0;
	info->middle = 0;
}

int	check_ret(int ret, int *end)
{
	if (ret == 1) {
		write(1, "STOP_SIMULATION\n", 16);
		*end = 1;
		return (0);
	}
	return (1);
}

int	car_movment(info_t info, char **stock, int *end)
{
	int	ret = 0;

	car_speed(info.middle);
	ret = check_err_parcing(&stock);
	if (check_ret(ret, end) == 0)
		return (0);
	right_and_left_dir(&info);
	ret = check_err_parcing(&stock);
	if (check_ret(ret, end) == 0)
		return (0);
	return (1);
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
	if (check_ret(ret, end) == 0)
		return (0);
	else {
		if (car_movment(info, stock, end) == 0)
			return (0);
	}
	return (0);
}
