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
    unsigned long long N;
    cin >> N;
    map<int, int> freq;
    if (N == 1)
    {
        freq[1]++;
    }
    else if (N == 2)
    {
        freq[3]++;
        freq[4]++;
    }
    else
    {
        if (N % 2 == 0)
        {
            freq[1] = N - 1;
            freq[(N - 2) / 2]++;
        }
        else
        {
            freq[1] = N - 2;
            freq[2]++;
            freq[(N + 1) / 2]++;
        }
    }
    cout << freq.size() << endl;
    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
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