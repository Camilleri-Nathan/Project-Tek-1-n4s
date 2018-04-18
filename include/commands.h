/*
** EPITECH PROJECT, 2017
** commands.h
** File description:
** Need4Stek
*/


#ifndef COMMANDS_H
#define COMMANDS_H

/* commands_simulations */
void	start_simulation(void);
void	stop_simulation(void);

/* commands_move_car */
int	car_forward(float speed);
int	car_backwards(float speed);
int	wheels_dir(float angle);

/* commands_info_car */
void	get_info_lidar(void);
void	get_current_speed(void);
void	get_current_wheels(void);
void	get_car_speed_max(void);
void	get_car_speed_min(void);

/*commands_info_time_and_cycle*/
void	get_info_simtime(void);
int	cycle_wait(int nb_cycle);

#endif /* COMMANDS_H */
