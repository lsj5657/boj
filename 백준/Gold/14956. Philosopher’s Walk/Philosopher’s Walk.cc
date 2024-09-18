#include<bits/stdc++.h>
using namespace std;
#define int long long

int x, y;
int n, m;


void func(int n, int m,  int shape){
	
	//cout << "x y: " << x << ' ' << y << '\n';
	//cout << "n m shape: " << n << ' ' << m << ' ' << shape << '\n';
	if(n == 2){
		vector<pair<int, int>> v;
		if(shape == 1){
			v = {{1,1}, {2,1}, {2,2}, {1,2}};
		}
		else if(shape == 2){
			v = {{1,1}, {1,2}, {2,2}, {2,1}};
		}
		else if (shape == 3){
			v = {{2,2}, {1,2}, {1,1}, {2,1}};
		}
		else if(shape == 4){
			v = {{2,1}, {2,2}, {1,2}, {1,1}};
		}
		else if(shape == 5){
			v = {{2,2},{2,1},{1,1},{1,2}};
		}

		x += v[m - 1].first;
		y += v[m - 1].second;

	}
	else{
		int width = (n / 2) * (n / 2);
		int cnt = (m - 1) / width;
		int nn = n / 2;
		int nshape;

		if(shape == 1){
			if(cnt == 0){
				nshape = 2;
			}
			if(cnt == 1){
				nshape = 1;
				x += nn;
			}
			if(cnt == 2){
				nshape = 1;
				x += nn;
				y += nn;
			}
			if(cnt == 3){
				nshape = 5;
				y += nn;
			}
			
			func(nn, m - cnt * width, nshape);
		}
		else if(shape == 2){
			if(cnt == 0){
				nshape = 1;
			}
			if(cnt == 1){
				y += nn;
				nshape = 2;
			}
			if(cnt == 2){
				x += nn;
				y += nn;
				nshape = 2;
			}
			if(cnt == 3){
				x += nn;
				nshape = 3;
			}
	
			func(nn, m - cnt * width, nshape);
		}
		else if(shape == 3){
			if(cnt == 0){
				nshape = 5;
				x += nn;
				y += nn;
			}
			if(cnt == 1) {
				nshape = 3;
				y += nn;
			}
			if(cnt == 2){
				nshape = 3;
			}
			if(cnt == 3){
				nshape = 2;
				x += nn;
			}
			func(nn, m - cnt * width, nshape);
		}
		else if(shape == 4){
			/*if(cnt == 1) {
				y += nn;
			}
			if(cnt == 2){
				x -= nn; y += nn;
			}
			if(cnt == 3){
				x -= nn;
			}
			int nshape;
			if(cnt == 0) nshape = 5;
			else if(cnt == 1)  nshape = 3;
			else if(cnt == 2) nshape = 3;
			else nshape = 2;
			func(nn, m - cnt * width, nshape);*/
		}
		else if(shape == 5){
			if(cnt == 0){
				nshape = 3;
				x += nn; y += nn;
			}
			if(cnt == 1) {
				nshape = 5;
				x += nn;
			}
			if(cnt == 2){
				nshape = 5;
			}
			if(cnt == 3){
				nshape = 1;
				y += nn;
			}
			func(nn, m - cnt * width, nshape);
		}
		
	}
}


signed main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	if(n == 2){
		vector<pair<int, int>> v = {{1,1}, {1,2}, {2,2}, {2,1}};
		cout << v[m - 1].first << ' ' << v[m - 1].second;
	}
	else{
		func(n, m, 2);

		cout << x << ' ' << y;
	}


	/*n = 16;
	for(int i = 1; i <= n * n; i++){
		cout << "n m: " << n << ' ' << i << '\n';
		x = y = 0;
		func(n, i, 2);

		cout << x << ' ' << y << "\n\n";
	}*/

}




