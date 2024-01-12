//#define  _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	char pc[200][10];
//	char ps[200][10];
//	for (int i = 0; i < n; i++) {
//		scanf("%s", &pc[i]);
//
//	}
//	char target[10] = { 0 };
//	scanf("%s", target);
//	int j = 0;
//	int top = -1;
//	for (j = 0; j < n; j++) {
//		if (strcmp(target, pc[j]) == 0) {
//			strcpy(ps[top + 1], target);
//			top++;
//			break;
//		}
//		if (strcmp(pc[j], "return") == 0) {
//			if (top == -1) {
//				break;
//			}
//
//			strcpy(ps[top], "\n");
//			top--;
//
//		}
//		else {
//			strcpy(ps[top + 1], pc[j]);
//			top++;
//		}
//	}
//	if (j == n  && strcmp(target, ps[top]) != 0) {
//		printf("NOT REFERENCED\n");
//		return 0;
//	}
//	int k = 0;
//	for (k = 0; k <= top; k++) {
//		printf("%s", ps[k]);
//		if (k != top) {
//			printf("->");
//		}
//	}
//	return 0;
//}