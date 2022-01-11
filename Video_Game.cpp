#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long H, W;
    cin >> W >> H;
    vector<long long> stacks(W);
    for(int i=0; i<W; i++){
        cin >> stacks[i];
    }
    int comm;
    long long crane = 0;
    int carrying=0;
    while (1){
        cin >> comm;
        if (comm==0){
            break;
        }
        if (comm==1){
            if (crane!=0){
                crane-=1;
            }
        }else if (comm==2){
            if (crane!=W-1){
                crane+=1;
            }
        }else if (comm==3){
            //pickup
            if (!carrying){
                if (stacks[crane]-1 >=0){
                    stacks[crane]-=1;
                    carrying = 1;
                }
            }
        }else if(comm==4){
            //drop
            if (carrying){
                if (stacks[crane]+1 <= H){
                    stacks[crane]+=1;
                    carrying=0;
                }
            }
        }

    }
    for (auto &p : stacks){
        cout << p << " ";
    }

}

int main(){
    solve();
}