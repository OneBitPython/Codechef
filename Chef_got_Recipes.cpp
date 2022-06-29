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
    int n;
    cin >> n;
    vector<string>a(n);
    for(int i = 0;i<n;++i)cin >> a[i];
    map<int,int>value; // number of values having that specific bitmask
    vector<char>order = {'a', 'e', 'i', 'o', 'u'};

    vector<vector<int>>co(n, vector<int>(26));
    for(int i = 0;i<n;++i){
        for(auto x : a[i])co[i][x-'a']++;
    }
    for(int i = 0;i<(1ll<<5);++i){
        vector<char>have;
        int c = 0;
        for(int j = 0;j<5;++j){
            if(i&(1ll<<j)){
                c+=(1ll<<j);
                have.pb(order[j]);
            }
        }
        int cnt = 0;
        for(int k = 0;k<n;++k){
            bool ok = 1;
            for(auto x : have){
                if(co[k][x-'a'] == 0)ok = 0;
            }
            cnt+=ok;
        }
        value[c] = cnt;
    }
    int res = 0;
    for(int i = 0;i<n;++i){
        int c = 0;
        for(int j = 0;j<5;++j){
            if(co[i][order[j]-'a'] == 0){
                c+=(1ll<<j);
            }
        }
        if(c == 0){
            res+=value[c]-1;
            continue;
        }
        res+=value[c];
    }
    cout << res/2 << endl;
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