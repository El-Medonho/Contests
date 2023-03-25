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

    ll n,p,d; cin >> n >> p >> d; d--;
    
    vll arr(n);
    for(ll &i: arr) cin >> i;

    int best = d, ans = 0;
    ll totalsum = 0;
    vll dqsum(n,0);
    deque<ll> dq;

    for(int i = 0; i < d; i++){
        totalsum += arr[i]; 
    }

    int pnt2 = 0;
    for(int i = d; i < n; i++){
        totalsum += arr[i];
        best++;

        if(i-d > 0){
            dqsum[i-d] = dqsum[i-d-1] - arr[i-d-1] + arr[i];
            while(!dq.empty() && dq.front() < pnt2) dq.pop_front();
        }
        else dqsum[i-d] = totalsum;

        while(!dq.empty() && dqsum[dq.back()] <= dqsum[i-d]) dq.pop_back();
        dq.push_back(i-d);

        ll curr = dqsum[dq.front()];
        while(totalsum - curr > p){
            totalsum -= arr[pnt2];
            pnt2++;
            best--;

            while(!dq.empty() && dq.front() < pnt2) dq.pop_front();
            curr = dqsum[dq.front()];
        }

        ans = max(ans, best);
    }

    cout << ans << endl;


    return 0;
}