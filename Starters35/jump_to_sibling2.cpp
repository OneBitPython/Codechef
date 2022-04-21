#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

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
    int n;
    cin >> n;
    vector<int>a(n), evens, odds;
    for(int i= 0;i<n;++i){
        cin >> a[i];
        if(a[i]%2)odds.pb(i);
        else evens.pb(i);
    }
    if(a[0]%2 == a.back()%2){
        int cnt = 0;
        for(int i = 0;i<n;++i){
            if(a[i]%2 == a[0]%2)cnt++;
        }
        cout << cnt-1 << endl;
        return;
    }
    vector<int>pre(n), suf(n);
    int cnt = 0;
    for(int i = 1;i<n;++i){
        if(a[i]%2 == a[0]%2)cnt++;
        pre[i] = cnt;
    }
    cnt = 0;
    for(int i = n-2;i>=0;--i){
        if(a[i]%2 == a.back()%2)cnt++;
        suf[i] = cnt;
    }
    int res = 1e18;
    for(int i = 0;i<n;++i){
        if(a[i]%2 == a[0]%2){
            // can jump from here
            int b = pre[i];
            if(a[i]%2 == 0){
                // search for next  odd
                auto  y = upper_bound(all(odds), i);
                if((y-odds.begin())>=odds.size())continue;
                int x = *y;
                b+=suf[x];
                res = min(res, b+1);
            }else{
                auto  y = upper_bound(all(evens), i);
                if((y-evens.begin())>=evens.size())continue;
                int x = *y;
                b+=suf[x];
                res = min(res, b+1);
            }
        }
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        solve();
    }
}