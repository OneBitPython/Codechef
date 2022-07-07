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

struct edge{
    int x,y,t,f;
};

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<edge>>X(n+1), Y(n+1);
    vector<vector<bool>>a(n, vector<bool>(m));
    for(int i = 0;i<k;++i){
        edge Edge;
        cin >> Edge.x >> Edge.y >> Edge.t >> Edge.f;
        Edge.x--;
        Edge.y--;
        a[Edge.x][Edge.y] = 1;
        X[Edge.x].pb(Edge);
        Y[Edge.y].pb(Edge);
    }
    vector<vector<bool>>safe(n, vector<bool>(m,1));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(a[i][j]){
                safe[i][j] = 0;
                continue;
            }
            int time = i+j;
            for(edge &val : X[i]){
                // check if a bullet is here at the specific time
                int dist = abs(i-val.x)+abs(j-val.y);
                int x = time-(val.t+dist);
                if(x < 0)continue;
                if(x%val.f == 0){
                    safe[i][j] = 0;
                    break;
                }
            }
            if(!safe[i][j])continue;
            for(edge &val : Y[j]){
                // check if a bullet is here at the specific time
                int dist = abs(i-val.x)+abs(j-val.y);
                int x = time-(val.t+dist);
                if(x < 0)continue;
                if(x%val.f == 0){
                    safe[i][j] = 0;
                    break;
                }
            }
        }
    }
    
    vector<vector<int>>dp(n, vector<int>(m));
    if(safe[0][0])dp[0][0] = 1;
    for(int i = 1;i<n;++i){
        if(safe[i][0] && dp[i-1][0])dp[i][0] = 1;
    }
    for(int i = 1;i<m;++i){
        if(safe[0][i] && dp[0][i-1])dp[0][i] = 1;
    }
    for(int i = 1;i<n;++i){
        for(int j = 1;j<n;++j){
            if(safe[i][j] && (dp[i-1][j] || dp[i][j-1])){
                dp[i][j] = 1;
            }
        }
    }
    if(dp[0][0] && dp[n-1][m-1]){
        cout << "YES" << endl;
        cout << n+m-2 << endl;
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