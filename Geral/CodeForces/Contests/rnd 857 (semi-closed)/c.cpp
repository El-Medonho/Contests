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
typedef long double ld;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

int solve(){

    int n,m; cin >> n >> m;

    int cnt = 0;
    vector<vll> grid(256, vll(256,0));

    for(int i = 0; i < 256; i+=2){
        for(int j = 0; j < 256; j+=2){
            ll term = 4*(cnt++);
            grid[i][j] = term;
            if(j < 256-1) grid[i][j+1] = ++term;
            if(i < 256-1) grid[i+1][j] = ++term;
            if(i < 256-1 && j < 256-1) grid[i+1][j+1] = ++term;
        }
    }

    cout << n*m << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << esp;
        }
        cout << endl;
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