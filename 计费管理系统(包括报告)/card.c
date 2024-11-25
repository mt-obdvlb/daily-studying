#define _CRT_SECURE_NO_WARNINGS
#include"func.h";



bool add_card(System *s) {//��ӿ�
	if (s->card_cnt >= MAX_CARD_NUM)return false;
	printf("��ֱ����뿨��,����Ϳ������\n");
	scanf("%s%s%d", s->c[s->card_cnt].id, s->c[s->card_cnt].password, &s->c[s->card_cnt].money);
	s->c[s->card_cnt].condition = 1;
	s->c[s->card_cnt].times = 1;
	s->c[s->card_cnt].cn = getNewCostNode();
	CostNode* tmp = LastCostNode(s->c[s->card_cnt].cn);
	tmp->flag = 1;
	strcpy(tmp->time, curTime());
	tmp->condition = 1;
	s->total_money += s->c[s->card_cnt].money;
	s->month_money[cur_month()] += s->c[s->card_cnt].money;
	tmp->cost = s->c[s->card_cnt].money;
	strcpy(s->c[s->card_cnt].last_used , curTime());
	s->c[s->card_cnt].tt = time1970();
	printCard(s, s->card_cnt);
	s->card_cnt++;
	return true;
}

bool search_card(System* s) {//��ѯ��
	printf("��������Ҫ��ѯ���Ŀ���:(�м䲻Ҫ�пո�)\n");
	char tmp[50];
	scanf("%s", tmp);
	for (int i = 0; i < s->card_cnt; i++) {
		if (strcmp(tmp, s->c[i].id)==0) {
			printCard(s,i);
			return true;
		}
	}
	return false;
}

bool exit_card(System* s) {//ע����
	printf("��������Ҫע�����Ŀ���:(�м䲻Ҫ�пո�)\n");
	char tmp[50];
	scanf("%s", tmp);
	for (int i = 0; i < s->card_cnt; i++) {
		if (strcmp(tmp, s->c[i].id)==0) {
			s->c[i].condition = 0;
			return true;
		}
	}
	return false;
}
