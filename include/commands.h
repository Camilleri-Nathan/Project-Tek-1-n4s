/*
** EPITECH PROJECT, 2017
** commands.h
** File description:
** Need4Stek
*/


#ifndef COMMANDS_H
#define COMMANDS_H

/* commands_move_car */
int	car_forward(float speed);
int	car_backwards(float speed);
int	wheels_dir(float angle);

/* commands_info_car */
void	get_info_lidar(void);

#endif /* COMMANDS_H */
