#define _CRT_SECURE_NO_WARNINGS
#include"func.h"


void begin(System* s){//�ϻ�
	printf("������Ҫʹ�ÿ��Ŀ���\n");
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
		printf("  �޴˿���!  \n");
		return;
	}
	switch (s->c[ind].condition) {
		case 0:
			printf("�ÿ���ע��!\n");
			return;
		case 2:
			printf("�ÿ�����ʹ����!\n");
			return;
	}
	flag = 0;
LOOP1:
	printf("������˿�������\n");
	char tps[50];
	scanf("%s", tps);
	flag++;
	if(strcmp(s->c[ind].password, tps) == 0) {
		system("cls");
		printCard(s,ind);
		printf("�ϻ��ɹ�!\n");
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
		printf("  �������(%d��\2��)!  \n",flag);
		if (flag == 2)return;
		system("pause");
		system("cls");
		goto LOOP1;
	}
}

void end(System* s) {//�»�
	int flag = 1;
	
	for (int i = 0; i < s->card_cnt; i++) {
		if (s->c[i].condition == 2) {
			printf("����ʹ���еĿ���:\n");
			flag = 0;
			printCard(s,i);
			system("pause");
			system("cls");
		}
	}
	if (flag) {
		printf("������ʹ���еĿ�!\n");
		return;
	}
	printf("��������Ҫ�»��Ŀ���!\n");
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
		printf("�޴˿���!\n");
		return;
	}
	printf("�����뿨������\n");
	char tps[50];
	scanf("%s", tps);
	if (strcmp(tps, s->c[indCard].password) != 0) {
		printf("�������!\n");
		return;
	}
	printf("������ȷ\n");
	system("pause");
	system("cls");
	printCard(s,indCard);
	long long money = 0;
	long long cur_time = time1970();
	long long t = cur_time - s->c[indCard].tt;
	printf("����%d���շѱ�׼\n",s->rule_cnt);
	for (int i = 0; i < s->rule_cnt; i++) {
		printf("     �շѱ�׼%d:\n", i + 1);
		printChargeRule(s, i);
		system("pause");
	}
	int indRule = -1;
	printf("������Ҫʹ�õ��շѱ�׼�ı��!\n");
	scanf("%d", &indRule);
	indRule--;
	if (indRule < 0 || indRule >= s->rule_cnt) {
		printf("�޴��շѱ�׼!\n");
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
	printf("Ҫ�շ�%lldԪ\n", money);
	while(s->c[indCard].money < money) {
		printf("�˺�����!\n");
		printf("��ȱ%lldԪ,���ֵ!\n", money- (long long)s->c[indCard].money);
		printf("������Ҫ��ֵ������:\n");
		int tm=0;
		scanf("%d", &tm);
		s->c[indCard].money += tm;
	}
	printf("�»��ɹ�!\n");
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