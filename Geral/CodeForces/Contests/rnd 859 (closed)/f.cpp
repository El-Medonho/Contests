//MEDONHO APENAS

#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

int solve(){

    int n,m; cin >> n >> m;

    vector<vector<pii>> visited(n+1, vector<pii> (m+1, {0,0}));

    pii curr,end;

    {
        int i,j; cin >> i >> j;
        curr = {i,j};
        cin >> i >> j;
        end = {i,j};
    }

    pii vel;
    string dir; cin >> dir;

    if(dir == "DR") vel = {1,1};
    if(dir == "DL") vel = {1,-1};
    if(dir == "UR") vel = {-1,1};
    if(dir == "UL") vel = {-1,-1};

    ll ans = 0;

    while(true){
        if((end.f - curr.f)*vel.f == (end.s - curr.s)*vel.s && (end.f - curr.f)*vel.f >= 0){
            cout << ans << endl;
            return 0;
        }

        pii term = {(vel.f == 1) ? n : 1, (vel.s == 1) ? m : 1};
        if(abs(term.f - curr.f) <= abs(term.s - curr.s)){
            ans++;

            pii ne = {term.f, curr.s + ((abs(term.f - curr.f))*vel.s)};
            
            if(visited[ne.f][ne.s] == vel || visited[ne.f][ne.s].f == 2){
                cout << -1 << endl;
                return 0;
            }

            if(visited[ne.f][ne.s].f != 0) visited[ne.f][ne.s] = {2,2};
            else visited[ne.f][ne.s] = vel;

            vel.f *= -1;
            if(ne.s == term.s) vel.s *= -1;

            curr = ne;
        }
        else{
            ans++;

            pii ne = {curr.f + ((abs(term.s - curr.s))*vel.f) ,term.s};
            
            if(visited[ne.f][ne.s] == vel || visited[ne.f][ne.s].f == 2){
                cout << -1 << endl;
                return 0;
            }

            if(visited[ne.f][ne.s].f != 0) visited[ne.f][ne.s] = {2,2};
            else visited[ne.f][ne.s] = vel;

            vel.s *= -1;

            curr = ne;
        }
    }

    return 0;
}

int main(){
    fastio;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}