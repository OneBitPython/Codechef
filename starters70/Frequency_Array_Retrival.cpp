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
    int n;
    cin >> n;
    set<int>st;
    vector<int>a(n);
    int mx = 0;
    for(int i = 0;i<n;++i){
        cin >>a[i];
        st.insert(a[i]);
        mx = max(mx, a[i]);
    }
    
    vector<int>res(n);
    vector<int>taken(n+1);
    vector<set<int>>pos(mx+1);
    for(int i = 0;i<n;++i)pos[a[i]].insert(i);
    for(int i = 1;i<=mx;++i){
        if(pos[i].empty())continue;
        if(pos[i].size()%i != 0){
            cout << - 1<< endl;
            return;
        }
    }
    int curr = 1;
    for(int i = 0;i<n;++i){
        if(taken[i])continue;
        int took = 0;
        while(!pos[a[i]].empty()){
            if(took==a[i])break;
            int x= *pos[a[i]].begin();  
            took++;
            taken[x] = 1;
            res[x] = curr;
            pos[a[i]].erase(pos[a[i]].begin());
        }
        curr++;
    }
    int mxn = 1e5;
    curr = *max_element(all(res));
    if(curr > mxn){
        cout << -1 << endl;
        return;
    }
    for(auto x : res)cout << x << ' ';
    cout << endl;
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