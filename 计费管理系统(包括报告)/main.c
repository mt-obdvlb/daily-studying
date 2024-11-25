#define _CRT_SECURE_NO_WARNINGS
#include"func.h"

int main() {
	int flag = 1;
	System* s = getNewSystem();
	ReadFileSystem(s);
	while (flag) {
		system("cls");
		meun();
		int choice;
		scanf("%d", &choice);
		system("cls");
		if (choice == 2|| choice == 6|| choice == 7) {
			printf("若要进入管理员模式请输入密码!(不用输入)\n");
			system("pause");
			system("cls");
		}
		switch (choice) {
			case 1://卡
				card_meun();
				scanf("%d",&choice);
				system("cls");
				switch (choice) {
					case 1:
						if (!add_card(s)) {
							printf("卡容量已满!\n");
							printf(" 添加失败!\n");
						}
						else {
							printf("添加成功!\n");
						}
						system("pause");
						break;
					case 2:
						if (!search_card(s)) {
							printf("查询失败!\n");
							printf(" 无此卡!\n");
						}
						system("pause");

						break;
					case 3:
						if (!exit_card(s)) {
							printf("注销失败!\n");
						}
						else {
							printf("注销成功!\n");
						}
						system("pause");
						break;
					case 0:
						break;
					default:
						printf("          请输入对应数字            \n");
						system("pause");
				}
				break;
			case 2://消费规则
				chargeRule_meun();
				scanf("%d", &choice);
				system("cls");
				switch (choice) {
					case 1:
						printf("请输入你想的添加计费标准类型\n");
						printf("1.     按时间计费         \n");
						printf("0.         其他\n");
						scanf("%d", &choice);
						if (choice != 1) {
							printf("功能未实现!\n");
							system("pause");
							break;
						}
						if (add_rule(s)) {
							printf("添加成功!\n");
						}
						else {
							printf("  添加失败!\n");
						}
						system("pause");
						break;
					case 2:
						if (!search_rule(s)) {
							printf("查询失败!\n");
							system("pause");
						}
						break;
					case 3:
						if (erase_rule(s)) {
							printf("删除成功!\n");
						}
						else {
							printf("删除失败!\n");
						}
						system("pause");
						break;
					case 4:
						if (revise_rule(s)) {
							printf("修改成功!\n");
						}
						else {
							printf("修改失败!\n");
						}
						system("pause");
						break;
					case 0:
						break;
					default:
						printf("          请输入对应数字            \n");
						system("pause");

				}
				break;

			case 3://上机下机
				charge_meun();
				scanf("%d", &choice);
				system("cls");
				switch (choice) {
					case 1:
						begin(s);
						system("pause");
						break;
					case 2:
						end(s);
						system("pause");
						break;
					case 0:
						break;
					default:
						printf("          请输入对应数字            \n");
						system("pause");

				}
				break;

			case 4://充值退费
				cost_meun();
				scanf("%d", &choice);
				system("cls");
				switch (choice) {
					case 1:
						cost_charge(s);
						system("pause");
						break;
					case 2:
						cost_exit_charge(s);
						system("pause");
						break;
					case 0:
						break;
					default:
						printf("          请输入对应数字            \n");
						system("pause");

				}
				break;

			case 5://查询
				search_meun();
				scanf("%d", &choice);
				system("cls");
				switch (choice) {
					case 1:
						search_cost(s);
						system("pause");
						break;
					case 2:
						search_total(s);
						system("pause");
						break;
					case 3:
						search_month(s);
						system("pause");
						break;
					case 0:
						break;
					default:
						printf("          请输入对应数字            \n");
						system("pause");

				}
				break;
			case 6:
				printf("你确定要清除系统吗 \n");
				printf("   Y(y)   N(n) \n");
				getchar();
				char cc;
				scanf("%c", &cc);
				if (cc == 'N' || cc == 'n')break;
				if (cc != 'Y' && cc != 'y')break;
				s = getNewSystem();

				printf("清除成功!\n");
				system("pause");
				break;
			case 0:
				printf("你确定要退出吗 \n");
				printf("   Y(y)   N(n) \n");
				getchar();
				char c;
				scanf("%c", &c);
				if (c == 'N' || c == 'n')break;
				if (c != 'Y' && c != 'y')break;
				flag = 0;
				break;
			case 7:
				print_All(s);
				system("pause");
				break;
			default:
				printf("          请输入对应数字            \n");
				system("pause");
				break;
		}
	}
	WriteFileSystem(s);
	return 0;
}