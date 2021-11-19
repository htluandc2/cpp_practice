#include<iostream>
using namespace std;

int n_lines;
double xv[500010], yv[500010];
int p[500010][2];
double x[1001], y [1001];



int main() {
	freopen("input.txt", "r", stdin);
	int N;
	n_lines = 0;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	// For tesing I-O
	/*
	for(int i = 0; i < N; i++) {
		cout << x[i] << " " << y[i] << "\n";
	}
	*/
	
	for(int i = 0; i < N; i++) {
		for(int j = i+1; j < N; j++) {
			p[n_lines][0] = i; 
			p[n_lines][1] = j;
			n_lines++;
		}
	}
	
	int n_rec = 0;
	for(int d1 = 0; d1 < n_lines; d1++) {
		for(int d2 = d1+1; d2 < n_lines; d2++) {
			bool is_rec= false;

			int i1, i2, i3, i4;
			i1 = p[d1][0]; i2 = p[d1][1];
			i3 = p[d2][0]; i4 = p[d2][1];

			double xv13 = x[i1] - x[i3], yv13 = y[i1] - y[i3];
			double xv24 = x[i2] - x[i4], yv24 = y[i2] - y[i4];

			double xv14 = x[i1] - x[i4], yv14 = y[i1] - y[i4];
			double xv23 = x[i2] - x[i3], yv23 = y[i2] - y[i3];

			double xv12 = x[i1] - x[i2], yv12 = y[i1] - y[i2];
			double xv34 = x[i3] - x[i4], yv34 = y[i3] - y[i4];

			if((xv12 == 0) && (xv34 == 0)) {
				if((yv13 == 0 && yv24 == 0) || (yv14 == 0 && yv23 == 0)) {
					n_rec++;
					is_rec = true;
				}
			}
			else if((yv12 == 0) && (yv34 == 0)) {
				if((xv13 == 0 && xv24 == 0) || (xv14 == 0 && xv23 == 0)) {
					n_rec++;
					is_rec = true;
				}
			}
			else if((xv12 == 0) || (xv34 == 0)) {
				is_rec = false;
			}
			else {
				if((yv12 / xv12) == (yv34 / xv34)) {
					bool c1 = ((yv13/xv13) * (yv12/xv12)== - 1) && ((yv24/xv24) * (yv12/xv12)== - 1);
					bool c2 = ((yv14/xv14) * (yv12/xv12)== - 1) && ((yv23/xv23) * (yv12/xv12)== - 1);
					if(c1 || c2) {
						n_rec++;
						is_rec = true;
					}
				}
			}

			if(is_rec) {
				cout << "(" << x[i1] << ", " <<  y[i1] << ") ";
				cout << "(" << x[i2] << ", " <<  y[i2] << ") \n";
				cout << "(" << x[i3] << ", " <<  y[i3] << ") ";
				cout << "(" << x[i4] << ", " <<  y[i4] << ") \n";
				cout << "\n";
			}
		}
	}

	cout << n_rec / 2 << "\n";
}