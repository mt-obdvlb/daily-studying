#define _CRT_SECURE_NO_WARNINGS
#include"func.h"

void search_cost(System* s) {//��ѯ������
	printf("������Ҫ��ѯ���Ѽ�¼���Ŀ���\n");
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
		printf("�˿��Ų�����!\n");
		return;
	}
	CostNode* tnode = s->c[ind].cn;
	if (s->c[ind].times == 0) {
		printf("�ÿ������Ѽ�¼!\n");
		return;
	}
	for (int i = 0; i<s->c[ind].times; i++, tnode = tnode->next) {
		if (tnode->flag == 0)break;
		if (tnode->flag == 1) {
			printf("�˿�����%sʱ��", tnode->time);
			if (tnode->condition==0) {
				printf("���˷�%dԪ\n", tnode->cost);
			}
			else if(tnode->condition==1){
				printf("����ֵ%dԪ\n", tnode->cost);
			}
		}
		else {
			printf("�˿��Ŵ� %s ��ʼ�� %s ����������%dԪ\n", tnode->begin, tnode->end, tnode->condition);
		}
		system("pause");
		system("cls");
	}
}

void search_total(System* s) {//��ѯ������
	printf("�ܹ�����:%lldԪ!\n", s->total_money);
}

void search_month(System* s) {//��ѯ������
	for (int i = 0; i < 12; i++) {
		printf("��%d�¹�����%lldԪ\n", i + 1, s->month_money[i]);
	}
}