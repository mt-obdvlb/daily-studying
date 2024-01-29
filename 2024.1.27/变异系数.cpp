#include<iostream>
#include<cmath>


using namespace std;

double calu(double x,double y){
	return y/x;
}

int main(){
	double x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	double a1 = calu(x1,y1);
	double a2 = calu(x2,y2);
	if(a1>a2)cout<<"A"<<endl;
	else cout<<"B"<<endl;
	return 0;
}
