#ifndef SPROJECT_BOARDMODIFIER_H
#define SPROJECT_BOARDMODIFIER_H

#include "board.h"
#include "linkedList.h"
#include "stack.h"

/**
* @param board != NULL
* @param r in range [0,board.size]
* @param c in range [0,board.size]
* @return pointer to an array size board.size. each cell i is: 1 if i+1 is a legal solution for
* board[r][c], otherwise cell i is 0.
*/
int * get_all_sol_cell(Board *board, int r, int c);

/**
 * @param board != NULL && is_erroneous(board) == 0. THIS FUNCTIONS CHANGES THE BOARD, MUST RECEIVE A COPY OF GAME BOARD
 * @param super_array a size*size*size empty array
 * @return 1 iff board is solvable and ILP succeeded.
 * Input board is autofilled until no more cells can be automatically filled, and
 * then utilises gurobi optimizer in order to solve the board with minimal amount of variables and constraints.
 *  super_array[i*size^2 + j*size +v] == 0 iff the value v is legal for board(i,j) AND the cell is empty (after multiple autofills)
 */
int ILP_solve(Board *board, int *super_array);


/**
 *
 * @param board != NULL && is_erroneous(board) == 0.
 * @return 1 iff the board is solvable, and the input board now holds the solution.
 */
int generate_solution(Board* board);

/**
* @param board != NULL
* @param changed_cells != NULL pointer to the list of the changed cells of the command
* notice: if input mark_errors == 0, changed_cells can be NULL.
* @param r in range [0,board.size-1]
* @param c in range [0,board.size-1]
* @param value in range [1,board.size]
* @param inc_or_dec: 1 for increasing error for each conflict, -1 for decreasing error for each conflict,
* 0 otherwise.
* @return 1 if cell is valid for input value. 0 otherwise.
*/
int validate_cell(Board *board, LinkedListCells *changed_cells, int r, int c, int value, int inc_or_dec);

/**
 *
 * @param board != NULL && is_erroneous(board) == 0.
 * @param moves
 * @return number of cells that were autofilled by the function
 * if moves != NULL the function calls set_command which adds the moves to the linked list.
 * otherwise it simply sets the value in the board TODO: WE NEED TO ADDRESS THIS BECAUSE THIS OBSTRUCTS MODULARITY
 */
int autofill(Board* board, LinkedList *moves);


/** update board cells to the values of the cells in old_values (error/value/fixed)
* @param board != NULL
* @param old_values != NULL. a list of NodeCell
*/
void change_cells_to(Board *board, LinkedListCells *old_values);
void set_command(Board *board, LinkedList *moves, int r, int c, int value);

int num_solutions_BT(Board* board);

#endif /*SPROJECT_BOARDMODIFIER_H*/
