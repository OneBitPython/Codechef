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

void dfs(int u, int par, vector<int>&parent, vector<vector<int>>&adj,vector<int>&leaves){
    parent[u] = par;
    bool leaf =1;
    for(int v : adj[u]){
        if(v!=par){leaf = 0;dfs(v, u, parent, adj,leaves);}
    }
    if(leaf)leaves.pb(u);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0;i<n-1;++i){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    vector<int>parent(n+1);
    vector<int>leaves;
    dfs(1, -1, parent, adj, leaves);

    int l = 0, r = leaves.size()-1;
    while(l < r){
        int m = (l+r)/2;
        int k = (m-l)+1;
        cout << "? " << k+1  << " 1 ";
        for(int i = l;i<=m;++i){
            cout << leaves[i] <<  ' ';
        }
        
        cout << endl;
        int x;
        cin >> x;
        if(x){
            r = m;
        }else l = m+1;
    }
    
    int u = leaves[l];
    vector<int>path;
    while(u != -1){
        path.pb(u);
        u = parent[u];
    }
    reverse(all(path));
    
    l = 0, r = path.size()-1;
    while(l<r){
        int m = (l+r)/2;
        int k = (m-l)+1;
        cout << "? " << k << ' ';

        for(int i = l;i<=m;++i)cout << path[i] << ' ';
        cout << endl;
        int x;
        cin >> x;
        if(x){
            r = m;
        }else l = m+1;
    }
    cout << "? 1 1" << endl;
    int x;
    cin >> x;
    if(x)cout << "! 1" << endl;
    else cout << "! " << path[l]  << endl;
}

int32_t main()
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    read(T);
    while (T--)
    {
        solve();
    }
}