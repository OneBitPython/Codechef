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



bool intersect(vector<pair<int,int>>&a){
    int n = a.size();
    sort(all(a));
    for(int i = 0;i<n-1;++i){
        if(a[i].second >= a[i+1].first){
            return 1;
        }
    }
    return 0;
}
void solve()
{
    int c,n,k;
    cin >> c >> n >> k;
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;++i){
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a));
    if(k == 0){
        for(int i = 0;i<n-1;++i){
            if(a[i].second >= a[i+1].first){
                cout << "Bad" << endl;
                return;
            }
        }
        cout << "Good" << endl;
    }else{
        vector<pair<int,int>>available;
        if(a[0].first > 1)available.pb({1, a[0].first-1});
        if(a.back().second < c)available.pb({a.back().second + 1, c});
        int mx = a[0].second;
        for(int i = 1;i<n;++i){
            if(a[i].first - 1 > mx){
                available.pb({mx+1, a[i].first-1});
            }
            mx = max(mx, a[i].second);
        }
        // find an intersecting range
        for(int i = 0;i<n-1;++i){
            if(a[i].second >= a[i+1].first){
                // try changing the positions of these ranges, one at a time
                vector<pair<int,int>>b;
                for(int j = 0;j<n;++j){
                    if(i == j)continue;
                    b.pb(a[j]);
                }
                int req = a[i].second - a[i].first + 1;
                bool ok = 0;
                for(auto x : available){
                    if(x.second - x.first + 1 >= req){
                        b.pb(x);
                        ok = 1;
                        break;
                    }
                }
                if(!intersect(b) && ok){
                    cout << "Good" << endl;
                    return;
                }
                // try the same for i+1
                b.clear();
                for(int j = 0;j<n;++j){
                    if(j==(i+1))continue;
                    b.pb(a[j]);
                }
                req = a[i+1].second - a[i+1].first + 1;
                ok = 0;
                for(auto x : available){
                    if(x.second - x.first + 1 >= req){
                        b.pb(x);
                        ok = 1;
                        break;
                    }
                }
                if(!intersect(b) && ok){
                    cout << "Good" << endl;
                    return;
                }
                cout << "Bad" << endl;
                return;
            }
        }
        cout << "Good" << endl;
    }
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