/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 01:25:52 by klamprak          #+#    #+#             */
/*   Updated: 2024/01/28 04:59:50 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define SIZE 4

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
	if (height > h_ar[col])
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
	if (height > h_ar[col + 4])
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
	if (height > h_ar[row + 8])
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
	if (height > h_ar[row + 12])
		return (0);
	return (1);
}
