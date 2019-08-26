#include <stdio.h>
#include <stdlib.h>
#include "triangle_routines.h"

#define BOARD_SIZE 15
#define NUM_MOVES 36
#define MOVE_SIZE 3

int moves[NUM_MOVES][MOVE_SIZE] =
{
    {0, 1, 3},
    {3, 1, 0},
    {1, 3, 6},
    {6, 3, 1},
    {0, 2, 5},
    {5, 2, 0},
    {3, 4, 5},
    {5, 4, 3},
    {6, 7, 8},
    {8, 7, 6},
    {7, 8, 9},
    {9, 8, 7},
    {2, 5, 9},
    {9, 5, 2},
    {2, 4, 7},
    {7, 4, 2},
    {1, 4, 8},
    {8, 4, 1},
    {3, 6, 10},
    {10, 6, 3},
    {4, 7, 11},
    {11, 7, 4},
    {3, 7, 12},
    {12, 7, 3},
    {4, 8, 13},
    {13, 8, 4},
    {5, 8, 12},
    {12, 8, 5},
    {5, 9, 14},
    {14, 9, 5},
    {10, 11, 12},
    {12, 11, 10},
    {11, 12, 13},
    {13, 12, 11},
    {12, 13, 14},
    {14, 13, 12}
};


/* return number of pegs on board. */
int npegs(int board[]);

/* return 1 if move is valid, else return 0 */
int valid_move(int board[], int move[]);

/* Make this move on board */
void make_move(int board[], int move[]);

/* unmake move on this board. */
void unmake_move(int board[], int move[]);

/* 
 * Solve the game starting from this board.  Return 1 if the game can
 * be solved; otherwise return 0.  Do not permanently alter the board passed
 * in. Once a solution is found, print the boards making up the solution in
 * reverse order. 
 */
int solve(int board[]);

int npegs(int board[]) {
    int i, num_pegs = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i]) {
            num_pegs++;
        }
    }
    return num_pegs;
}

int valid_move(int board[], int move[]) {
    /*
     * If the first and second spots have pegs and the third
     * doesn't then it is a valid move
     */
    if ((board[move[0]] == 1) && (board[move[1]] == 1)
            && (board[move[2]] == 0)) {
        return 1;
    }
    return 0;
}
   
void make_move(int board[], int move[]) {
    board[move[0]] = 0;
    board[move[1]] = 0;
    board[move[2]] = 1;
} 


void unmake_move(int board[], int move[]) {
    board[move[0]] = 1;
    board[move[1]] = 1;
    board[move[2]] = 0;
}

int solve(int board[]) {
    int i, j, solve_f;

    if (npegs(board) <= 1) {
        triangle_print(board);
        return 1;
    }

    else {
        for(j = 0; j < NUM_MOVES; j++) {
        /* first, make a valid move, and check that
        * board is solvable from the subsequent position
        */
            if (valid_move(board, moves[j])) {
                make_move(board, moves[j]);
                solve_f = solve(board);
                unmake_move(board, moves[j]);
                if(solve_f) {
                    triangle_print(board);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(void) {
    int board[BOARD_SIZE];
    int solve_f;

    triangle_input(board);
    solve_f = solve(board);

    if(!solve_f) { 
        printf("there is no solution\n");
    }
    else {
        printf("solution found!\n");
    }
    return 0;
}


