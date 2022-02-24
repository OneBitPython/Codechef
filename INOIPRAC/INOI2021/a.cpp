#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

template<typename T>
void output(vector<T>&a){
	for(auto x: a)cout << x << ' ';
	cout << endl;
}

template<typename T>
void output(vector<vector<T>>&a){
	for(auto x: a)output(x);
}

template<typename T>
void output(set<T>&a){
	for(auto x: a)cout << x << ' ';
	cout << endl;
}

template<typename T, typename F>
void output(pair<T, F>&a){
	cout << a.first << ' ' << a.second << endl;
}

template<typename T, typename F>
void output(vector<pair<T, F>> &a){
	for(auto x: a)output(x);
}

template<typename T,typename F>
void output(map<T, F> &a){
	for(auto u : a){
		output(u);
	}
}

void print(){cout << endl;}
template<typename one, typename... args>
void print(one first, args... rest){
	cout << first << ' ';
	print(rest...);
}
vector<vector<pair<int,int>>> adj;
vector<int>visited, colors;

int dfs(int u, int curr_color, int&s1, int&s2){
	colors[u] = curr_color;
	visited[u] = 1;
	if(curr_color == 1)s1++;
	else s2++;
	for(auto c : adj[u]){
		int t =c.first, v = c.second;
		if(visited[v])continue;
		if(t == 1){
			int new_color = (!colors[u]);
			if(colors[v]!=-1){
				print('f');
				if(colors[v] != new_color)return -1;
			}
			dfs(v, new_color, s1, s2);
		}else{
			int new_color = colors[u];
			if(colors[v]!=-1){
				print('f');
				if(colors[v] != new_color)return -1;
			}
			dfs(v, new_color, s1, s2);
		}
	}
	return max(s1, s2);
}

void cleanup(){
	adj.clear();
	colors.clear();
	visited.clear();
}

void solve(){
	int n, q;
	cin >> n >> q;

	adj.resize(n+1);
	colors.resize(n+1,-1);
	visited.resize(n+1, 0);
	for(int c = 0;c<q;++c){
		int type, i, j;
		cin >> type >> i >> j;

		adj[i].pb({type, j});
		adj[j].pb({type, i});
	}
	int ans=0;
	bool ok = 1;

	for(int i = 1;i<=n;++i){
		if(!visited[i]){
			int s1 = 0, s2 = 0;
			int resp = dfs(i, 1, s1, s2);
			if(resp == -1)ok = 0;
			ans+=resp;
		}
	}

	if(ok)cout << ans << endl;
	else cout << -1 << endl;
	cleanup();
}

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--)solve();
	
}