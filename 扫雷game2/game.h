#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define LOW 9
#define ROWS ROW+2
#define LOWS LOW+2
#define Easy_Difficulty 10

void meun(void);
void game(void);
void InitialBoard(char Board[ROWS][LOWS], int rows, int lows,char c);
void DisplayBoard(char Board[ROWS][LOWS], int row, int low);
void SetMine(char Board[ROWS][LOWS], int row, int low);
int MineSearch(char MineBoard[ROWS][LOWS], char ShowBoard[ROWS][LOWS], int row, int low);
char SumMine(char Board[ROWS][LOWS], int x, int y);
int Is_Win(char Board[ROWS][LOWS], int row, int low);