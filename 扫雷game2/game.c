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
				printf("�˳���Ϸ!\n");
				break;
			default:
				printf("�������!!!����������!\n");
				break;
		}
	} while (input);
	return 0;
}

