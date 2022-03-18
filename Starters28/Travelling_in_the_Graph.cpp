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


vector<set<pair<int,int>>> adj;
vector<bool>visited;


int dijkstra(int n){
    // returns the cost from 1 to n
    vector<int>cost(n+1, INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1}); // cost and node
    cost[1] = 0;
    // print(n);
    while(!pq.empty()){
        auto u = pq.top();
        if(u.second == n){
            return cost.back();
        }
        pq.pop();
        if(visited[u.second])continue;
        visited[u.second] = 1;
        for(auto v : adj[u.second]){
            int curr_cost = cost[v.second];
            int new_cost = cost[u.second]+v.first;
            if(new_cost < curr_cost && !visited[v.second]){
                cost[v.second] = new_cost;
                pq.push({new_cost, v.second});
            }
        }
    }
    return 1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    for(int i = 0;i<m;++i){
        int u, v;
        cin >> u >> v;
        adj[u].insert({0, v});
        adj[v].insert({0, u});
    }
    visited.resize(n+1, 0);
    for(int i = 1;i<n;++i){
        if(adj[i].count({0, i+1}) == 0){
            adj[i].insert({1, i+1});
            adj[i+1].insert({1, i});
        }
    }
    cout << dijkstra(n) << endl;
    adj.clear();
    visited.clear();
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    read(T);
    while (T--)
    {
        solve();
    }
}