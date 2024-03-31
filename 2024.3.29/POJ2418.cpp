#include<iostream>
#include<map>
#include<set>
using namespace std;

map<string,int> m;
set<string> s;
int sum = 0;

int main(){
	string t;
	while(getline(cin,t)){
		m[t]++;
		s.insert(t);
		sum++;
	}
	while(!s.empty()){
		t = *s.begin();
		cout<<t;
		s.erase(*s.begin());
		printf(" %.4lf\n",100.0*m[t]*1.0/sum);
	}
	return 0;
}
