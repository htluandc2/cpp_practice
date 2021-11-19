#include<stdio.h>
#include<iostream>
#include<time.h>
using namespace std;

int main() {
	clock_t tStart = clock();
	freopen("input.txt", "r", stdin);

	int N, K;
	scanf("%d %d", &N, &K);
	int cases = 0;
	// cout << K << "\n";
	
	if(K == 1) {
		cases = 1;
	}
	else if(K == 2){
		if(N % 2 == 0) {
			cases = N / 2 - 1;
		}
		else {
			cases = N / 2;
		}
	}
	else if(K == 3) {
		for(int i = 1; i <= N/3; i++) {
			for(int j = i+1; j <= N/2; j++) {
				int k = N - i - j;
				if(i < j && j < k && (i+j+k) == N) {
					cases++;
				}
			}
		}
	}
	else if(K == 4) {
		for(int i = 1; i <= N/4; i++) {
			for(int j = i+1; j <= N/3; j++) {
				for(int k = j+1; k <= N/2; k++) {
					int l = N - i - j - k;
					if(i < j 
						&& j < k 
						&& k < l) {
							cases++;
					}
				}
			}
		}
	}
	// printf("%d\n", K);
	printf("%d\n", cases);
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}