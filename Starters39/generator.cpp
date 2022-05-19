#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define endl "\n"
#define all(c) c.begin(), c.end()

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int32_t main()
{
    srand(time(0));
    int t = rand(1,100);
    cout << t<< endl;
    while(t--){
        int n = rand(1,100);
        cout << n << endl;
        for(int i = 0;i<n;++i){
            int w = rand(97,97+25);
            char x = w;
            cout << x;
        }
        cout << endl;
    }
}
