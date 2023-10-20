#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		meun();
		scanf("%d", &input);
		switch (input) {
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏!\n");
				break;
			default:
				printf("输入错误!!!请重新输入!\n");
				break;
		}
	} while (input);
	return 0;
}

