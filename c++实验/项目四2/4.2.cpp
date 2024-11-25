#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<iomanip>

using namespace std;
const int MAX_STU = 1005;
struct Student {
	string num, name;
	int score;
}stu[MAX_STU];

int tot = 0;

ostream& operator<<(ostream& out, Student& s) {
	cout << setw(7) << s.num << setw(10) << s.name
		<< setw(7) << s.score ;
	return out;
}

int main() {
	ifstream fin;
	fin.open("stud.dat",ios::binary);
	if (fin.is_open()) {
		while (fin.read((char*)&stu[tot++], sizeof(Student)));
		tot--;
	}
	fin.close();
	ofstream fout;
	fout.open("stud.dat",ios::binary);
	if (fout.is_open() == 0) {
		cout << "打开失败" << endl;
		return 0;
	}
	int opt,flag=1,n;
	string x,tmp;
	while (flag) {
		cout << "选择(1:输入数据 2:输出数据 3:按姓名查找数据 其他退出):";
		cin >> opt;
		switch (opt) {
			case 1:
				cout << "输入数据" << endl<<"学生人数:";
				cin >> n;
				for (int i = 1; i <= n; i++,tot++) {
					cout << "第" << i << "个学生(学号 姓名 成绩):";
					cin >> stu[tot].num >> stu[tot].name >> stu[tot].score;
				}
				break;
			case 2:
				cout << "输出数据" << endl;
				cout << "学号  姓名  成绩 " << endl;
				for (int i = 0; i < tot; i++) {
					cout << stu[i] << endl;
				}
				break;
			case 3:
				cout << "输入姓名:";
				cin >> x;
				cout << "输出匹配的结果:" << endl;
				cout << "学号 姓名  成绩" << endl;
				for (int i = 0; i < tot; i++) {
					if (stu[i].name.size() < x.size())continue;
					tmp = stu[i].name.substr(0,x.size());
					if (tmp == x)cout << stu[i] << endl;
				}
				break;
			default:
				flag = 0;
		}
	}
	for (int i = 0; i < tot; i++) {
		fout.write((const char*) & stu[i], sizeof(Student));
	}
	fout.close();
	if (fout.fail())cout << "文件操作错误!" << endl;
	return 0;
}