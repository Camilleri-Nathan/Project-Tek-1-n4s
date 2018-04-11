/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** structure for different answer
*/

#ifndef	ANSWER_TYPE_H_
#define	ANSWER_TYPE_H_

typedef struct type_one
{
	unsigned int	id;
	char		*status;
	char		*code_str;
}type_one_t;

typedef struct type_two
{
	unsigned int	id;
	char		*status;
	char		*code_str;
	float		add_info[32];
}type_two_t;

typedef struct type_three
{
	unsigned int	id;
	char		*status;
	char		*code_str;
	float		other_info;
}type_three_t;

typedef struct type_four
{
	unsigned int	id;
	char		*status;
	char		*code_str;
	long		time_past[2];
}type_four_t;

#endif		/* ANSWER_TYPE_H_ */
