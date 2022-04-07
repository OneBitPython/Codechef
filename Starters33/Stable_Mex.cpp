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

void print(){cout << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cout << one << " ";
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
    set<int>st;
    map<int,int>freq;
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        freq[v]++;
        st.insert(v);
    }
    vector<int>a(all(st));
    
    int mex = 0;
    n = st.size();
    for(int i = 0;i<=n;++i){
        if(st.count(mex) == 1)mex++;
    }
    if(mex == 1){
        cout << -1 << endl;
        return;
    }
    if(mex == 0){
        cout << *min_element(all(a))-1 << endl;
        return;
    }
    int search = mex-1;
    // need search no. of successive integers and cnt[integer[end]] +1 should be 0
    int res = 0;
    for(int i = 0;i<n;++i){
        if(a[i] < mex)continue;
        int got = a[i];
        bool ok = 1;
        int cnt = 1;
        for(int j = i+1;j<n;++j){
            if(cnt == search)break;
            if(a[j] != got+1){
                break;

            }
            cnt++;
            got = a[j];
        }
        if(freq[got+1] == 0 && cnt == search)res++;
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
    while (T--)
    {
        solve();
    }
}