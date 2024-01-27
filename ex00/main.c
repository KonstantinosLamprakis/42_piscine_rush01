// 4x4 board, heights 1, 2, 3, 4
// making sure each row and column only has one box of each size
// output will contain the first solution you encounter
// every row and column sees the correct number of boxes from each the possible points of view (left/right for rows, up/down for columns)
// This is the ONLY acceptable input for your program. Any other input must be considered an error.
// In case of error or if you can’t find any solutions, display "Error" followed by a line break.
// Your program must be written in accordance with the Norm
// If you want bonus points, you may try to handle other map size (up to 9x9 !!!!).

// Paterns:
// for MAX height on side: we fill all cells ex. 1 2 3 4
// for MIN height on side: you put the MAX first ex. 4
// for x height on side: MAX should be at least x more cells far from the start
// same as above: MAX - 1 should be at least x - 1 cell, MAX - 2 at least x - 2
// for x height on side: you can not put MAX - x in
// MAX - x could be after the 1st, MAX - x + 1 at 2ns, MAX - x + 2 at 3rd etc.

