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
void solve()
{
    int n, k;
    cin >> n >> k;
    int v = 0;
    int i = 1;
    k-=n;
    for(;i<=n;++i){
        v = (i*(i+1))/2;
        v-=i;
        if(v > (k))break;
    }
    i--;
    vector<int> ans(n);
    for(int j = 0;j<i;++j){ans[j] = j+1;}
    int done = ((i*(i+1)/2)-i)+n;
    int rem = (k+n)-done;
    int pos=-1;
    for(int j = i;j<n;++j){
        if(rem <= 0)break;
        if(rem >= j){
            ans[j] = ans[0];
            rem-=j;
        }else{
            ans[j] = ans[j-rem-1];
            break;
        }
    }
    
    for(int j = 0;j<n;++j){
        if(ans[j] == 0){
            pos = j;
            break;
        }
    }
    
    if(pos!=-1){
        int se = ans[pos-1];
        for(int i = pos;i<n;++i){
            ans[i] = se;
        }
    }
    output(ans);
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