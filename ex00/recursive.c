/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:54:02 by klamprak          #+#    #+#             */
/*   Updated: 2024/01/28 01:13:45 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
// ./a.out "3 1 2 3 2 2 3 1 2 2 1 3 3 2 2 1"
// ./a.out "3 2 2 1 1 3 2 2 3 2 3 1 1 3 2 2"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 4

int		valid(int board[SIZE][SIZE], int row, int column, int guess, int heights[SIZE]);
int		solve(int board[SIZE][SIZE], int inp_heigh_arr[SIZE * 4]);
int		find_empty_cell(int board[SIZE][SIZE], int *row, int *column);
void	put_str(char *str);
void	print_board(int board[SIZE][SIZE]);
int		validate_input(char *str, int *input_arr);
void	initialize_table(int board[SIZE][SIZE]);

int	main(int argc, char *argv[])
{
	int	board[SIZE][SIZE];
	int	*inp_heigh_arr;
	int	row;
	int	column;

	initialize_table(board);
	row = 0;
	column = 0;
	if (argc != 2){
		put_str("Error\n");
		return (0);
	}
	inp_heigh_arr = malloc(SIZE * SIZE * sizeof(int));
	if (!validate_input(argv[1], inp_heigh_arr)){
		put_str("Error\n");
		return (0);
	}
	if (solve(board, inp_heigh_arr))
		print_board(board);
	else
		put_str("Error TODO not solution\n");
}

// int	is_height_valid(int board[][SIZE], int row, int column, int guess, int inp_heigh_arr[SIZE])
// {
// 	int	i;
// 	int	height;
// 	int	max;
// 	// colup check
// 	i = 0;
// 	height = 0;
// 	max = 0;
// 	while(i < SIZE)
// 	{
// 		if(board[i][column] > max)
// 		{
// 			height++;
// 			max = board[i][column];
// 		}
// 		i++;
// 	}
// 	if (height > inp_heigh_arr[column])
// 		return (0);
// }

int	valid(int board[SIZE][SIZE], int row, int column, int guess, int inp_heigh_arr[SIZE])
{
	int	i;
	int	height;
	int	max;

	i = 0;
	while (i < SIZE)
	{
		if (board[row][i] == guess)
			return (0);
		if (board[i][column] == guess)
			return (0);
		i++;
	}
	// colup check
	i = 0;
	height = 0;
	max = 0;
	while(i < SIZE)
	{
		if(board[i][column] > max)
		{
			height++;
			max = board[i][column];
		}
		i++;
	}
	if (height > inp_heigh_arr[column])
		return (0);
	printf("\ncolup height: %d\n", height);
	// coldown check
	i = SIZE - 1;
	height = 0;
	max = 0;
	while(i >= 0)
	{
		if(board[i][column] > max)
		{
			height++;
			max = board[i][column];
		}
		i--;
	}
	if (height > inp_heigh_arr[column + 4])
		return (0);
	printf("\ncoldown height: %d\n", height);
	// rowleft check
	i = 0;
	height = 0;
	max = 0;
	while(i < SIZE)
	{
		if(board[row][i] > max)
		{
			height++;
			max = board[row][i];
		}
		i++;
	}
	if (height > inp_heigh_arr[row + 8])
		return (0);
	printf("\nrowleft height: %d\n", height);
	// rowright check
	i = SIZE - 1;
	height = 0;
	max = 0;
	while(i >= 0)
	{
		if(board[row][i] > max)
		{
			height++;
			max = board[row][i];
		}
		i--;
	}
	printf("\nrowright height: %d\n", height);
	if (height > inp_heigh_arr[row + 12])
		return (0);
	return (1);
}

int find_empty_cell(int board[SIZE][SIZE], int *row, int *column)
{
	int	x;
	int	y;

	x = 0;
	while(x < SIZE)
	{
		y = 0;
		while (y < SIZE)
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

int	solve(int board[SIZE][SIZE], int inp_heigh_arr[SIZE * 4])
{
	int	row;
	int	column;
	int	guess;

	if(!find_empty_cell(board, &row, &column))
		return (1);
	guess = 1;
	while (guess <= SIZE)
	{
		if (valid(board, row, column, guess, inp_heigh_arr))
		{
			board[row][column] = guess;
			if(solve(board, inp_heigh_arr))
				return (1);
			board[row][column] = 0;
		}
		guess++;
	}
	return (0);
}