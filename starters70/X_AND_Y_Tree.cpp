#include <bits/stdc++.h>
using namespace std;

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


void dfs(int u, int p, vector<vector<int>>&adj, vector<int>&par){
    for(int v : adj[u]){
        if(v==p)continue;
        par[v] = u;
        dfs(v,u,adj,par);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    vector<int>par(n+1);
    vector<int>subtree(n+1);
    vector<int>in(n+1);
    for(int i= 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        in[u]++;
        in[v]++;
    }
    dfs(1,-1,adj,par);
    int q;
    cin >> q;
    int res = n-1;
    int cnt = 0;
    vector<int>c(n+1);
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int u;
            cin >> u;
            if(subtree[u])continue;

            if(in[u]==1 && u != 1){
                // leaf
                c[par[u]]++;
                subtree[u] = 1;
                cnt++;
                res--;
            }else{
                int x = adj[u].size();
                if(u!=1)x--;
                if(c[u]==x){
                    subtree[u] = 1;
                    cnt++;
                    res--;
                    c[par[u]]++;
                }
            }
        }else{
            if(cnt==n)cout << n-1 << endl;
            else cout << res << endl;
        }
    }
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}