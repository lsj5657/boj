#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(string s){
	if(s.length() % 2) return 0;

	for(int i = 0; i < s.length(); i += 2){
		if(s[i] == '0') return 0;
	}

	for(int i = 1; i < s.length() - 2; i+=2){
		if(s[i] == s[i + 2]) return 0;
	}

	return 1;
}

string convert(string s){
	string ret = "";


	for(int i = 0; i < s.length(); i+=2){
		int cnt = s[i] - '0';
		while(cnt--){
			ret += s[i + 1];
		}
	}

	return ret;
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;

	if(!isValid(s)) cout << -1;
	else{
		string t = convert(s);



		if(t[0] == '0') cout << -1;
		else cout << t;
	}

}
