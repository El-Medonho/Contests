#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;

int t,p,sz; 
vii energy(0), dif(0), score(0);
    vector<vector<vii>> dp;


void solve(int mask, int en, int prob){
    int guys = 0;

    if(dp[mask][en][prob] != -1) return;
    dp[mask][en][prob] = 0;

    for(int i = 0; i < t; i++){
        if(mask & (1<<i)) guys++;
    }

    for(int i = 0; i < t; i++){

        if(mask & (1<<i)){
            if(en > energy[i]) continue;

            if(prob > 0){
                solve(mask,en,prob-1); dp[mask][en][prob] = max(dp[mask][en][prob], dp[mask][en][prob-1]);
            }

            if(en + dif[prob] <= energy[i]) {
                if(prob > 0){
                    solve(mask,en+dif[prob],prob-1);
                    dp[mask][en][prob] = max(dp[mask][en][prob], dp[mask][en + dif[prob]][prob-1] + score[prob]);
                } else{
                    dp[mask][en][prob] = max(score[prob], dp[mask][en][prob]);
                }
            }

            if(guys > 1){
                solve(mask ^ (1<<i), 0, prob);
                dp[mask][en][prob] = max(dp[mask][en][prob], dp[mask ^ (1<<i)][0][prob]);
            }

        }
    }
}

int main(){
    fastio;

    cin >> t >> p;

    sz = 1; int hjk = t;
    while(hjk--) sz<<=1;

    dp.resize(sz+1, vector<vii>(101, vii(101, -1)));
    
    energy.resize(t), dif.resize(p), score.resize(p);
    for(int &i: energy) cin >> i;
    for(int &i: dif) cin >> i;
    for(int &i: score) cin >> i;

    solve(sz-1, 0, p-1);

    cout << dp[sz-1][0][p-1] << endl;

    return 0;
}