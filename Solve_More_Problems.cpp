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

struct node{
    int a,b;
};

bool pos(vector<node>&a, int x, int k){
    // take x values
    vector<vector<int>>c;
    int n = a.size()-1;
    for(int i = 1;i<=n;++i)c.pb({a[i].a+a[i].b,a[i].a,a[i].b});
    sort(all(c));
    int mn2 = 1e18, mn1 = 1e18;
    for(int i = x-1;i<n;++i){
        mn2 = min(mn2, c[i][0]);
        mn1 = min(mn1, c[i][1]);
    }
    int cost = 0;
    for(int i = 0;i<x-1;++i)cost+=c[i][0];
    if(cost+mn1<=k)return 1;
    for(int i = 0;i<x-1;++i){
        int cost2 = cost-c[i][0]+c[i][1]+mn2;
        if(cost2<=k)return 1;
    }
    return 0;
}

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<node>a(n+1);    
    for(int i = 1;i<=n;++i)cin >> a[i].a;
    for(int i = 1;i<=n;++i)cin >> a[i].b;
    int l = 1, r = n;
    int res = 0;
    while(l <= r){
        int m = (l+(r-l)/2);
        if(pos(a,m,k))res = m, l = m+1;
        else r = m-1;
    }
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