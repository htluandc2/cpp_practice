#include<iostream>
using namespace std;

char str[110];
char max_p[110];
char nplim_arr[110];

int len(char str[]) {
	int i = 0;
	for(i = 0; str[i] != '\0'; i++) {
	}
	return i;
}



bool is_greater(char s1[], char s2[]) {
	int size = len(s1);
	for(int i = 0; i < size; i++) {
		if(s1[i] < s2[i]) return false;
	}
	return true;
}

void test(int k) {
	char t[100];
}

int main() {
	freopen("Text.txt", "r", stdin);

	int N;
	cin >> str;
	cout << len(str) << "\n";

	// make max npalim
	int size = len(str);
	for(int i = 0; i <= size/2; i++) {
		max_p[i] = str[i];
		max_p[size-1-i] = str[i];
	}
	if(!is_greater(str, max_p)) {
		cout << "hear";
		max_p[size/2] -= 1;
	}

	for(int i = 0; i <= size/2; i++) {
		cout << max_p[i];
	}
	cout << "\n";

	return 0;
}