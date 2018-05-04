/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** left_and_dir
*/

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
