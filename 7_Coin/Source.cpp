#include<iostream>
using namespace std;

char seqs[1000010];
int n_o[1000010];
int n_r[1000010];

int main() {
	freopen("Text.txt", "r", stdin);
	int n;
	float k;
	cin >> n >> k;
	cin >> seqs;
	/*
	cout << n << " " << k << "\n";
	cout << seqs << "\n";
	*/
	int r = 0, o = 0;
	for(int i = 0; i < n; i++) {
		if(seqs[i] == 'O') o++;
		if(seqs[i] == 'R') r++;
		n_r[i] = r;
		n_o[i] = o;
	}

	int max_len = 0;
	for(int i = 0; i < n; i++) {
		for(int j = n-1; j > i; j--) {
			if(j - i <= max_len) break;
			r = 0; o = 0;
			if(i == 0) {
				r = n_r[j];
				o = n_o[j];
			}
			else {
				r = n_r[j] - n_r[i];
				o = n_o[j] - n_o[i];
			}
			// printf("(%d, %d): r=%d, o=%d\n", i, j, r, o);
			if(r != 0 && (o * 1.0f / r == k) && (j - i > max_len)) {
				max_len = j - i;
				// printf("Case: (%d, %d): r=%d, o=%d\n", i, j, r, o);
			}
		}
	}

	cout << max_len << "\n";
}