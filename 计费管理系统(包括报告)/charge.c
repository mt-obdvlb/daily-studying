#define _CRT_SECURE_NO_WARNINGS
#include"func.h"


void begin(System* s){//上机
	printf("请输入要使用卡的卡号\n");
	char tid[50];
	scanf("%s", tid);
	int flag = 1;
	int ind = 0;
	for (int i = 0;flag&& i < s->card_cnt; i++) {
		if (strcmp(s->c[i].id, tid) != 0)continue;
		flag = 0;
		ind = i;
	}
	if (flag) {
		printf("  无此卡号!  \n");
		return;
	}
	switch (s->c[ind].condition) {
		case 0:
			printf("该卡已注销!\n");
			return;
		case 2:
			printf("该卡正在使用中!\n");
			return;
	}
	flag = 0;
LOOP1:
	printf("请输入此卡的密码\n");
	char tps[50];
	scanf("%s", tps);
	flag++;
	if(strcmp(s->c[ind].password, tps) == 0) {
		system("cls");
		printCard(s,ind);
		printf("上机成功!\n");
		CostNode* tmp = LastCostNode(s->c[ind].cn);
		tmp->flag = 1;
		tmp->condition = 2;
		strcpy(tmp->begin, curTime());
		s->c[ind].condition = 2;
		strcpy(s->c[ind].last_used, curTime());
		s->c[ind].tt = time1970();
		return;
	}
	else {
		printf("  输入错误(%d次\2次)!  \n",flag);
		if (flag == 2)return;
		system("pause");
		system("cls");
		goto LOOP1;
	}
}

void end(System* s) {//下机
	int flag = 1;
	
	for (int i = 0; i < s->card_cnt; i++) {
		if (s->c[i].condition == 2) {
			printf("正在使用中的卡有:\n");
			flag = 0;
			printCard(s,i);
			system("pause");
			system("cls");
		}
	}
	if (flag) {
		printf("无正在使用中的卡!\n");
		return;
	}
	printf("请输入你要下机的卡号!\n");
	char tid[50];
	scanf("%s", tid);
	flag = 1;
	int indCard = -1;
	for (int i = 0;flag&& i < s->card_cnt; i++) {
		if (strcmp(tid, s->c[i].id) == 0) {
			indCard = i;
			flag = 0;
		}
	}
	if (flag) {
		printf("无此卡号!\n");
		return;
	}
	printf("请输入卡的密码\n");
	char tps[50];
	scanf("%s", tps);
	if (strcmp(tps, s->c[indCard].password) != 0) {
		printf("输入错误!\n");
		return;
	}
	printf("密码正确\n");
	system("pause");
	system("cls");
	printCard(s,indCard);
	long long money = 0;
	long long cur_time = time1970();
	long long t = cur_time - s->c[indCard].tt;
	printf("共有%d条收费标准\n",s->rule_cnt);
	for (int i = 0; i < s->rule_cnt; i++) {
		printf("     收费标准%d:\n", i + 1);
		printChargeRule(s, i);
		system("pause");
	}
	int indRule = -1;
	printf("请输入要使用的收费标准的编号!\n");
	scanf("%d", &indRule);
	indRule--;
	if (indRule < 0 || indRule >= s->rule_cnt) {
		printf("无此收费标准!\n");
		return;
	}
	switch (s->r[indRule].condition) {
		case 1:
			money = s->r[indRule].cost * t / 3600;
			break;
		case 2:
			money = s->r[indRule].cost * t / 60;
			break;
		case 3:
			money = s->r[indRule].cost * t;
			break;
	}
	s->total_money += money;
	s->month_money[cur_month()] += money;
	printf("要收费%lld元\n", money);
	while(s->c[indCard].money < money) {
		printf("账号余额不足!\n");
		printf("还缺%lld元,请充值!\n", money- (long long)s->c[indCard].money);
		printf("请输入要充值的数额:\n");
		int tm=0;
		scanf("%d", &tm);
		s->c[indCard].money += tm;
	}
	printf("下机成功!\n");
	s->c[indCard].condition = 1;
	strcpy(s->c[indCard].last_used, curTime());
	s->c[indCard].money -= money;
	s->c[indCard].tt = time1970();
	s->c[indCard].times++;
	CostNode* tmp = LastBeginCostNode(s->c[indCard].cn);
	tmp->flag = 2;
	tmp->cost = money;
	strcpy(tmp->end, curTime());
	printCard(s, indCard);
}