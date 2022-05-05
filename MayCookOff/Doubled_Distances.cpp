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
    vector<int>a(n);
    for(int &u : a)cin >> u;
    vector<int>s = a;
    sort(all(s));
    if(n>=4 && s==a){
        cout << "NO" << endl;
        return;
    })
    // vector<int>a = {1,2,3,4,5,6};
    // int n = a.size();
    // vector<int>order = {0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3};
    // // vector<int>order = {0,0,0,1,1,1,2,2,2,3,3,3};
    // // set<vector<in>orderings;
    // do{
    //     bool got = 0;
    //     do{
    //         vector<int>res;
    //         for(int i = 0;i<n-2;++i){
    //             int cnt = 0;
    //             if(a[i] > a[i+1])cnt++;
    //             if(a[i]>a[i+2])cnt++;
    //             if(a[i+1]>a[i+2])cnt++;
    //             res.pb(cnt);
    //         }
    //         vector<int>od;
    //         for(int i = 0;i<n-2;++i)od.pb(order[i]);
    //         if(res == od){
    //             got = 1;
    //             break;
    //         }
    //     }while(next_permutation(all(a)));
    //     sort(all(a));
    //     if(!got){
    //         bool ok = 1;
    //         for(int i = 0;i<(int)(order.size()-1);++i){
    //             if((order[i]==0 && order[i+1] == 3) || (order[i]==3 && order[i+1] == 0)){
    //                 ok = 0;
    //             }
    //         }
    //         // for(int i = 0;i<(int)(order.size()-2);++i){
    //         //     if((order[i]==0&&order[i+1]==1&&order[i+2]==0) || (order[i]==3&&order[i+1]==2&&order[i+2]==3))ok = 0;
    //         // }
    //         if(ok){
    //             for(int i = 0;i<n-2;++i)cout << order[i] << ' ';
    //             cout << endl;
    //         }
    //     }      
    // }while(next_permutation(all(order)));
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