#define _CRT_SECURE_NO_WARNINGS
#include"func.h"


System* getNewSystem() {//��ȡһ���µ�ϵͳ
	System* ret = (System*)malloc(sizeof(System));
	ret->card_cnt = 0;
	ret->total_money = 0;
	for (int i = 0; i < MONTH; i++) {
		ret->month_money[i] = 0;
	}
	ret->rule_cnt = 1;
	ret->r[0].condition = 1;
	ret->r[0].cost = 10;
	return ret;
}

void ReadFileSystem(System* s) {//����ϵͳ
	FILE* fpr = fopen("�Ʒѹ���ϵͳ.txt", "r");
	fscanf(fpr, "%lld", &s->total_money);
	for (int i = 0; i < MONTH; i++) {
		fscanf(fpr, "%lld", &s->month_money[i]);
	}
	fscanf(fpr, "%d", &s->card_cnt);
	for (int i = 0; i < s->card_cnt; i++) {
		fscanf(fpr, "%lld%d%d%d", &s->c[i].tt, &s->c[i].money, &s->c[i].times, &s->c[i].condition);
		fscanf(fpr, "%s%s%s", s->c[i].last_used, s->c[i].id, s->c[i].password);
		s->c[i].cn = getNewCostNode();
		CostNode* cn = s->c[i].cn;
		for (int i = 0; i < s->c[i].times; i++) {
			fscanf(fpr, "%d%d%d", &cn->cost, &cn->flag, &cn->condition);
			if (cn->flag == 2) {
				fscanf(fpr, "%s%s", cn->begin, cn->end);
			}
			else {
				if (cn->condition == 2) {
					fscanf(fpr, "%s", cn->begin);
				}
				else {
					fscanf(fpr, "%s", cn->time);
				}
			}
			cn->next = getNewCostNode();
			cn = cn->next;
		}
	}
	fscanf(fpr, "%d", &s->rule_cnt);
	for (int i = 1; i < s->rule_cnt; i++) {
		fscanf(fpr,"%d%d", &s->r[i].cost, &s->r[i].condition);
	}
	fclose(fpr);
	fpr = NULL;
}

void WriteFileSystem(System* s) {//д��ϵͳ
	FILE* fpw = fopen("�Ʒѹ���ϵͳ.txt", "w");
	fprintf(fpw,"%lld\n", s->total_money);
	for (int i = 0; i < MONTH; i++) {
		fprintf(fpw, "%lld\n", s->month_money[i]);
	}
	fprintf(fpw, "%d\n", s->card_cnt);
	for (int i = 0; i < s->card_cnt; i++) {
		fprintf(fpw, "%lld\n%d\n%d\n%d\n", s->c[i].tt, s->c[i].money, s->c[i].times, s->c[i].condition);
		fprintf(fpw, "%s\n%s\n%s\n", s->c[i].last_used, s->c[i].id, s->c[i].password);
		CostNode* cn = s->c[i].cn;
		for (int i = 0; i < s->c[i].times; i++) {
			fprintf(fpw, "%d\n%d\n%d\n", cn->cost, cn->flag, cn->condition);
			if (cn->flag == 2) {
				fprintf(fpw, "%s\n%s\n", cn->begin, cn->end);
			}
			else {
				if (cn->condition == 2) {
					fprintf(fpw, "%s\n", cn->begin);
				}
				else {
					fprintf(fpw, "%s\n", cn->time);
				}
			}
			cn = cn->next;
		}
	}
	fprintf(fpw, "%d\n", s->rule_cnt);
	for (int i = 1; i < s->rule_cnt; i++) {
		fprintf(fpw,"%d\n%d\n", s->r[i].cost, s->r[i].condition);
	}
	fclose(fpw);
	fpw = NULL;
}

long long time1970() {//��ȡ1970�����ڵ�����
	int set = 0;
	time_t timep;
	set = time(&timep);
	return set;
}

