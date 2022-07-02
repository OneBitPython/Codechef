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
    int n,m,x,y,k;
    cin >> n >>m >> x >>y >> k;
    vector<int>a(n), b(m);
    for(int &u : a)cin >> u;
    for(int &u : b)cin >> u;
    sort(all(a));
    sort(all(b));
    if(k==n){
        cout<< -1 << endl;
        return;
    }
    int res = 0;
    int nxt_a_b = a[0]+x;
    int nxt_b_c = lower_bound(all(b), nxt_a_b) - b.begin();
    int cancel = k;
    nxt_b_c+=(cancel);
    if(nxt_b_c>=m){
        cout<< -1 << endl;
        return;
    }
    int reach = b[nxt_b_c]+y;
    res = max(res, reach);
    for(int i = 1;i<=k;++i){
        if(i >= n){
            cout << -1 << endl;
            return;
        }
        int nxt_a_b = a[i]+x;
        int nxt_b_c = lower_bound(all(b), nxt_a_b) - b.begin();
        int cancel = k-i;
        nxt_b_c+=(cancel);
        if(nxt_b_c>=m){
            cout<< -1 << endl;
            return;
        }
        int reach = b[nxt_b_c]+y;
        res = max(res, reach);
    }
    cout << res << endl;
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