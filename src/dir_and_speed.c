/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** left_and_dir
*/

#include "get_info.h"
#include <unistd.h>

void	left_dir(float middle)
{
	if (middle > 2000)
		write(1, "WHEELS_DIR:-0.02\n", 17);
	else if (middle > 1800)
		write(1, "WHEELS_DIR:-0.05\n", 17);
	else if (middle > 1500)
		write(1, "WHEELS_DIR:-0.08\n", 17);
	else if (middle > 1000)
		write(1, "WHEELS_DIR:-0.10\n", 17);
	else if (middle > 500)
		write(1, "WHEELS_DIR:-0.15\n", 17);
	else if (middle > 350)
		write(1, "WHEELS_DIR:-0.3\n", 16);
	else if (middle > 200)
		write(1, "WHEELS_DIR:-0.4\n", 16);
	else if (middle > 100)
		write(1, "WHEELS_DIR:-0.5\n", 16);
	else if (middle > 50)
		write(1, "WHEELS_DIR:-0.65\n", 17);
	else
		write(1, "WHEELS_DIR:-0.9\n", 16);
}

void	right_dir(float middle)
{
	if (middle > 2000)
		write(1, "WHEELS_DIR:0.02\n", 16);
	else if (middle > 1800)
		write(1, "WHEELS_DIR:0.05\n", 16);
	else if (middle > 1500)
		write(1, "WHEELS_DIR:0.08\n", 16);
	else if (middle > 1000)
		write(1, "WHEELS_DIR:0.10\n", 16);
	else if (middle > 500)
		write(1, "WHEELS_DIR:0.15\n", 16);
	else if (middle > 350)
		write(1, "WHEELS_DIR:0.3\n", 15);
	else if (middle > 200)
		write(1, "WHEELS_DIR:0.4\n", 15);
	else if (middle > 100)
		write(1, "WHEELS_DIR:0.5\n", 15);
	else if (middle > 100)
		write(1, "WHEELS_DIR:0.65\n", 16);
	else
		write(1, "WHEELS_DIR:0.9\n", 15);
}


void 	right_and_left_dir(info_t *info)
{
	float	middle = info->middle;

	if (info->n_left >= info->n_right) {
		right_dir(middle);
	} else {
		left_dir(middle);
	}
}

void	car_speed(float middle)
{
	if (middle >= 1800)
		write(1, "CAR_FORWARD:1\n", 14);
	else if (middle >= 1700)
		write(1, "CAR_FORWARD:0.9\n", 17);
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
	else if (middle >= 100)
		write(1, "CAR_FORWARD:0.1\n", 16);
	else if (middle >= 50)
		write(1, "CAR_FORWARD:0.05\n", 17);
	else
		write(1, "CAR_FORWARD:0\n", 14);
}
