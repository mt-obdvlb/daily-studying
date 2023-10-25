#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define S(x) pow(x,2)

int f( long long  s,long  long n, long long* x, long long* y);

int main() {
	long long t = 0;
	long long n = 0;
	long long s = 0;
	long long d = 0;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld%lld", &n, &s, &d);
		long  long xs, xd, ys, yd ;
		f(s,n, &xs, &ys);
		f(d,n, &xd, &yd);
		printf("%.0llf\n", 10*(long double)(sqrt(S(xs - xd) + S(ys - yd))));
	}
	return 0;
}

int f(long  long s,long  long n, long long* x, long long* y) {
	if (n == 1) {
		if (s == 1) *x = 0, *y = 0;
		else if (s == 2) *x = 0, *y = 1;
		else if (s == 3) *x = 1, *y = 1;
		else *x = 1, *y = 0;
		return 0;
	}
	else {
		long  long L = 0;
		long  long xx = 0;
		long  long yy = 0;
		L = pow(2, n - 1);
		long long LL = L * L;
		if (s <= LL) {
			f(s, n-1, &xx, &yy);
			*x = yy;
			*y = xx;
		}
		else if (s <= 2 * LL) {
			f(s - LL, n - 1, &xx, &yy);
			*x = xx  ;
			* y = yy + L;
		}
		else if (s <= 3 * LL) {
			f(s - 2*LL, n - 1, &xx, &yy);
			*x = xx+L;
			*y = yy + L;
		}
		else if (s <= 4 * LL) {
			f(s - 3 * LL, n - 1, &xx, &yy);
			*x = 2 * L - yy - 1;
			*y = L - xx - 1;
		}
		return 0;
	}

}