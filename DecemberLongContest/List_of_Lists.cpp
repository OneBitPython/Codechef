#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

int sum()
{
    return 0;
}
template <typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

void print() { cout << endl; };
template <typename T, typename... Args>
void print(T one, Args... rest)
{
    cout << one << " ";
    print(rest...);
}

void read(){};
template <typename T, typename... Args>
void read(T &one, Args &...rest)
{
    cin >> one;
    read(rest...);
}

void solve()
{
    int N;
    read(N);
    vector<int>arr(N);
    for (int i=0;i<N;++i){
        cin >> arr[i];
    }
    if (N==1){
        cout << 0 << endl;
    }else{
        sort(all(arr));
        int a=0,final=0;
        for (int i=0;i<N-1;++i){
            if (arr[i]==arr[i+1]){
                a++;
            }else{
                a++;
                final=max(a,final);
                a=0;
            }
        }
        a++;
        final = max(a,final);
        if (final==N){
            print(0);
        }else{
            if (final>=2){
                cout << N-final+1 << endl;
            }else{
                print(-1);
                
            }
        }
    }
}

int32_t main()
{
    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}