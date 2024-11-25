#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int MaxSize = 100; // ջ���ܱ�������Ԫ�ظ��� 

template<class T>
class Stack {
public:
	Stack(){
		memset(elem, 0, sizeof(elem));
		top = -1;
	}
	void Push(T& n) {
		if (Size() >= MaxSize) {
			cout << "ջ����" << endl;
			return;
		}
		elem[++top] = n;
	}
	void Pop() {
		if (Empty()) {
			cout << "ջΪ��!" << endl;
			return;
		}
		top--;
		return;
	}
	T GetTop() {
		if (Empty()) {
			cout << "ջΪ��!" << endl;
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
	// ջ�Ĺ��캯�� 
	// ��ջ������Ԫ�� 
	// �ӷǿ�ջ��ջ��ɾ��һ��Ԫ�� 
	// ���طǿ�ջ��ջ��Ԫ�� 
	// �ж�ջ�Ƿ�Ϊ�� 
	// ����ջ��Ԫ�صĸ��� 
	void ClearStack() {
		memset(elem, 0, sizeof(elem));
		top = -1;
	}
	// ��ջ��� 
	~Stack() {
		memset(elem, 0, sizeof(elem));
		top = -1;
	}
	// ջ���������� 
private:
	T elem[MaxSize];  // ����ջ�и�Ԫ�ص����� 
	int top;
};

int main() {
	Stack<int> ist;
	cout << "����ջ:" << endl;
	int n,t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		ist.Push(t);
	}
	cout <<"ջ�Ĵ�СΪ:" << ist.Size() << endl;
	while (n--) {
		cout << "��ǰջ��Ԫ��Ϊ:" << ist.GetTop() << endl;
		ist.Pop();
	}
	Stack<char> sst;
	cout << "�ַ�ջ:" << endl;
	char ch;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		sst.Push(ch);
	}
	cout << "ջ�Ĵ�СΪ:" << sst.Size() << endl;
	string s="";
	while (n--) {
		s+=sst.GetTop();
		sst.Pop();
	}
	reverse(s.begin(),s.end());
	cout << "�ַ���Ϊ: " << s << endl;
	return 0;
}
