#define _CRT_SECURE_NO_WARNINGS
#include"func.h"


System* getNewSystem() {//获取一个新的系统
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

void ReadFileSystem(System* s) {//读入系统
	FILE* fpr = fopen("计费管理系统.txt", "r");
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

void WriteFileSystem(System* s) {//写入系统
	FILE* fpw = fopen("计费管理系统.txt", "w");
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

long long time1970() {//获取1970到现在的秒数
	int set = 0;
	time_t timep;
	set = time(&timep);
	return set;
}

char* curTime() {//获取现在的时间
	time_t timep;
	struct tm* p;
	char time1[50];
	time(&timep);
	p = gmtime(&timep);
	//将它们合成一个字符串
	sprintf(time1,"%d年%d月%d日%d:%d:%d\0", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
	return time1;
}


int cur_month() {//获取现在的月份
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	return p->tm_mon;
}

void printCard(System* s, int ind) {
	printf("卡号:%s\n", s->c[ind].id);
	printf("卡状态:%s\n", s->c[ind].condition == 1 ? "可以使用" : (s->c[ind].condition == 2 ? "上机中" : "已注销"));
	printf("余额:%d\n", s->c[ind].money);
	printf("使用次数:%d\n", s->c[ind].times);
	printf("最后使用时间:%s\n", s->c[ind].last_used);
}

void printChargeRule(System* s, int ind) {
	printf("收费标准类型:按时间收费\n");
	printf("收费价格:每%s%d元\n", s->r[ind].condition == 1 ? "小时" : (s->r[ind].condition == 2 ? "分钟" : "秒"), s->r[ind].cost);
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

CostNode* LastCostNode(CostNode* cn) {//获取最后一个没使用节点
	CostNode* ret = cn;
	while (ret) {
		if (ret->flag == 0)break;
		ret = ret->next;
	}
	ret->next = getNewCostNode();
	return ret;
}

CostNode* LastBeginCostNode(CostNode* cn) {//获取最后一个使用了一半的节点
	if (cn->condition == 2 && cn->flag == 1) {
		if (cn->next == NULL)cn->next = getNewCostNode();
		return cn;
	}
	return LastBeginCostNode(cn->next);
}

void print_All(System* s) {//输出所有信息
	printf("总消费:%lld\n", s->total_money);
	for (int i = 0; i < MONTH; i++) {
		printf( "第%d月消费了:%lld\n",i+1, s->month_money[i]);
	}
	printf("卡的数量:%d\n", s->card_cnt);
	for (int i = 0; i < s->card_cnt; i++) {
		printf( "卡的1970使用时间:%lld\n卡的余额:%d\n卡的使用次数:%d\n卡的状态%d(0为注销,1为可使用,2为上机中)\n", s->c[i].tt, s->c[i].money, s->c[i].times, s->c[i].condition);
		printf( "%s\n%s\n%s\n", s->c[i].last_used, s->c[i].id, s->c[i].password);
		CostNode* cn = s->c[i].cn;
		for (int i = 0; i < s->c[i].times; i++) {
			printf("卡这次消费的金额%d\n卡这次消费的状态1(1为使用,0为未使用,2为使用完成)%d\n卡这次消费的状态2(0为退费,1为充值,2为消费)%d\n", cn->cost, cn->flag, cn->condition);
			if (cn->flag == 2) {
				printf("卡开始使用时间:%s\n卡结束使用时间:%s\n", cn->begin, cn->end);
			}
			else {
				if (cn->condition == 2) {
					printf("卡开始使用时间%s\n", cn->begin);
				}
				else {
					printf("卡的使用时刻%s\n", cn->time);
				}
			}
			cn = cn->next;
		}
	}
	printf("规则数:%d\n", s->rule_cnt);
	for (int i = 0; i < s->rule_cnt; i++) {
		printf("规则消费金额:%d\n规则状态%d(1小时,2分钟,3秒)\n", s->r[i].cost, s->r[i].condition);
	}
}