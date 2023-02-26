#include "bits/stdc++.h"
#include <queue>
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


int main(){
    fastio;
    int t = 0; cin >> t;
    while(t--){

        int n; cin >> n;
        vii arr(n);
        for(int &x: arr) cin >> x;

        int minm = 0, maxm = INF;
        bool next = false;

        for(int i = 1; i < n; i++){
            int val = (arr[i]+arr[i-1])/2;
            
            if(arr[i] > arr[i-1]){
                maxm = min(maxm, val);
            }

            else if(arr[i] < arr[i-1]){
                if(((arr[i]+arr[i-1]))%2 == 1) val++;
                minm = max(minm, val);
            }

            if(minm > maxm){
                cout << -1 << endl;
                next = true;
                break;
            }
        }

        if(next) continue;

        cout << minm << endl;
    }    

    return 0;
}