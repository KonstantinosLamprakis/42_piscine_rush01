/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:54:02 by klamprak          #+#    #+#             */
/*   Updated: 2024/01/27 21:02:13 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO ./a.out "1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 4

int	valid(int[][SIZE], int, int, int);
int	solve(int[][SIZE]);
int	find_empty_cell(int[][SIZE], int *, int *);

void	put_str(char *str);
void	print_board(int board[SIZE][SIZE]);
int	*validate_input(char *str);
void	optimize_board(int board[SIZE][SIZE], int input[SIZE * 4]);

int	main(int argc, char *argv[])
{
	int	board[SIZE][SIZE] = {0};
	int	*input;
	int	row;
	int	column;

	row = 0;
	column = 0;

	if (argc != 2){
		put_str("Error\n");
		return (0);
	}
	input = validate_input(argv[1]);
	if (input[0] == -1){
		put_str("Error\n");
		return (0);
	}
	if (solve(board))
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

int	valid(int board[][SIZE], int row, int column, int guess)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (board[row][i] == guess)
			return (0);
		if (board[i][column] == guess)
			return (0);
		i++;
	}
	// TODO_check_4_sides_condition
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

int	solve(int board[][SIZE])
{
	int	row;
	int	column;
	int	guess;

	if(!find_empty_cell(board, &row, &column))
		return (1);

	guess = 1;
	while (guess <= SIZE)
	{
		if (valid(board, row, column, guess))
		{
			board[row][column] = guess;
			if(solve(board))
				return (1);
			board[row][column] = 0;
		}
		guess++;
	}
	return (0);
}