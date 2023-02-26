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
typedef unsigned long long ull;

int main(){
    fastio;

    int n; cin >> n;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int curr = 0;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        pq.push({b,a});
    }

    int ans = 0;

    while(!pq.empty()){
        pii movie = pq.top();
        pq.pop();
        if(movie.s < curr) continue;
        ans++;
        curr = movie.f;
    }

    cout << ans << endl;


    return 0;
}