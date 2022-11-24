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


vector<int>id, sz;
int root(int x){
    if(x==id[x])return x;
    return id[x] = root(id[x]);
}

bool merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return 0;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    id.resize(n);
    sz.resize(n,1);
    iota(all(id),0ll);
    vector<vector<int>>g(31);
    for(int i = 0;i<n;++i){
        int x;
        cin >> x;
        for(int j = 0;j<=30;++j){
            if(x&(1ll<<j))g[j].pb(i);
        }
    }
    vector<vector<int>>edges;
    for(int i = 0;i<=30;++i){
        int m = g[i].size();
        for(int j = 0;j<m-1;++j)edges.pb({1ll<<i, g[i][j], g[i][j+1]});
    }
    sort(all(edges));
    int took = 0;
    int res = 0;
    for(auto x : edges){
        if(merge(x[1], x[2])){
            took++;
            res+=x[0];
        }
    }
    if(took != n-1)res = -1;
    cout << res << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}