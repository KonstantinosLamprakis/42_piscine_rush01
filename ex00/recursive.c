/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:54:02 by klamprak          #+#    #+#             */
/*   Updated: 2024/01/27 23:19:57 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//./a.out "1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7"
//./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 4

int	valid(int board[][SIZE], int row, int column, int guess, int heights[SIZE]);
int	solve(int board[][SIZE], int heights[]);
int find_empty_cell(int board[][SIZE], int *row, int *column);

void	put_str(char *str);
void	print_board(int board[SIZE][SIZE]);
int	*validate_input(char *str);
void	optimize_board(int board[SIZE][SIZE], int input[SIZE * 4]);

int	main(int argc, char *argv[])
{
	int	board[SIZE][SIZE] = {0};
	int	*heights;
	int	row;
	int	column;

	row = 0;
	column = 0;

	if (argc != 2){
		put_str("Error\n");
		return (0);
	}
	heights = validate_input(argv[1]);
	if (heights[0] == -1){
		put_str("Error\n");
		return (0);
	}
	if (solve(board, heights))
	{
		print_board(board);
	}
	else
	{
		put_str("Error: NO SOLUTIONS\n");
		//TODO_print just error
	}
	return (0);
}

int	valid(int board[][SIZE], int row, int column, int guess, int heights[SIZE])
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
	if (height > heights[column])
		return (0);
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
	if (height > heights[column + 4])
		return (0);
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
	if (height > heights[row + 8])
		return (0);
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
	if (height > heights[column + 12])
		return (0);
	return (1);
}

int find_empty_cell(int board[][SIZE], int *row, int *column)
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

int	solve(int board[SIZE][SIZE], int heights[])
{
	int	row;
	int	column;
	int	guess;

	if(!find_empty_cell(board, &row, &column))
		return (1);

	guess = 1;
	while (guess <= SIZE)
	{
		if (valid(board, row, column, guess, heights))
		{
			board[row][column] = guess;
			if(solve(board, heights))
				return (1);
			board[row][column] = 0;
		}
		guess++;
	}
	return (0);
}