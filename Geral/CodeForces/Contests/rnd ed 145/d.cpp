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

    string str; cin >> str;

    vll occur(2,0);

    for(char c: str){
        int x = c-'0';
        occur[x]++;
    }

    int n = str.size();

    ll ans = 0;
    for(int i = n-1; i > -1;){
        if(str[i] == '1') {i--; occur[1]--;continue;}
        if(occur[1] == 0) break;
        
        vll qq(2,0);
        bool pass = false;

        for(; i > -1; i--){
            int x = str[i]-'0';
            if(x == 0 && pass) break;
            qq[x]++;
            if(x == 1) pass = true;
        }

        if(occur[1] == 1 && qq[0] == 1) ans += 1e12;
        else ans += min(qq[0], qq[1]) * (1e12 + 1);

        for(int i = 0; i < 2; i++) occur[i]-=qq[i];

    }

    cout << ans << endl;

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