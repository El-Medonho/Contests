//https://szkopul.edu.pl/problemset/problem/xfpVU8vFP2RzZ0hrqWq9kTZM/site/?key=statement

// ░░░░░░░░░░░░▄▄▄█████████▄▄▄░░░░░░░░░░░░
// ░░░░░░░░▄▄██████▀▀▀▀▀▀▀██████▄▄░░░░░░░░
// ░░░░░░▄████▀▀░░░░░░░░░░░░░▀▀████▄░░░░░░
// ░░░░▄███▀░░░░░░░░░░░░░░░░░░░░▀▀███▄░░░░
// ░░▄███▀░░░░░░░░░░░░░░░░░░░░░░░░░████░░░
// ░▄███▀░░░░░▄▄▄▄░░░░░░░░░░░░░░░░░░▀███░░
// ░███░░░░░░█████▄░░░░░░░░░░░░░░░░░░▀███░
// ███▀░░░░░░██████░░░░░░░░░░░░░░░░░░░███▄
// ███░░░░░░░█████▀░░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░████▄░░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░░▀███▄░░░░░░░░░░░░░░░░░░░███
// ███░░░░░░░░░░░█████▄░░░▄███▄▄░░░░░░▄███
// ▀███░░░░░░░░░░░░▀████████████░░░░░░███░
// ░███▄░░░░░░░░░░░░░▀▀████████▀░░░░░███▀░
// ░░████░░░░░░░░░░░░░░░░░▀▀▀░░░░░░▄███▀░░
// ░░███▀░░░░░░░░░░░░░░░░░░░░░░░░░▄███▀░░░
// ░▄███░░░░▄▄░░░░░░░░░░░░░░░░░▄████▀░░░░░
// ▄███▄▄███████▄▄▄░░░░░░░▄▄▄█████▀░░░░░░░
// ███████▀▀▀▀▀███████████████▀▀░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ▒█░░▒█ █░░█ █▀▀█ ▀▀█▀▀ █▀▀ ░█▀▀█ █▀▀█ █▀▀█░
// ▒█▒█▒█ █▀▀█ █▄▄█ ░░█░░ ▀▀█ ▒█▄▄█ █░░█ █░░█░
// ▒█▄▀▄█ ▀░░▀ ▀░░▀ ░░▀░░ ▀▀▀ ▒█░▒█ █▀▀▀ █▀▀▀░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
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

    int n; cin >> n;
    
    vii arr(n);
    for(int &i: arr) cin >> i;

    vector<deque<int>> vec(0);
    int low;
    

    int h; cin >> h;

    while(h--){
        int k; cin >> k;
        vec.pb(deque<int> (0)); 
        vii ind(1e6+4, -1);
        
        vii dp(n,-1); dp[0] = 0;

        int bk = 0;
        ind[0] = 0;
        vec[0].pb(0);
        low = 0;

        for(int i = 1; i < n; i++){
            while(true){
                while(!vec[ind[low]].empty() && vec[ind[low]].front() < i-k) vec[low].pop_front();
                if(vec[ind[low]].empty()){
                    vec[ind[low]] = vec[ind[bk]];
                    vec.resize(vec.size()-1);
                    bk = dp[vec[ind[bk]-1].front()];
                    ind[bk] = ind[low];
                    low++;
                    continue;
                }
                else break;
            }

            if(i > k && !vec[ind[dp[i-k-1]]].empty()) {
                while(!vec[dp[i-k-1]].empty() && vec[dp[i-k-1]].front() < i-k) vec[dp[i-k-1]].pop_front();
                if(vec[ind[dp[i-k-1]]].empty()){
                    vec[ind[low]] = vec[ind[bk]];
                    vec.resize(vec.size()-1);
                    bk = dp[vec[ind[bk]-1].front()];
                    ind[bk] = ind[low];
                }
            }

            int curr = (arr[vec[ind[low]].front()] > arr[i]) ? low : low+1;

            if(i == n-1){
                cout << curr << endl;
                break;
            }

            dp[i] = curr;

            if(ind[curr] == -1) {
                vec.pb(deque<int> (0));
                ind[curr] = vec.size()-1;
                bk = curr;
            }

            while(!vec[ind[curr]].empty() && vec[curr].front() < i-k) vec[curr].pop_front();
            while(!vec[ind[curr]].empty() && arr[vec[curr].back()] <= arr[i]) vec[curr].pop_back();
            vec[ind[curr]].push_back(i);
        }
        vec.resize(0);
    }

    return 0;
}