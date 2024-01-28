/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:54:02 by klamprak          #+#    #+#             */
/*   Updated: 2024/01/28 05:10:18 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
// ./a.out "3 1 2 3 2 2 3 1 2 2 1 3 3 2 2 1"
// ./a.out "3 2 2 1 1 3 2 2 3 2 3 1 1 3 2 2"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define S 4
// declarations of this file main.c
int		valid(int board[S][S], int row, int column, int guess);
int		solve(int board[S][S], int inp_heigh_arr[16]);
int		find_empty_cell(int board[S][S], int *row, int *column);
int		validate_all(int board[S][S], int inp_heigh_arr[16]);
void	put_str(char *str);
// declarations of util.c
void	print_board(int board[S][S]);
int		validate_input(char *str, int *input_arr);
void	initialize_table(int board[S][S]);
// declarations of valid.c
int		is_col_up_valid(int board[S][S], int col, int h_ar[S]);
int		is_col_down_valid(int board[S][S], int col, int h_ar[S]);
int		is_row_left_valid(int board[S][S], int row, int h_ar[S]);
int		is_row_rig_val(int board[S][S], int row, int h_ar[S]);

int	main(int argc, char *argv[])
{
	int	board[S][S];
	int	*inp_heigh_arr;
	int	row;
	int	column;

	initialize_table(board);
	row = 0;
	column = 0;
	if (argc != 2)
	{
		put_str("Error\n");
		return (0);
	}
	inp_heigh_arr = malloc(S * S * sizeof(int));
	if (!validate_input(argv[1], inp_heigh_arr))
	{
		put_str("Error\n");
		return (0);
	}
	if (solve(board, inp_heigh_arr))
		print_board(board);
	else
		put_str("Error TODO not solution\n");
}

int	valid(int board[S][S], int row, int column, int guess)
{
	int	i;

	i = 0;
	while (i < S)
	{
		if (board[row][i] == guess)
			return (0);
		if (board[i][column] == guess)
			return (0);
		i++;
	}
	return (1);
}

int	find_empty_cell(int board[S][S], int *row, int *column)
{
	int	x;
	int	y;

	x = 0;
	while (x < S)
	{
		y = 0;
		while (y < S)
		{
			if (!board[x][y])
			{
				*row = x;
				*column = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	solve(int board[S][S], int inp_heigh_arr[16])
{
	int	row;
	int	column;
	int	guess;

	if (!find_empty_cell(board, &row, &column))
	{
		return (validate_all(board, inp_heigh_arr));
	}
	guess = 1;
	while (guess <= S)
	{
		if (valid(board, row, column, guess))
		{
			board[row][column] = guess;
			if (solve(board, inp_heigh_arr))
				return (1);
			board[row][column] = 0;
		}
		guess++;
	}
	return (0);
}

int	validate_all(int board[S][S], int inp_heigh_arr[16])
{
	int	row;
	int	column;
	int	is_v;

	row = 0;
	is_v = 1;
	while (row < S && is_v)
	{
		column = 0;
		while (column < S && is_v)
		{
			is_v = is_v && is_col_up_valid(board, column, inp_heigh_arr);
			is_v = is_v && is_col_down_valid(board, column, inp_heigh_arr);
			is_v = is_v && is_row_left_valid(board, row, inp_heigh_arr);
			is_v = is_v && is_row_rig_val(board, row, inp_heigh_arr);
			column++;
		}
		row++;
	}
	return (is_v);
}
