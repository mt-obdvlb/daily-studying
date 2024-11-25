#include<iostream>
#define S(x) ((x)*(x))
using namespace std;

class MyPoint {
public:
	MyPoint(double x0, double y0) :x(x0), y(y0) {}
	MyPoint(MyPoint& np) :x(np.x), y(np.y) {}
	double getX() { return x; }
	double getY() { return y; }
	void setX(double x0) { x = x0; }
	void setY(double y0) { y = y0; }
	void setPoint(double x0, double y0) { x = x0; y = y0; }
	void setPoint(MyPoint& np) { x = np.x; y = np.y; }
	double getLength(MyPoint p) {
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
	void printIt() { cout << " (" << x << "," << y << ") "; }
private:
	double x, y;
};

class Triangle {
public:
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3) :p1(x1, y1), p2(x2, y2), p3(x3, y3) {}

	double getC() {
		return p1.getLength(p2) + p1.getLength(p3) + p2.getLength(p3);
	}

	double getS() {
		double a = p1.getLength(p2), b = p2.getLength(p3), c = p1.getLength(p3), p = (a + b + c) / 2.0;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	void print() {
		cout << "三角形的三点坐标分别为:" << endl;
		p1.printIt(); cout << endl;
		p2.printIt(); cout << endl;
		p3.printIt(); cout << endl;
		cout << "三角形的周长为:  " << getC() << "  面积为:  " << getS() << endl;
	}
private:
	MyPoint p1, p2, p3;
};

int main() {
	Triangle t(0.0, 0.0, 3.0, 4.0, 3.0, 0.0);
	t.print();
	return 0;
}