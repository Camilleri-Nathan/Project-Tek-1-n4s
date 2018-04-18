/*
** EPITECH PROJECT, 2018
** jf
** File description:
** hfdsoq
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"
#include "get_info.h"
#include "my.h"

char	**tab_err(void)
{
	char **tab_error = NULL;
	int fd = 0;
	int index = 0;

	fd = open("./mess_err.txt", O_RDONLY);
	if (fd == -1)
		return (NULL);
	tab_error = malloc(sizeof(char *) * 26);
	if (tab_error == NULL)
		return (NULL);
	while (index < 25) {
		tab_error[index] = get_next_line(fd);
		if (tab_error == NULL)
			return (NULL);
		index++;
	}
	tab_error[index] = NULL;
	close(fd);
	return (tab_error);
}

int	check_wrong_mess(char **stock)
{
	char **tab_error = tab_err();
	int index = 0;

	while (strcmp(tab_error[index], stock[2])) {
		index++;
	}
	if (index == 25)
		return (84);
	if (strcmp(stock[0], my_int_to_str(index)) == 0)
		return (0);
	return (84);
}

int	check_end(char **stock)
{
	int index = 0;
	int count = 0;

	while (stock[index])
		index++;
	index--;
	while (stock[index][count] != '\0') {
		if (stock[index][count] == '-' &&
		    stock[index][count + 1] == '1') {
			return (84);
		}
		count++;
	}
	return (0);
}

int	check_err_parcing(char ***stock)
{
	char *line = get_next_line(0);

	*stock = do_double_arr(line);
	fprintf(stderr, "line: %s\n", line);
	if (*stock == NULL)
		return (84);
	if (check_wrong_mess(*stock) == 84) {
		return (84);
	}
	if (check_end(*stock))
		return (1);
	return (0);
}

void	parcing_captor(info_t *info, char **stock)
{
	info->n_left = (atof(stock[4]) + atof(stock[5])) / 2;
	info->left = (atof(stock[12]) + atof(stock[13])) / 2;
	info->middle = (atof(stock[19]) + atof(stock[20])) / 2;
	info->n_right = (atof(stock[25]) + atof(stock[26])) / 2;
	info->right = (atof(stock[32]) + atof(stock[33])) / 2;
}

int	main(void)
{
	int	quit= 0;
	char	**stock = NULL;
	int	end = 0;

	write(1, "START_SIMULATION\n", 17);
	quit = check_err_parcing(&stock);
	if (atoi(stock[0]) != 1)
		return (84);
	if (quit == 84)
		return (84);
	while (end == 0) {
		ia(&end, stock);
	}
	write(1, "CAR_FORWARD:0,15\n", 17);
	check_err_parcing(&stock);
	write(1, "STOP_SIMULATION\n", 16);
	quit = check_err_parcing(&stock);
	if (quit == 1) {
		return (0);
	}
	else if (quit == 84)
		return (84);
	return (0);
}
