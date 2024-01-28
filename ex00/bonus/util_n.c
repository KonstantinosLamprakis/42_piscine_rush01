/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:01:45 by iziane            #+#    #+#             */
/*   Updated: 2024/01/28 22:15:42 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 7

// just initialize table with 0
void	initialize_table(int board[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

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

// just print all the table
void	print_board(int board[SIZE][SIZE])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			put_str(" ");
			j++;
		}
		put_str("\n");
		i++;
	}
}

// not 2 spaces in the row, not space at the start or at the end
// no ther character than digits from 1 to size
int	validate_input(char *str, int *input_arr)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] > '0' && str[i] <= '0' + SIZE)
		{
			input_arr[counter] = str[i] - '0';
			counter++;
		}
		else if (!(str[i] == ' ' && str[i + 1] != ' '))
			return (0);
		i++;
	}
	if (counter != (SIZE * 4) || str[i - 1] == ' ' || str[0] == ' ')
		return (0);
	return (1);
}
