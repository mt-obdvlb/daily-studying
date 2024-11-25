#include<iostream>   
using namespace std;
class IntArray {
public:
	IntArray(int sz);
	// �����ʼ��Ϊsz��Ԫ�أ���ֵȫΪ0 
	IntArray(int* array, int sz);  // �þ�̬���� array ��ǰ sz ��Ԫ�س�ʼ��������
	
	IntArray(const IntArray& rhs); // ���ƹ��캯�� 
	
	~IntArray() {
		delete ia;
	};

	void getNewIntArray(int sz, int* array);

	void printAll();

private:
	int* ia;
	int size;
};
IntArray::IntArray(int sz) {
	int* array = new int[sz]();
	getNewIntArray(sz,array);
}
// ��ʼ������Ԫ�� 
IntArray::IntArray(int* array, int sz) {
	getNewIntArray(sz, array);
}
// �������ݳ�Ա 
IntArray::IntArray(const IntArray& rhs) {
	getNewIntArray(rhs.size, rhs.ia);
}

void IntArray::getNewIntArray(int sz, int* array) {
	size = sz;
	ia = new int[size];
	// �������ݳ�Ա  
	for (int ix = 0; ix < size; ++ix)
		ia[ix] = array[ix];
}

void IntArray::printAll()
{
	for (int ix = 0; ix < size; ++ix)
		cout << ia[ix] << "  ";
	cout << endl;
}
int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	IntArray arr1(10), arr2(a, 5), arr3(arr2);
	arr1.printAll();
	arr2.printAll();
	arr3.printAll();
	return 0;
}