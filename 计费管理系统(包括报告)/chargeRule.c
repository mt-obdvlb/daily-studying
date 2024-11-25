#define _CRT_SECURE_NO_WARNINGS
#include"func.h"

bool add_rule(System* s) {//����շѹ���
	if (s->rule_cnt >= MAX_RULE_NUM)return false;
	int c;
	int flag = 1;
	while (flag) {
		printf("�������Ǹ���Сʱ,���ӻ��������շ�\n");
		printf("0.����  1.Сʱ  2.����  3.��\n");
		scanf("%d", &c);
		switch (c) {
		case 1:
			flag = 0;
			printf("����ÿСʱ�շ�Ϊ:\n");
			break;
		case 2:
			flag = 0;
			printf("����ÿ�����շ�Ϊ:\n");
			break;
		case 3:
			flag = 0;
			printf("����ÿ���շ�Ϊ:\n");
			break;
		case 0:
			return false;
		default:
			printf("����������!\n");
		}
	}
	s->r[s->rule_cnt].condition = c;
	scanf("%d", &s->r[s->rule_cnt].cost);
	printf("     �շѱ�׼%d:", s->rule_cnt + 1);
	printChargeRule(s, s->rule_cnt);
	s->rule_cnt++;
	return true;
}

bool search_rule(System* s) {//��ѯ�շѹ���
	if (s->rule_cnt == 0)return false;
	for (int i = 0, I = s->rule_cnt; i < I; i++) {
		printf("�շѱ�׼%d:\n", i+1);
		printChargeRule(s, i);
		system("pause");
		system("cls");
	}
	return true;
}

bool erase_rule(System* s) {//ɾ���շѹ���
	printf("������Ҫɾ�����շѱ�׼�ı��(��ͨ����ѯ֪)\n");
	int l, r = s->rule_cnt;
	scanf("%d", &l);
	if (l > r||l<1)return false;
	for (int i = l; i < r; i++) {
		s->r[i - 1].condition = s->r[i].condition;
		s->r[i - 1].cost = s->r[i].cost;
	}
	return true;
}

bool revise_rule(System* s) {//�޸��շѹ���
	printf("������Ҫ�޸ĵ��շѱ�׼�ı��(��ͨ����ѯ֪)\n");
	int ind;
	scanf("%d", &ind);
	if (ind<1 || ind>s->rule_cnt)return false;
	ind--;
	printf("     �շѱ�׼%d:", ind + 1);
	printChargeRule(s, ind);
	printf("������Ҫ�޸�Ϊÿ__�շ�\n");
	printf("1.Сʱ 2.���� 3.��\n");
	scanf("%d", &s->r[ind].condition);
	printf("������ÿ%s�շѶ���Ԫ:\n", s->r[ind].condition == 1 ? "Сʱ" : (s->r[ind].condition == 2 ? "����" : "��"));
	scanf("%d", &s->r[ind].cost);
	return true;
}