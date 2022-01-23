#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

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
    int n;cin >> n;
    if(n==1){
        cout << 2 << endl;
    }else if(n==2){
        cout << "2 3" << endl;
    }else{
            vector<int>ans;
            ans.pb(2);
            ans.pb(3);
            unordered_map<int,bool> taken;
            taken[2] = 1;
            taken[3] = 1;
            for(int i = 2;i<n;++i){
                int start;
                if(ans[i-1]%2==0){
                    start = 3;
                }else{
                    start = 2;
                }
                int pos = start;
                for(;pos<(int)(1e5);pos+=2){
                    int l = 2;
                    int sum = pos;
                    bool got = true;
                    if(!taken[pos]){
                        for(int j = i-1;j>=0;--j){
                            sum+=ans[j];
                            if(sum % l == 0){
                                got=false;
                                break;
                            }
                            l++;
                        }
                        if(got){
                            taken[pos] = 1;
                            ans.pb(pos);
                            break;
                        }
                    }
                    
                }
                
            }
            // bool b = false;
            // for(int i = n-1;i>=1;--i){
            //     int l = 2;
            //     int sum = ans[i];
            //     if(b)break;
            //     for(int j = i-1;j>=0;--j){

            //         sum+=ans[j];
            //         if(sum % l == 0){
                        
            //             cout << "WRONG" << endl;return;
            //             b=true;break;

            //         }
            //         l++;
            //     }
            // }
            output(ans);
    }
    
    
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}