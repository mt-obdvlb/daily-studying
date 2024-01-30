#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class BigInt :public vector<int>{
public:
	static int Maxlen;
	BigInt(string &s,int k){
		for(int i = 0,j = s.size()-1;i<k;i++,j--)push_back(s[j]-'0');
	}
	BigInt(){
		push_back(0);
	}
	BigInt(int n,int v):vector<int>(n,v){
	}
	BigInt(int x){
		push_back(x);
		update();
	}
	void update(){
		for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 < Maxlen) {
                if (i + 1 == size()) push_back(0);
                at(i + 1) += at(i) / 10;
            }
            at(i) %= 10;
        }
	}
	BigInt operator*(const BigInt &a) {
        BigInt ret(min(Maxlen, int(size() + a.size() - 1)), 0);
        for (int i = 0; i < size(); i++) {
            for (int j = 0; j < a.size(); j++) {
                if (i + j >= Maxlen) continue;
                ret[i + j] += at(i) * a[j];
            }
        }
        ret.update();
        return ret;
    }
	BigInt& operator*=(int x){
		for(int i = 0;i<size();i++)at(i)*=x;
		update();
		return *this;
	}
	
};

int BigInt::Maxlen = 0;

ostream& operator<<(ostream& out,BigInt& b){
	for(int i = b.size()-1;i>=0;i--)out<<b[i];
	return out;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    BigInt::Maxlen = k;
    BigInt n(s, k);
    BigInt pre_y = n, y;
    vector<int> arr;
    for (int i = 0; i < n.size(); i++) {
        y = pre_y;
        int cnt = 1;
        while ((y * n).at(i) != n[i]) {
            y = y * pre_y;
            cnt += 1;
            if (cnt == 11) break;
        }
        if (cnt == 11) {
            cout << "-1" << endl;
            return 0;
        }
        arr.push_back(cnt);
        pre_y = y;
    }
    BigInt ans = 1;
    for (int i = 0; i < arr.size(); i++) {
        ans *= arr[i];
    }
    cout << ans << endl;
    return 0;
}
