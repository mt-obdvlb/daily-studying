#define _CRT_SECURE_NO_WARNINGS
#include"func.h"

bool add_rule(System* s) {//添加收费规则
	if (s->rule_cnt >= MAX_RULE_NUM)return false;
	int c;
	int flag = 1;
	while (flag) {
		printf("请输入是根据小时,分钟还是秒来收费\n");
		printf("0.返回  1.小时  2.分钟  3.秒\n");
		scanf("%d", &c);
		switch (c) {
		case 1:
			flag = 0;
			printf("请问每小时收费为:\n");
			break;
		case 2:
			flag = 0;
			printf("请问每分钟收费为:\n");
			break;
		case 3:
			flag = 0;
			printf("请问每秒收费为:\n");
			break;
		case 0:
			return false;
		default:
			printf("请重新输入!\n");
		}
	}
	s->r[s->rule_cnt].condition = c;
	scanf("%d", &s->r[s->rule_cnt].cost);
	printf("     收费标准%d:", s->rule_cnt + 1);
	printChargeRule(s, s->rule_cnt);
	s->rule_cnt++;
	return true;
}

bool search_rule(System* s) {//查询收费规则
	if (s->rule_cnt == 0)return false;
	for (int i = 0, I = s->rule_cnt; i < I; i++) {
		printf("收费标准%d:\n", i+1);
		printChargeRule(s, i);
		system("pause");
		system("cls");
	}
	return true;
}

bool erase_rule(System* s) {//删除收费规则
	printf("请输入要删除的收费标准的编号(可通过查询知)\n");
	int l, r = s->rule_cnt;
	scanf("%d", &l);
	if (l > r||l<1)return false;
	for (int i = l; i < r; i++) {
		s->r[i - 1].condition = s->r[i].condition;
		s->r[i - 1].cost = s->r[i].cost;
	}
	return true;
}

bool revise_rule(System* s) {//修改收费规则
	printf("请输入要修改的收费标准的编号(可通过查询知)\n");
	int ind;
	scanf("%d", &ind);
	if (ind<1 || ind>s->rule_cnt)return false;
	ind--;
	printf("     收费标准%d:", ind + 1);
	printChargeRule(s, ind);
	printf("请输入要修改为每__收费\n");
	printf("1.小时 2.分钟 3.秒\n");
	scanf("%d", &s->r[ind].condition);
	printf("请输入每%s收费多少元:\n", s->r[ind].condition == 1 ? "小时" : (s->r[ind].condition == 2 ? "分钟" : "秒"));
	scanf("%d", &s->r[ind].cost);
	return true;
}