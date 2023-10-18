#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

int main() {
	srand((unsigned int)time(NULL));
	char board[ROW][COL] = { 0 };
	int input = 0;
	do {
		emum();
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误!!!\n请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}