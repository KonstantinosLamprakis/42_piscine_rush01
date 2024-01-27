/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:01:45 by iziane            #+#    #+#             */
/*   Updated: 2024/01/27 19:55:01 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 4

int valid(int[][9], int, int, int);
int solve(int[][9]);
int find_empty_cell(int[][9], int *, int *);

int main() {
  int puzzle[9][9] = {{1, 7, 4, 0, 9, 0, 6, 0, 0},
                      {0, 0, 0, 0, 3, 8, 1, 5, 7},
                      {5, 3, 0, 7, 0, 1, 0, 0, 4},
                      {0, 0, 7, 3, 4, 9, 8, 0, 0},
                      {8, 4, 0, 5, 0, 0, 3, 6, 0},
                      {3, 0, 5, 0, 0, 6, 4, 7, 0},
                      {2, 8, 6, 9, 0, 0, 0, 0, 1},
                      {0, 0, 0, 6, 2, 7, 0, 3, 8},
                      {0, 5, 3, 0, 8, 0, 0, 9, 6}};
  int row = 0;
  int column = 0;

  if (solve(puzzle)) {
	//TODO_print_solution
  }
  else {
    //TODO_no_solution_found
  }

  return 0;
}

int valid(int puzzle[][9], int row, int column, int guess) {
  for (int x = 0; x < 9; ++x) {
    if (puzzle[row][x] == guess) return 0;
    if (puzzle[x][column] == guess) return 0;
  }
  // TODO_check_4_sides_condition
  return 1;
}

int find_empty_cell(int puzzle[][9], int *row, int *column) {
  for (int x = 0; x < 9; x++) {
    for (int y = 0; y < 9; y++) {
      if (!puzzle[x][y]) {
        *row = x;
        *column = y;
        return 1;
      }
    }
  }
  return 0;
}

int solve(int puzzle[][9]) {
  int row;
  int column;

  if(!find_empty_cell(puzzle, &row, &column)) return 1;

  for (int guess = 1; guess < SIZE; guess++) {
    if (valid(puzzle, row, column, guess)) {
      puzzle[row][column] = guess;

      if(solve(puzzle)) return 1;
      puzzle[row][column] = 0;
    }
  }
  return 0;
}