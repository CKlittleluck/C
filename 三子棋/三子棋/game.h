#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void initBoard(char board[ROW][COL], int row, int col);
void DispiayBoard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);

char iswin(char board[ROW][COL], int row, int col);