#define _CRT_SECURE_NO_WARNINGS
#include"func.h"

void search_cost(System* s) {//查询卡消费
	printf("请输入要查询消费记录卡的卡号\n");
	char tid[50];
	scanf("%s", tid);
	int flag = 1;
	int ind = -1;
	for (int i = 0;flag && i < s->card_cnt; i++) {
		if (strcmp(s->c[i].id, tid) == 0) {
			flag = 0;
			ind = i;
		}
	}
	system("cls");
	if (flag) {
		printf("此卡号不存在!\n");
		return;
	}
	CostNode* tnode = s->c[ind].cn;
	if (s->c[ind].times == 0) {
		printf("该卡无消费记录!\n");
		return;
	}
	for (int i = 0; i<s->c[ind].times; i++, tnode = tnode->next) {
		if (tnode->flag == 0)break;
		if (tnode->flag == 1) {
			printf("此卡号在%s时刻", tnode->time);
			if (tnode->condition==0) {
				printf("共退费%d元\n", tnode->cost);
			}
			else if(tnode->condition==1){
				printf("共充值%d元\n", tnode->cost);
			}
		}
		else {
			printf("此卡号从 %s 开始到 %s 结束共花费%d元\n", tnode->begin, tnode->end, tnode->condition);
		}
		system("pause");
		system("cls");
	}
}

void search_total(System* s) {//查询总消费
	printf("总共花费:%lld元!\n", s->total_money);
}

void search_month(System* s) {//查询月消费
	for (int i = 0; i < 12; i++) {
		printf("第%d月共花费%lld元\n", i + 1, s->month_money[i]);
	}
}