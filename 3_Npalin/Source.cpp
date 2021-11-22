#include<iostream>
using namespace std;

# define END -1

char c[110];
int a[110];
int a_max[110];
int len;

void make_mirror(int src[], int dst[]) {
	for(int i = 0; i < len; i++) {
		dst[i] = src[i];
	}
	for(int i = len/2; i < len; i++) {
		dst[i] = src[len - i - 1];
	}
}

int cmp(int a[], int b[]) {
	for(int i = 0; i < len; i++) {
		if(a[i] != b[i]) return a[i] - b[i];
	}
	return 0;
}

// For debuging
void print_arr(int a[], int len) {
	for(int i = 0; i < len; i++) {
		cout << a[i];
	}
	cout << "\n";
}



int main() {
	freopen("Text.txt", "r", stdin);
	cin >> c;
	len = 0;
	for(int i = 0; c[i] != '\0'; i++) {
		a[len++] = c[i] - '0';
	}

	// cout << len << "\n";
	// print_arr(a, len);
	make_mirror(a, a_max);
	// print_arr(a_max, len);
	
	bool includeMax = cmp(a_max, a) <= 0;

	int e = 0, s = 0, re = 0;
	if(len % 2 == 1) {
		e = 1;
		s = len/2;
	}
	else {
		e = 0;
		s = len/2-1;
	}

	for(int i = s; i >= e; i--) {
		int j = i;
		re = 0;
		a[j] = (a[j] + 9);
		re = a[j] / 10;
		a[j] %= 10;
		j--;
		// cout << a[j] << "\n";
		while(j >= 0) {
			a[j] = (a[j] + re);
			re = a[j] / 10;
			a[j] %= 10;
			j--;
			// cout << a[j] << "\n";
		}
	}
	if(re != 0) cout << re;
	if(!includeMax) a[s] -= 1;
	print_arr(a, s+1);
}