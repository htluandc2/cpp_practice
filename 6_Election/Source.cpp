#include<iostream>
using namespace std;

#define max_parties 2000

int N;
int a[1010];

int threshold;

int n_min = max_parties;	// save count of parties
int n_holds = max_parties;	// save count of holds in assembly
int a_holds[1010];
bool b[1010];

void init() {
	for(int i = 0; i < N; i++) {
		a_holds[i] = 0;
		b[i] = false;
	}
}

void find(int i, int holds, int n_parties) {
	if((holds > threshold) && (n_parties < n_min) && (holds <= n_holds)) {
		// printf("%d - %d - %d\n", i, holds, n_parties);
		n_min = n_parties;
		n_holds = holds;
		for(int i = 0, j = 0; i < N; i++) {
			if(b[i] == true) {
				a_holds[j++] = i;
			}
		}
	}
	if(i == N) {
		return;
	}
	if(n_parties > n_min) {
		return;
	}
	if(holds > n_holds) {
		return;
	}

	b[i] = true;
	find(i+1, holds+a[i], n_parties+1);
	b[i] = false;
	find(i+1, holds, n_parties);
}

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> N;
	init();
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		threshold += a[i];
	}
	threshold /= 2;
	/*
	cout << threshold << "\n";
	for(int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	*/
	find(0, 0, 0);
	cout << n_min << "\n";
	for(int i = 0; i < n_min; i++) {
		cout << a_holds[i]+1 << " ";
	}
	cout << "\n";
}