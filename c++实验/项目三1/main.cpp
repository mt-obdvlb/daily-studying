#include<iostream>
#define S(x) ((x)*(x))
#define pi 3.1415926
using namespace std;

class Geometric_shape {
public:
	virtual double perimeter() { return 0; }

	virtual double area() { return 0; }

	virtual double volume() { return 0; }

	virtual void Show(){}
};

class Circle :public Geometric_shape {
public:
	Circle(double r):r(r){}

	void Show() {
		cout << "Բ��";
	}

	double area() {
		return pi * r * r;
	}

	double perimeter() {
		return 2 * pi * r;
	}

	double getr() { return r; }

private:
	double r;
};

class Rectangle :public Geometric_shape {
public:
	Rectangle(double a,double b):a(a),b(b){}

	void Show() {
		cout << "����";
	}

	double area() {
		return a * b;
	}

	double perimeter() {
		return 2 * (a + b);
	}



	double geta() { return a;}

	double getb() { return b; }

private:
	double a, b;
};

class Triangle :public Geometric_shape {
public:
	Triangle(double a, double b, double c) :a(a), b(b), c(c) { p = (a + b + c) / 2; }

	void Show() {
		cout << "������";
	}

	double area() {
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	double perimeter() {
		return p * 2;
	}

	double geta() { return a; }

	double getb() { return b; }

	double getc() { return c; }

	double getp() { return p; }

private:
	double a, b, c,p;
};

class Box :public Rectangle {
public:
	Box(double a,double b,double c):Rectangle(a,b),c(c){}

	double volume() {
		return area() * c;
	}

	void Show() {
		cout << "������";
	}

private:
	double c;
};

class Cylinder :public Circle {
public:
	Cylinder(double r, double h) :Circle(r), h(h) {}

	double volume() {
		return area() * h;
	}

	void Show() {
		cout << "Բ��";
	}

private:
	double h;
};

class Cone : public Circle {
public:
	Cone(double r, double h) :Circle(r), h(h) {}

	double area() {
		return pi *S(getr());
	}

	double volume() {
		return area() * h;
	}

	void Show() {
		cout << "Բ׶";
	}

private:
	double h;
};

class T_pyramid :public Triangle {
public:
	T_pyramid(double a, double b, double c,double h) :Triangle(a,b,c) ,h(h){}

	double volume() {
		return area() * h;
	}

	void Show() {
		cout << "����׶";
	}

private:
	double h;
};

class T_prism :public Triangle {
public:
	T_prism(double a, double b, double c,double h) :Triangle(a, b, c),h(h) {}

	void Show() {
		cout << "������";
	}

	double volume() {
		return area() * h;
	}

private:
	double h;
};

int main() {
	Geometric_shape* gs[] = { new Circle(10),new  Rectangle(6,8),new
	Triangle(3,4,5), new Box(6,8,3), new Cylinder(10,3), new  Cone(10,3),
	new T_pyramid(3,4,5,3), new T_prism(3,4,5,3) };
	for (int i = 0; i < 8; i++) {
		gs[i]->Show();
		cout << endl;
	}
	// ���ͼ�ε����ͣ��硰Բ�Ρ� 
	cout << "ƽ��ͼ�Σ�" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "ͼ���ܳ���" << gs[i]->perimeter() << '\t';
			cout << "ͼ�������" << gs[i]->area() << '\t';
			cout << "ͼ�������" << gs[i]->volume() << endl;
		}
	cout << "����ͼ�Σ�" << endl;
	for (int i = 3; i < 8; i++) {
		cout << "ͼ�ε��ܳ���" << gs[i]->perimeter() << '\t';
		cout << "ͼ�ε������" << gs[i]->area() << '\t';
		cout << "ͼ�����  ��" << gs[i]->volume() << endl;
	}
	return 0;
}