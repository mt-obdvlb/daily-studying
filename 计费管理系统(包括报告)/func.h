
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<stdbool.h>
#define DEBUG_1
#define MAX_CARD_NUM 100
#define MAX_RULE_NUM 50
#define MONTH 12

typedef struct CostNode {//����ʵ��
	int cost, flag, condition;//flag 1Ϊʹ��,0Ϊδʹ��,2Ϊʹ�����
	char begin[50], end[50], time[50];//condition 0Ϊ�˷�,1Ϊ��ֵ,2Ϊ����
	struct CostNode* next;
}CostNode;

typedef struct Card {
	long long tt;
	CostNode* cn;
	int  money, times, condition;//condition 0Ϊע��,1Ϊ��ʹ��,2Ϊ�ϻ���
	char last_used[50], id[25], password[25];
}Card;

typedef struct Rule {
	int cost, condition;//1Сʱ,2����,3��
}Rule;

typedef struct System {
	long long total_money;
	long long month_money[12];
	int card_cnt;
	int rule_cnt;
	Rule r[MAX_RULE_NUM];
	Card c[MAX_CARD_NUM];
}System;

int cur_month();//�����·�
long long time1970();//��ȡ1970����������
void WriteFileSystem(System* s);//д�ļ�
void ReadFileSystem(System* s);//���ļ�
CostNode* getNewCostNode();//��ȡһ���ڵ�
CostNode* LastCostNode(CostNode* cn);//��ȡ���һ��δʹ�õĽڵ�
CostNode* LastBeginCostNode(CostNode* cn);//��ȡ��һ����ʼʹ�õ�ûʹ����ڵ�
System* getNewSystem();//��ȡһ���µ�ϵͳ
void meun();//�˵�
char* curTime();//��ȡ����ʱ��
void card_meun();//���˵�
void printChargeRule(System* s, int ind);//�����ֵ������Ϣ
void printCard(System* s, int ind);//�������Ϣ
bool add_card(System* s);//��ӿ�
bool search_card(System* s);//��ѯ��
bool exit_card(System* s);//ע����
void chargeRule_meun();//���ѹ���˵�
bool add_rule(System* s);//������ѹ���
bool search_rule(System* s);//��ѯ���ѹ���
bool erase_rule(System* s);//ɾ�����ѹ���
bool revise_rule(System* s);//�޸����ѹ���
void charge_meun();//�ϻ��»� �˵�
void begin(System* s);//�ϻ�
void end(System* s);//�»�
void cost_meun();//��ֵ�˷Ѳ˵�
void cost_charge(System* s);//��ֵ
void cost_exit_charge(System* s);//�˷�
void search_meun();//��ѯ�˵�
void search_cost(System* s);//��ѯ������
void search_total(System* s);//��ѯ������
void search_month(System* s);//��ѯ������
void print_All(System* s);//���������Ϣ
