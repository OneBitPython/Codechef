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
vector<int> id, sz;
int root(int x){
    if(x==id[x])return x;
    return id[x] = root(id[x]);
}
bool merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u == v)return false;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>>edges;
    vector<pair<int,int>>pos;
    id.resize(n+1);
    sz.resize(n+1);
    for(int i = 0;i<n;++i){
        id[i] = i;
        sz[i] = 1;
        int a,b;
        cin>> a >> b;
        pos.pb({a,b});
    }
    pos.pb({0,0});
    n = pos.size();
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            if(i!=j){
                int cost = abs(pos[i].first - pos[j].first)+abs(pos[i].second - pos[j].second);
                edges.pb({cost, make_pair(i,j)});
            }
        }
    }
    sort(all(edges));
    // for(auto x: edges){
    //     cout << x.first << " ";
    //     output(x.second);
    // }
    set<int>res;
    for(auto edge : edges){
        if(merge(edge.second.first, edge.second.second)){
            int u = edge.second.first, v = edge.second.second;
            if(res.count(u) == 0)res.insert(u);
            if(res.count(v) == 0)res.insert(v);
        }
    }
    output(res);
    // sort(all(a), [&](auto a, auto b){
    //     return a.second.first + a.second.second < b.second.first + b.second.second;
    // });
    // for(auto x : a){
    //     cout << x.first << " ";
    // }
    // cout << endl;
    
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