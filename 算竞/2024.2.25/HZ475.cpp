#include<iostream>
#include<vector>
#include<string>
using namespace std;
class BigInt;
ostream& operator<<(ostream& out, const BigInt& b);

class BigInt :public vector<int> {
public:
	BigInt(const string& s) {
		for (int i = s.size() - 1; i >= 0; i--)push_back(s[i] - '0');
		update();
	}
	BigInt(int n, int x) :vector<int>(n, x) {
	}
	BigInt(int x){
		push_back(x);
		update();
	}
	void update() {
		for (int i = 0; i < size(); i++) {
			if (at(i) < 10)continue;
			if (i == size() - 1)push_back(0);
			at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		while (size() > 1 && at(size() - 1) == 0)pop_back();
	}
	BigInt operator/(BigInt& x) {
		int cnt = 0;
		BigInt t1(*this);
		if(t1==x)return BigInt(1);
		if(x>t1)return BigInt(0);
		while (t1 > x) {
			x *= 10;
			cnt++;
		}
		x /= 10;
		BigInt ret(cnt, 0);
		while (cnt) {
			while (t1 >= x) {
				ret[cnt-1]++;
				t1 -= x;
			}
			x /= 10;
			cnt--;
		}
		ret.update();
		return ret;
	}
	bool operator>(const BigInt& b) {
		if (b.size() != size())return size() > b.size();
		for (int I = size() - 1, i = I; i >= 0; i--) {
			if (at(i) == b[i])continue;
			return at(i) > b[i];
		}
		return 0;
	}
	bool operator>=(const BigInt& b) {
		if (b.size() != size())return size() >= b.size();
		for (int I = size() - 1, i = I; i >= 0; i--) {
			if (at(i) == b[i])continue;
			return at(i) >= b[i];
		}
		return true;
	}
	void operator*=(int x) {
		for (int i = 0; i < size(); i++)at(i) *= x;
		update();
	}
	void operator/=(int x) {
		int y = 0;
		for (int i = size() - 1; i >= 0; i--) {
			y = y * 10 + at(i);
			at(i) = y / x;
			y %= x;
		}
		update();
	}
	BigInt operator-(const BigInt& b) {
		BigInt ret(*this);
		ret -= b;
		return ret;
	}
	void operator-=(const BigInt& b) {
		for (int i = 0; i < b.size(); i++) {
			at(i) -= b[i];
			if (at(i) > 0||i==size()-1)continue;
			at(i + 1) -= 1;
			at(i) += 10;
		}
		update();
	}

};
ostream& operator<<(ostream& out, const BigInt& b) {
	for (int i = b.size() - 1; i >= 0; i--)out << b[i];
	return out;
}

string n, m;

int main() {
	cin >> n >> m;
	BigInt a(n), b(m);
	cout << (b / a) << endl;
	return 0;
}
