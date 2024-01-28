/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 01:25:52 by klamprak          #+#    #+#             */
/*   Updated: 2024/01/28 22:15:50 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 7

// each function counts how many boxes can you see from the coresponding view
int	is_col_up_valid(int board[SIZE][SIZE], int col, int h_ar[SIZE])
{
	int	i;
	int	height;
	int	max;

	i = 0;
	height = 0;
	max = 0;
	while (i < SIZE)
	{
		if (board[i][col] > max)
		{
			height++;
			max = board[i][col];
		}
		i++;
	}
	if (height != h_ar[col])
		return (0);
	return (1);
}

int	is_col_down_valid(int board[SIZE][SIZE], int col, int h_ar[SIZE])
{
	int	i;
	int	height;
	int	max;

	i = SIZE - 1;
	height = 0;
	max = 0;
	while (i >= 0)
	{
		if (board[i][col] > max)
		{
			height++;
			max = board[i][col];
		}
		i--;
	}
	if (height != h_ar[col + SIZE])
		return (0);
	return (1);
}

int	is_row_left_valid(int board[SIZE][SIZE], int row, int h_ar[SIZE])
{
	int	i;
	int	height;
	int	max;

	i = 0;
	height = 0;
	max = 0;
	while (i < SIZE)
	{
		if (board[row][i] > max)
		{
			height++;
			max = board[row][i];
		}
		i++;
	}
	if (height != h_ar[row + SIZE * 2])
		return (0);
	return (1);
}

int	is_row_rig_val(int board[SIZE][SIZE], int row, int h_ar[SIZE])
{
	int	i;
	int	height;
	int	max;

	i = SIZE - 1;
	height = 0;
	max = 0;
	while (i >= 0)
	{
		if (board[row][i] > max)
		{
			height++;
			max = board[row][i];
		}
		i--;
	}
	if (height != h_ar[row + SIZE * 3])
		return (0);
	return (1);
}
