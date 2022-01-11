#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

void print(){cout << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cout << one << " ";
    print(rest...);
}

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

void solve()
{
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s; 
    string modify = s.substr(0, K);
    string output = "";
    for(int i=0;i<K/2;++i){
        char first = modify[i];
        char last = modify[K-i-1];
        output+=first;
        output+=last;
    }
    if (modify.size()%2==1){
        output+=modify[modify.size()/2];
    }
    reverse(all(output));
    output+=(s.substr(K));
    cout << output << endl;
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