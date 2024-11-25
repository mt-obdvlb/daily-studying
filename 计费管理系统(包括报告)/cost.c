#define _CRT_SECURE_NO_WARNINGS
#include"func.h"



void cost_charge(System* s) {//充值
	printf("请输入要充值卡的卡号\n");
	char tid[50];
	scanf("%s", tid);
	int ind = 0;
	int flag = 1;
	for (int i = 0; flag && i < s->card_cnt; i++) {
		if (strcmp(tid, s->c[i].id) == 0)flag = 0;
		ind = i;
	}
	if (flag) {
		printf("无此卡!\n");
		return;
	}
	char tps[50];
	printf("请输入卡密码:\n");
	scanf("%s", tps);
	if (strcmp(tps, s->c[ind].password) != 0) {
		printf("输入错误!\n");
		return;
	}
	printf("密码正确!\n");
	system("pause");
	system("cls");
	printCard(s, ind);
	printf("请输入要充值的数额:\n");
	int tm = 0;
	scanf("%d", &tm);
	strcpy(s->c[ind].last_used, curTime());
	s->c[ind].times++;
	s->c[ind].money += tm;
	printf("充值成功!\n");
	CostNode* tmp = LastCostNode(s->c[ind].cn);
	tmp->flag = 1;
	strcpy(tmp->time, curTime());
	tmp->cost = tm;
	tmp->condition = 1;
	printCard(s, ind);
}

void cost_exit_charge(System* s) {//退费
	printf("请输入要退费卡的卡号\n");
	char tid[50];
	scanf("%s", tid);
	int ind = 0;
	int flag = 1;
	for (int i = 0; flag && i < s->card_cnt; i++) {
		if (strcmp(tid, s->c[i].id) == 0)flag = 0;
		ind = i;
	}
	if (flag) {
		printf("无此卡!\n");
		return;
	}
	char tps[50];
	printf("请输入卡密码:\n");
	scanf("%s", tps);
	if (strcmp(tps, s->c[ind].password) != 0) {
		printf("输入错误!\n");
		return;
	}
	printf("密码正确!\n");
	system("pause");
	system("cls");
	printCard(s, ind);
	printf("请输入要退的数额:\n");
	int tm = 0;
	scanf("%d", &tm);
	if (tm > s->c[ind].money) {
		printf("退费失败!\n");
		return;
	}
	printf("退费成功!\n");
	CostNode* tmp = LastCostNode(s->c[ind].cn);
	tmp->flag = 1;
	strcpy(tmp->time, curTime());
	tmp->condition = 0;
	tmp->cost = tm;
	s->c[ind].money -= tm;
	s->c[ind].times++;
	strcpy(s->c[ind].last_used, curTime());
	system("pause");
	system("cls");
	printCard(s, ind);
}