#include <bits/stdc++.h>
using namespace std;

#define int double
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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> w(n);
    for(int i = 0;i<n;++i){
        cin >> w[i];
    }
    sort(all(w));
    for(int c = 0;c<k;++c){
        int a, b;
        cin>> a >> b;
        vector<pair<int,bool>>dp(n);
        dp[0].first = a;
        dp[0].second = 0;
        for(int i = 1;i<n;++i){
            int min_ = dp[i-1].first+a;
            min_*=2;
            bool v = 0;
            for(int j = i-1;j>=0;--j){
                
                if(!dp[j].second){
                    int cost = dp[j].first;
                    int r = w[i]+w[j];
                    cost+=(r*b);
                    cost*=2;

                    if(cost < min_){ 
                        min_ = cost;
                        v= 1;
                    }
                }else{
                    int cost = a;
                    int r = w[i]+w[j];
                    cost+=(r*b);
                    cost+=(dp[j-1].first);
                    cost*=2;
                    if(cost < min_){
                        min_ = cost;
                        v = 0;
                    }
                }
                
            }
            dp[i] = make_pair(min_, v);
        }
        cout << (long long)((dp[n-1].first)) << endl;
        
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