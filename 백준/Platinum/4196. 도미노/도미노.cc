#include <bits/stdc++.h>
using namespace std;
#define int long long


int n, m;
int out[100005];
vector<int> adj[100005], inv[100005];
bool vis1[100005], vis2[100005];
stack<int> stk;

vector<int> scc;

int num[100006];
vector<int> sccadj[100005];
int in[100005];

void dfs(int cur){
	if(vis1[cur]) return;
	vis1[cur] = 1;
	for(int nxt : adj[cur]){
		dfs(nxt);
	}
	stk.push(cur);
}

void dfs2(int cur, vector<int>& v){
	if(vis2[cur]) return;
	vis2[cur] = 1;
	for(int nxt : inv[cur]){
		dfs2(nxt, v);
	}
	v.push_back(cur);
}


bool compare(vector<int> a, vector<int> b){
	return a[0] < b[0];
}

signed main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n >> m;

		for(int i = 0; i <= n; i++){
			out[i] = -1;
			vis1[i] = vis2[i] = num[i] = in[i] = 0;
			adj[i].clear();
			inv[i].clear();
			sccadj[i].clear();
			scc.clear();
		}
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			out[u] = v;
			adj[u].push_back(v);
			inv[v].push_back(u);
		}

		for(int i = 1; i <= n; i++){
			dfs(i);
		}


		vector<vector<int>> scc;
		while(!stk.empty()){
			vector<int> v;
			dfs2(stk.top(), v);
			sort(v.begin(), v.end());
			stk.pop();
			if(v.empty()) continue;
			scc.push_back(v);

		}

		for(int i = 0; i < scc.size(); i++){
			vector<int> v = scc[i];
			//cout << i << ": ";
			for(auto w : v){
				//cout << w << ' ';
				num[w] = i;
			}
			//cout << '\n';
		}


		for(int i = 1; i <= n; i++){
			
			for(int nxt : adj[i]){
				if(num[nxt] == num[i]) continue;
				in[num[nxt]]++;
			}
		}

		/*cout << "in: \n";
		for(int i = 0; i < scc.size(); i++){
			cout << in[i] << ' ';
		}
		cout << '\n';*/
		int ans = 0;
		for(int i = 0; i < scc.size(); i++){
			if(!in[i]) ans++;
		}

		if(!ans) ans++;
		cout <<  ans << '\n';
	}

}
