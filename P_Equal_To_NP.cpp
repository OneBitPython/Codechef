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
    string s;
    cin >> s;

    int ans=0;
    for(int i = 0; i < s.size();++i){
        if (s[i]=='N'){
            if (i<s.size()-1){
                if (s[i+1]=='N'){
                    ans++;
                    s[i+1]='P';
                }
            }
        }
    }
    int count_N = count(all(s), 'N');

    ans+=(count_N - s.size()/2);
    cout << ans << endl;
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}