char* curTime() {//��ȡ���ڵ�ʱ��
	time_t timep;
	struct tm* p;
	char time1[50];
	time(&timep);
	p = gmtime(&timep);
	//�����Ǻϳ�һ���ַ���
	sprintf(time1,"%d��%d��%d��%d:%d:%d\0", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
	return time1;
}


int cur_month() {//��ȡ���ڵ��·�
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	return p->tm_mon;
}

void printCard(System* s, int ind) {
	printf("����:%s\n", s->c[ind].id);
	printf("��״̬:%s\n", s->c[ind].condition == 1 ? "����ʹ��" : (s->c[ind].condition == 2 ? "�ϻ���" : "��ע��"));
	printf("���:%d\n", s->c[ind].money);
	printf("ʹ�ô���:%d\n", s->c[ind].times);
	printf("���ʹ��ʱ��:%s\n", s->c[ind].last_used);
}

void printChargeRule(System* s, int ind) {
	printf("�շѱ�׼����:��ʱ���շ�\n");
	printf("�շѼ۸�:ÿ%s%dԪ\n", s->r[ind].condition == 1 ? "Сʱ" : (s->r[ind].condition == 2 ? "����" : "��"), s->r[ind].cost);
}

CostNode* getNewCostNode() {
	CostNode* ret = (CostNode*)malloc(sizeof(CostNode));
	ret->begin[0] = '\0';
	ret->end[0] = '\0';
	ret->time[0] = '\0';
	ret->next = NULL;
	ret->cost = 0;
	ret->flag = 0;
	ret->condition = -1;
	return ret;
}

CostNode* LastCostNode(CostNode* cn) {//��ȡ���һ��ûʹ�ýڵ�
	CostNode* ret = cn;
	while (ret) {
		if (ret->flag == 0)break;
		ret = ret->next;
	}
	ret->next = getNewCostNode();
	return ret;
}

CostNode* LastBeginCostNode(CostNode* cn) {//��ȡ���һ��ʹ����һ��Ľڵ�
	if (cn->condition == 2 && cn->flag == 1) {
		if (cn->next == NULL)cn->next = getNewCostNode();
		return cn;
	}
	return LastBeginCostNode(cn->next);
}

void print_All(System* s) {//���������Ϣ
	printf("������:%lld\n", s->total_money);
	for (int i = 0; i < MONTH; i++) {
		printf( "��%d��������:%lld\n",i+1, s->month_money[i]);
	}
	printf("��������:%d\n", s->card_cnt);
	for (int i = 0; i < s->card_cnt; i++) {
		printf( "����1970ʹ��ʱ��:%lld\n�������:%d\n����ʹ�ô���:%d\n����״̬%d(0Ϊע��,1Ϊ��ʹ��,2Ϊ�ϻ���)\n", s->c[i].tt, s->c[i].money, s->c[i].times, s->c[i].condition);
		printf( "%s\n%s\n%s\n", s->c[i].last_used, s->c[i].id, s->c[i].password);
		CostNode* cn = s->c[i].cn;
		for (int i = 0; i < s->c[i].times; i++) {
			printf("��������ѵĽ��%d\n��������ѵ�״̬1(1Ϊʹ��,0Ϊδʹ��,2Ϊʹ�����)%d\n��������ѵ�״̬2(0Ϊ�˷�,1Ϊ��ֵ,2Ϊ����)%d\n", cn->cost, cn->flag, cn->condition);
			if (cn->flag == 2) {
				printf("����ʼʹ��ʱ��:%s\n������ʹ��ʱ��:%s\n", cn->begin, cn->end);
			}
			else {
				if (cn->condition == 2) {
					printf("����ʼʹ��ʱ��%s\n", cn->begin);
				}
				else {
					printf("����ʹ��ʱ��%s\n", cn->time);
				}
			}
			cn = cn->next;
		}
	}
	printf("������:%d\n", s->rule_cnt);
	for (int i = 0; i < s->rule_cnt; i++) {
		printf("�������ѽ��:%d\n����״̬%d(1Сʱ,2����,3��)\n", s->r[i].cost, s->r[i].condition);
	}
}