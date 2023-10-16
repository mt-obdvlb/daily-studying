//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//void game();
//int main() {
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do {
//		printf("#########################\n");
//		printf("#######1.开始游戏########\n");
//		printf("#######0.退出游戏########\n");
//		printf("#########################\n");
//		scanf("%d", &input);
//		switch (input) {
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("输入错误,请重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//void game() {
//	int ret = 0;
//	int guess = 0;
//	ret = rand()%100+1;
//	while (1) {
//		printf("请输入数字\n");
//		scanf("%d", &guess);
//		if (guess > ret) {
//			printf("猜大了");
//		}
//		else if (guess < ret) {
//			printf("猜小了");
//		}
//		else {
//			printf("猜到了\n");
//			break;
//		}
//	}
//}