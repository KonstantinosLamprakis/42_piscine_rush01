/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:01:45 by iziane            #+#    #+#             */
/*   Updated: 2024/01/27 20:58:34 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 4

void	put_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_board(int board[SIZE][SIZE])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while(i < SIZE)
	{
		j = 0;
		while(j < SIZE)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			j++;
		}
		c = '\n';
		write(1, &c, 1);
		i++;
	}
}

int	*validate_input(char *str)
{
	int	i;
	int	*input_arr;
	int	is_space;
	int	is_valid;
	int	counter;

	i = 0;
	counter = 0;
	is_space = 0;
	is_valid = 1;
	input_arr = malloc(SIZE * 4 * sizeof(int));
	while (str[i] != '\0' && is_valid)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			is_space = 1;
			input_arr[counter] = str[i] - '0';
			counter++;
		}
		else if ((str[i] == ' ' && is_space))
			is_space = 0;
		else
			is_valid = 0;
		i++;
	}
	if (!is_valid || counter != (SIZE * 4) || str[i - 1] == ' ')
		input_arr[0] = -1;
	return (input_arr);
}

void	optimize_board(void	put_str(char *str), int input[SIZE * 4])
{
	//TODO place the right number based on patterns to save time
}