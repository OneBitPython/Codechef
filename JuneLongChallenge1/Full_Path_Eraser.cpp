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


const int mxn = (int)4e5;
int a[mxn];
int dist[mxn];
int parent[mxn];
int subtree[mxn];
vector<int>adj[mxn];


void find_subtrees(int u, int p = -1){
    subtree[u] = a[u];
    for(int v : adj[u]){
        if(v == p)continue;
        parent[v] = u;
        find_subtrees(v, u);

        subtree[u] = __gcd(subtree[u], subtree[v]);
        
    }
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i<=n;++i){
        dist[i] = 0;
        a[i] = 0;
        parent[i] = 0;
        subtree[i] = 0;
        adj[i].clear();
    }
    for(int i = 1;i<=n;++i){
        cin >> a[i];
    }
    for(int i = 0;i<n-1;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    
    find_subtrees(1);
    queue<int>q;
    q.push(1);
    vector<bool>visited(n+1);
    vector<int>cost(n+1);
    parent[1] = 1;
    int mx = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        if(visited[u])continue;
        cost[u] = cost[parent[u]];
        cost[u]-=subtree[u]; 
        if(u == 1){
            cost[u] = 0;
        }
        visited[u] = 1;
        for(int v : adj[u]){
            if(visited[v])continue;
            cost[u]+=subtree[v];
            q.push(v);
        }
        mx = max(mx, cost[u]);
    }
    cout << mx << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}