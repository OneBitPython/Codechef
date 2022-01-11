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
    string s, ans;
    read(N, s);
    for (int i = 0; i < N-1;++i){
        char one = s[i+1];
        char winner = s[i];
        for (int j=i+1;j<N;++j){
            if (one==winner){
                winner = one;
            }else if (one == 'R' && winner == 'S' || winner=='R' && one=='S'){
                winner = 'R';
            }else if(one=='P' && winner=='R' || one=='R' && winner=='P'){
                winner = 'P';
            }else if(one=='S' && winner=='P'||one=='P'&&winner=='S'){
                winner='S';
            }
            one = s[j+1];
        }

        ans+=winner;
    }
    ans+=s.back();
    print(ans);
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