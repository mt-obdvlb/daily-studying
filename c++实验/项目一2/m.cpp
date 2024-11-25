#include<iostream>

using namespace std;

class Rectangle {
public:
	Rectangle(double a=0.0,double b=0.0):a(a),b(b){}
	
	double getC() {
		return (a + b) * 2.0;
	}
	
	double getS() {
		return a *b;
	}

	void print() {
		cout << "长: " << a << "  宽: " << b << "  的矩形周长为: "
			<< getC() << "  面积为: " << getS() << endl;
	}

private:
	double a, b;
};


int main() {
	Rectangle obj1(20, 50), obj2(3.6, 4.5);
	obj1.print(), obj2.print();
	return 0;
}