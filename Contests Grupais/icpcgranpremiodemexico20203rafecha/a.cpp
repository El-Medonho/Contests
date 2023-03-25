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

int main(){
    fastio;

    int t,p; cin >> t >> p;

    int sz = 1, hjk = t;
    while(hjk--) sz<<=1;
    
    vii energy(t), dif(p), score(p);
    for(int &i: energy) cin >> i;
    for(int &i: dif) cin >> i;
    for(int &i: score) cin >> i;

    int best = 0;
    vector<vector<vii>> dp(sz+1, vector<vii>(105, vii(105, 0)));
    vector<vector<vii>> called(sz+1, vector<vii>(105, vii(105, 0)));
    queue<pair<int,pii>> qw;
    
    for(int i = 0; i < t; i++){
        qw.push({1<<i,{energy[i], 0}});
        called[1<<i][energy[i]][0] = 1;
    }

    while(!qw.empty()){
        pair<int,pii> curr = qw.front(); qw.pop();
        int team = curr.f, en = curr.s.f, prob = curr.s.s;

        if(en >= dif[prob]){
            int nw = en-dif[prob];
            int points = dp[team][en][prob] + score[prob];
            best = max(best, points);
            if(prob != p-1){
                dp[team][nw][prob+1] = max(dp[team][nw][prob+1], points);
                if(!called[team][nw][prob+1]) qw.push({team,{nw,prob+1}});
                called[team][nw][prob+1] = 1;
            }
        }

        if(prob < p-1){
            dp[team][en][prob+1] = max(dp[team][en][prob+1], dp[team][en][prob]);
            if(!called[team][en][prob+1]) qw.push({team,{en,prob+1}});
            called[team][en][prob+1] = 1;
        }

        if(team != sz-1){
            for(int i = 0; i < t; i++){
                if(!(team & (1<<i))){
                    int gg = team ^ (1<<i);
                    dp[gg][energy[i]][prob] = max(dp[team][en][prob], dp[gg][energy[i]][prob]);
                    if(!called[gg][energy[i]][prob]) qw.push({gg, {energy[i], prob}});
                    called[gg][energy[i]][prob] = 1;
                }
            }

        }
    }

    cout << best << endl;

    return 0;
}