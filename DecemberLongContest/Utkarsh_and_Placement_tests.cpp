#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<char> preferences(3);
    for (int i = 0; i <3;++i){
        cin >> preferences[i];
    }
    char x,y ;
    cin >> x >> y;
    for (auto &p : preferences){
        if (p == x || p==y){
            cout << p << endl;
            break;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}