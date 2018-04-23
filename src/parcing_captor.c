/*
** EPITECH PROJECT, 2017
** parcing_captor.c
** File description:
** need4stek
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

void	parcing_captor(info_t *info, char **stock)
{
	info->n_left = (atof(stock[4]) + atof(stock[5])) / 2;
	info->left = (atof(stock[12]) + atof(stock[13])) / 2;
	info->middle = (atof(stock[19]) + atof(stock[20])) / 2;
	info->right = (atof(stock[25]) + atof(stock[26])) / 2;
	info->n_right = (atof(stock[32]) + atof(stock[33])) / 2;
}
