#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int n; vector<pair<int,int>> beacons; vector<int> records, visited, forsearch;
priority_queue<pair<int,int>> pq;
int range;
int ans = 100000000;

int chainreaction(int index){

    // int currpos, currrange;
    // currpos = beacons[index].f;
    // currrange = beacons[index].s;

    // if(currpos >= range){
    //     if(index == n-1) return destroyed+1;
    //     int u = chainreaction(index+1, destroyed+1);
    //     return u;
    // }

    // if(visited[index] == 1) return records[index];
    // visited[index] = 1;

    // if(index >= n-1) return destroyed;
    // range = currpos-currrange;
    // int u = chainreaction(index+1, destroyed);
    // records[index] = u - destroyed;
    // return u;

//---------------------------------------------------

    int currrange = beacons[index].f - beacons[index].s;

    if (index == n-1) return 0;
    if (currrange <= beacons[n-1].f) return records[index] = n-1-index;  

    int u = lower_bound(forsearch.begin(), forsearch.end(), currrange) - forsearch.begin();
    return records[index] = (n-1-index) - u + records[n-1-(u-1)];
}

int main(){
    fastio;
    cin >> n;
    beacons.resize(n); records.resize(n,0); visited.resize(n,0); forsearch.resize(n);
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        pq.push({a,b});
    }
    int g = 0;
    while(!pq.empty()){
        beacons[g] = pq.top();
        pq.pop();
        g++;
    }
    for(int i = 0; i < n; i++){
        forsearch[i] = beacons[i].first;
    }

    reverse(forsearch.begin(), forsearch.end());

    // cout << beacons.back().first << endl;

    for(int i = n-1; i >= 0; i--){
        chainreaction(i);
    }

    for(int i = 0; i < n; i++){
        range = 100000000;
        int u = records[i];
        ans = min(u+i, ans);
    }

    cout << ans << endl;

    return 0;
}
