#include<iostream>   
using namespace std;
class IntArray {
public:
	IntArray(int sz);
	// 数组初始化为sz个元素，初值全为0 
	IntArray(int* array, int sz);  // 用静态数组 array 的前 sz 个元素初始化新数组
	
	IntArray(const IntArray& rhs); // 复制构造函数 
	
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
// 初始化数组元素 
IntArray::IntArray(int* array, int sz) {
	getNewIntArray(sz, array);
}
// 拷贝数据成员 
IntArray::IntArray(const IntArray& rhs) {
	getNewIntArray(rhs.size, rhs.ia);
}

void IntArray::getNewIntArray(int sz, int* array) {
	size = sz;
	ia = new int[size];
	// 设置数据成员  
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