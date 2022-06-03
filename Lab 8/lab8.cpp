#include "lab8.h"

unsigned long long bci(int n, int m) {
	if ((m == 0) || (m == n)) return 1;
	if (m == 1) return n;
	else return bci(n - 1, m) + bci(n - 1, m - 1);
}