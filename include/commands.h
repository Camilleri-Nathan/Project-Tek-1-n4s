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

int	check_err_parcing(char ***stock);

void 	right_and_left_dir(info_t *info);
void	car_speed(float middle);
void	left_dir(float middle);
void	right_dir(float middle);

#endif /* COMMANDS_H */
