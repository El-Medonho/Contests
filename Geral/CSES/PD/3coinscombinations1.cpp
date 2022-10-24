#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int n,x; vector<int> coins; vector<ll> newbest;

ll newcover(){
    for(int next = x; next>=0; next--){
        for(int i : coins){
            int sum = next + i;
            if (sum > x) sum = 0;
            else sum = newbest[sum];
            newbest[next] += sum;
        }
        newbest[next] = mod(newbest[next], MOD);
    }
    return newbest[0];
}

int main(){
    fastio;
    cin >> n >> x;
    coins.resize(n,0);
    newbest.resize(x+1,0);
    newbest[x] = 1;
    for (int i = 0; i<n; i++) cin >> coins[i];
    cout << (newcover()) << endl;
    return 0;
}