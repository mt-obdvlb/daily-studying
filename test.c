#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void BlankBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void game() {
	char ret = 0;
	char board[ROW][COL] = { 0 };
	BlankBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1) {
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret == '*') {
			printf("你赢了\n");
			break;
		}
		else if (ret == '#') {
			printf("你输了\n");
			break;
		}
		else if (ret == 'Q') {
			printf("平局\n");
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret == '*') {
			printf("你赢了\n");
			break;
		}
		else if (ret == '#') {
			printf("你输了\n");
			break;
		}
		else if (ret == 'Q') {
			printf("平局\n");
			break;
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
			
		}
		printf("\n");
		j = 0;
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void emum(void) {
	printf("***********************\n");
	printf("******1. 开始游戏******\n");
	printf("******0. 退出游戏******\n");
	printf("***********************\n");
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	while (1) {
		printf("请输入坐标\n");
		scanf("%d %d", &x,& y);
		if (board[x - 1][y - 1] == ' ') {
			board[x - 1][y - 1] = '*';
			break;
		}
		else {
			printf("输入错误\m");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col) {
	int x = 0; 
	int y = 0; 
	while (1) {
		x = rand() % 3;
		y = rand() % 3;
		if (board[x ][y] == ' ') {
			board[x ][y] = '#';
			break;
		}
	}
}

char is_win(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
		for (i = 0; i < row; i++) {
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
				return board[0][i];
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
			return board[1][1];
		}
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') {
			return board[1][1];
		}
		for (i = 0; i < row; i++) {
			int j = 0;
			for (j = 0; j < col; j++) {
				if (board[i][j] == ' ') {
					return 'C';
				}
			}
		}
		return 'Q';
	}
}
