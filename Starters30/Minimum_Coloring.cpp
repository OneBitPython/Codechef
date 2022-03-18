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
bool valid(vector<vector<int>> &a, int n, int m){
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(a[i][j]==0)return 0;
            vector<pair<int,int>>neighbours;
            if(i > 0)neighbours.pb({i-1, j});
            if(j > 0)neighbours.pb({i, j-1});
            if(i < n-1)neighbours.pb({i+1, j});
            if(j < m-1)neighbours.pb({i, j+1});
            for(auto v : neighbours){
                if(a[v.first][v.second] == a[i][j]){
                    return 0;
                }
            }
        }
    }
    return 1;
}
void solve()
{
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    vector<vector<int>> a(n, vector<int>(m,0)), a2(n, vector<int>(m, 0));
    x1--;
    y1--;
    x2--;
    y2--;
    a[x1][y1] = 1;
    a[x2][y2] = 2;
    queue<pair<int,int>> q;
    vector<vector<bool>>visited(n, vector<bool>(m, 0));
    q.push({x2, y2});
    while(!q.empty()){
        int i  =q.front().first, j = q.front().second;
        q.pop(); 
        if(visited[i][j])continue;
        visited[i][j] = 1;
        vector<pair<int,int>>neighbours;
        if(i > 0)neighbours.pb({i-1, j});
        if(j > 0)neighbours.pb({i, j-1});
        if(i < n-1)neighbours.pb({i+1, j});
        if(j < m-1)neighbours.pb({i, j+1});
        for(int k = 1;k<=(int)(3);++k){
            bool ok = 1;
            for(auto v : neighbours){
                if(a[v.first][v.second] == k)ok = 0;
            }
            if(ok){
                if(a[i][j] == 0)a[i][j] = k;
                for(auto v : neighbours){
                    q.push(v);
                }
                break;
            }
        }

    }
    for(auto x : a){
        output(x);
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
    read(T);
    while (T--)
    {
        solve();
    }
}