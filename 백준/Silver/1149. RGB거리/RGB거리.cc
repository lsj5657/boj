#include <iostream>
using namespace std;

int d[1001][3];
int rgb[1001][3];


int main() {
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) 
		for (int y = 0; y < 3; y++)
			cin >> rgb[x][y];



	for (int j = 0; j < 3; j++) {
		d[0][j] = rgb[0][j];
	}
	for (int i = 1; i < n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + rgb[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + rgb[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + rgb[i][2];
	}


	cout << min(min(d[n - 1][0], d[n - 1][1]),d[n-1][2]);
}