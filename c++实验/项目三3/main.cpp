#include<iostream>

using namespace std;

int gcd(int a, int b) {
	return a%b ?gcd(b,a%b): b;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

class Rational {
public:
	Rational(int a=0,int b = 1):a(a),b(b){}

	Rational operator + (Rational & c) {
		int p = lcm(b, c.getb());
		cout << p << endl;
		int pa = p/b, pb = p/c.getb();
		int ta = a * pa + c.geta() * pb;
		int tb = p;
		if (tb % ta == 0||(ta&&ta%tb==0)){
			int t = gcd(ta, tb);
			tb /= t, ta /= t;
		}
		Rational ret(ta, tb);
		return ret;
	}

	int geta() { return a; }

	int getb() { return b; }

private:
	int a, b;
};

ostream& operator<<(ostream& out,Rational& c) {
	out << c.geta() << "/" << c.getb();
	return out;
}

int main() {
	Rational x(1, 3), y(1, 6), z;
	z = x + y;
	cout << x << " + " << y << " = " << z << endl;
	return 0;
}
