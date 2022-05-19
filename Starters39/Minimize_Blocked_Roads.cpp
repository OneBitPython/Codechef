#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define dbg(x...)                          \
    cerr << "LINE(" << __LINE__ << ") -> " \
         << "[" << #x << "] = [";          \
    _print(x)
#else
#define dbg(x...)
#endif

void print()
{
    cerr << endl;
};
template <typename T, typename... Args>
void print(T one, Args... rest)
{
    cerr << one << " ";
    print(rest...);
}

int sum() { return 0; }
template <typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n)
{
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
        if ((n & i) != 0)
        {
            val += "1";
        }
        else
        {
            val += "0";
        }
    }
    while (val.front() == '0')
    {
        val.erase(0, 1);
    }
    return val;
}

void dfs(int u, vector<vector<int>> &adj, vector<vector<int>> &subtree, vector<bool> &visited, vector<int> &dist)
{
    subtree[u] = {u};
    visited[u] = 1;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        dist[v] = dist[u] + 1;
        dfs(v, adj, subtree, visited, dist);
        for (auto x : subtree[v])
            subtree[u].pb(x);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> pos;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].pb(v);
        adj[v].pb(u);
        if (x == 1)
        {
            pos.pb({u, v});
        }
    }
    vector<vector<int>> subtree(n + 1);
    vector<bool> visited(n + 1);
    vector<int> dist(n + 1);
    dfs(1, adj, subtree, visited, dist);

    vector<pair<vector<int>, int>> b;
    for (int i = 1; i <= n; ++i)
    {
        b.pb({subtree[i], i});
    }

    set<int> ones;
    for (auto x : pos)
    {
        if (dist[x.first] > dist[x.second])
        {
            ones.insert(x.first);
        }
        else
            ones.insert(x.second);
    }

    sort(all(b), [&](auto x, auto y)
         { return x.first.size() > y.first.size(); });
    int res = 0;
    int curr = n;
    bool ok = 0;
    vector<bool> took(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        if (curr <= k)
        {
            ok = 1;
            break;
        }
        if (ones.count(b[i].second))
        {
            if (took[b[i].second])
                continue;
            vector<int> sub = b[i].first;
            curr -= sub.size();
            for (auto x : sub)
                took[x] = 1;
            res++;
        }
    }
    if (!ok)
    {
        cout << -1 << endl;
        return;
    }
    cout << res << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        solve();
    }
}