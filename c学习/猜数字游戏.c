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
//		printf("#######1.��ʼ��Ϸ########\n");
//		printf("#######0.�˳���Ϸ########\n");
//		printf("#########################\n");
//		scanf("%d", &input);
//		switch (input) {
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("�������,����������\n");
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
//		printf("����������\n");
//		scanf("%d", &guess);
//		if (guess > ret) {
//			printf("�´���");
//		}
//		else if (guess < ret) {
//			printf("��С��");
//		}
//		else {
//			printf("�µ���\n");
//			break;
//		}
//	}
//}