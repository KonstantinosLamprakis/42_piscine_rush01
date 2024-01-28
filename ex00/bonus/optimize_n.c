/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:59:18 by klamprak          #+#    #+#             */
/*   Updated: 2024/01/28 22:26:29 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 7

// Paterns:
// is_pattern:
// for x height on side: MAX should be at least x more cells far from the start
// same as above: MAX - 1 should be at least x - 1 cell, MAX - 2 at least x - 2
// initialize:
// for MAX height on side: we fill all cells ex. 1 2 3 4
// for MIN height on side: you put the MAX first ex. 4
// if left_side + right_side == MAX + 1, then at x position(from either side)
// is the MAX (same for up-down)
// periodically:
// if i the position of max(start counting from 0) and x = i + 1 then all
// positions should be filled by sequent

int	is_pattern(int row, int col, int guess, int h_ar[SIZE])
{
	int	temp;

	temp = (guess - SIZE + h_ar[col] - 1);
	if (temp > -1 && temp < SIZE && temp > row)
		return (0);
	temp = 2 * SIZE - guess - h_ar[col + SIZE];
	if (temp > -1 && temp < SIZE && temp < row)
		return (0);
	temp = (guess - SIZE + h_ar[row + SIZE * 2] - 1);
	if (temp > -1 && temp < SIZE && temp > col)
		return (0);
	temp = 2 * SIZE - guess - h_ar[row + SIZE * 3];
	if (temp > -1 && temp < SIZE && temp < col)
		return (0);
	return (1);
}

void	fill_the_min(int board[SIZE][SIZE], int i)
{
	if (i < SIZE)
		board[0][i] = SIZE;
	else if (i < SIZE * 2)
		board[SIZE - 1][i - SIZE] = SIZE;
	else if (i < SIZE * 3)
		board[i - 2 * SIZE][0] = SIZE;
	else if (i < SIZE * 4)
		board[i - SIZE * 3][SIZE - 1] = SIZE;
}

void	fill_the_max(int board[SIZE][SIZE], int row, int col, int rev)
{
	int	j;

	j = 0;
	if (row == -1)
	{
		while (j < SIZE)
		{
			if (rev)
				board[j][col - SIZE] = SIZE - j;
			else
				board[j][col] = j + 1;
			j++;
		}
	}
	else
	{
		while (j < SIZE)
		{
			if (rev)
				board[row - SIZE * 3][j] = SIZE - j;
			else
				board[row - SIZE * 2][j] = j + 1;
			j++;
		}
	}
}

void	fill_based_on_sum(int board[SIZE][SIZE], int h_ar[SIZE])
{
	int	i;

	i = 0;
	while (i < SIZE * 4)
	{
		if (i < SIZE)
		{
			if (h_ar[i] + h_ar[i + 4] == SIZE + 1)
				board[h_ar[i] - 1][i] = SIZE;
		}
		if (i >= 2 * SIZE && i < 3 * SIZE)
		{
			if (h_ar[i] + h_ar[i + 4] == SIZE + 1)
				board[i - SIZE * 2][h_ar[i] - 1] = SIZE;
		}
		i++;
	}
}

// check if 1 or SIZE values exists on heights table and fill the board
void	fill_board(int board[SIZE][SIZE], int h_ar[SIZE])
{
	int	i;

	i = 0;
	while (i < SIZE * 4)
	{
		if (h_ar[i] == 1)
		{
			fill_the_min(board, i);
		}
		if (h_ar[i] == SIZE)
		{
			if (i < SIZE)
				fill_the_max(board, -1, i, 0);
			else if (i < SIZE * 2)
				fill_the_max(board, -1, i, 1);
			else if (i < SIZE * 3)
				fill_the_max(board, i, -1, 0);
			else if (i < SIZE * 4)
				fill_the_max(board, i, -1, 1);
		}
		i++;
	}
}
