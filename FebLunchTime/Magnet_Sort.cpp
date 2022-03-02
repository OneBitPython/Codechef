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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &u : a)cin >> u;
    string s;
    cin >> s;
    vector<int> ac = a;
    sort(all(ac));
    if(a == ac){
        cout << 0 << endl;
        return;
    }
    set<char>tmp;
    for(auto x : s){
        tmp.insert(x);
    }
    if(tmp.size() == 1){
        cout << -1 << endl;
        return;
    }
    if(s[0] != s.back()){
        cout << 1 << endl;
        return;
    }
    // check if if you can sort the elements in such a way that the min of one side is greater than the max of the other side
    vector<bool> sorted_from_left;
    for(int i = 0;i<n-1;++i){
        if(a[i] > a[i+1]){
            for(int j = i;j<n;++j){
                sorted_from_left.push_back(0);
            }
            break;
        }else sorted_from_left.push_back(1);
    }
    vector<int> min_from_right(n);
    min_from_right.back() = a.back();
    for(int i = n-2;i>=0;--i)min_from_right[i] = min(a[i], min_from_right[i+1]);
    for(int i = 1;i<n;++i){
        if(s[i] != s.back()){
            if(sorted_from_left[i-1]){
                if(min_from_right[i] >= a[i-1]){
                    cout << 1 << endl;
                    return;
                }
            }
        }
    }
    vector<bool>sorted_from_right;
    for(int i = n-1;i>=1;--i){
        if(a[i] < a[i-1]){
            for(int j = i;j>=0;--j){
                sorted_from_right.pb(0);
            }
            break;
        }else sorted_from_right.pb(1);
    }
    reverse(all(sorted_from_right));

    vector<int> max_from_left;
    max_from_left.pb(a[0]);
    for(int i = 1;i<n;++i)max_from_left.pb(max(a[i], max_from_left[i-1]));
    for(int i = n-1;i>=1;--i){
        if(s[i-1] != s[0]){
            if(sorted_from_right[i]){
                if(max_from_left[i-1] <= a[i]){
                    cout << 1 << endl;
                    return;
                }
            }else break;
        }
    }
    cout << 2 << endl;


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