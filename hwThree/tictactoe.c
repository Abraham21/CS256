/*
/*
 * File: tictactoe.c
 *
 * Author: Abraham Yepremian
 *
 * Description: Homework 3 for CS 256
 * Chapter 7 Problem 18 Tic Tac Toe
 *
 * Last edited: 4/19/2018
 *
 */

#include <stdio.h>
#include <stdlib.h>

	int checkgameBoard(char gameBoard[3][3])
	{
	    int x;
	    for(x = 0; x < 3; x++)
	    {

	      if ((gameBoard[x][0] != '*') &&
	          (gameBoard[x][0] == gameBoard[x][1]) &&
	          (gameBoard[x][0] == gameBoard[x][2]))
	         return(gameBoard[x][0] == 'O' ? -1 : 1);


	      if ((gameBoard[0][x] != '*') &&
	          (gameBoard[0][x] == gameBoard[1][x]) &&
	          (gameBoard[0][x] == gameBoard[2][x]))
	         return(gameBoard[0][x] == 'O' ? -1 : 1);
	    };


	    if ((gameBoard[0][0] != '*') &&
	       (gameBoard[0][0] == gameBoard[1][1]) &&
	       (gameBoard[0][0] == gameBoard[2][2]))
	      return(gameBoard[0][0] == 'O' ? -1 : 1);


	    if ((gameBoard[2][0] != '*') &&
	       (gameBoard[2][0] == gameBoard[1][1]) &&
	       (gameBoard[0][0] == gameBoard[0][2]))
	      return(gameBoard[2][0] == 'O' ? -1 : 1);


	    return 0;
	}

int main(){
	printf("Tic-Tac-Toe Game");

	int row = 0;
	int column = 0;
	int line = 0;
	int player = 0;
	int winner = 0;
	char gameBoard [3][3] = {
					{'*','*','*'},
					{'*','*','*'},
					{'*','*','*'}
	};
		for (int i = 0; i<9 && winner==0; i++)
		{
			printf("\n\n");
			printf(" %c | %c | %c\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
			printf("---|---|---\n");
			printf(" %c | %c | %c\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
			printf("---|---|---\n");
			printf(" %c | %c | %c\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
			player = i%2 + 1;

			do
			{
					printf("\nPlayer %d, input the row and column of where to place your %c: ", player,(player==1)?'X':'O');
					scanf("%d%d", &row,&column);
			}while((row > 2 || column > 2 || row<0 || column <0) || (gameBoard[row][column] == 'X' || gameBoard[row][column] == 'O'));

			gameBoard[row][column] = (player == 1) ? 'X' : 'O';

			winner = checkgameBoard(gameBoard);

		}

		if(winner==0)
			printf("The game is a draw\n");
		else if(winner==-1)
			printf("\nPlayer 0 has won\n");
		else
			printf("\nPlayer %d has won\n", winner);

		//print game board
		printf("\n\n");
		printf(" %c | %c | %c\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
		printf("---|---|---\n");
		printf(" %c | %c | %c\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
		printf("---|---|---\n");
		printf(" %c | %c | %c\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);


	return 0;

}
