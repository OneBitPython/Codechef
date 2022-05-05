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
    vector<int>a(n),b(n),c(n);
    for(int &u :a)cin >> u;
    for(int &u :b)cin >> u;
    for(int &u :c)cin >> u;


    int k1, k2;
    cin >> k1 >> k2;
    int res = 0;
    vector<bool>taken(n);
    for(int i = 0;i<n;++i){
        if(c[i] >= b[i] && c[i] >= a[i]){
            taken[i] = 1;
            res+=c[i];
        }
    }
    vector<pair<int,int>> d, e;
    for(int i = 0;i<n;++i){
        d.pb({a[i], i});
        e.pb({b[i], i});
    }
    sort(all(d), [&](auto one, auto two){
        return one.first > two.first;
    });
    sort(all(e), [&](auto one, auto two){
        return one.first > two.first;
    });
    if(k1 <= k2){
        for(int i = 0;i<n;++i){
            if(taken[d[i].second])continue;
            if(k1 > 0){
                if(d[i].first > b[d[i].second]){
                    k1--;
                    res+=d[i].first;
                    taken[d[i].second] = 1;
                }
            }
        }
        for(int i = 0;i<n;++i){
            if(taken[e[i].second])continue;
            if(k2 > 0){
                if(e[i].first > a[e[i].second]){
                    k2--;
                    res+=e[i].first;
                    taken[e[i].second] = 1;
                }
            }
        }
    }else{
        for(int i = 0;i<n;++i){
            if(taken[e[i].second])continue;
            if(k2 > 0){
                if(e[i].first > a[e[i].second]){
                    k2--;
                    res+=e[i].first;
                    taken[e[i].second] = 1;
                }
            }
        }
        for(int i = 0;i<n;++i){
            if(taken[d[i].second])continue;
            if(k1 > 0){
                if(d[i].first > b[d[i].second]){
                    k1--;
                    res+=d[i].first;
                    taken[d[i].second] = 1;
                }
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}