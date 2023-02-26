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

    int n, k; cin >> n >> k;
    set<pii, greater<pii>> man;
    priority_queue<pii, vector<pii>, greater<pii>> movies, ending;

    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        movies.push({b,a});
    }

    int ans = 0;

    for(int i = 0; i < k; i++) man.insert({0,i});

    while(!movies.empty()){

        // if(!ending.empty() && ending.top().f <= movies.top().s){
        //     man.insert({ending.top().f,ending.top().s});
        //     ending.pop();
        //     continue;
        // }

        if(man.empty() || movies.top().s < (*man.rbegin()).f){
            movies.pop();
            continue;
        }

        ans++;
        // ending.push({movies.top().f, (*man.begin()).s});
        int x = (*man.lower_bound({movies.top().s,INF})).s;
        man.erase(*man.lower_bound({movies.top().s, INF}));
        man.insert({movies.top().f, x});
        movies.pop();

    }

    cout << ans << endl;

    return 0;
}