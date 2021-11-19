#include<iostream>
using namespace std;

int a[100010];
int N = 0;
int MAX_N = 10010;
int MIN_N = -10010;

int index_min_max[6];
int choosen[100010], len_choosen;

void reset_choosen() {
	for(int i = 0; i < N; i++) {
		choosen[i] = 0;
	}
}

void get_3_min() {
	for(int t = 0; t < 3; t++) {
		int min = MAX_N;
		for(int i = 0; i < N; i++) {
			if(a[i] < min && choosen[i] == 0) {
				index_min_max[len_choosen] = i;
				min = a[i];
			}
		}
		if(min != MAX_N) {
			choosen[index_min_max[len_choosen]] = 1;
			len_choosen++;
		}
	}
}

void get_3_max() {
	for(int t = 0; t < 3; t++) {
		int max = MIN_N;
		for(int i = 0; i < N; i++) {
			if(a[i] > max && choosen[i] == 0) {
				index_min_max[len_choosen] = i;
				max = a[i];
			}
		}
		if(max != MIN_N) {
			choosen[index_min_max[len_choosen]] = 1;
			len_choosen++;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	len_choosen = 0;
	reset_choosen();
	get_3_min();
	get_3_max();

	int maxProd = MIN_N;
	for(int i = 0; i < len_choosen; i++) {
		for(int j = i+1; j < len_choosen; j++) {
			int idx1 = index_min_max[i]; 
			int idx2 = index_min_max[j];
			if(a[idx1] * a[idx2] > maxProd) {
				maxProd = a[idx1] * a[idx2];
			}
		}
	}

	for(int i = 0; i < len_choosen; i++) {
		for(int j = i+1; j < len_choosen; j++) {
			for(int k = j+1; k < len_choosen; k++) {
				int idx1 = index_min_max[i]; 
				int idx2 = index_min_max[j];
				int idx3 = index_min_max[k];
				if(a[idx1] * a[idx2] * a[idx3] > maxProd) {
					maxProd = a[idx1] * a[idx2] * a[idx3];
				}
			}
		}
	}

	printf("%d\n", maxProd);
}