#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);

	string s;
	cin >> s;

	int a, b, c;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '@'){
			a = i;
		}
		else if(s[i] == '#'){
			b = i;
		}
		else if(s[i] == '!'){
			c = i;
		}
	}


	if(c < b){
		if(b < a){
			cout << a - c - 1;
		}
		else{
			cout << -1;
		}
	}
	else if(b < c){
		if(a < b){
			cout << c - a - 1;
		}
		else cout << -1;
	}

}