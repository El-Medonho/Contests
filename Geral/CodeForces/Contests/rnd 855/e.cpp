#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

int solve(){

    int n,k; cin >> n >> k;

    string s,t; cin >> s >> t;

    
    vii arr(26, 0);
    for(int i = 0; i < n; i++){
        arr[s[i]-'a']++;
    }
    for(int i = 0; i < n; i++){
        arr[t[i]-'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(arr[i] != 0){
            cout << "NO" << endl;
            return 0;
        }
    }

    if(n < (k*2)){
        vii aaa(n,0);
        for(int i = 0; i < n-k; i++){
            aaa[i]++;
            aaa[i+k]++;
        }
        if(n > k) aaa[n-1]++;
        
        vii ar1(26,0);
        vii ar2(26,0);
        for(int i = 0; i < n; i++){
            if(aaa[i] == 0 && s[i] != t[i]){
                cout << "NO" << endl;
                return 0;                
            }
            if(aaa[i] != 0){
                ar1[s[i]-'a']++;
                ar2[t[i]-'a']++;
            }
        }
        for(int i = 0; i < 26; i++){
            if(ar1[i] != ar2[i]){
                cout << "NO" << endl;
                return 0;  
            }
        }
    }

    cout << "YES" << endl;


    return 0;
}

int main(){
    fastio;

    int t = 0; cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}