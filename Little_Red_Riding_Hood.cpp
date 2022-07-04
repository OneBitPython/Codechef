#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}




void solve()
{
    int n,m;
    cin >>n >> m;
    vector<vector<int>>a(n, vector<int>(n));
    for(int i = 0 ;i<n;++i){
    	for(int j = 0;j<n;++j)cin >> a[i][j];
    }
	vector<vector<int>>p;
	for(int i = 0;i<m;++i){
		int u,v,k;
		cin>> u >> v >> k;
		p.pb({u-1, v-1, k});
	}		
	vector<vector<bool>>safe(n, vector<bool>(n, 0));
	for(auto x : p){
		int c = x[0], t = x[1], k = x[2];
		queue<pair<int,int>>q;
		vector<vector<bool>>visited(n, vector<bool>(n));	
		q.push({c, t});
		while(!q.empty()){
			int i = q.front().first, j = q.front().second;
			q.pop();
			if(visited[i][j])continue;
			int dist = abs(c-i)+abs(t-j);
			if(dist <= k)safe[i][j] = 1;
			else continue;
			visited[i][j] = 1;
			vector<pair<int,int>>neighbours;
			if(i > 0)neighbours.pb({i-1, j});
			if(j > 0)neighbours.pb({i, j-1});
			if(i < n-1)neighbours.pb({i+1, j});
			if(j < n-1)neighbours.pb({i, j+1});
			for(auto v : neighbours){
				if(visited[v.first][v.second])continue;
				q.push(v);
			}
		}
	}
	vector<vector<int>>dist(n, vector<int>(n, -1e18));
	dist[0][0] = a[0][0];
	for(int i = 1;i<n;++i){
		if(!safe[i][0])break;
		dist[i][0] = dist[i-1][0] + a[i][0];
	}
	for(int i =1;i<n;++i){
		if(!safe[0][i])break;
		dist[0][i] = dist[0][i-1]+a[0][i];
	}
	if(!safe[0][0]){
		cout << "NO" << endl;
		return;
	}
	for(int i = 1;i<n;++i){
		for(int j = 1;j<n;++j){
			if(safe[i][j]){
				int mx = -1e18;
				if(safe[i-1][j])mx = max(mx, dist[i-1][j]);
				if(safe[i][j-1])mx = max(mx, dist[i][j-1]);
				if(safe[i-1][j] || safe[i][j-1])dist[i][j] = mx + a[i][j];

			}
		}
	}
	if(dist.back().back() != -1e18){
		cout << "YES" << endl;
		cout << dist.back().back() << endl;
	}else cout << "NO" << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}