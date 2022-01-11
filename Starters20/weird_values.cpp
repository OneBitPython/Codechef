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
    int n;
    cin >> n;
    vector<vector<int>> inds(n+1);
    for (int i=1; i<=n; ++i){
        int x;
        cin >> x;
        if (x <= n){
            inds[x].push_back(i);
        }
    }
    int ans = 0;
    for(int x=1;x<=n;++x){
        vector<int>indsx = inds[x];
        indsx.insert(indsx.begin(), 0);
        indsx.pb(n+1);
        for (int i=1; i<(int)indsx.size()-x;++i){
            ans += (int)x * (indsx[i] - indsx[i - 1]) * (indsx[i + x] - indsx[i+x-1]);
        }
    }
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