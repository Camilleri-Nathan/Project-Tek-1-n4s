/*
** EPITECH PROJECT, 2017
** commands_info_car.c
** File description:
** Need4Stek
*/

#include <unistd.h>
#include <stdio.h>

void	get_info_lidar(void)
{
	write(1, "GET_INFO_LIDAR\n", 15);
}

void	get_current_speed(void)
{
	write(1, "GET_CURRENT_SPEED\n", 18);
}

void	get_current_wheels(void)
{
	write(1, "GET_CURRENT_WHEELS\n", 19);
}

void	get_car_speed_max(void)
{
	write(1, "GET_CAR_SPEED_MAX\n", 18);
}

void	get_car_speed_min(void)
{
	write(1, "GET_CAR_SPEED_MIN\n", 18);
}
