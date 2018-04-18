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

int	ia(int *end)
{
	int	ret = 0;
	char	**stock = NULL;
	info_t info;

	init_info(&info);
	if (info.middle == 0) {
		get_info_lidar();
		fprintf(stderr, "Info lidar ok\n");
   		ret = check_err_parcing(&stock);
		fprintf(stderr, "Read ok\n");
		parcing_captor(&info, stock);
  		fprintf(stderr, "Parse ok\n");
		if (ret == 84) {
			*end = 1;
			return (0);
		}
		fprintf(stderr, "ret_1: %d\n", ret);
		if (ret == 1) {
			*end = 1;
			return (0);
		}
		fprintf(stderr, "ret_2: %d\n", ret);
		car_speed(info.middle);
		fprintf(stderr, "ret_3: %d\n", ret);
	}
	fprintf(stderr, "ret_4: %d\n", ret);
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
