#include<iostream>
using namespace std;

class Complex {
public:

	Complex(int a = 0 ,int b = 0) :a(a), b(b) {}

	Complex operator+(Complex& d) {
		Complex ret(a+d.geta(),b+d.getb() );
		return ret;
	}


	int geta() { return a; }

	int getb() { return b; }


private:
	int a, b;
};

Complex operator+(double c, Complex& d) {
	int a = int(c);
	double tb = c - a;
	while ((double)int(tb+1e-6) + 1e-6 < tb) {
		tb = tb*10.0;
	}
	int b = (int)(tb+1e-6);
	Complex ret(a + d.geta(), b + d.getb());
	return ret;
}

ostream& operator<<(ostream& out, Complex& c) {
	out << c.geta() << "." << c.getb();
	return out;
}

int main() {
	Complex a(2, 5), b(7, 8), c(0, 0);
	c = a + b;
	c = 4.1 + a;
	cout << c << endl;
	return 0;
}