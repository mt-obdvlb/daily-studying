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
			printf("��Ҫ�������Աģʽ����������!(��������)\n");
			system("pause");
			system("cls");
		}
		switch (choice) {
			case 1://��
				card_meun();
				scanf("%d",&choice);
				system("cls");
				switch (choice) {
					case 1:
						if (!add_card(s)) {
							printf("����������!\n");
							printf(" ���ʧ��!\n");
						}
						else {
							printf("��ӳɹ�!\n");
						}
						system("pause");
						break;
					case 2:
						if (!search_card(s)) {
							printf("��ѯʧ��!\n");
							printf(" �޴˿�!\n");
						}
						system("pause");

						break;
					case 3:
						if (!exit_card(s)) {
							printf("ע��ʧ��!\n");
						}
						else {
							printf("ע���ɹ�!\n");
						}
						system("pause");
						break;
					case 0:
						break;
					default:
						printf("          �������Ӧ����            \n");
						system("pause");
				}
				break;
			case 2://���ѹ���
				chargeRule_meun();
				scanf("%d", &choice);
				system("cls");
				switch (choice) {
					case 1:
						printf("�������������ӼƷѱ�׼����\n");
						printf("1.     ��ʱ��Ʒ�         \n");
						printf("0.         ����\n");
						scanf("%d", &choice);
						if (choice != 1) {
							printf("����δʵ��!\n");
							system("pause");
							break;
						}
						if (add_rule(s)) {
							printf("��ӳɹ�!\n");
						}
						else {
							printf("  ���ʧ��!\n");
						}
						system("pause");
						break;
					case 2:
						if (!search_rule(s)) {
							printf("��ѯʧ��!\n");
							system("pause");
						}
						break;
					case 3:
						if (erase_rule(s)) {
							printf("ɾ���ɹ�!\n");
						}
						else {
							printf("ɾ��ʧ��!\n");
						}
						system("pause");
						break;
					case 4:
						if (revise_rule(s)) {
							printf("�޸ĳɹ�!\n");
						}
						else {
							printf("�޸�ʧ��!\n");
						}
						system("pause");
						break;
					case 0:
						break;
					default:
						printf("          �������Ӧ����            \n");
						system("pause");

				}
				break;

			case 3://�ϻ��»�
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
						printf("          �������Ӧ����            \n");
						system("pause");

				}
				break;

			case 4://��ֵ�˷�
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
						printf("          �������Ӧ����            \n");
						system("pause");

				}
				break;

			case 5://��ѯ
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
						printf("          �������Ӧ����            \n");
						system("pause");

				}
				break;
			case 6:
				printf("��ȷ��Ҫ���ϵͳ�� \n");
				printf("   Y(y)   N(n) \n");
				getchar();
				char cc;
				scanf("%c", &cc);
				if (cc == 'N' || cc == 'n')break;
				if (cc != 'Y' && cc != 'y')break;
				s = getNewSystem();

				printf("����ɹ�!\n");
				system("pause");
				break;
			case 0:
				printf("��ȷ��Ҫ�˳��� \n");
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
				printf("          �������Ӧ����            \n");
				system("pause");
				break;
		}
	}
	WriteFileSystem(s);
	return 0;
}