#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long hills, valleys;
    cin >> hills >> valleys;
    char prev='0';
    if (hills>valleys || hills==valleys){
        prev = '0';
    }else{
        prev = '1';
    }
    string ans = "";
    ans+=prev;
    for (int i=0;i<(hills+valleys);++i){
        if (prev=='1'){
            ans+='0';
            prev='0';
        }else{
            ans+='1';
            prev='1';
        }
    }
    ans+=prev=='0'?'1':'0';
    cout << ans.size() << endl;
    cout << ans << endl; 
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}