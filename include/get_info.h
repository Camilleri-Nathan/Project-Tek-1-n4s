/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** get info
*/

#ifndef GET_INFO_H_
#define GET_INFO_H_

typedef struct info_s
{
	float n_left;
	float left;
	float middle;
	float right;
	float n_right;
}info_t;

char	**do_double_arr(char *str);
int	check_err_parcing(char ***stock);
void	parcing_captor(info_t *info, char **stock);
int     ia(int *end, char **stock);

#endif /* GET_INFO_H_ */
