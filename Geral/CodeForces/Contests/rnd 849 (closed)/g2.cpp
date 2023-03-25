#include "bits/stdc++.h"
#include <queue>

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

int main(){
    fastio;

    int t; cin >> t;
    while(t--){
        priority_queue<pii, vector<pii>, greater<pii>> pql, pqr;
        int n,c; cin >> n >> c;
        vii arr(n,0), used(n,0); 
        pii best = {INF,-1};
        for(int i = 0; i < n ; i++){
            cin >> arr[i];
            if(arr[i]+1+i < best.f && i == 0) best = {arr[i]+1+i, i};
            else if(arr[i]+1+i < best.f && (((n%i == 1 && i <= (i/2)+1)||(n%i == 0 && i < i/2)))) best = {arr[i]+1+i, i};
            pql.push({i+1+arr[i],i});
            pqr.push({(n-i)+arr[i],i});
        }
        int ans = 0, ans1 = 0, ans2 = 0;

        int inc = c;

        // return 0;
        if(best.s != -1){
        c -= best.f; 
        used[best.s] = 1; 
        ans1++;
        if(c < 0){
            ans1--;
            c = 0;
            // cout << ans1 << endl;
            // continue;
        }
        int cnt = 0;
        while(c > 0 && cnt < n){
            if((pqr.empty() && !pql.empty()) || (!pql.empty() && pql.top().f < pqr.top().f)){
                if(used[pql.top().s] == 1) {pql.pop(); continue;}
                c -= pql.top().f; used[pql.top().s] = 1;
                pql.pop();
                ans1++;
            }
            else if(!pqr.empty()){
                if(used[pqr.top().s] == 1) {pqr.pop(); continue;}
                c -= pqr.top().f; used[pqr.top().s] = 1;
                pqr.pop();
                ans1++;
            }
            cnt++;
        }
        if(c < 0){
            ans1--;
        }
        }
        while(!pql.empty()) pql.pop();
        while(!pqr.empty()) pqr.pop();

        for(int i = 0; i < n; i++){
            pql.push({i+1+arr[i],i});
            pqr.push({(n-i)+arr[i],i});
        }
        c = inc;
        // return 0;
        used.resize(0);
        used.resize(n,0);

{
        c -= pql.top().f; 
        used[pql.top().s] = 1; 
        ans2++;
        pql.pop();
        if(c < 0){
            ans2--;
            c = 0;
            // cout << ans1 << endl;
            // continue;
        }
        // return 0;
        int cnt = 0;
        while(c > 0 && cnt < n){
            if((pqr.empty() && !pql.empty()) || (!pql.empty() && pql.top().f < pqr.top().f)){
                if(used[pql.top().s] == 1) {pql.pop(); continue;}
                c -= pql.top().f; used[pql.top().s] = 1;
                pql.pop();
                ans2++;
            }
            else if(!pqr.empty()){
                if(used[pqr.top().s] == 1) {pqr.pop(); continue;}
                c -= pqr.top().f; used[pqr.top().s] = 1;
                pqr.pop();
                ans2++;
            }
            cnt++;
        }
        // return 0;
        if(c < 0){
            ans2--;
        }
        }
        ans = max(ans1, ans2);

        // return 0;

        cout << ans << endl;
        continue;
    }

    return 0;
}