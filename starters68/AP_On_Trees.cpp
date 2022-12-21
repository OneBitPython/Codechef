#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;


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

vector<int>a;
vector<vector<int>>adj;
vector<int>in,out,ft,dist;
vector<vector<int>>up;
int timer = 1;
void dfs(int u, int p){
    in[u] = timer;
    ft[timer] = u;
    timer++;
    for(int v : adj[u]){
        if(v==p)continue;
        up[v][0] = u;
        for(int j = 1;j<=30;++j)up[v][j] = up[up[v][j-1]][j-1];
        dist[v] = dist[u]+1;
        dfs(v,u);
    }
    out[u] = timer;
    ft[timer] = u;
    timer++;
}

int lca(int u, int v){
    if(dist[v] > dist[u])swap(u,v);
    int k= dist[u]-dist[v];
    for(int i = 0;i<=30;++i){
        if(k&(1ll<<i))u = up[u][i];
    }
    if(u==v)return u;
    for(int i = 30;i>=0;--i){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[v][0];
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    a.resize(n+1);
    ft.resize(2*n+1);
    out.resize(n+1);
    in.resize(n+1);
    dist.resize(n+1);
    up = vector<vector<int>>(n+1, vector<int>(31));
    for(int i= 1;i<=n;++i)cin >> a[i];
    for(int i = 0;i<n-1;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    dbg(in,out,ft);
    vector<vector<int>>queries;
    int m;
    cin >> m;
    for(int i = 0;i<m;++i){
        int u,v;
        cin>> u >> v;
        if(in[v] < in[u])swap(u,v);
        int l = lca(u,v);
        if(l==u){
            queries.pb({in[u], in[v],i,-1});
        }else queries.pb({out[u],in[v],i,l});
    }
    int sz = sqrt(n);
    sort(all(queries), [&](auto &one, auto &two){
        int o = one[0]/sz, t = two[0]/sz;
        if(o==t)return one[1] < two[1];
        return o < t;
    }); 
    dbg(queries);
    int l = 1, r = 0;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}