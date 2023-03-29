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



void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int>t(m+1), c(m+1);
    for(int i = 1;i<=m;++i)cin >> t[i];
    for(int i = 1;i<=m;++i)cin >> c[i];
    int a = 0, b = 0;
    int res = 0;
    for(int i = 1;i<=n;++i){
        int nxt = lower_bound(all(t),i)-t.begin();
        int v = c[nxt];
        if(a-2 >= b){
            b++;
        }else if(b-2 >= a)a++;
        else{
            if(v==1)a++;
            else b++;
        }
        if(t[nxt]==i){
            if(v==1){
                if(a > b)res++;
                else a=0,b=0;
            }else{
                if(a < b)res++;
                else a=0,b=0;
            }
        }
    }
    cout <<res << endl;
    // vector<vector<int>>dp(n+1, vector<int>(2));
    // dp[1][1] = 1;
    // vector<int>diff(n+1);
    // diff[1] = 1;
    // for(int i = 2;i<=m;++i){
    //     if(t[i]-t[i-1]==1 && c[i] == c[i-1])diff[i] = 3-(diff[i-1]) ;
    //     else diff[i] = 1;
    // }
    // for(int i  = 2;i<=m;++i){
    //     dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
    //     if(t[i]-t[i-1] == 1){
    //         if(c[i]==c[i-1])dp[i][1] = max(dp[i-1][1],dp[i-1][0])+1;
    //         else{
    //             if(t[i]-t[i-2] == 2){
    //                 if(diff[i-2]<2)dp[i][1] = max(dp[i-2][1],dp[i-1][0])+1;

    //             }else dp[i][1] = max(dp[i-2][1],dp[i-1][0])+1;
    //         }
    //     }else if(t[i]-t[i-1]==2){
    //         if(c[i]==c[i-1])dp[i][1] = max(dp[i-1][1],dp[i-1][0])+1;
    //         else{
    //             if(diff[i-2]<2)dp[i][1] = max(dp[i-2][1],dp[i-1][0])+1;
    //         }
    //     }else dp[i][1] = max(dp[i-1][1],dp[i-1][0])+1;
    // }
    // dbg(dp);
    // cout << max(dp[m][0],dp[m][1]) << endl;
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