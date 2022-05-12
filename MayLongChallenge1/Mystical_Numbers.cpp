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
    vector<vector<int>> not_set_b(n+5,vector<int>(32)),set_b(n+5,vector<int>(32)),set_b_msb(n+5,vector<int>(32)); // stores prefix of number of values with x bit not set
    vector<int>a(n);
    for(int &u : a)cin >> u;
    for(int i = 0;i<=31;++i){
        int cnt = 0, cnt1 = 0,cnt2=0;
        for(int j = 0;j<n;++j){
            if(a[j] == 0)cnt1++;
            else{
                if((a[j])&(1ll<<i)){
                    //ith bit set
                    int w = log2l(a[j]);
                    if(w==i)cnt++;
                }else{
                    // ith bit not set
                    cnt1++;
                    int w = log2l(a[j]);
                    if(w>i)cnt2++;
                }
            }
            not_set_b[j][i] = cnt1;
            set_b[j][i] = cnt;
            set_b_msb[j][i] = cnt2;
        }
    }
    vector<int>pref(n);
    int cy = 0;
    for(int i = 0;i<n;++i){
        if(a[i] == 0)cy++;
        pref[i] = cy;
    }
    int q;
    cin >> q;

    while(q--){
        int l,r,x;
        cin >> l >> r >> x;
        l--;
        r--;
        if(x == 0){
            int ct = r-l+1;
            int count0 = pref[r];
            if(l>0)count0-=pref[l-1];
            cout << ct-count0 << endl;
            continue;
        }
        // check how many values have 0 bit in the msb of x
        int v = log2l(x);//check how many have not set bit in the vth bit position
        int res = not_set_b[r][v];
        if(l>0)res-=not_set_b[l-1][v];
            // go from the msb to 30 and check how many have set bit in the ith position
        for(int i = v+1;i<=31;++i){
            res+=set_b[r][i];
            if(l>0)res-=set_b[l-1][i];
        }
        int c2 = set_b_msb[r][v];
        if(l>0)c2-=set_b_msb[l-1][v];
        res-=c2;
        cout << res << endl;
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
        solve();
    }
}