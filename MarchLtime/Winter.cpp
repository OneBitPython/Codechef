#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

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

void print(){cout << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cout << one << " ";
    print(rest...);
}

void output(map<int, pair<int,int>>&mp){
    for(auto itr=mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " - " << itr->second.first << " " << itr->second.second << endl;
    }
}

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

template<typename T>
void output(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}
template<typename one,typename two>
void output(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}

template <typename T>
void output(vector<vector<T>> &v){
    for(auto x : v){
        output(x);
    }
    cout << endl;
}
template <typename T, typename W>
void output(pair<T, W>&p){
    cout << p.first << " " << p.second << endl;
}
template <typename T, typename W>
void output(vector<pair<T, W>> &arr){
    for(auto x : arr){
        cout << x.first << " " << x.second << endl;
    }
}
const int MXN = 1e6;
bitset<MXN>frozen;
set<int> freeze(set<int>&froze, bitset<MXN>frozen, vector<vector<int>> &adj){
    set<int>f;
    for(auto x : froze){
        
        for(int v : adj[x]){
            frozen[v] = 1;
            f.insert(v);
        }
    }
    return f;
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n+1);
    for(int i = 0;i<m;++i){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // for(int i = 1;i<=n;++i){
    //     print(i);
    //     output(adj[i]);
    //     cout << endl;
    // }
    // cout << endl;
    set<int>froze;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int u;
            cin >> u;
            froze.insert(u);
            frozen[u] = 1;
        }
        if(t == 3){
            int u;
            cin >> u;
            cout << (frozen[u]?"YES\n":"NO\n");
        }
        if(t == 2){
            int time;
            cin >> time;
            while(time--)froze = freeze(froze, frozen, adj);
            
        }
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
    // read(T);
    while (T--)
    {
        solve();
    }
}