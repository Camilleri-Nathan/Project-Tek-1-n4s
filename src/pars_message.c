/*
** EPITECH PROJECT, 2018
** need_for_steck
** File description:
** parsing message api
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

void	free_tab_error(char **tab_error)
{
	int	count = 0;

	while (tab_error[count] != NULL) {
		free(tab_error[count]);
		count++;
	}
	free(tab_error);
}

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
	char	**tab_error = tab_err();
	int	index = 0;
	int	arraylen = my_arraylen((char const **)stock);
	char	*number = NULL;

	if (arraylen <= 2)
		return (84);
	while (tab_error[index] != NULL) {
		if (stock[2] && strcmp(tab_error[index], stock[2]) != 0) {
			index++;
		}
		else
			break;
	}
	if (index == 25) {
		free_tab_error(tab_error);
		return (84);
	}
	number = my_int_to_str(index);
	if (strcmp(stock[0], number) == 0) {
		free(number);
		free_tab_error(tab_error);
		return (0);
	}
	free(number);
	free_tab_error(tab_error);
	return (84);
}

int	check_end(char **stock)
{
	int index = 0;
	int count = 0;

	while (stock[index])
		index++;
	index -= 2;
	if (strcmp(stock[index], "Track Cleared") == 0)
		return (84);
	index = 0;
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
	free(line);
	if (*stock == NULL) {
		exit (84);
	}
	if (check_wrong_mess(*stock) == 84) {
		return (84);
	}
	if (check_end(*stock) == 84) {
		return (1);
	}
	return (0);
}
