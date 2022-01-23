#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
ll even = 0,odd = 0;
vector<vector<int>> conn;

void dfs(vector<int> v[],int ci,int x,bool vis[]){
    vis[x] = true;
    conn[ci].push_back(x);
    for(int i : v[x]){
        if(!vis[i]){
            dfs(v,ci,i,vis);
        }
    }
}
void dfs2(vector<int> v[],int x,bool vis[],int level,int e){
    vis[x] = true;
    if(e)
        even += level;
    else
        odd += level;
    for(int i : v[x]){
        if(!vis[i]){
            dfs2(v,i,vis,level+1,e);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        even = 0;odd = 0;
        conn.clear();
        int n,m;
        cin >> n >> m;
        vector<int> v[n];
        for(int i = 0; i < m; i++){
            int x,y;
            cin >> x >> y;
            v[x-1].push_back(y-1);
            v[y-1].push_back(x-1);
        }
        bool vis[n];
        for(int i = 0; i < n; i++)
            vis[i] = false;
        int ci = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                conn.push_back(vector<int>());
                dfs(v,ci,i,vis);ci++;
            }
        }
        for(int i = 0; i < n; i++)
            vis[i] = false;
        for(auto i:conn){
            /*cout << i.size() << " ";
            for(int j : i){
                cout << j << " ";
            }
            cout << endl;*/
            if(i.size()%2==0){
                int head = INT_MAX;
                for(int j : i)
                    head = min(head,j);
                dfs2(v,head,vis,1,1);
            }else {
                int head = INT_MIN;
                for(int j : i)
                    head = max(head,j);
                dfs2(v,head,vis,1,0);
            }
        }
        cout << even << " " << odd << "\n";
    }
    return 0;
}