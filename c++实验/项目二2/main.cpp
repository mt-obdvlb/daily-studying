#include<iostream>
#define S(x) ((x)*(x))
using namespace std;

class Point {
public:
	Point(double xv, double yv) { x = xv; y = yv; }
	Point(Point& pt) { x = pt.x;  y = pt.y; }
	double getx() { return x; }
	double gety() { return y; }
	double Area() { return 0; }
	void Show() { cout << "x=" << x << ' ' << "y=" << y << endl; }
private:
	double x, y;
};

class Rectangle:public Point {
public:
	Rectangle(double x,double y,double len,double wide):
		Point(x,y),len(len),wide(wide){}
	
	double Area() { return len * wide; }

	void position(Point& pt) {
		double x = pt.getx();
		double y = pt.gety();
		if (x > getx() && x < (getx() + len) && y > gety() && y < (gety() + wide))
			cout << "在图形里面" << endl;
		else if (x == getx() || x == (getx() + len) || y == gety() || y == (gety() + wide))
			cout << "在图形上" << endl;
		else
			cout << "在图形外" << endl;
	}

	double getC() { return (len + wide) * 2; }

private:
	double len, wide;
};

class Circle :public Point {
public:
	Circle(double x,double y,double r):Point(x,y),r(r){}
	void position(Point& pt) {
		double x = pt.getx(), y = pt.gety();
		double len = sqrt(S(getx() - x) + S(gety() - y));
		if(len>r)cout << "在图形外" << endl;
		else if(len<r)cout << "在图形里面" << endl;
		else cout << "在图形上" << endl;
	}

	double getC() { return 2 * 3.14 * r; }

	double getArea(){
		return 3.14 * r * r;
	}

private:
	double r;
};

int main() {
	Point p(0, 0);
	Rectangle rec(-1, 0, 2, 2);
	Circle cir(1, 1, 1);
	rec.position(p);
	cir.position(p);
	return 0;
}