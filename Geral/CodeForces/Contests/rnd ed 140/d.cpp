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

    int n; cin >> n;
    string str; cin >> str;

    sort(str.begin(), str.end());

    int beg = 0, dif = 1;
    for(int i = n-1; i > -1; i--){
        if(str[i] == '1') beg += dif;
        dif<<=1;
    }

    int fin = 0; dif=1;
    for(int i = 0; i < n; i++){
        if(str[i] == '1') fin += dif;
        dif<<=1;
    }

    for(int i = beg; i < fin; i++) cout << i+1 << esp;
    cout << fin+1 << endl;

    return 0;
}

int main(){
    fastio;

    int t = 1;
    while(t--){
        solve();
    }    

    return 0;
}