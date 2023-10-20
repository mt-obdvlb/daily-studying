#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void meun(void) {
	printf("#######################\n");
	printf("#####1.开始游戏########\n");
	printf("#####0.退出游戏########\n");
	printf("#######################\n");
	printf("请输入:\n");
}

void game(void) {
	char mine[ROWS][LOWS] = { 0 };
	char show[ROWS][LOWS] = { 0 };
	InitialBoard(mine, ROWS, LOWS, '0');
	InitialBoard(show, ROWS, LOWS, '*');
	while (Is_Win(show,ROW,LOW)) {
		DisplayBoard(show, ROW, LOW);
		SetMine(mine, ROW, LOW);
		int is = MineSearch(mine,show,ROW,LOW);
		if (is == 0) {
			break;
		}
		
	}
	if(Is_Win(show, ROW, LOW) ==0){
		printf("你赢了!!!!\n");
	}
}

void InitialBoard(char Board[ROWS][LOWS], int rows, int lows,char c) {
	int i = 0;
	for (i = 0; i < rows; i++) {
		int j = 0;
		for (j = 0; j < lows; j++) {
			Board[i][j] = c;
		}
	}
}

void DisplayBoard(char Board[ROWS][LOWS], int row, int low) {
	int i = 0;
	printf("--------扫雷-------\n");
	for (i = 0; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= low; j++) {
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
	printf("--------扫雷-------\n");

}

void SetMine(char Board[ROWS][LOWS], int row, int low) {
	int count = Easy_Difficulty;
	while (count) {
		int x = rand() % 8 + 1;
		int y = rand() % 8 + 1;
		if (Board[x][y] == '0') {
			Board[x][y] = '1';
			count--;
		}
	}
}

int MineSearch(char MineBoard[ROWS][LOWS], char ShowBoard[ROWS][LOWS], int row, int low){
	int x = 0;
	int y = 0;
	do {
		printf("请输入坐标:(1-9)\n");
		scanf("%d %d", &y, &x);
	} while (x > ROW || x < 1 || y > LOW || y < 1);
	if (ShowBoard[x][y] == ' ') {
		printf("已输入,请重新输入!!!\n");
	}
	else if (MineBoard[x][y] == '1') {
		printf("你被炸死了!废物\n");
		return 0;
	}
	else {
		ShowBoard[x][y] = ' ';
		if(ShowBoard[x + 1][y]!=' ')
		ShowBoard[x + 1][y] = SumMine(MineBoard, x + 1, y) + '0';
		if (ShowBoard[x - 1][y] != ' ')
		ShowBoard[x - 1][y] = SumMine(MineBoard, x - 1, y) + '0';
		if (ShowBoard[x + 1][y + 1] != ' ')
		ShowBoard[x + 1][y + 1] = SumMine(MineBoard, x+1, y+1) + '0';
		if (ShowBoard[x + 1][y - 1] != ' ')
		ShowBoard[x + 1][y - 1] = SumMine(MineBoard, x+1, y-1) + '0';
		if (ShowBoard[x - 1][y + 1] != ' ')
		ShowBoard[x - 1][y + 1] = SumMine(MineBoard, x-1, y+1) + '0';
		if (ShowBoard[x - 1][y - 1] != ' ')
		ShowBoard[x - 1][y - 1] = SumMine(MineBoard, x-1, y-1) + '0';
		if (ShowBoard[x][y + 1] != ' ')
		ShowBoard[x][y + 1] = SumMine(MineBoard, x, y+1) + '0';
		if (ShowBoard[x][y - 1] != ' ')
		ShowBoard[x][y - 1] = SumMine(MineBoard, x, y-1) + '0';
	}
	return 1;
}

char SumMine(char Board[ROWS][LOWS], int x, int y) {
	char c = (Board[x+1][y] + Board[x-1][y] + Board[x+1][y+1] +
		Board[x+1][y-1] + Board[x-1][y+1] + Board[x-1][y-1] +
		Board[x][y+1] + Board[x][y-1] - 8*'0');
	return c;
}

int Is_Win(char Board[ROWS][LOWS], int row, int low) {
	int i = 0;
	for (i = 1; i <= row; i++) {
		int j = 0;
		for (j = 1; j <= low; j++) {
			if (Board[i][j]=='*') {
				return 1;
			}
		}
	}
	return 0;
}