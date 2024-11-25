
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<stdbool.h>
#define DEBUG_1
#define MAX_CARD_NUM 100
#define MAX_RULE_NUM 50
#define MONTH 12

typedef struct CostNode {//链表实现
	int cost, flag, condition;//flag 1为使用,0为未使用,2为使用完成
	char begin[50], end[50], time[50];//condition 0为退费,1为充值,2为消费
	struct CostNode* next;
}CostNode;

typedef struct Card {
	long long tt;
	CostNode* cn;
	int  money, times, condition;//condition 0为注销,1为可使用,2为上机中
	char last_used[50], id[25], password[25];
}Card;

typedef struct Rule {
	int cost, condition;//1小时,2分钟,3秒
}Rule;

typedef struct System {
	long long total_money;
	long long month_money[12];
	int card_cnt;
	int rule_cnt;
	Rule r[MAX_RULE_NUM];
	Card c[MAX_CARD_NUM];
}System;

int cur_month();//现在月份
long long time1970();//获取1970到现在秒数
void WriteFileSystem(System* s);//写文件
void ReadFileSystem(System* s);//读文件
CostNode* getNewCostNode();//获取一个节点
CostNode* LastCostNode(CostNode* cn);//获取最后一个未使用的节点
CostNode* LastBeginCostNode(CostNode* cn);//获取第一个开始使用但没使用完节点
System* getNewSystem();//获取一个新的系统
void meun();//菜单
char* curTime();//获取现在时间
void card_meun();//卡菜单
void printChargeRule(System* s, int ind);//输出充值规则信息
void printCard(System* s, int ind);//输出卡信息
bool add_card(System* s);//添加卡
bool search_card(System* s);//查询卡
bool exit_card(System* s);//注销卡
void chargeRule_meun();//消费规则菜单
bool add_rule(System* s);//添加消费规则
bool search_rule(System* s);//查询消费规则
bool erase_rule(System* s);//删除消费规则
bool revise_rule(System* s);//修改消费规则
void charge_meun();//上机下机 菜单
void begin(System* s);//上机
void end(System* s);//下机
void cost_meun();//充值退费菜单
void cost_charge(System* s);//充值
void cost_exit_charge(System* s);//退费
void search_meun();//查询菜单
void search_cost(System* s);//查询卡消费
void search_total(System* s);//查询月消费
void search_month(System* s);//查询总消费
void print_All(System* s);//输出所有信息
