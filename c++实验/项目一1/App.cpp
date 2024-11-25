#include"MyClass.h"

int main() {
	MyClass obj1, obj2(5, 8);
	obj1.x = 1;
	obj1.y = 3;
	obj1.Print();
	obj2.Print();
	return 0;
}