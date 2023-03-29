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

bool pos(vector<int>&pres, vector<int>&cnt, int j, int k){
    pres[j]++;
    int mn = 1e18, mx = 0;
    for(int i = 0;i<26;++i){
        mx = max(mx, pres[i]);
        if(cnt[i])mn = min(mn, pres[i]);
    }
    pres[j]--;
    dbg(mn,mx);
    return (mx-mn)<=k;
}

void solve()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t;
    vector<int>cnt(27), pres(27);
    for(auto x : s)cnt[x-'a']++;
    int mx = 0, mn = 1e18;
    for(int i = 0;i<n;++i){
        bool ok = 0;
        for(int j = 25;j>=0;--j){
            if(cnt[j]==0)continue;
            // try to check if you can add this letter
            if(pos(pres, cnt, j, k)){
                char x = j+'a';
                t+=x;
                pres[j]++;
                cnt[j]--;
                ok = 1;
                break;
            }
        }
        if(!ok){
            cout << -1 << endl;
            return;
        }
    }
    reverse(all(t));
    cout << t << endl;
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