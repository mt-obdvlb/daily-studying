#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int MaxSize = 100; // 栈中能保存的最多元素个数 

template<class T>
class Stack {
public:
	Stack(){
		memset(elem, 0, sizeof(elem));
		top = -1;
	}
	void Push(T& n) {
		if (Size() >= MaxSize) {
			cout << "栈已满" << endl;
			return;
		}
		elem[++top] = n;
	}
	void Pop() {
		if (Empty()) {
			cout << "栈为空!" << endl;
			return;
		}
		top--;
		return;
	}
	T GetTop() {
		if (Empty()) {
			cout << "栈为空!" << endl;
			return 0;
		}
		return elem[top];
	}
	bool Empty() {
		return top==-1;
	}
	int Size() {
		return top + 1;
	}
	// 栈的构造函数 
	// 往栈顶增加元素 
	// 从非空栈的栈顶删除一个元素 
	// 返回非空栈的栈顶元素 
	// 判断栈是否为空 
	// 返回栈中元素的个数 
	void ClearStack() {
		memset(elem, 0, sizeof(elem));
		top = -1;
	}
	// 将栈清空 
	~Stack() {
		memset(elem, 0, sizeof(elem));
		top = -1;
	}
	// 栈的析构函数 
private:
	T elem[MaxSize];  // 保存栈中各元素的数组 
	int top;
};

int main() {
	Stack<int> ist;
	cout << "整数栈:" << endl;
	int n,t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		ist.Push(t);
	}
	cout <<"栈的大小为:" << ist.Size() << endl;
	while (n--) {
		cout << "当前栈顶元素为:" << ist.GetTop() << endl;
		ist.Pop();
	}
	Stack<char> sst;
	cout << "字符栈:" << endl;
	char ch;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		sst.Push(ch);
	}
	cout << "栈的大小为:" << sst.Size() << endl;
	string s="";
	while (n--) {
		s+=sst.GetTop();
		sst.Pop();
	}
	reverse(s.begin(),s.end());
	cout << "字符串为: " << s << endl;
	return 0;
}
